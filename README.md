# What Compiler

A compiler for the **What** programming language - an esoteric language designed to be the backbone of VanadiumOS.

## About the Project

This compiler is currently in the **planning phase** and is being developed alongside the VanadiumOS project. The What programming language is designed with a minimalistic syntax and direct memory manipulation capabilities.

## Language Syntax

What uses a character-based syntax for operations and memory management:

| Character | Meaning |
|-----------|---------|
| `@<value>` | Function selector where `value` represents a basic function |
| `/<value>` | Specific parameter for any function |
| `$(address)<value>` | Parameter provider with memory address (use `_` for auto-allocation) |
| `x<value>` | Hexadecimal value indicator |

### Example Syntax
`@x01/x01$(_)x0A`

The compiler ignores spaces and newlines unless explicitly specified with `x` prefix.

## Project Status

⚠️ **Planning Phase** - This compiler is currently in early development and requires:
- File system integration
- Executable architecture specification
- Parser implementation
- Code generation components

## Related Projects

- [VanadiumOS](https://github.com/Julioccps/vanadium-os) - The operating system that will utilize the What programming language

## Development

This compiler is being designed to compile What language source code into Assembly code in the moment, but is planned to be compatible with the VanadiumOS architecture, once it's well defined and implemented

