import sys

def main():
    # Ensure both minimum and maximum lengths are provided
    if len(sys.argv) != 3:
        print("Usage: python length_filter.py <min_length> <max_length>")
        sys.exit(1)
    
    try:
        min_len = int(sys.argv[1])
        max_len = int(sys.argv[2])
    except ValueError:
        print("Min and max lengths must be integers")
        sys.exit(1)
    
    # Process each word from the standard input
    for line in sys.stdin:
        word = line.strip()
        if word and min_len <= len(word) <= max_len:
            print(word)

if __name__ == '__main__':
    main()
