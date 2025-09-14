

def main():
    # Prompt the user for some text
    text = input("TexT: ")
    length = len(text)

    # Count the number of letters, words, and sentences in the text
    letters = count_letters(text, length)
    words = count_words(text)
    sentences = count_sentences(text)

    # Compute the Coleman-Liau index
    L = (letters / words) * 100
    S = (sentences / words) * 100
    index = 0.0588 * L - 0.296 * S - 15.8

    # Print the grade level
    if index < 1:
        print("Before Grade 1")

    elif index > 15:
        print("Grade 16+")

    else:
        print("Grade", int(round(index)))

    return 0

# Return the number of letters in text


def count_letters(text, length):
    letters = 0
    for i in range(length):
        if text[i].isalpha():
            letters += 1

    return letters

# Return the number of words in text


def count_words(text):
    return text.count(" ")+1

# Return the number of sentences in text


def count_sentences(text):
    return text.count(".")+text.count("?")+text.count("!")


main()
