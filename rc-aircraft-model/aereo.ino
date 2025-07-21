#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>

#include <Servo.h>

// 4 servos + ESC (treated as a servo)
Servo aileronR;
Servo aileronL;

Servo rudder;
Servo elevator;

Servo throttle;

// same struct we used to send value
struct ControlData {
  int aileron
  int elevator;
  int rudder;
  int throttle;
};

// just to order all values we have for each servo
// in particular:

// arduino has a max of 10 bits, so we have
// 2^10 = 1024 values to cover 0-5V signal

// inputMin refers to 0V
// inputMax refers to 5V

// servoMin refers to minumin rotation angle in degrees (tipical is from 0°)
// servoMax refers to maximum rotation angle in degrees (tipical is uptil 180°)

// servoNeutral refers to the position (in degrees) of the servo

struct ServoData {
  int inputMin = 0; 
  int inputMax = 1023;
  int servoMin = 0;           // °
  int servoMax = 180;         //°
  int servoNeutral = 90;      //°
}

ControlData controls;

// just to debug with monitor
// write true to see if the antenna 
// receives all the values well
// and write them as well
// TO BE ACTIVATED ONLY with arduino plugged in 
bool debug = false; 

// let's define the pins (NOT TO BE CHANGED: see circuit!)
const int pin_aileronR	= 2;
const int pin_aileronL 	= 3;
const int pin_elevator	= 4;
const int pin_rudder    = 5;
const int pin_throttle  = 6;

RF24 Receiver(9, 10); // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void setup() {

  aileronR.attach(pin_aileronR);
  aileronL.attach(pin_aileronL);

  rudder.attach(pin_rudder); 
  elevator.attach(pin_elevator);

  throttle.attach(pin_throttle);

  Serial.begin(9600); 
  Receiver.begin(); 
  Receiver.openReadingPipe(0, address); 
  Receiver.setPALevel(RF24_PA_MIN); 
  Receiver.setChannel(87);
  Receiver.setDataRate(RF24_250KBPS); 
  Receiver.startListening(); 

}

void loop() {
  if(Receiver.available()) {
    
    Receiver.read(&controls, sizeof(controls));
    
    aileronR.write(map(controls.aileronR, 0, 1023, 0, 180));
    aileronL.write(map(controls.aileronL, 0, 1023, 180, 0)); // left side is inverted
    elevator.write(map(controls.elevator, 0, 1023, 0, 180));
    rudder.write(map(controls.rudder, 0, 1023, 0, 180));
    throttle.write(map(controls.throttle, 0, 1023, 0, 180));

    if (debug) {
   	  Serial.print("ailR: "); Serial.print(controls.aileronR);
    	Serial.print("ailL: "); Serial.print(controls.aileronL);
    	Serial.print("elev: "); Serial.print(controls.elevator);
    	Serial.print("rudd: "); Serial.print(controls.rudder);
    	Serial.print("thro: "); Serial.println(controls.throttle);
    }
   
  }


}
