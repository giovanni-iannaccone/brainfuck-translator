# 🧠 Brainfuck to C++ Converter

This program is a Brainfuck to C++ converter. It takes Brainfuck source code as input and generates equivalent C++ code, preserving the logic and functionality of the original program. This tool is useful for understanding how Brainfuck programs work or for integrating Brainfuck logic into larger C++ projects.

## ❓ What is Brainfuck?

Brainfuck is a minimalist programming language designed to challenge and amuse programmers. It uses only eight commands and operates on an array of memory cells, each initially set to zero. The language is Turing complete, meaning it can theoretically compute anything that other programming languages can, given enough memory and time.

Brainfuck Commands

| Command                      | Description                                                            |
|------------------------------|------------------------------------------------------------------------|
| `>`                          | Move the memory pointer to the right.                                  |
| `<`                          | Move the memory pointer to the left.                                   |
| `+`                          | Increment the value at the memory cell under the pointer.              |
| `-`                          | Decrement the value at the memory cell under the pointer.              |
| `[`                          | Jump forward to the instruction after `]` if the current cell is zero. |
| `]`                          | Jump back to the matching `[` if the current cell is non-zero.         |
| `.`                          | Output the character at the memory cell under the pointer.             |
| `,`                          | Input a character and store it in the memory cell under the pointer.   |


## 🛠️ How the Converter Works

1. **Input Parsing**:  The program reads a Brainfuck source file and validates its syntax.
2. **Translation**:    Each Brainfuck command is translated into its equivalent C++ logic.
3. **Output**:         A C++ file is generated containing the translated code. The output can be compiled with any standard C++ compiler.

#### Example

Brainfuck Code
```
++++[>++++<-]>.
```

Generated C++ Code
```cpp
#include <iostream>
int main() {
char a[30000];
char *ptr = a;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
while(*ptr) {
ptr++;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
ptr--;
--*ptr;
}
ptr++;
putchar(*ptr);
return 0; 
} 

```

## 🚀 How to Use

1. **Compile the Converter**: ensure you have a C++ compiler installed. Compile the converter program.
2. **Run the Converter**: provide a Brainfuck source file as input.
```
./brainfuck input.bf output.cpp
```

3. **Compile the Output**: compile the generated C++ file.
```
g++ output.cpp -o output
```

4. **Run the Result**: execute the compiled program.
```
./output
```

## 📋 Requirements
- A C++ compiler (e.g., GCC, Clang, or MSVC).
- Basic understanding of Brainfuck and C++ (optional but helpful).