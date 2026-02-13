from random import randint


def main():
    lvl = get_level()
    score = 0

    for _ in range(10):
        fails = 0
        x = generate_integer(lvl)
        y = generate_integer(lvl)
        solution = x + y

        while True:
            if fails == 3:
                print(f"{x} + {y} = {solution}")
                break

            try:
                answer = int(input(f"{x} + {y} = "))
                if answer != solution:
                    raise ValueError
            except ValueError:
                fails += 1
                print("EEE")
                pass
            else:
                score += 1
                break

    print(f"Score: {score}")


def get_level():
    while True:
        try:
            n = int(input("Level: ").strip())
        except ValueError:
            pass
        else:
            match n:
                case 1 | 2 | 3:
                    return n
                case _:
                    pass


def generate_integer(level):
    match level:
        case 1:
            return randint(0, 9)
        case 2:
            return randint(10, 99)
        case 3:
            return randint(100, 999)
        case _:
            raise ValueError


if __name__ == "__main__":
    main()
