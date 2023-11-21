#include <string>
#include <iostream>

#include "tokens.hpp"

static std::string IdentifierStr;
static double NumVal;

static int gettok()
{
    static int LastChar = ' ';

    //Skip any whitespaces
    while(isspace(LastChar))
    {
        LastChar = getchar();
    }

    if(isalpha(LastChar))
    {
        IdentifierStr = LastChar;
        while (isalnum(LastChar = getchar()))
        {
            IdentifierStr += LastChar;
        }

        if(IdentifierStr == "module") return tok_module;
        if(IdentifierStr == "always") return tok_always;
        if(IdentifierStr == "posedge") return tok_posedge;
        if(IdentifierStr == "begin") return tok_begin;
        if(IdentifierStr == "end") return tok_end;
        if(IdentifierStr == "input") return tok_input;
        if(IdentifierStr == "output") return tok_output;
        if(IdentifierStr == "wire") return tok_wire;
        if(IdentifierStr == "reg") return tok_reg;
        
        return tok_identifier;
    }

    if(isdigit(LastChar) || LastChar == '.')
    {
        std::string NumStr;
        do
        {
            NumStr += LastChar;
            LastChar = getchar();
        }while(isdigit(LastChar) || LastChar == '.');

        NumVal = strtod(NumStr.c_str(), 0);
        return tok_number;
    }

    if(LastChar == '#')
    {
        do
        {
            LastChar = getchar();
        } while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');
        
        if(LastChar != EOF)
            return gettok();
    }

    if(LastChar == EOF)
        return tok_eof;

    int ThisChar = LastChar;
    LastChar = getchar();
    return ThisChar;
}

int main(int argc, char** argv)
{
    std::cout << gettok() << std::endl;
    return 0;
}