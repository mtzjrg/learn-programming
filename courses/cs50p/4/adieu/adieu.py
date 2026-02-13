import inflect

p = inflect.engine()
names = []

while True:
    try:
        name = input("Name: ")
        if name not in names:
            names.append(name)
    except EOFError:
        print(f"\nAdieu, adieu, to {p.join(names)}")
        break
