# What Compiler

A compiler for the **What** programming language - an esoteric language designed to be the backbone of VanadiumOS.

## About the Project

This compiler is currently in the **planning phase** and is being developed alongside the VanadiumOS project. The What programming language is designed with a minimalistic syntax and direct memory manipulation capabilities.

## Language Syntax

The official file extension for the language is `.wtf` (**W**ha**T** **F**ile).

What uses a character-based syntax. The syntax is mostly free-form, as the compiler generally ignores spaces and newlines.

The `x` (or `X`) character serves a dual purpose:
1.  **Hexadecimal Prefix:** When followed by hex digits (e.g., `x0A`), it denotes a raw hexadecimal value.
2.  **Whitespace Signifier:** When followed by a whitespace character (like a space, tab, or a literal newline), it makes that single whitespace character significant to the parser. This provides a more direct way to handle characters like newlines (which are stored as 0x0A) than writing them out as a two-character hex code.

| Character | Meaning | Description |
|-----------|---------|-------------|
| @ | Function Selector | Selects a function to be executed (e.g., @x01 for NAND). In ARM, this corresponds to `SVC #imm` for syscalls. |
| `/` | Parameter | A parameter with no address provider. |
| ^ | Call section | The equivalent of a `BL label` instruction in ARM Assembly |
| `$` | Addressed Parameter | A parameter with a specified address or register. |
| `_` | Auto-allocate | Used with `$` to auto-allocate memory or choose a register. |
| . | return | Not the equivalent of `return` on other programming languages,
    but the `BX LR` in ARM Assembly |
| `x` | Hexadecimal Value | Indicates the following value is in hexadecimal format (e.g., `x0A`). |
| `\` | Comment | The rest of the line after `\` is ignored. |
| `:` | Section/Label | A raw text string followed by a colon defines a section or label. |

For address operations indicated by parentheses `()`, values between `x00` and `x0F` inclusive represent registers `r0-r15`. Any other value within an address operation refers to a memory address. If a specific value is set, it resides in the `.data` section; if it's `x00`, it's located in the `.bss` section. Each addressable unit is 32 bits (4 bytes) long, allowing for 32-bit values. The address space supported is `x00` to `xFF` (`0-255`), as 'if the developer needs more than 256 variables in an esoteric project they are probably doing something wrong'.

### Example Syntax
```wtf
\ "Hello, World!" program
@x07/x10/x48656C6C
@x07/x11/x6F2C x x57
@x07/x12/x6F726C64
@x07/X13/X21 x
x00
@x05/x01$(x10)
@x08/x00
```

## Function look-up table
| Value  | Function | Parameters | Description |
|--------|----------|------------|-------------|
| `@x01` | NAND     | `dest_reg`, `src_a`, `src_b` | Performs a NAND operation. `src_a` and `src_b` can be immediate values. |
| `@x02` | COMP     | `reg_a`, `reg_b` | Compares two values. |
| `@x03` | MOVE/SHIFT | `reg_a`, `direction`, `quantity` | Shifts the bits in a register. `reg_a` can be immediate. `direction` is `x00` for right, `x01` for left. |
| `@x04` | JMP      | `condition`, `target_address` | Jumps to a target address based on a condition. `target_address` can be a section label. |
| `@x05` | WRITE    | `file_descriptor`, `memory_pointer` | Writes from a memory location to a file descriptor (e.g., stdout). `memory_pointer` must be an addressed parameter. Stops writing when a null character (`x00`) is encountered. |
| `@x06` | READ     | `file_descriptor`, `memory_pointer`/`register` | Reads from a file descriptor into memory or a register. |
| `@x07` | ASSIGN   | `memory_pointer`, `value` | Assigns an immediate value to a register or memory location. If `value` is empty, allocates space in the `.bss` section. |
| `@x08` | EXIT     | `exit_code` | Terminates the program with a given exit code. |

## JMP Conditions
| Value | Condition  | Description           |
|-------|------------|-----------------------|
| x00   | ALWAYS     | Unconditional jump    |
| x01   | EQ         | Jump if equal         |
| x02   | NE         | Jump if not equal     |
| x03   | LT         | Jump if less than     |
| x04   | GT         | Jump if greater than  |

## Standard File Descriptors
| Value | Descriptor |
|-------|------------|
| x00   | stdin      |
| x01   | stdout     |
| x02   | stderr     |

## Project Status

⚠️ **Planning Phase** - This compiler is currently in early development and requires:
- Parser implementation
- Code generation components

## Related Projects

- [VanadiumOS](https://github.com/Julioccps/vanadium-os) - The operating system that will utilize the What programming language

## Development

This compiler is being designed to compile What language source code into ARM Assembly, as VanadiumOS will transition a RTOS(Real Time Operating system) in ARM architecture.
