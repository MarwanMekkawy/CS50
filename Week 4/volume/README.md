# CS50 Week 4 – Volume

This project modifies the **volume of WAV audio files** using C. It reads a WAV file, scales its audio samples by a given factor, and writes the result to a new WAV file.

---

## Overview
The program allows you to **increase or decrease the volume** of a WAV audio file.

- Input WAV file must be **16-bit PCM**.
- Output WAV file will have the same format as the input.
- Scaling is done by multiplying each audio sample by a given factor.

---

## Usage

Compile the program (assuming the file is named `volume.c`):

```bash
gcc -o volume volume.c helpers.c -lm

Run the program:
./volume input.wav output.wav factor

Examples
./volume input.wav output.wav 2.0   # Double the volume
./volume input.wav output.wav 0.5   # Halve the volume