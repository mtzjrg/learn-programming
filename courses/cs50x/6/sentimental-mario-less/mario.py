from cs50 import get_int


def main():
    draw_pyramid(get_height())


def get_height() -> int:
    while True:
        h: int | None = get_int("Height: ")
        if h is not None and 1 <= h <= 8:
            return h


def draw_pyramid(h: int) -> None:
    spaces: int = h - 1
    for _ in range(h):
        print(f"{' ' * spaces}{'#' * (h - spaces)}")
        spaces -= 1


main()
