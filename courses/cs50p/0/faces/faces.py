def main():
    print(convert(input("")))

def convert(s):
    return s.replace(":)", "🙂").replace(":(", "🙁")


main()
