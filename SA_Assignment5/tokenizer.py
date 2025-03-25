import sys
import re

def main():
    for line in sys.stdin:
        # Use regex to find words
        words = re.findall(r'\b\w+\b', line)
        # Print each word on a separate line
        for word in words:
            print(word)

if __name__ == '__main__':
    main()
