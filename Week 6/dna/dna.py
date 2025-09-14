import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) not in (2, 3):
        print(
            f"Usage: python {sys.argv[0]} [databases file].csv [DNA file].txt")
        print("OR")
        print(f"Usage: python {sys.argv[0]} [DNA file].txt")
        sys.exit(0)

    elif len(sys.argv) == 2:
        databases_file = "databases/large.csv"
        Dna_file = sys.argv[1]

    elif len(sys.argv) == 3:
        databases_file = sys.argv[1]
        Dna_file = sys.argv[2]

    # Read database file into a variable
    with open(databases_file) as f:
        reader = csv.DictReader(f)
        Db = list(reader)
        strs = reader.fieldnames[1:]

    # Read DNA sequence file into a variable
    with open(Dna_file) as f:
        Dna = f.read().strip()

    # Find longest match of each STR in DNA sequence
    result_str_count = []
    for i in strs:
        result_str_count.append(longest_match(Dna, i))

    # Check database for matching profiles
    for row in Db:
        name = row["name"]
        values = [int(row[s]) for s in strs]
        if values == result_str_count:
            print(name)
            sys.exit(0)

    print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
