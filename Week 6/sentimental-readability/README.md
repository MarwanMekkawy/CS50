# Sentimental-Readability (CS50 Week 6)

This project is part of **CS50’s Introduction to Computer Science** — Week 6 (Python).  
The goal is to analyze **text inputted by the user** and determine its **sentiment** and **readability**.

---

## Problem Description

The program should:

1. **Prompt the user** to input a line of text via the terminal.
2. **Analyze the text** for sentiment using a sentiment library or word lists.
3. **Calculate readability** using metrics like the Coleman-Liau index.
4. Output both **sentiment score** and **readability grade level**.

---

## Files

- `sentimental_readability.py` → main Python program.
- `README.md` → this file.

---

## Usage

Run the program from the terminal:
to test:
- python readability.py, and wait for a prompt for input. Type in One fish. Two fish. Red fish. Blue fish. and press enter. Your program should output Before Grade 1.
- python readability.py, and wait for a prompt for input. Type in Would you like them here or there? I would not like them here or there. I would not like them anywhere. and press enter. Your program should output Grade 2.
- python readability.py, and wait for a prompt for input. Type in Congratulations! Today is your day. You're off to Great Places! You're off and away! and press enter. Your program should output Grade 3.
- python readability.py, and wait for a prompt for input. Type in Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard. and press enter. Your program should output Grade 5.
- python readability.py, and wait for a prompt for input. Type in In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since. and press enter. Your program should output Grade 7.
- python readability.py, and wait for a prompt for input. Type in Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do: once or twice she had peeped into the book her sister was reading, but it had no pictures or conversations in it, "and what is the use of a book," thought Alice "without pictures or conversation?" and press enter. Your program should output Grade 8.
- python readability.py, and wait for a prompt for input. Type in When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right; when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh. and press enter. Your program should output Grade 8.
- python readability.py, and wait for a prompt for input. Type in There are more things in Heaven and Earth, Horatio, than are dreamt of in your philosophy. and press enter. Your program should output Grade 9.
- python readability.py, and wait for a prompt for input. Type in It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him. and press enter. Your program should output Grade 10.
- python readability.py, and wait for a prompt for input. Type in A large class of computational problems involve the determination of properties of graphs, digraphs, integers, arrays of integers, finite families of finite sets, boolean formulas and elements of other countable domains. and press enter. Your program should output Grade 16+

```bash
python sentimental_readability.py
