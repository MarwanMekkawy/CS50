# CS50 Speller – Problem Set 5

This repository contains the **Speller** project from CS50, which implements a **fast spell-checking program** in C.

The program reads a dictionary of words into memory and checks a text file for misspelled words using a **hash table** for efficient lookup.

---

## Problem Overview

- Implement a spell checker that can load a dictionary, check words in a text file, and report misspelled words.
- Optimize for **execution time** (wall-clock) and ensure **no memory leaks**.
- Handle **case-insensitive** word checking.
- Use a hash table to achieve fast word lookup.

---

## Project Structure
speller/
│── speller.c # Main program (DO NOT modify)
│── dictionary.c # Implement: load, hash, size, check, unload
│── dictionary.h # Function prototypes and constants
│── Makefile # Compile instructions
│── dictionaries/ # Contains dictionary files (small, large)
│── texts/ # Example text files for testing

## Key Functions to Implement

1. **`load`** – Load dictionary words into memory.
2. **`hash`** – Convert a word into a hash table index.
3. **`size`** – Return the number of words in the dictionary.
4. **`check`** – Return `true` if a word is in the dictionary; `false` otherwise.
5. **`unload`** – Free all allocated memory.

> You **cannot modify** `speller.c` or the function prototypes.  
> You **can modify** `dictionary.c` and `dictionary.h` (add variables or helper functions as needed).

---

## Usage

Compile the program using the provided Makefile:

```bash
make speller
Run the program with the default dictionary:
./speller texts/text1.txt
Or specify a dictionary:
./speller dictionaries/small texts/text1.txt
or
./speller dictionaries/large texts/text1.txt