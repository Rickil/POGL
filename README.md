# OpenGL Fire Scene with Raytracer

## Overview

This project is an OpenGL-based application that simulates a captivating fire scene using a raytracer. The implementation considers shadows and reflections, making the fire particles act as light sources for the raytracing process. The result is a visually stunning and realistic representation of a dynamic and illuminating fire.

## Features

1. **Raytracing Engine:** The project incorporates a raytracer that efficiently traces rays of light as they interact with the scene elements, creating a visually appealing and realistic fire effect.

2. **Fire simulation** The project has a fire simulation using kdtrees and density of particles.

3. **Fire Particle Lights:** Each particle of the fire is treated as a source of light, contributing to the illumination of the scene. This adds a dynamic and naturalistic aspect to the fire simulation.

4. **Shadows:** The raytracer considers the presence of obstacles in the scene, accurately casting shadows based on the position and intensity of the fire particles.

5. **Reflections:** Reflective surfaces are implemented in the scene, allowing for the simulation of reflections that enhance the overall realism of the fire scene.

6. **Optimizations** This project required a huge optimization by using octrees to make it run around 30 fps.

![POGL_UNCROPPED](https://github.com/Rickil/POGL/assets/38404628/15543fce-003d-4a78-98af-79238f49914d)
