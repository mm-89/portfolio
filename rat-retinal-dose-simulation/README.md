# Retinal Dose Simulation in the Rat Eye  
*An experiment-inspired computational model*

## Overview
In a previous project, I developed a model capable of calculating and predicting light exposure on complex shapes and geometries, such as the human body and, in particular, the eyes ([see here](https://github.com/mm-89/portfolio/tree/main/light-exposure-model)). 

With this new project, I wanted to couple that exposure model with an optical model, i.e., a model that quantifies how energy is transferred through an optical system.

In the scientific literature, measurements are available regarding the radiant dose received on the retinas of laboratory rats, along with details of the experimental setup. Reproducing that experiment in a controlled numerical environment provides several advantages and makes it possible to understand which factors play an important role.

To achieve this, I used the [Optometrika](https://github.com/mm-89/Optometrika) model, first validating it and then modifying the source code so that it could:

1) interface with my external exposure model, and  
2) return the output in the format I needed (specifically, a radiant dose in J/m²).

This project recreates the experimental exposure conditions and estimates the spatial distribution of retinal irradiance, allowing a direct comparison with laboratory measurements.

## Scientific Background
The simulation relies on an analytical model of the rat eye, which includes:
- corneal and lens curvatures  
- positions of optical surfaces  
- wavelength-dependent refractive indices  
- a fixed pupil diameter  
- overall transmittance of the ocular media  

This optical model provides the geometric and physical foundation needed to trace rays through the eye and determine where energy is deposited on the retina.

## Modeling Approach
The simulation reproduces the original experimental conditions:
- a blue LED source (449 nm) described through measured or estimated radiometric parameters  
- an eye placed in an “average” position below the source  
- three representative locations inside the cage, selected to approximate plausible average rat positions  
- a horizontal gaze direction, matching the geometry of the experimental setup  
- 10 million rays per simulation, traced through the optical system to produce retinal irradiance maps  

Radiant dose was computed by integrating the irradiance over a 2-hour exposure, as in the real experiment.

## Objectives
- Reproduce the laboratory light-exposure conditions  
- Compute the irradiance distribution on the retina 
- Estimate the radiant dose received at different cage positions  
- Compare simulated results with experimental measurements  
- Investigate differences between the simulated and measured energy distributions  

## Main Findings
The model:
- produces dose values of the same order of magnitude as the real measurements  
- shows maximal exposure near the central area of the cage  
- reveals spatial patterns that differ from those observed experimentally, suggesting that additional geometric, behavioral, or optical factors may be involved  

Possible double internal reflections within the lens were also tested, but they were not sufficient to explain the energy peak recorded in the experimental data.

Read the technical report [HERE](Report_rat_eye.pdf)