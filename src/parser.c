#include "parser.h"

Program parse_file(const char* filename, ParserContext* ctx){
    Program prog = {0};
    FILE* file = fopen(filename, "rb");
    if (file){
        parser_init(ctx, file);
        // TODO
    }else {
        printf("Error: Not able to open following file: %s", filename);
    }    
        return prog;
    
}

void free_program(Program* program){
    // TODO
}

int read_next_token(ParserContext* ctx, Token* out_token){
    // TODO
}

uint8_t parse_hex_value(const char* str){
    // TODO
}

Statement* parse_instruction(ParserContext* ctx, Token* current_token){
    // TODO
}


Parameter parse_parameter(ParserContext* ctx){
    // TODO
}

int validate_instruction(Instruction* instr){
    // TODO
}

int is_valid_function_id(uint8_t id){
    // TODO
}

int is_valid_jump_condition(uint8_t cond){
    // TODO
}

void parser_error(int line, const char* message){
    // TODO
}

void syntax_warning(int line, const char* message){
    // TODO
}
