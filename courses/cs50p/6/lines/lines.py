from sys import argv, exit


if len(argv) < 2:
    exit("Too few command-line arguments")
if len(argv) > 2:
    exit("Too many command-line arguments")
if not argv[1].endswith(".py"):
    exit("Not a Python file")

line_count = 0
try:
    with open(argv[1]) as file:
        for row in file:
            if not row.isspace() and not row.lstrip().startswith("# "):
                line_count += 1
except FileNotFoundError:
    exit("File does not exist")
else:
    print(line_count)
