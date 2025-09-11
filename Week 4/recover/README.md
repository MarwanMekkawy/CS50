# CS50 Week 4 – Recover

This project implements a program to **recover JPEG images** from a raw memory card file using C.

---

## Overview
The goal of **Recover** is to:

- Scan a raw file (e.g., a memory card image) for JPEG headers.
- Extract each JPEG into a separate file.
- Name recovered files sequentially (e.g., 000.jpg, 001.jpg, 002.jpg, …).

This project emphasizes **file I/O**, **buffers**, and **pointer manipulation**.

---

## Usage

Compile your program (assuming the file is named `recover.c`):

```bash
gcc -o recover recover.c

Run the program:

./recover card.raw