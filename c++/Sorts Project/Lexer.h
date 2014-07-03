/*
 * *****************************************************************************
 * file name : Lexer.h
 * author    : Hung Q. Ngo
 * description: a simple lexical analyzer
 * *****************************************************************************
 */

#ifndef _LEXER_H
#define _LEXER_H

#include <string>
#include <vector>

enum token_types_t { 
    IDENT,  // a sequence of alphanumeric characters and _, starting with alpha
    STRING, // sequence of characters between " ", no escape
    DELIM,  // {}[]
    OPERATOR, // +-/*=
    COMMENT,  // # follows by any characters to the end of line/file
    INTEGER,  // a series of digits
    ENDTOK, // end of string/file, no more token
    ERRTOK,  // unrecognized token
    DROPIT //turns strings inside of () into empty spaces to be cleared
};

struct Token {
    token_types_t type;
    std::string value;
    // constructor for Token
    Token(token_types_t tt=ENDTOK, std::string val="") : type(tt), value(val) {}
};

/**
 * -----------------------------------------------------------------------------
 * the Lexer class:
 * - take a string to be scanned
 * - scan for tokens and return one at a time
 * -----------------------------------------------------------------------------
 */
class Lexer {
    public:
    // constructor
    Lexer(std::string str="") : input_str(str), cur_pos(0), separators(" \t\n") { }

    // a couple of modifiers
    void set_input(std::string); // set a new input, 
    void restart();              // move cursor to the beginning, restart

    Token next_token();           // returns the next token
    std::vector<Token> tokenize(); // returns the rest of the tokens
    bool has_more_token();        // are there more token(s)?

    private:
    std::string input_str;  // the input string to be scanned
    size_t      cur_pos;    // current position in the input string
    std::string separators; // set of separators; *not* the best option!
};

#endif
