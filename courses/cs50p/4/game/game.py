import random


while True:
    try:
        lvl = int(input("Level: ").strip())
    except ValueError:
        pass
    if lvl > 0:
        answer = random.randint(1, lvl)
        break

while True:
    try:
        guess = int(input("Guess: ").strip())
    except ValueError:
        pass
    if guess > 0:
        if guess < answer:
            print("Too small!")
        elif guess > answer:
            print("Too big!")
        else:
            print("Just right!")
            break
