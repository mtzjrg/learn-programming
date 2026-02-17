# shirt.png: https://cs50.harvard.edu/python/2022/psets/6/shirt/shirt.png
# muppets.zip: https://cs50.harvard.edu/python/2022/psets/6/shirt/muppets.zip

import os
import sys

from PIL import Image, ImageOps


if len(sys.argv) < 3:
    sys.exit("Too few command-line arguments")
if len(sys.argv) > 3:
    sys.exit("Too many command-line arguments")

valid_extensions = [".jpg", ".jpeg", ".png"]
first_ext = os.path.splitext(sys.argv[1])[1]
second_ext = os.path.splitext(sys.argv[2])[1]

if first_ext not in valid_extensions:
    sys.exit("Invalid input")
if second_ext not in valid_extensions:
    sys.exit("Invalid output")
if first_ext != second_ext:
    sys.exit("Input and output have different extensions")

try:
    image = Image.open(sys.argv[1])
except FileNotFoundError:
    sys.exit("Input does not exist")

shirt = Image.open("shirt.png")
new_image = ImageOps.fit(image=image, size=shirt.size)
new_image.paste(shirt, shirt)
new_image.save(sys.argv[2])
