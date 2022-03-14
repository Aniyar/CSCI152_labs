
#ifndef INPUT_ 
#define INPUT_  

#include <iostream>
#include "filereader.h" 

// This is the tokenizer for lab exercise 5. 
// You are very welcome to study this code, but you don't have to.
// Actually, the code is mostly unreadable because it is automatically
// generated.

enum inputtype { 
       inp_plus, inp_minus, inp_times, inp_div, inp_mod, inp_pow, 
       inp_sin, inp_cos, inp_tan, inp_exp, inp_log, 
       inp_sqrt, inp_abs, 
       inp_e, inp_pi,
       inp_num, inp_ident, inp_garbage, inp_comment, inp_whitespace, 
       inp_end };

const char* cstring( inputtype inp );
   // Return a C-string representing inp, so that it can be printed.

inline std::ostream& operator << ( std::ostream& out, inputtype inp )
   { return out << cstring( inp ); } 

std::pair< inputtype, size_t > read( filereader& inp ); 


#endif

