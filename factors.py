#!/usr/bin/python3
import sys
"""import csv

if (len(sys.argv) != 2):
    print("Usage: factors <file>")
    exit()

with open(sys.argv[1], 'r') as file:
    numbers = csv.reader(file)
    for n in numbers:
        i = 2
        while (int(n[0]) % i != 0):
            i = i + 1
        print("{}={}*{}".format(int(n[0]), int(int(n[0]) / i), i))

        #print(int(n[0]))
"""


def factorize(n):
    for i in range(2, n//2 + 1):
        if n % i == 0:
            return (i, n // i)


def main(input_file):
    try:
        with open(input_file, 'r') as file:
            for line in file:
                n = int(line.strip())
                (p, q) = factorize(n)
                print(f"{n}={q}*{p}")
    except FileNotFoundError:
        print("File not found.")
    except ValueError:
        print("Invalid input in the file.")
    except Exception as e:
        print(f"An error occurred: {e}")


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: factors <file>")
        sys.exit(1)
    input_file = sys.argv[1]
    main(input_file)
