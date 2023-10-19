# Jan-Feb 2023
### Question 2.3:
The station code should meet the following requirements.
- Should begin with a capital letter.
- This is followed by any 2 lowercase alphabetic characters.
- This is followed by the same capital letter as the initial character of the code.
- The numeric part of the code is made up of any 3 digits, where the first digit cannot be zero.
- There should be no other characters before or after this code.

`Note: when using QRegularExpression you need to escape your string literals like backslash. If you use a backslash in a string, then you have to escape it in the string with another backslash`

```cpp
"^([A-Z]){1}[a-z]{2}\\1[1-9]{1}\\d{2}$"   OR   "^([A-Z]){1}[a-z]{2}\\1[1-9]{1}[0-9]{2}$"

// The sections are grouped by parenthesis "()"
// And are seen as:
//  Group 1 - ([A-Z])

// {1}  - means that there should be 1 instance of the defined group
// {2}  - means that there should be 2 instances of the defined group
// {n}  - means that there should be n instance(n) of the defined group (replace n with an integer)
// \d   - means digit (0-9)
// ^    - Start of string, or start of line in multilinepattern
// $    - End of string, or end of line in multi-line pattern
// [A-Z] - defines a selection from the uppercase letter A until the uppercase letter Z
// [a-z] - defines a selection from the lowercase letter a until the lowercase letter z
// The trailing \1 means that it should repeat Group 1
// If you put a trailing \2 then you want it to repeat Group 2
// If you put a trailing \3 then you want it to repeat Group 3 etc.

// When used with QRegularExpression
QRegularExpression re("^([A-Z]){1}[a-z]{2}\\1[1-9]{1}\\d{2}$");

// When just provided (not a QRegularExpression)
^([A-Z]){1}[a-z]{2}\1[1-9]{1}\d{2}$
```

# Oct-Nov 2021
### Question 2.2
Write the regular expression that can be used to check whether a string meets the following requirements:
- The first character should be a G, K, or W (for Gauteng, KwaZulu-Natal and Western Cape).
- The second character could be any uppercase alphabetic character.
- This should be followed by one or more lowercase alphabetic characters or digits.
- The final character should be the same as the first character.

`Note: when using QRegularExpression you need to escape your string literals like backslash. If you use a backslash in a string, then you have to escape it in the string with another backslash`

```cpp
// ([GKW])([A-Z])([a-z\d]+)\1   OR  ([GKW])([A-Z])([a-z0-9]+)\1
// The sections are grouped by parenthesis "()"
// And are seen as:
//  Group 1 - ([GKW])
//  Group 2 - ([A-Z])
//  Group 3 - ([a-z\d]+)

// The trailing \1 means that it should repeat Group 1
// If you put a trailing \2 then you want it to repeat Group 2
// If you put a trailing \3 then you want it to repeat Group 3 etc.

// When used with QRegularExpression
QRegularExpression re("([GMK])([A-Z](a-z0-9)+)\\1");

// When just provided (not a QRegularExpression)
([GMK])([A-Z](a-z0-9)+)\1
```