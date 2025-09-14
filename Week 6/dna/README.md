# DNA (CS50 Week 6)

This project is part of **CS50’s Introduction to Computer Science** — Week 6 (Python).  
The goal is to identify a person based on their DNA sequence using STR (Short Tandem Repeats) counts.

---

## Problem Description

Each human genome contains **short tandem repeats (STRs)** — sequences of DNA that repeat consecutively.  
Different individuals have different counts of these STRs, which can be used for identification.

Your program should:

1. Read a **database CSV file** containing names and STR counts.
2. Read a **DNA sequence TXT file**.
3. Determine which individual (if any) matches the DNA sequence.

---

## Files

- `dna.py` → main Python program.
- `databases/` → folder containing sample CSV files.
- `sequences/` → folder containing DNA sequence `.txt` files.
- `README.md` → this file.

---

## Usage

Run the program from the terminal:


```bash
python dna.py
OR
python dna.py sequence.txt
OR
python dna.py data.csv sequence.txt
