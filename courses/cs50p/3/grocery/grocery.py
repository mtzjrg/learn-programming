grocery_list = {}

while True:
    try:
        grocery_item = input("").upper()
        if grocery_item in grocery_list:
            grocery_list[grocery_item] += 1
        else:
            grocery_list.update({grocery_item: 1})
    except EOFError:
        sorted_grocery_list = dict(sorted(grocery_list.items()))
        for item in sorted_grocery_list:
            print(sorted_grocery_list[item], item)
        break
