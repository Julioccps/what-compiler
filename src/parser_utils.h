#ifndef PARSER_UTILS_H
#define PARSER_UTILS_H

#include <stdio.h>
#include <stdint.h>

#define SECTOR_SIZE 512
#define BUFFER_MAX_SIZE (SECTOR_SIZE * 8) // TODO: Implement Buffer Refill, for files larger than 4KB

typedef struct{
    FILE* file;
    char char_buffer[BUFFER_MAX_SIZE];
    char current_char;
    char next_char;
    int char_number;
    int bytes_read;
} ParserContext;

void parser_init(ParserContext* ctx, FILE* file);
char peek_char(ParserContext* ctx);
char parser_advance(ParserContext* ctx); // Advances and returns the previous char

int is_hex_digit(char c);
int is_wtf_whitespace(char c);

#endif

