import sys
from random import choice

from pyfiglet import Figlet

figlet = Figlet()


def main():
    FONTS = figlet.getFonts()
    match len(sys.argv):
        case 1:
            figlet_text(input("Input: ").strip(), choice(FONTS))
        case 3:
            if sys.argv[1] in ["-f", "--font"] and sys.argv[2] in FONTS:
                figlet_text(input("Input: ").strip(), sys.argv[2])
            else:
                sys.exit("Invalid usage")
        case _:
            sys.exit("Invalid usage")


def figlet_text(s, figlet_font):
    figlet.setFont(font=figlet_font)
    print(f"Output: \n{figlet.renderText(s)}")


main()
