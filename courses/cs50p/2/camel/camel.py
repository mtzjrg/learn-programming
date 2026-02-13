var_name = input("camelCase: ")
new_var_name = ""

for c in var_name:
    if c.isupper():
        new_var_name += f"_{c.lower()}"
    else:
        new_var_name += c

print(f"snake_case: {new_var_name}")
