# What Compiler

A compiler for the **What** programming language - an esoteric language designed to be the backbone of VanadiumOS.

## About the Project

This compiler is currently in the **planning phase** and is being developed alongside the VanadiumOS project. The What programming language is designed with a minimalistic syntax and direct memory manipulation capabilities.

## Language Syntax

What uses a character-based syntax for operations and memory management. The compiler ignores spaces and newlines.

| Character | Meaning | Description |
|-----------|---------|-------------|
| `@` | Function Selector | Selects a function to be executed (e.g., `@x01` for NAND). |
| `/` | Parameter | A parameter with no address provider. |
| `$` | Addressed Parameter | A parameter with a specified address or register. |
| `_` | Auto-allocate | Used with `$` to auto-allocate memory or choose a register. |
| `x` | Hexadecimal Value | Indicates the following value is in hexadecimal format (e.g., `x0A`). |
| `\` | Comment | The rest of the line after `\` is ignored. |
| `:` | Section/Label | A raw text string followed by a colon defines a section or label. |

### Example Syntax
`@x05/x01$(_)x0A \ This is a comment`

## Function look-up table
| Value  | Function | Parameters | Description |
|--------|----------|------------|-------------|
| `@x01` | NAND     | `dest_reg`, `src_a`, `src_b` | Performs a NAND operation. `src_a` and `src_b` can be immediate values. |
| `@x02` | COMP     | `reg_a`, `reg_b` | Compares two values. |
| `@x03` | MOVE/SHIFT | `reg_a`, `direction`, `quantity` | Shifts the bits in a register. `reg_a` can be immediate. `direction` is `x00` for right, `x01` for left. |
| `@x04` | JMP      | `condition`, `target_address` | Jumps to a target address based on a condition. `target_address` can be a section label. |
| `@x05` | WRITE    | `file_descriptor`, `memory_pointer` | Writes from a memory location to a file descriptor (e.g., stdout). `memory_pointer` must be an addressed parameter. |
| `@x06` | READ     | `file_descriptor`, `memory_pointer`/`register` | Reads from a file descriptor into memory or a register. |
| `@x07` | ASSIGN   | `memory_pointer`, `value` | Assigns an immediate value to a register or memory location. If `value` is empty, allocates space in the `.bss` section. |
| `@x08` | EXIT     | `exit_code` | Terminates the program with a given exit code. |

## Project Status

⚠️ **Planning Phase** - This compiler is currently in early development and requires:
- File system integration
- Executable architecture specification
- Parser implementation
- Code generation components

## Related Projects

- [VanadiumOS](https://github.com/Julioccps/vanadium-os) - The operating system that will utilize the What programming language

## Development

This compiler is being designed to compile What language source code into Assembly code in the moment, but is planned to be compatible with the VanadiumOS architecture, once it's well defined and implemented.