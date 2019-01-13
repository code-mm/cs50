# Questions

## What's `stdint.h`?

A header file defining the size of data types. The sizes depend on the used hardware platform and compiler.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

This data types ensure a specific size of the data type in memory at runtime.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

According to their typdef in `bmp.h`:
BYTE    1 byte
DWORD   4 byte
LONG    4 byte
WORD    2 byte

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

ASCII          BM
decimal        42, 77
hexadecimal    0x42, 0x4d

## What's the difference between `bfSize` and `biSize`?

First one defines the size for the whole file, later only for the image.

## What does it mean if `biHeight` is negative?

A negative value indicates a bottom up image. Means the first line of the actual image data is at the end
of the image data and last line is a the top.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

According to the Microsoft documentation (https://msdn.microsoft.com/en-us/library/dd183376(v=vs.85).aspx)
the field `biBitCount` determines the number of bits that define each pixel. Possible values are 0, 1, 4, 8, 16, 24, 32.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

Either the file doesn't exist or the program hasn't sufficient access rights.

## Why is the third argument to `fread` always `1` in our code?

This argument defines how much elements `fread` should read. The argument before
this one defines the size of each element. It only reads the amount of data required
for the specific use case.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

(4−(3×3) mod 4) mod 4 = 3

## What does `fseek` do?

It set's the cursor of a file handle to a given offset.

## What is `SEEK_CUR`?

It defines the cursor postion e.g. `whence` for the `fseek` function. `SEEK_CUR` specifically
sets the cursor position to current position of the file pointer.

## Whodunit?

It was Professor Plum with the candlestick in the library.