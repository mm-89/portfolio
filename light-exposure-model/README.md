# Light Exposure Simulation Library

This project is a Python-based numerical model for simulating skin and ocular exposure to **natural and artificial light** in customizable scenarios, developed as part of research published in *Computers in Biology and Medicine* (Elsevier, 2024).

🔬 **Why this model?**  
Overexposure to UV and blue light is associated with various diseases. Traditional light sensors are limited to specific positions and conditions. This library instead offers a **3D computational method** to simulate light exposure on complex geometries like human faces or entire bodies, with high spatial and temporal resolution.

### 🧠 Key Features

- Simulates direct, diffuse, and ground-reflected light
- Includes anisotropic sky model (Perez)
- Supports **artificial light sources** with arbitrary geometry and radiance
- Based on `trimesh` and `pyembree` for fast ray tracing
- Highly customizable (load any `.stl`, `.ply`, `.obj` mesh)
- Outputs spatial dose distributions and zonal statistics
- Validated against **analytical models**, **RTM data**, and **real measurements**

### 📖 Publication

Marro M., Moccozet L., Vernez D.  
**A numerical model for quantifying exposure to natural and artificial light in human health research**  
*Computers in Biology and Medicine*, Volume 171, 2024.  
DOI: [10.1016/j.compbiomed.2024.108119](https://doi.org/10.1016/j.compbiomed.2024.108119)

### 🛠️ Technologies

- Python 3.12  
- Trimesh  
- PyEmbree  
- VTKPlotter (for visualization)  
- NumPy, SciPy

### 📷 Example Output

![Example](img/example_irradiance_map.png)

*(Visualizing cumulative irradiance on a 3D mesh of a human head under ambient light)*

### 📁 Examples

In the `examples/` folder, you will find:

- Simple usage with a flat plane
- Head exposure simulation using environmental data
- Artificial light scenario: laptop screen and blue light