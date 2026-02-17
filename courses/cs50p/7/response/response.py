import validators


def main():
    print(validate(input("What's your email address? ")))


def validate(email):
    if validators.email(email):
        return "Valid"
    return "Invalid"


main()
