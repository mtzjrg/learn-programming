from datetime import date
from sys import exit

import inflect

p = inflect.engine()


def main():
    bday = input("Date of Birth: ")

    if bday.upper().isupper():
        exit("Invalid date")
    print(convert(bday))


def convert(bday):
    mins = date.today() - date.fromisoformat(bday)
    mins = p.number_to_words(mins.days * 24 * 60, andword="")
    return f"{mins.capitalize()} minutes"


if __name__ == "__main__":
    main()
