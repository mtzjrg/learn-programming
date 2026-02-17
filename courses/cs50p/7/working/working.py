import re


def main():
    print(convert(input("Hours: ")))


def convert(s):
    if matches := re.search(
        r"^(\d{1,2}):?(\d{2})? (AM|PM) to (\d{1,2}):?(\d{2})? (AM|PM)$", s
    ):
        (
            first_hour,
            first_min,
            first_meridiem,
            second_hour,
            second_min,
            second_meridiem,
        ) = matches.groups()
    else:
        raise ValueError

    try:
        first_min = convert_min(first_min)
        second_min = convert_min(second_min)
    except ValueError:
        raise ValueError

    if first_hour.startswith("0") or second_hour.startswith("0"):
        raise ValueError
    if int(first_hour) > 12 or int(second_hour) > 12:
        raise ValueError

    first_hour = convert_hour(int(first_hour), first_meridiem)
    second_hour = convert_hour(int(second_hour), second_meridiem)

    return f"{first_hour:02}:{first_min:02} to {second_hour:02}:{second_min:02}"


def convert_min(min):
    if min:
        if int(min) > 59:
            raise ValueError
        return int(min)
    return 0


def convert_hour(hour, meridiem):
    match meridiem:
        case "AM":
            if hour == 12:
                hour = 0
        case "PM":
            if hour != 12:
                hour += 12
    return hour


if __name__ == "__main__":
    main()
