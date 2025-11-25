from cs50 import get_float

# Prompt users change owed.
while True:
    change = get_float("Change owed: ")
    if change >= 0:
        break

# Convert change to cents.
cents = round(change * 100)

coins = 0

# Quarters.
coins += cents // 25
cents %= 25

# Dimes.
coins += cents // 10
cents %= 10

# Nickels.
coins += cents // 5
cents %= 5

# Pennies.
coins += cents // 1
cents %= 1

# Print the minimum number of coins.
print(coins)
