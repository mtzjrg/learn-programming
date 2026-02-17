def main():
    while True:
        try:
            fuel = convert(input("Fraction: "))
        except (ValueError, ZeroDivisionError):
            pass
        else:
            print(gauge(fuel))
            break


def convert(fraction):
    x, y = fraction.split("/")
    if 0 <= (int(x) / int(y)) <= 1:
        return round((int(x) / int(y)) * 100)
    raise ValueError


def gauge(percentage):
    if percentage >= 99:
        return "F"
    elif percentage <= 1:
        return "E"
    return f"{percentage}%"


if __name__ == "__main__":
    main()
