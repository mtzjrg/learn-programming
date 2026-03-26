from random import choice
from sys import argv, exit

from pyfiglet import Figlet

figlet = Figlet()
fonts = figlet.getFonts()


def main() -> None:
    match len(argv):
        case 1:
            draw_figlet(input("Input: ").strip(), choice(fonts))
        case 3:
            if argv[1] not in ("-f", "--font"):
                die()
            if argv[2] not in fonts:
                die(f'Error: "{argv[2]}" not found')
            draw_figlet(input("Input: ").strip(), argv[2])
        case _:
            die()


def die(error: str = "Usage: python figlet.py [ -f | --font FONT]"):
    print(error)
    exit(1)


def draw_figlet(text: str, font: str) -> None:
    if not text:
        die("Error: Input cannot be empty")
    figlet.setFont(font=font)
    print(f"Output: \n{figlet.renderText(text)}")


main()
