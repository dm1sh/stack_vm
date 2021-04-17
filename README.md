# stack_vm

Stack based virtual machine and assembly code compiler

## Features

- Assembly language compilation
- Binary code execution
- Assembly
  - Stack operations (push & pop)
  - Arithmetics operations
  - I/O operations

## Assembly documentation

### Example programm:

Put it into input.s

```asm
PUSH 65
OUTC
PUSH 1
ADD
OUTC
PUSH 1
ADD
OUTC
```

Run

```bash
make
./build/stack_vm build input.s
./build/stack_vm run out.bin
```

It must print first three English characters

### Commands:

- **NONE**
  Doesn't do anything
- **PUSH**
  Pushes value to stack
- **POP**
  Removes from stack top
- **ADD**
  Removes two top values in stack and pushes their sum
- **SUB**
  Removes two top values in stack and pushes substraction of them
- **MUL**
  Removes two top values in stack and pushes multiplication of them
- **DIV**
  Removes two top values in stack and pushes integer part of division
- **MOD**
  Removes two top values in stack and pushes modulo
- **IN**
  Inputs string with C I/O operators
- **OUTS**
  Outputs string with C I/O operators
- **OUTC**
  Outputs one stack element as char with I/O operators

## TODO

- Variables
- Arithmetics operators
- Strings
- I/O operators
- Loops
- Arrays
