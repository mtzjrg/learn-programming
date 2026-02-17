# before.csv: https://cs50.harvard.edu/python/2022/psets/6/scourgify/before.csv

import csv
import sys


if len(sys.argv) < 3:
    sys.exit("Too few command-line arguments")
if len(sys.argv) > 3:
    sys.exit("Too many command-line arguments")

students = []
try:
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            last, first = row["name"].split(",")
            students.append(
                {"first": first.strip(), "last": last.strip(), "house": row["house"]}
            )
except FileNotFoundError:
    sys.exit(f"Could not read {sys.argv[1]}")
else:
    with open(sys.argv[2], "w") as new_file:
        first_row = ["first", "last", "house"]
        writer = csv.DictWriter(new_file, fieldnames=first_row)
        writer.writeheader()
        for student in students:
            writer.writerow(
                {
                    "first": student["first"],
                    "last": student["last"],
                    "house": student["house"],
                }
            )
