# DJB2 Hash via C/C++ Preprocessor

This is a compile time constant implementation of the DJB2 Hash using the C/C++ Preprocessor.
You can generate the preprocessor macros using `python3 gen_djb2.py [MAXIMUM_HASH_STRING_LENGTH=25]`

## Why is this useful

This is useful for situations with a list of items with IDs known at compile time.

Heres a trivial example:

```c
typedef struct my_error {
    int id;
    char msg[64];
} my_error;
```

In order to define errors there are a few common solutions..

## Declaring using Macros

```c
#define MYERROR(name, id, msg) my_error name = {id, msg}

MYERROR(GENERAL_ERROR, 0, "Unknown error occured!");
MYERROR(OS_ERROR, 1, "OS error occured!");
```

This solution is fine but doesn't have compile time check for collisions.

## Using an ENUM

This is common too and doesn't use a struct but rather just a raw enum

```c
enum ProgramError {
    GENERAL_ERROR,
    OS_ERROR,
    ...
}
```

However this can create frustrating bugs where someone in the codebase changes
the order of errors and everything breaks. 

This can be fixed with some post build script validating the enum and comparing to a
previous version but its cumbersome and hard.

## Using My Solution

My solution allows taking the first solution and having an ID generated automatically from the error name.

The hash support having a shorter name than max hash length.

```c
#define MYERROR(name, msg) my_error name = {hash0(name), msg}

MYERROR(GENERAL_ERROR, "Unknown error occured!");
MYERROR(OS_ERROR, "OS error occured!");
```

A full tested solution can be seen in `main.c` build it using `make all` and running either `example` or `example-debug`

If you're paranoid you'd say that there's still a small chance for collisions see `paranoid.c`. `make paranoid && ./paranoid`
