from cs50 import get_int

while True:
    h = get_int("Height: ")
    if 1 <= h <= 8:
        break

# Print half-pyramid
for i in range(h):
    # Print spaces on the left
    print(" " * (h - i - 1), end="")

    # Print hashes
    print("#" * (i + 1))
