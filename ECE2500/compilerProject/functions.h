//header file for functions
#include <fstream>
#include <iostream>
#include <iomanip>
#include <memory>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h> 

#include "exceptions.h"
#include "lexer.h"
#include "util.h"


//name: bits_to_machine
//purpose: take in a 32 bit binary int and convert it to hex machine code. Returns hex as string.
//holding off on this



//name: name_to_num
//purpose: take a name and convert it to corresponding opcode number. Returns int
int name_to_num(std::string name);


//name: name_to_func_num
//purpose: to take a name and return its function, if there is one (R TYPE), returns int
int name_to_func_num(std::string name);


//name: target_to_num
//purpose: take a target and convert it to a corresponding number. Returns int
int target_to_num(std::string target);


//name: four_to_machine
//purpose: take in 4 ints (opcode, target, target, target), create hex machine code.
int four_to_machine(int op, int rs, int rt, int rd, int shamt, int func);



//name: determine_type
//purpose: to determine a functions type. Returns 0 for R, 1 for I and 2 for unknown. Return type is int.
// Takes in function name as input
int determine_type(std::string name);


//name r_type_args
//purpose to take args for R type and generate corresponding hex output
int r_type_args(std::string arg);




//name is_hex_notation
//purpose to determine if a string contains hex of not
bool is_hex_notation(std::string const& s);



//name extractor_r
//purpose to extract the fields of r type instructions and return an int of the completed hex code
int extractor_r(std::string name, std::vector<lexer::token> tokens);



//name: extractor_i
//purpose: take in an I type label and run the necessary stuffs on it
int extractor_i(std::string name, std::vector<lexer::token> tokens);



//name: i_type_machine
//purpose: takes in all int i type parameters and assembles them to the correct hex format
int i_type_machine(int op, int rs, int rt, int imm);



//name branch_assembler
//purpose: to assemble branch instructions
int branch_assembler(std::vector<std::string> label_vec, std::string name, std::vector<lexer::token> tokens, std::vector<int> line, int curr_line);




