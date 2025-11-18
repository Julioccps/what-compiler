#ifndef PARSER_H
#define PARSER_H

#include <stdint.h>

// Enum to define the type of a parameter
typedef enum {
    PARAM_TYPE_NO_ADDRESS,
    PARAM_TYPE_W_ADDRESS,
} ParameterType;

// Represents a parameter for a function
typedef struct {
    ParameterType type;
    uint8_t value;
    char* address;  // For PARAM_TYPE_W_ADDRESS, address can be "_" for auto-allocation
} Parameter;

// Represents a single instruction (a function call with its parameters)
typedef struct {
    uint8_t function_id;
    Parameter* params;
    int num_params;
} Instruction;

// Represents the entire program as a series of instructions
typedef struct {
    Instruction* instructions;
    int num_instructions;
} Program;

#endif
