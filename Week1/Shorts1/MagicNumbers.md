# Magic Numbers
## E.g. Mario
- In mario pryramid we capped it at 23.
- Why 23? Because standard height of a terminal window is 24, so we wanted to fit it into the terminal.
- I iaA Bad habbit to write constants into your code. 
- By doing so, it is reffered to as a magic number. Which we want to try and avoid.
```
card deal_cards(deck name)
{
    for (int i = 0; i < 52; i++)
    {
        // deal the cards
    }
}
```
- 52 is the magic number.

### To resolve the problem:
```
card deal_cards(deck name)
{
    int deck_size = 52;
    for (int i = 0; i < deck_size; i++)
    {
        //deal the cards
    }
}
```
- This fixes one problem but created another.
- What if the deck size decreases by 1?
- C provides a preprocessor directive (macro) for creating symbolic constants.

> #define NAME REPLACEMENT
- At the time your program is compiled, #define goes through your code and replaces NAME with REPLACEMENT.
- If #include is similar to copy/paste, then #define is analogous to find/replace.

> #define PI 3.14159265
- #define goes through code and reokaces PI with 3.14159265.


### Best solution:
```
#define DECKSIZE 52

card deal_cards(deck name)
{
    for (int i = 0; i < DECKSIZE; i++)
    {
        // deal the cards.
    }
}
```