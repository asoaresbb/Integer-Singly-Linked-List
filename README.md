# cpp-singly-linked-list

A singly linked list of integers in C++, built by hand with nodes and pointers, and driven by text commands read from the standard input. The output is in English.

Each node (`Inode`) holds a value and a pointer to the next node. The list (`Isll`) keeps a pointer to the first node and the number of nodes, and frees every node when it's destroyed.

## Commands

One command per line. Positions start at 0.

| Command | What it does | Example |
| --- | --- | --- |
| `insert_0 <values...>` | Inserts each value at the start, in order | `insert_0 12 7` gives `7 12` |
| `insert_end <values...>` | Inserts each value at the end, in order | `insert_end 5 6` |
| `insert_pos <pos> <value>` | Inserts a value at a position, from 0 to the list size; other positions are ignored | `insert_pos 1 10` |
| `remove <value>` | Removes the first node with that value | `remove 10` |
| `alter <pos> <value>` | Changes the value at a position | `alter 0 3` |
| `find <value>` | Says whether the value is in the list | `find 42` |
| `print` | Prints the values from start to end | `print` |
| `clear` | Removes every node | `clear` |

Empty lines are skipped, unknown commands are reported, and the program ends at the end of the input.

## Running

Requires a C++ compiler such as `g++` or `clang++`.

```sh
g++ -Wall -Wextra main-isll.cpp isll.cpp -o main-isll
./main-isll                         # type commands; Ctrl+D to finish
./main-isll < input.txt             # run the commands in a file
```

`input.txt` uses every command, and `output.txt` holds the expected output:

```sh
./test.sh    # builds the program, runs input.txt and compares the result with output.txt
```

## Structure

| File | What it does |
| --- | --- |
| `isll.h` | The node and list types |
| `isll.cpp` | The list operations |
| `main-isll.cpp` | Reads the commands and calls the list |
| `input.txt`, `output.txt` | Example commands and their expected output |
| `test.sh` | Builds, runs and compares |

## Context

Course project for Data Structures and Algorithms (Estruturas de Dados e Algoritmos Fundamentais), Universidade Aberta, April 2025.
