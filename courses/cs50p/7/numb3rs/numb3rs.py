import re


def main():
    print(validate(input("IPv4 Address: ")))


def validate(ip):
    if matches := re.search(r"^(\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3})$", ip):
        bytes = matches.groups()
    else:
        return False

    for byte in bytes:
        if int(byte) > 255:
            return False
    return True


if __name__ == "__main__":
    main()
