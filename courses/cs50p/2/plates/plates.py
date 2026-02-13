def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):
    # Plate at least two chars, no more than 6, is comprised of letters/numbers
    # and the first two chars are letters
    if 2 <= len(s) <= 6 and s.isalnum() and s[0:2].isalpha():
        for c in s:
            # There should be no numbers in the middle of a plate number
            if c.isdigit():
                idx = s.index(c)
                # First number used cannot be zero
                if s[idx:].isdigit() and c != '0':
                    # Meets all requirements, valid plate
                    return True
                # Doesn't meet all requirements, invalid plate
                return False
        # Only letters, meets all requirements, valid plate
        return True
    # Doesn't meet all requirements, invalid plate
    return False


main()
