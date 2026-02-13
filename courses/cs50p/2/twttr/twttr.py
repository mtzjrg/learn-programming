text = input("Input: ")
new_text = ""

for c in text:
    if c.lower() not in ['a', 'e', 'i', 'o', 'u']:
        new_text += c

print(f"Output: {new_text}")
