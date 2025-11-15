# Ocular Irradiance Model

This repository contains the link to the source code and model used in the article:

- link the the official repository [HERE](https://github.com/mm-89/OcularAmbientIrradianceModel)

**"A model of ocular ambient irradiance at any head orientation"**  
_Michele Marro, Laurent Moccozet, David Vernez_  
Computers in Biology and Medicine (Elsevier), 2024  

DOI: [10.1016/j.compbiomed.2024.108119](https://doi.org/10.1016/j.compbiomed.2024.108903)

## Overview

This model estimates the amount of ambient ultraviolet irradiance reaching the ocular region depending on head orientation, solar position, and environmental light conditions.

🔬 Originally developed to study the link between **UV exposure** and **ocular pathologies** such as cataracts or pterygium.

📐 Built using a validated Monte Carlo-based 3D model, and converted into fast, closed-form equations using:
- Hemispherical harmonic regression (for the direct component)
- Sigmoid+linear model (for diffuse and reflected components)

🧠 The model accounts for:
- Sun position and irradiance (DNI/DHI)
- Head pitch/yaw (angles β and α)
- Anatomical occlusions (nose, eyelids, etc.)

## Features

- Python implementation
- Compute **ocular irradiance** and **radiant exposure**
- Can be integrated with radiative transfer models (e.g. libRadtran)
- Supports simulations over time and orientation
