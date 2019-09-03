# Learning C Language and the UNIX System

Code snippets and cheat sheet for UNIX and C.

- [Learning C Language and the UNIX System](#learning-c-language-and-the-unix-system)
- [C Language](#c-language)
  - [Bitwise Operators](#bitwise-operators)
    - [Example](#example)
  - [Flush a Stream](#flush-a-stream)
    - [`fflush`](#fflush)
  - [Typedef Deceleration](#typedef-deceleration)
    - [Examples](#examples)
  - [`switch` Statement](#switch-statement)
  - [`scanf`](#scanf)
- [UNIX Operations](#unix-operations)
  - [`gcc`](#gcc)
    - [Options](#options)
  - [File Permissions](#file-permissions)
    - [`chmod`](#chmod)
      - [Examples](#examples-1)
  - [`export`](#export)
  - [`cut`](#cut)
    - [Options](#options-1)
    - [Example](#example-1)
  - [`grep`](#grep)
    - [Options](#options-2)
  - [`ls`](#ls)
    - [Options](#options-3)
  - [`ps`](#ps)
    - [Options](#options-4)
  - [`sort`](#sort)
    - [Options](#options-5)
  - [`uniq`](#uniq)
    - [Options](#options-6)
  - [Displaying Files in stdout](#displaying-files-in-stdout)
    - [`cat`](#cat)
    - [`head`](#head)
    - [`tail`](#tail)
  - [`wc`](#wc)
  - [`diff`](#diff)
  - [`svn`](#svn)
  - [`ln`](#ln)
    - [Options](#options-7)

# C Language

## Bitwise Operators

- `&` Binary and
- `|` Binary or
- `^` Binary xor

### Example

```C
int a=5, b=11, c;
c=a^b; // c = 14 
```

## Flush a Stream

```C
fflush(FILE *stream);
fpurge(FILE *stream);
```

### `fflush`

Flushes buffer for the stream. With no input, it will flush all buffers.

## Typedef Deceleration

Use [cdecl](https://cdecl.org) for easy conversion.

### Examples

- `int* F(char*, int**);`
  - declare F as function (pointer to char, pointer to pointer to int) returning pointer to int

## `switch` Statement

Needs to break explicitly.

## `scanf`

`scanf` family scans input according to a format.

# UNIX Operations

## `gcc`

Used for compiling C. GNU Compiler Collection.

### Options

- `-o`
  - Sets output file.
- `-O`
  - Optimization level.

## File Permissions

`ls -lsa` or `ls -l` to check permissions of files in a directory.

```
0 drwxr-xr-x   7 name  staff   224  3 Sep 10:43 .
0 drwx------+ 13 name  staff   416  3 Sep 10:43 ..
0 drwxr-xr-x  12 name  staff   384  3 Sep 10:43 .git
8 -rw-r--r--   1 name  staff    14  3 Sep 10:43 .gitignore
8 -rw-r--r--   1 name  staff  1306  3 Sep 11:43 README.md
8 -rw-r--r--   1 name  staff   114  3 Sep 10:43 hello1.c
8 -rw-r--r--   1 name  staff   289  3 Sep 10:43 helloworld.c
```

`--- --- ---` corresponds to user permissions, group permissions, other permissions.

`r` is read permission, `w` write permission, `x` execute permission.

### `chmod`

Change permission of a file. 

#### Examples

- `chmod  ug+x file` 
  - Assign executable permission to file for user and group.


## `export`

```
$ FOO="bar"
```

This will not be visible in child processes. Unless you export it.

```
$ export FOO
```

## `cut`

Cutting sections from each line.

### Options

- `-c`
  - Select line and cut.
- `-d` 
  - Select delimiter.
- `-f list`
  - The list specifies fields separated by the delimiter.

### Example

```bash
who | cut -c 1-8
ps -e|cut -d ' ' -f 1 |uniq |sort| wc -l 
```

## `grep` 

### Options

- `v`
  - Exclude 

## `ls`

Lists files.

### Options

- `-l`
  - Permissions
- `-a`
  - Include entries with `.` in front. Show hidden files.
- `-d`
  - Entries listed as plain files. 
- `-i` 
  - For each file print the serial number.

## `ps`

Lists processes.

### Options

- `-e`
  - Display processes for all users.
- `-f`
  - Display full information (information on resource usage etc.).

## `sort`

Sorts line by line. Tip: `sort` and then `uniq`. 

### Options

- `-r`
  - Sort in reverse.
- `-k`
  - Sorts according to some key.

## `uniq`

Filter out repeated lines

### Options

- `-c`
  - Precedes line with the number of times it has occurred.

## Displaying Files in stdout

### `cat`

Display entire file.

### `head`

Display first x lines. `head -x hello.c;`

### `tail`

Display last x lines. `tail -x hello.c;`

## `wc`

Word count. `wc -l` for line count.

## `diff`

```bash
diff file1 file2
```

Displays diff of two files. Use `vimdiff` for visual experience.

## `svn`

Why even learn svn?

- commit
- add
- remove
- move
- update
- info
- log
- status 
- diff

## `ln`

Make links. To create a symbolic link

### Options

- `-s`
  - Creates a symbolic link.


