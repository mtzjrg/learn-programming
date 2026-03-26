def main() -> None:
    greeting: str = input("Greeting: ").strip().lower()
    print(f"${reward(greeting)}")


def reward(greeting: str) -> int:
    if greeting.startswith("hello"):
        return 0
    elif greeting.startswith("h"):
        return 20
    return 100


main()
