def main():
    time = convert(input("What time is it? "))

    if 7 <= time <= 8:
        print("breakfast time")
    elif 12 <= time <= 13:
        print("lunch time")
    elif 18 <= time <= 19:
        print("dinner time")

def convert(time):
    hours, minutes = time.split(":")

    # Convert hours
    match hours:
        case "12" if minutes.endswith("a.m."):
            hours = 0
        case hours if minutes.endswith("p.m.") and int(hours) != 12:
            hours = int(hours) + 12
        case _:
            hours = int(hours)
    # Convert minutes
    minutes = int(minutes.rstrip("a.m.").rstrip("p.m.")) / 60

    return hours + minutes


if __name__ == "__main__":
    main()
