#pragma once
enum Token 
{
    tok_eof = -1,

    tok_module = -2,
    
    tok_always = -3,
    tok_posedge = -4,
    tok_begin = -5,
    tok_end = -6,

    tok_input = -7,
    tok_output = -8,
    tok_wire = -9,
    tok_reg = -10,

    tok_identifier = -11,
    tok_number = -12
};