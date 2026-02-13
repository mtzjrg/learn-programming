def main():
    x, y, z = input("Expression: ").split(" ")
    print(calculate(int(x), int(z), y))


def calculate(n1, n2, op):
    match op:
        case "+":
            solution = n1 + n2
        case "-":
            solution = n1 - n2
        case "*":
            solution = n1 * n2
        case "/":
            solution = n1 / n2

    return float(solution)


main()
