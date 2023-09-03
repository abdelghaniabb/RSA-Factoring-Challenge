#!/usr/bin/python3
import sys
def isprime(p):
    for i in range(2, p//2 + 1):
        if p % i == 0:
            return False
    return True

def factorize(n):
    for i in range(2, n//2 + 1):
        if n % i == 0 and isprime(i) and isprime(n // i):
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
