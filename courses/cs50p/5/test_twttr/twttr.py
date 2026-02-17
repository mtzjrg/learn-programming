def main():
    print(f"Output: {shorten(input('Input: ').strip())}")


def shorten(word):
    new_word = ""
    for c in word:
        if c.lower() not in ["a", "e", "i", "o", "u"]:
            new_word += c
    return new_word


if __name__ == "__main__":
    main()
