from cs50 import get_string
import math

# Promt user.
text = get_string("Text: ")

# Counters.
letters = 0
words = 1
sentences = 0

# Count counters.
for c in text:
    if c.isalpha():
        letters += 1
    elif c == " ":
        words += 1
    elif c in [".", "!", "?"]:
        sentences += 1

# Averages per 100 words.
L = (letters / words) * 100
S = (sentences / words) * 100

# Coleman-Liau index.
X = round(0.0588 * L - 0.296 * S - 15.8)

# Grade Level.
if X < 1:
    print("Before Grade 1")
elif X >= 16:
    print("Grade 16+")
else:
    print(f"Grade {X}")
