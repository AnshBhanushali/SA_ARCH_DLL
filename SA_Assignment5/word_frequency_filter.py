import sys
from collections import Counter

def main():
    if len(sys.argv) != 2:
        print("Usage: python word_frequency_filter.py <min_frequency>")
        sys.exit(1)

    try:
        min_freq = int(sys.argv[1])
    except ValueError:
        print("Minimum frequency must be an integer")
        sys.exit(1)
    
    # Read all words from standard input and remove extra whitespace
    words = [line.strip() for line in sys.stdin if line.strip()]
    
    # Count the frequency of each word
    freq = Counter(words)
    
    # Output words that meet or exceed the frequency threshold
    for word, count in freq.items():
        if count >= min_freq:
            print(word)

if __name__ == '__main__':
    main()
