#ifndef PARSER_H
#define PARSER_H

#include <stdint.h>
#include "parser_utils.h"

typedef enum {
    TOKEN_EOF,
    TOKEN_FUNCTION_ID,
    TOKEN_PARAM_N_ADDR,
    TOKEN_PARAM_W_ADDR,
    TOKEN_AUTO_ALLOC,
    TOKEN_HEX_VALUE,
    TOKEN_LABEL_DEF,
    TOKEN_LABEL_REF,
    TOKEN_UNKNOWN,
    TOKEN_ERROR
} TokenType;

typedef struct {
    TokenType type;
    char text[64]; // Static short buffer
    int line; // For Error handling
    int value; // could be uint8_t | Think of that later, not now
} Token;

typedef enum {
    PARAM_TYPE_NO_ADDRESS, // Parameter like /x0A
    PARAM_TYPE_W_ADDRESS,  // Parameter like $(_)x4F
} ParameterType;

typedef struct {
    ParameterType type;
    uint8_t value;
    const char* address_label;  // For PARAM_TYPE_W_ADDRESS, can be a label name or "_"
} Parameter;

typedef struct {
    uint8_t function_id;
    Parameter* params;
    int num_params;
} Instruction;


// Represents a label definition in the code, e.g., "my_label:"
typedef struct {
    char* name;
}LabelDefinition;

// Enum to define what kind of statement we have
typedef enum {
    STATEMENT_INSTRUCTION,
    STATEMENT_LABEL_DEFINITION,
} StatementType;

// A Statement can be either an Instruction or a Label definition.
typedef struct StatementNode {
    StatementType type;
    union {
        Instruction instruction;
        LabelDefinition label;
    } as;
    int line; // Keep track of line number for errors
} Statement;

typedef struct{
    Statement* statements;
    size_t count;
    size_t capacity;
} Program;

Program parse_file(const char* filename, ParserContext* ctx);
void free_program(Program* program);

int read_next_token(ParserContext* ctx, Token* out_token);
uint8_t parse_hex_value(const char* str);

StatementNode* parse_instruction(ParserContext* ctx, Token* current_token);
Parameter parse_parameter(ParserContext* ctx);

int validate_instruction(Instruction* instr);
int is_valid_function_id(uint8_t id);
int is_valid_jump_condition(uint8_t cond);

void parser_error(int line, const char* message);
void syntax_warning(int line, const char* message);

#endif // PARSER_H
