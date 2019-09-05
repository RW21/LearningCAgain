# Learning C Language and the UNIX System

Code snippets and cheat sheet for UNIX and C55.

- [Learning C Language and the UNIX System](#learning-c-language-and-the-unix-system)
- [C Language](#c-language)
  - [Types](#types)
  - [Bitwise Operators](#bitwise-operators)
    - [Example](#example)
  - [Numerical Operators](#numerical-operators)
    - [Division](#division)
  - [Pointers](#pointers)
    - [Pointer Related Functions](#pointer-related-functions)
    - [Examples](#examples)
  - [Structs](#structs)
  - [Macros](#macros)
    - [Example](#example-1)
  - [Conditional Compiling](#conditional-compiling)
  - [`enums`](#enums)
  - [`unions`](#unions)
  - [Flush a Stream](#flush-a-stream)
    - [`fflush`](#fflush)
  - [Receiving Input from stdin](#receiving-input-from-stdin)
    - [Input ffunctions](#input-ffunctions)
  - [Typedef Deceleration](#typedef-deceleration)
    - [Example](#example-2)
  - [Reading from Files/Streams](#reading-from-filesstreams)
  - [`switch` Statement](#switch-statement)
  - [`scanf`](#scanf)
  - [Freeing Memory](#freeing-memory)
  - [Processes](#processes)
    - [Macros](#macros-1)
    - [Zombies](#zombies)
- [UNIX Operations](#unix-operations)
  - [Redirection](#redirection)
    - [Example](#example-3)
  - [`gcc`](#gcc)
    - [Options](#options)
  - [File Permissions](#file-permissions)
    - [`chmod`](#chmod)
      - [Examples](#examples-1)
  - [`export`](#export)
  - [`cut`](#cut)
    - [Options](#options-1)
    - [Example](#example-4)
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
  - [Deleting files/directories](#deleting-filesdirectories)
    - [`rm`](#rm)
      - [Options](#options-8)
    - [`rmdir`](#rmdir)
  - [File Transportation](#file-transportation)
    - [`cp`](#cp)
      - [Options](#options-9)
    - [`mv`](#mv)
  - [`less` and `more`](#less-and-more)
    - [`less`](#less)
    - [`more`](#more)

# C Language

## Types

- Signed integer types
  - char ≤ short int ≤ int ≤ long int ≤ long long int
- Unsigned integer types
  -  unsigned char ≤ unsigned short int ≤ unsigned int ≤ unsigned long int ≤ unsigned long long int
-  floating point types
   -  float ≤ double ≤ long double

## Bitwise Operators

- `&` Binary and
- `|` Binary or
- `^` Binary xor

### Example

```C
int a=5, b=11, c;
c=a^b; // c = 14 
```

## Numerical Operators

### Division

Integer division will always truncate towards zero.

## Pointers

### Pointer Related Functions

- `memset()`
  - Set a chunk of bytes to a value.
- `memcpy()`
  - Copy bytes from a pointer to a pointer.

Use [cdecl](https://cdecl.org) for easy conversion.

### Examples

- `int* F(char*, int**);`
  - Declare F as function (pointer to char, pointer to pointer to int) returning pointer to int.
- `void (*g)();`
  - `g` is a pointer to a function that takes in an unspecified number of parameters and returns nothing.

## Structs

```C
struct Data { 
int length ;
char* str ;
};

struct Data d1;
struct Data* d2=malloc(sizeof(struct Data));

// linked list
struct Node { 
int value ;
struct Node* next ;
};

(*(*(*(*n).next).next).next).value = 4;
// or
n−>next−>next−>next = 4
```

## Macros

Looks like a function call but is processed by the preprocessor (macro processor that is used by the compiler to transform code before compiling).

### Example

```C
#define CUBE(X) ((X)*(X)*(X))
```

## Conditional Compiling

```C
#ifdef OMP SUPPORT
// stuff that only works under OMP
#endif

#ifndef A
#define A // A things
#endif
```

## `enums`

```C
enum Day{
    SUNDAY,
    MONDAY,...
};

enum Day d = TUESDAY;
```

## `unions`

```C
union Staff{
    struct TechStaff staff;
    struct PaymentInfo info;
};
```


## Flush a Stream

```C
fflush(FILE *stream);
fpurge(FILE *stream);
```

### `fflush`

Flushes buffer for the stream. With no input, it will flush all buffers.

## Receiving Input from stdin

### Input ffunctions

- `fgetc()`
- `fgets()`
- `fread()`

## Typedef Deceleration

`typedef actualtype newname ;`

Typedef on structs are possible.

### Example

```C
typedef char* cptr;

cptr x, y, z;
```

## Reading from Files/Streams

Use `fopen()` to get a `FILE*`. Remember to `fclose()`. `fopen()` will return a null pointer if it fails to open a file.


## `switch` Statement

Needs to break explicitly.

## `scanf`

`scanf` family scans input according to a format.

## Freeing Memory

We should free memory which is reserved dynamically.

## Processes

`fork()` forks a process. Returns 0 if direct child and child's process id otherwise. `exit()` is a system call which ends the current process. You cannot use it to end different processes. 

### Macros

- `WIFEXITED`
  - Returns a nonzero value if the child process terminated normally with exit.
- `WEXITSTATUS`
  - If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value from the child process. [gnu.org](https://www.gnu.org/software/libc/manual/html_node/Process-Completion-Status.html)

### Zombies

The memory and resources of the process have been released but part of the process still remains. A process in this state is called a zombie.

# UNIX Operations

## Redirection

To redirect stdin use `>`.

### Example

```bash
ls /etc > listoffiles
cat listoffiles
```

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

- `-v`
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

Make links. Can create a symbolic link.

### Options

- `-s /path/to/file /path/to/symlink`
  - Creates a symbolic link.

## Deleting files/directories

### `rm`

Delete a file.

#### Options

- `-r`
  - Deletes files recursively in a directory.
- `-f`
  - Deletes without confirmation.

### `rmdir`

`rm` but for directories. Deletes directory provided it is empty.

## File Transportation

### `cp`

Copy file. `cp /Desktop/1/a /Desktop/2/a`

#### Options

- `-R`
  - Copies the entire directory. 

### `mv`

Move file. `mv hello.c Desktop/hello.c`
Tip: Useful for renaming as well. `mv hello.c bye.c`

## `less` and `more`

Pager commands. Can show long files to screen.

> “`less` is more, but more `more` than `more` is, so `more` is less `less`, so use more `less` if you want less `more`.” —Slackware Linux Essentials

### `less`

> "Opposite of more" - man less

### `more`

> "Opposite of less" - man more

Use `less` instead of more. 