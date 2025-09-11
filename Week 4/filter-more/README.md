# CS50 Week 4 – Filter

This project implements a **BMP image filter** in C. It reads a 24-bit uncompressed BMP file, applies a filter, and writes the resulting image to a new BMP file.

---

## Overview
The program supports four filters:

- **b** – Blur
- **e** – Edges
- **g** – Grayscale
- **r** – Reflect

Filters are applied to the image loaded from the input BMP file, and the result is saved to the output BMP file.

---

## Usage

Compile your program (assuming the file is named `filter.c`):

```bash
gcc -o filter filter.c helpers.c -lm

Run the program:
./filter [filter_flag] infile.bmp outfile.bmp

Examples:-
./filter g input.bmp output.bmp    # Apply grayscale
./filter r input.bmp output.bmp    # Apply reflect
./filter b input.bmp output.bmp    # Apply blur
./filter e input.bmp output.bmp    # Apply edges
