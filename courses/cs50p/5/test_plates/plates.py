def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):
    if 2 <= len(s) <= 6 and s.isalnum() and s[0:2].isalpha():
        for c in s:
            if c.isdigit():
                idx = s.index(c)
                if s[idx:].isdigit() and c != "0":
                    return True
                return False
        return True
    return False


if __name__ == "__main__":
    main()
