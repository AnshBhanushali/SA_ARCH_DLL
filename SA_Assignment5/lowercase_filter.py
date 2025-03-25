import sys

def main():
    # Process each line or word from the standard input
    for line in sys.stdin:
        word = line.strip()
        if word:
            print(word.lower())

if __name__ == '__main__':
    main()
