def main():
    fuel = get_fuel()

    if fuel >= 99:
        print("F")
    elif fuel <= 1:
        print("E")
    else:
        print(f"{fuel}%")


def get_fuel():
    while True:
        fraction = input("Fraction: ")
        try:
            x, y = fraction.split('/')
            if 0 <= (int(x) / int(y)) <= 1:
                return round((int(x) / int(y)) * 100)
        except (ValueError, ZeroDivisionError):
            pass


main()
