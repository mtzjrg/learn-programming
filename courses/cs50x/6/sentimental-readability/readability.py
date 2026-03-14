from cs50 import get_string


def main():
    text: str | None = get_string("Text: ")
    if text is None:
        return 1

    lvl: int = reading_level(text)
    if lvl >= 16:
        print("Grade 16+")
    elif lvl < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {lvl}")


def reading_level(s: str) -> int:
    words: int = len(s.split())
    if words == 0:
        return 0
    letters: int = sum(1 for c in s if c.isalnum())
    sentences: int = sum(1 for c in s if c in [".", "!", "?"])

    avg_letters: float = (letters / words) * 100
    avg_sentences: float = (sentences / words) * 100
    return round(0.0588 * avg_letters - 0.296 * avg_sentences - 15.8)


main()
