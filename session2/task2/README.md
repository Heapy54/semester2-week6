# Task 2: Unit Testing with Acutest

## Overview

Write unit tests for the provided `is_palindrome()` function using **Acutest**, a lightweight C testing framework.

## Why Acutest instead of assert()?

| Feature | assert() | Acutest |
|---------|----------|---------|
| Continues after failure | No (stops) | Yes |
| Shows test names | No | Yes |
| Counts pass/fail | Manual | Automatic |
| Formatted output | No | Yes |

## Instructions

1. Open `1_tests.c`
2. Look at the example test function `test_obvious_palindrome()`
3. Add more test functions following the same pattern
4. Register each test in the `TEST_LIST` at the bottom

## Acutest Syntax

```c
void test_something(void) {
    TEST_CHECK(condition);           /* Check passes if condition is true */
    TEST_MSG("Message if it fails"); /* Optional: explain the failure */
}

TEST_LIST = {
    { "test name", test_something },
    { NULL, NULL }  /* Must end with NULL */
};
```

## What to Test

Consider testing:

- Obvious palindromes: "racecar", "madam", "level"
- Single characters: "a"
- Empty string: ""
- Non-palindromes: "hello", "world"
- Even-length palindromes: "abba", "deed"
- Edge cases: case sensitivity ("Racecar"), spaces ("race car")

## Running Your Tests

```bash
gcc 1_tests.c -o tests
./tests
```

## Expected Output

```
Test obvious palindrome (racecar)...              [ OK ]
Test single character...                          [ OK ]
Test non palindrome...                            [ OK ]
SUCCESS: All 3 tests passed.
```

If a test fails:
```
Test case sensitive...                            [ FAILED ]
  1_tests.c:25: Check is_palindrome("Racecar") == 1 failed
SUCCESS: 2 of 3 tests passed, 1 failed.
```

## Tips

- Each test function tests ONE specific case
- Use descriptive test names in TEST_LIST
- TEST_MSG helps you understand what went wrong
- Aim for at least 5 different test cases
