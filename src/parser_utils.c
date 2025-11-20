#include "parser_utils.h"

const int hex_lkt[256] = { // hexadecimal LookUp Table
    ['0'] = 1, ['1'] = 1, ['2'] = 1, ['3'] = 1, ['4'] = 1, ['5'] = 1, ['6'] = 1, ['7'] = 1, ['8'] = 1, ['9'] = 1, ['a'] = 1,
    ['b'] = 1, ['c'] = 1, ['d'] = 1, ['e'] = 1, ['f'] = 1, ['A'] = 1, ['B'] = 1, ['C'] = 1, ['D'] = 1, ['E'] = 1, ['F'] = 1
};
const int wtspce[256] = {[0x20] = 1, [0x0A] = 1, [0x09] = 1};

void parser_init(ParserContext* ctx, FILE* file){
    ctx->file = file;
    ctx->char_number = 0;
    ctx->bytes_read = fread(ctx->char_buffer, 1, BUFFER_MAX_SIZE, ctx->file);
    if (ctx->bytes_read > 0){
        ctx->current_char = ctx->char_buffer[0];
        ctx->next_char = (ctx->bytes_read > 1) ? ctx->char_buffer[1] : EOF;
    } else {
        ctx->current_char = EOF;
        ctx->next_char = EOF;
    }
}

char peek_char(ParserContext* ctx){
    if ((ctx->char_number + 1 >= ctx->bytes_read) || (ctx->current_char == EOF)){
        return EOF;
    }
    return ctx->char_buffer[ctx->char_number + 1];
}

char parser_advance(ParserContext* ctx){
    char temp = ctx->current_char;
    if (ctx->char_number < ctx->bytes_read){
        ctx->char_number++;
        if (ctx->char_number < ctx->bytes_read){
            ctx->current_char = ctx->char_buffer[ctx->char_number];
        }else {
            ctx->current_char = EOF;
        }
        ctx->next_char = peek_char(ctx);
    }
    return temp;
}

int is_hex_digit(char c){
    return hex_lkt[(unsigned char)c];
}

int is_wtf_whitespace(char c){
    return wtspce[(unsigned char)c];
}
