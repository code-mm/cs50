# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

Synonym for the disease known as silicosis. It is the longest word in the English language published in a dictionary.

## According to its man page, what does `getrusage` do?

The function returns statistics about the resource usage of a programm, so called process and all it's threads.

## Per that same man page, how many members are in a variable of type `struct rusage`?

The struct has 16 member variables.

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

It's faster. Pass by value creates a copy of the value in the memory. Pass by reference doesn't copy the value but only gives the
memory address where the value is available. The access of the value isn't different in both cases, in terms of the access time.

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

The for loop initializes by reading the first character from the file handle `file`. For every iteration it reads
a new character from the file, as long it doesn't reach the end of the file `EOF`.

Whitin the body of the loop a read character is checked if it's either a letter, digit or the end of a word was found.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

We couldn't recognize if a word exceeds the word length limit.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

The constant keyword makes the parameters immutable, therefore the functions `check` and `load` can't alter them.
It has the side effect that the functions in `dictionary.c` can't cause memory violations in the main function.
