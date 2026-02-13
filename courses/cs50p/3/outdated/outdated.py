def main():
    while True:
        try:
            print(format_date(input("Date: ").strip()))
        except ValueError:
            pass
        else:
            break


def format_date(d):
    MONTHS = [
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    ]

    if ' ' in d:
        month, day, year = d.split(' ')
        month = MONTHS.index(month) + 1
        day = int(day.removesuffix(','))

        if day < 1 or day > 31:
            raise ValueError
    else:
        month, day, year = d.split('/')
        month = int(month)
        day = int(day)

        if (day < 1 or day > 31) or (month < 1 or month > 12):
            raise ValueError
    year = int(year)

    return f"{year:04}-{month:02}-{day:02}"


main()
