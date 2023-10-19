# Jan-Feb 2023
### Question 2.3:
The station code should meet the following requirements.
- Should begin with a capital letter.
- This is followed by any 2 lowercase alphabetic characters.
- This is followed by the same capital letter as the initial character of the code.
- The numeric part of the code is made up of any 3 digits, where the first digit cannot be zero.
- There should be no other characters before or after this code.

`Note: when using QRegularExpression you need to escape your string literals like backslash. If you use a backslash in a string, then you have to escape it in the string with another backslash`

```c++
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

# Oct-Nov 2022
### Question 2.2
It has been decided to use regular expressions to scan the file. Write the regular
expression, in quotes, that can be used to check for the words “vegan chocolate” or
“vegan chocolates” in the provided text file. You should not use the pipe symbol (|) and
ensure that you use escape characters correctly. (4)

`Note: when using QRegularExpression you need to escape your string literals like backslash. If you use a backslash in a string, then you have to escape it in the string with another backslash`

```c++
// \b - Defines the word boundary (Its where a word starts or ends)
// ? - 0 or 1 instances of the selection in the group. If not in a group, then it relates to value before it.
// * - 0 or more instances of the selection in the group. If not in a group, then it relates to value before it.
// + - 1 or more instances of the selection in the group. If not in a group, then it relates to value before it.
// (a|b) a or b - This wasn't used, but is useful to know (Its a logical OR)


// When used with QRegularExpression
QRegularExpression re("\\bvegan chocolate[s]?\\b");
OR
QRegularExpression re("\\bvegan chocolate(s)?\\b");
OR
QRegularExpression re("\\bvegan chocolates?\\b");


// When just provided (not a QRegularExpression)
\bvegan chocolate[s]?\b
OR
\bvegan chocolate(s)?\b
OR
\bvegan chocolates?\b
```

# Oct-Nov 2021
### Question 2.2
Write the regular expression that can be used to check whether a string meets the following requirements:
- The first character should be a G, K, or W (for Gauteng, KwaZulu-Natal and Western Cape).
- The second character could be any uppercase alphabetic character.
- This should be followed by one or more lowercase alphabetic characters or digits.
- The final character should be the same as the first character.

`Note: when using QRegularExpression you need to escape your string literals like backslash. If you use a backslash in a string, then you have to escape it in the string with another backslash`

```c++
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

# Oct-Nov 2020
### Question 1.2.2
Provide the code (based on that provided above) that uses a QRegExpValidator to force a user to enter a patient number in exactly the following format:
- First 3 digits: number between 100 and 199.
- Optional gender character (using an f or an m).
- 3 or more alphabetic characters, where at least the first character is a capital letter. (11)

`Note: when using QRegularExpression you need to escape your string literals like backslash. If you use a backslash in a string, then you have to escape it in the string with another backslash`

```c++
// [1][0-9]{2}(f|m)?[A-Z]{1}[a-zA-Z]{2,}  OR  [1]\d{2}(f|m)?[A-Z]{1}[a-zA-Z]{2,}

// [1]      - Expect the digit 1 
// [0-9]    - defines a selection from the digits 0 through 0 (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)
// {2}      - Expecting 2 occurrences
// (f|m)    - Either f or m
// ?        - 0 or 1 instances of the selection in the group. If not in a group, then it relates to value before it.
// [A-Z]    - defines a selection from the uppercase letter A until the uppercase letter Z
// {1}      - Expecting 1 occurrence
// [a-zA-Z] - defines a selection from the lowercase a and uppercase letter A until the lowercase Z and uppercase letter Z
// {2,}     - Matches the previous token between 2 and unlimited times, as many times as possible, giving back as needed (greedy)

// When used with QRegularExpression
QRegularExpression re("[1][0-9]{2}(f|m)?[A-Z]{1}[a-zA-Z]{2,}");
OR
QRegularExpression re("[1]\\d{2}(f|m)?[A-Z]{1}[a-zA-Z]{2,}");

// When just provided (not a QRegularExpression)
[1][0-9]{2}(f|m)?[A-Z]{1}[a-zA-Z]{2,}
OR
[1]\d{2}(f|m)?[A-Z]{1}[a-zA-Z]{2,}
```