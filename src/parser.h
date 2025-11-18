#ifndef PARSER_H
#define PARSER_H

#include <stdint.h>

// --- Original Structs (mostly unchanged) ---

typedef enum {
    PARAM_TYPE_NO_ADDRESS, // Parameter like /x0A
    PARAM_TYPE_W_ADDRESS,  // Parameter like $label or $(_)
} ParameterType;

typedef struct {
    ParameterType type;
    uint8_t value;
    char* address;  // For PARAM_TYPE_W_ADDRESS, can be a label name or "_"
} Parameter;

typedef struct {
    uint8_t function_id;
    Parameter* params;
    int num_params;
} Instruction;

// --- New Generic Statement Structure ---

// Represents a label definition in the code, e.g., "my_label:"
typedef struct {
    char* name;
} LabelDefinition;

// Enum to define what kind of statement we have
typedef enum {
    STATEMENT_INSTRUCTION,
    STATEMENT_LABEL_DEFINITION,
} StatementType;

// A Statement can be either an Instruction or a Label definition.
// This uses a tagged union, a common C pattern for ASTs.
typedef struct StatementNode {
    StatementType type;
    union {
        Instruction instruction;
        LabelDefinition label;
    } as;
    int line; // Keep track of line number for errors
    struct StatementNode* next; // Pointer to the next statement in the list
} StatementNode;

// The entire program is now represented as a linked list of statements.
// The "Program" is simply a pointer to the head of this list.
typedef StatementNode* Program;


#endif // PARSER_H