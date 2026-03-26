import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states: list[str] = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state: str = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print("\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader: csv.DictReader[str]):
    new_cases: dict[str, list[int]] = {}
    previous_cases: dict[str, int] = {}

    # Get last 15 days of recent data from overall data
    recent_data = list(reader)[-56 * 15 :]
    for row in recent_data:
        state = row["state"]
        cases = int(row["cases"])

        if state not in new_cases:
            new_cases[state] = []
            previous_cases[state] = 0

        daily_new = cases - previous_cases[state]
        new_cases[state].append(daily_new)
        previous_cases[state] = cases

        if len(new_cases[state]) > 14:
            new_cases[state].pop(0)

    return new_cases


# Calculate and print out seven day average for given state
def comparative_averages(new_cases: dict[str, list[int]], states: list[str]):
    for state in sorted(states):
        previous_week_avg = sum(new_cases[state][:7]) / 7
        current_week_avg = sum(new_cases[state][7:]) / 7

        try:
            percentage = (current_week_avg - previous_week_avg) / previous_week_avg
        # Skip state
        except ZeroDivisionError:
            continue

        if percentage >= 0:
            direction = "an increase"
        else:
            direction = "a decrease"

        print(
            f"{state} had a 7-day average of {current_week_avg:.0f} and {direction} of {abs(round(percentage * 100))}%."
        )


main()
