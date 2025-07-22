// pin antenna:

// vcc : +3.3
// CE : D9
// CSN : D10
// MOSI : D11
// MISO : D12
// SCK : D13

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>

struct ControlData {
  int aileron;
  int elevator;
  int rudder;
  int throttle;
};

ControlData control;

int aileron  = 0;
int elevator = 0;
int rudder   = 0;
int throttle = 0;

// this is for me! -----------------------------------
// schema yoystik, pin in alto guardando da sinistra:

// 1: vuoto
// 2: vuoto
// 3: massa
// 4: +5V
// Per gli altri vedi sotto
// ----------------------------------------------------

// just to debug with monitor
// write true to see if the antenna 
// receives all the values well
// and write them as well
// TO BE ACTIVATED ONLY with arduino plugged in 
bool debug = true;

RF24 Transmitter(9, 10); // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  Transmitter.begin(); 
  Transmitter.openWritingPipe(address); 
  Transmitter.setPALevel(RF24_PA_MIN); 
  Transmitter.setChannel(87); 
  Transmitter.setDataRate(RF24_250KBPS); 
  Transmitter.stopListening(); 
}

void loop() {
  // average central value = 509-510
  aileron = analogRead(A0); // sx minimo, dx massimo

  // average center value = 518
  elevator = analogRead(A1); // giu massimo, su minimo

  // average central value = 505
  rudder = analogRead(A2); // sx minimo, dx massimo

  // A3 is connected but not used

  // trust
  throttle = analogRead(A4); 

  control.aileron = aileron;
  control.elevator = elevator;
  control.rudder = rudder;
  control.throttle = throttle;

  Transmitter.write(&control, sizeof(control));

  // per provare che funzioni il joystick
  if (debug) {
    Serial.print("Aileron");
    Serial.print("\t");
    Serial.print(control.aileron);

    Serial.print("Elevator");
    Serial.print("\t");
    Serial.print(control.elevator);

    Serial.print("Rudder");
    Serial.print("\t");
    Serial.print(control.rudder);

    Serial.print("Throttle");
    Serial.print("\t");
    Serial.print(control.throttle);
    Serial.println();
  }

}
