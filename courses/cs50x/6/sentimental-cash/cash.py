from cs50 import get_float


def main():
    print(get_coins(get_change()))


def get_change() -> int:
    while True:
        change: float | None = get_float("Change: ")
        if change is not None and change >= 0.0:
            return round(change * 100)


def get_coins(change: int) -> int:
    QUARTER = 25
    DIME = 10
    NICKEL = 5
    PENNY = 1

    coins = 0
    while change > 0:
        if change >= QUARTER:
            change -= QUARTER
        elif change >= DIME:
            change -= DIME
        elif change >= NICKEL:
            change -= NICKEL
        else:
            change -= PENNY
        coins += 1
    return coins


main()
