# Hexadecimal
⁰¹²³⁴⁵⁶⁷⁸⁹
- Most western cultures use the decimal system, aka base-10, to represent numeric data.
> 0123456789.

- As we know, computers use the binary system, aka base-2, to represent numeric (and indeed all data).
> 01.

- So our place values, instead of being 1, 10, 100, 1000, as they would in the decimal system, is 1, 2, 4, 8, 16 etc.
- Those 0s and 1s in large chains can be difficult to parse (resolve). However still useful to be able to express data.

## Hexadecimal system
- The hexadecimal system, aka base-16, is a much more concise way to express the data on a computers system.
> 0123456789abcdef.
> abcdef/ABCDEF is 10, 11, 12, 13, 14, 15 in decimal.
- This makes mapping easy because a group of four binary digits (bits) is able has 16 different combinations, and each of those combinations maps to a single hexadecimal digit.

- We have base-2 and base-10, why do we need base-16?:
- 16 is a power of 2, and so each hexadecimal digit 0 through f corresponds to a unique ordering, or unique arrangement of 4 binary digits, 4 bits.
- In this sense we can express very long, complex, binary numbers in hexadecimal in a much more concise way without losing information or having to do particularly cumborsome conversions on those numbers.

## Base numbering schemes
> Decimal Base-10 : 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15.

> Binary Base-2: 0000, 0001, 0010, 0011, 0100, 0101, 0110, 0111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111. (Goes 8,4,2,1)

> Hexadecimal Base-16 : 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, b, c, d, e, f.

- When expressing numbers in hexadecimal notation, to distinguish it from decimal notation, we prefix them with the prefix 0x.
- 0x means nothing, just a clue to identify a hexadecimal number.

> Hexadecimal Base-16 : 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf.

## Place values
- Binary - 1, 2, 4, 8... (powers of 2)
- Decimal - 1, 10, 100, 1000... (powers of 10)
- Hexadecimal - 1, 16, 256... (powers of 16)

> 397 this is the number three hundred and ninty seven.
> 0x397 is the hexadecimal number three, nine, seven. 
- This means something different as were using powers of 16 as all of our place values, instead of powers of 10.

0x|16²|16¹|16⁰
0x|256|16|1
0x|3|9|7

- Every group of 4 binary digits corresponds to a single hexadecimal digit, this makes it easy to change back and forth between hex and binary.
- To convert a binary number to hex, group 4 binary dgits together from right to left, pad the leftmost group with extra 0 bits at the front if necessary.
- Then use the chart from before to convert those bits to something a bit more concise.

E.g. How to understand what this means:
> 01000110101000101011100100111101.
This is a large binary number.
1. Split them up
> 0100 0110 1010 0010 1011 1001 0011 1101.
2. Build them from right to left.
> 1101 = 13 = D
> 0011 = 3
> 1001 = 9
> 1011 = 11 = B
> 0010 = 2
> 1010 = 10 = A
> 0110 = 6
> 0100 = 4
Which brings the number to:
> 0x46A2B93D

- Memory addresses are represented in hexidecimal.
- Useful skill in expressing and understanding memory addresses and other ways of using data in C.