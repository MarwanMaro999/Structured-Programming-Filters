# Image Processing Program

## Overview
This project is a C++-based image processing tool that allows users to apply various filters and transformations to RGB images. The program provides an interactive menu for users to load an image, apply multiple effects, and save the modified image.

## Features
- **Load and Save Images**: Read and write BMP images.
- **Basic Filters**: Apply black & white, inversion, darken, and lighten effects.
- **Transformations**: Flip (horizontal/vertical), rotate, skew, crop, and resize images.
- **Advanced Effects**: Blur, edge detection, mirroring, and image merging.
- **Interactive Menu**: User-friendly interface for selecting operations.

## Installation
1. Clone the repository:
   ```bash
   git clone <repository_url>
   cd image-processing
   ```
2. Compile the program using g++:
   ```bash
   g++ main.cpp -o image_processor
   ```
3. Run the program:
   ```bash
   ./image_processor
   ```

## Usage
1. Load an image by entering its filename.
2. Choose a filter or transformation from the menu.
3. Apply multiple operations as needed.
4. Save the modified image.

## Dependencies
- C++ Standard Library
- `bmplib.h` and `bmplib.cpp` (for handling BMP images)

