from cs50 import get_string


def main():
    card_number: str | None = get_string("Number: ")
    if card_number is not None:
        print(card_type(card_number, len(card_number)))
        return
    print("INVALID")


def card_type(card_number: str, card_length: int) -> str:
    if not valid_length(card_length) or not valid_checksum(card_number):
        return "INVALID"

    card_patterns: dict[int, list[tuple[str, str]]] = {
        13: [("4", "VISA")],
        15: [("34", "AMEX"), ("37", "AMEX")],
        16: [
            ("4", "VISA"),
            ("51", "MASTERCARD"),
            ("52", "MASTERCARD"),
            ("53", "MASTERCARD"),
            ("54", "MASTERCARD"),
            ("55", "MASTERCARD"),
        ],
    }

    for prefix, bank in card_patterns.get(card_length, []):
        if card_number.startswith(prefix):
            return bank
    return "INVALID"


def valid_length(n: int) -> bool:
    return n != 14 and 13 <= n <= 16


def valid_checksum(card: str) -> bool:
    total: int = 0
    for i, digit in enumerate(reversed(card)):
        n: int = int(digit)
        if i % 2 == 1:
            n *= 2
            if n > 9:
                n -= 9
        total += n
    return total % 10 == 0


main()
