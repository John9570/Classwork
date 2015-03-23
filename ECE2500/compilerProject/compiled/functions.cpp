#include "functions.h"

using namespace std;
//name: name_to_num
//purpose: take a name and convert it to corresponding opcode number. Returns int
int name_to_num(std::string name){

	if(name == "add" || name == "addu" || name == "and" || name == "sub"){
		return 0;
	}
	else if(name == "jr" || name == "nor" || name == "or" || name == "slt"){
		return 0;
	}
	else if(name == "sltu" || name == "sll" || name == "srl" || name == "subu"){
		return 0;
	}
	else if(name == "addi"){
		return 8;
	}
	else if(name == "addiu"){
		return 9;
	}
	else if(name == "andi"){
		return 12;
	}
	else if(name == "beq"){
		return 4;
	} 
	else if(name == "bne"){
		return 5;
	}
	else if(name == "lbu"){
		return 36;
	}
	else if(name == "lhu"){
		return 37;
	}
	else if(name == "ll"){
		return 48;
	}
	else if(name == "lui"){
		return 15;
	}
	else if(name == "lw"){
		return 35;
	}
	else if(name == "ori"){
		return 13;
	}
	else if(name == "slti"){
		return 10;
	}
	else if(name == "sltiu"){
		return 11;
	}
	else if(name == "sb"){
		return 40;
	}
	else if(name == "sc"){
		return 56;
	}
	else if(name == "sh"){
		return 41;
	}
	else if(name == "sw"){
		return 43;
	}

	else{
		return 63; //safe number
	}

}


//name: name_to_func_num
//purpose: to take a name and return its function, if there is one (R TYPE), returns int
int name_to_func_num(std::string name){

	if(name == "add"){
		return 32;
	}
	else if(name == "addu"){
		return 33;
	}	
	else if(name == "and"){
		return 36;
	}
	else if(name == "jr"){
		return 8;
	}
	else if(name == "nor"){
		return 39;
	}
	else if(name == "or"){
		return 37;
	}
	else if(name == "slt"){
		return 42;
	}
	else if(name == "sltu"){
		return 43;
	}
	else if(name == "sll"){
		return 0;
	}
	else if(name == "srl"){
		return 2;
	}
	else if(name == "sub"){
		return 34;
	}
	else if(name == "subu"){
		return 35;
	}
	else{
		return 63; //safe number
	}
}




//name: target_to_num
//purpose: take a target and convert it to a corresponding number. Returns int
int target_to_num(std::string target);


//name: R_to_machine
//purpose: take in 6 ints (opcode, rs, rt, rd, shamt, func), create hex machine code.
int four_to_machine(int op, int rs, int rt, int rd, int shamt, int func){

	 //Long int is at least 32 bits, most likely 64 though. 
	long unsigned int op_temp = 0;
	unsigned long int rs_temp = 0;
	unsigned long int rt_temp = 0;
	unsigned long int rd_temp = 0;
	unsigned long int shamt_temp = 0;
        unsigned long int out = 0; //holds final output 

	op_temp = op << 26;

	op_temp = op_temp & 4294967295;

	rs_temp = rs << 21;
	rt_temp = rt << 16;
	rd_temp = rd << 11;
	shamt_temp = shamt << 6;

	out = op_temp | rs_temp;
	//cout << "out is: " << std::hex << op_temp << endl;
	out |= rt_temp;
	out |= rd_temp;
	out |= shamt_temp;
	out |= func; 



	//cout << "out is: "; 
	//cout << std::setw(8) << std::hex << std::setfill('0') << out << endl;

	return out; 

}


//name: determine_type
//purpose: to determine a functions type. Returns 0 for R, 1 for I and 2 for branch, 3 for unknown. Return type is int.
// Takes in function name as input
int determine_type(std::string name){

	//R types
	if(name == "add" || name == "addu" || name == "and" || name == "jr" ){
		return 0;
	}
	else if(name == "nor" || name == "or" || name == "slt" || name == "sltu"){
		return 0;
	}
	else if(name == "sll" || name == "srl" || name == "sub" || name == "subu"){
		return 0;
	}
	
	// I types
	else if(name == "addi" || name == "addiu" || name == "andi"){
		return 1;
	}
	else if(name == "lbu" || name == "lhu" || name == "ll"){
		return 1;
	}
	else if(name == "lui" || name == "lw" || name == "ori" || name == "slti"){
		return 1;
	}
	else if(name == "sltiu" || name == "sb" || name == "sc" || name == "sh" || name == "sw"){
		return 1;
	}
	
	//branches
	else if(name == "beq" || name == "bne"){
		return 2;
	}


	// Unknown ?? 
	else{
		return 3;
	}

}


//name r_type_args
//purpose to take args for R type and generate corresponding hex output
int r_type_args(std::string arg){

	if(arg[0] == '('){
		arg = arg.substr(1,3);
	}


	if(arg == "$zero"){
		return 0;
	}
	else if(arg == "$at"){
		return 1;
	}
	else if(arg == "$v0"){
		return 2;
	}
	else if(arg == "$v1"){
		return 3;
	}
	else if(arg == "$a0"){
		return 4;
	}
	else if(arg == "$a1"){
		return 5;
	}
	else if(arg == "$a2"){
		return 6;
	}
	else if(arg == "$a3"){
		return 7;
	}
	else if(arg == "$t0"){
		return 8;
	}
	else if(arg == "$t1"){
		return 9;
	}
	else if(arg == "$t2"){
		return 10;
	}
	else if(arg == "$t3"){
		return 11;
	}
	else if(arg == "$t4"){
		return 12;
	}
	else if(arg == "$t5"){
		return 13;
	}
	else if(arg == "$t6"){
		return 14;
	}
	else if(arg == "$t7"){
		return 15;
	}
	else if(arg == "$s0"){
		return 16;
	}
	else if(arg == "$s1"){
		return 17;
	}
	else if(arg == "$s2"){
		return 18;
	}
	else if(arg == "$s3"){
		return 19;
	}
	else if(arg == "$s4"){
		return 20;
	}
	else if(arg == "$s5"){
		return 21;
	}
	else if(arg == "$s6"){
		return 22;
	}
	else if(arg == "$s7"){
		return 23;
	}
	else if(arg == "$t8"){
		return 24;
	}
	else if(arg == "$t9"){
		return 25;
	}
	else if(arg == "$k0"){
		return 26;
	}
	else if(arg == "$k1"){
		return 27;
	}
	else if(arg == "$gp"){
		return 28;
	}
	else if(arg == "$sp"){
		return 29;
	}
	else if(arg == "$fp"){
		return 30;
	}
	else if(arg == "$ra"){
		return 31;
	}
        
	//if we get to here, we are dealing with a number

	if( is_hex_notation(arg) ) {
		// we have a hex number 
	 	int temp;   
		arg.insert(0, 1, 'x');
		arg.insert(0, 1, '0');

		temp = strtoul(arg.c_str(), NULL, 16);
                 
		return temp;
	}
	else{
		//regular base 10 number
		unsigned int temp;   
		std::stringstream ss;
		ss << arg;
		ss >> temp;
		return temp;
	}	
       
}


//name is_hex_notation
//purpose to determine if a string contains hex of not
bool is_hex_notation(std::string const& s){
  return s.find_first_not_of("0123456789abcdefABCDEF", 2) == std::string::npos;
}


//name extractor_r
//purpose to extract the fields of r type instructions and return an int of the completed hex code
int extractor_r(string name, std::vector<lexer::token> tokens){

	int op, rs, rt, rd, shamt, func; //declare some stuff



	//do some shit
        if(name == "add"){
		op = name_to_num(name);
                rd = r_type_args( tokens[0].string() );
                rs = r_type_args( tokens[1].string() );
                rt = r_type_args( tokens[2].string() );
		shamt = 0;
		func = name_to_func_num( name ); 
	}	

        else if(name == "addu"){
		op = name_to_num(name);
                rd = r_type_args( tokens[0].string() );
                rs = r_type_args( tokens[1].string() );
                rt = r_type_args( tokens[2].string() );
		shamt = 0;
		func = name_to_func_num( name ); 
	}	
        
	else if(name == "and"){
		op = name_to_num(name);
                rd = r_type_args( tokens[0].string() );
                rs = r_type_args( tokens[1].string() );
                rt = r_type_args( tokens[2].string() );
		shamt = 0;
		func = name_to_func_num( name ); 
	}	

        else if(name == "jr"){
		op = name_to_num(name);
                rd = 0;
                rs = r_type_args( tokens[0].string() );
                rt = 0;
		shamt = 0;
		func = name_to_func_num( name ); 
	}	
        
	else if(name == "nor"){
		op = name_to_num(name);
                rd = r_type_args( tokens[0].string() );
                rs = r_type_args( tokens[1].string() );
                rt = r_type_args( tokens[2].string() );
		shamt = 0;
		func = name_to_func_num( name ); 
	}	

        else if(name == "or"){
		op = name_to_num(name);
                rd = r_type_args( tokens[0].string() );
                rs = r_type_args( tokens[1].string() );
                rt = r_type_args( tokens[2].string() );
		shamt = 0;
		func = name_to_func_num( name ); 
	}	
	
        else if(name == "slt"){
		op = name_to_num(name);
                rd = r_type_args( tokens[0].string() );
                rs = r_type_args( tokens[1].string() );
                rt = r_type_args( tokens[2].string() );
		shamt = 0;
		func = name_to_func_num( name ); 
	}	

        else if(name == "sltu"){
		op = name_to_num(name);
                rd = r_type_args( tokens[0].string() );
                rs = r_type_args( tokens[1].string() );
                rt = r_type_args( tokens[2].string() );
		shamt = 0;
		func = name_to_func_num( name ); 
	}	

        else if(name == "sll"){
		op = name_to_num(name);
                rd = r_type_args( tokens[0].string() );
                rs = 0;
                rt = r_type_args( tokens[1].string() );
		shamt = tokens[2].integer();
		func = name_to_func_num( name ); 
	}	

        else if(name == "srl"){
		op = name_to_num(name);
                rd = r_type_args( tokens[0].string() );
                rs = 0;
                rt = r_type_args( tokens[1].string() );
		shamt = tokens[2].integer();
		func = name_to_func_num( name ); 
	}	

        else if(name == "sub"){
		op = name_to_num(name);
                rd = r_type_args( tokens[0].string() );
                rs = r_type_args( tokens[1].string() );
                rt = r_type_args( tokens[2].string() );
		shamt = 0;
		func = name_to_func_num( name ); 
	}	

        else if(name == "subu"){
		op = name_to_num(name);
                rd = r_type_args( tokens[0].string() );
                rs = r_type_args( tokens[1].string() );
                rt = r_type_args( tokens[2].string() );
		shamt = 0;
		func = name_to_func_num( name ); 
	}	



	
	return four_to_machine(op, rs,  rt,  rd,  shamt, func);

}

//name: i_type_machine
//purpose: takes in all int i type parameters and assembles them to the correct hex format
int i_type_machine(int op, int rs, int rt, int imm){


	long unsigned int op_temp = 0;
	unsigned long int rs_temp = 0;
	unsigned long int rt_temp = 0;
        unsigned long int out = 0; //holds final output 

	op_temp = op << 26;

	op_temp = op_temp & 4294967295;

	rs_temp = rs << 21;
	rt_temp = rt << 16;

	out = op_temp | rs_temp;
	out |= rt_temp;
	out |= imm;


	//cout << "out is: "; 
	//cout << std::setw(8) << std::hex << std::setfill('0') << out << endl;

        return out; 


}


//name: extractor_i
//purpose: take in an I type label and run the necessary stuffs on it
int extractor_i(string name, std::vector<lexer::token> tokens){

	int op, rs, rt, imm; //declare some stuff

	//do some shit
        if(name == "addi"){
		op = name_to_num(name);
                rt = r_type_args( tokens[0].string() );
                rs = r_type_args( tokens[1].string() );
		imm = tokens[2].integer();
	}	
	else if(name == "addiu"){
		op = name_to_num(name);
                rt = r_type_args( tokens[0].string() );
                rs = r_type_args( tokens[1].string() );
		imm = tokens[2].integer();
	}			
	else if(name == "andi"){
		op = name_to_num(name);
                rt = r_type_args( tokens[0].string() );
                rs = r_type_args( tokens[1].string() );
		imm = tokens[2].integer();
	}			
	else if(name == "addiu"){
		op = name_to_num(name);
                rt = r_type_args( tokens[0].string() );
                rs = r_type_args( tokens[1].string() );
		imm = tokens[2].integer();
	}			
	else if(name == "lbu"){
		op = name_to_num(name);
                rt = r_type_args( tokens[0].string() );
                rs = r_type_args( tokens[1].string() );
		imm = tokens[2].integer();
	}			
	else if(name == "lhu"){
		op = name_to_num(name);
                rt = r_type_args( tokens[0].string() );
                rs = r_type_args( tokens[1].string() );
		imm = tokens[2].integer();
	}			
	else if(name == "ll"){
		op = name_to_num(name);
                rt = r_type_args( tokens[0].string() );
                rs = r_type_args( tokens[1].string() );
		imm = tokens[2].integer();
	}			
	else if(name == "lui"){
		op = name_to_num(name);
                rt = r_type_args( tokens[0].string() );
                rs = 0;
		imm = tokens[2].integer();
	}			
	else if(name == "lw"){
		op = name_to_num(name);
                rt = r_type_args( tokens[0].string() );
		imm = tokens[1].integer();
                rs = r_type_args( tokens[2].string() );
	}			
	else if(name == "ori"){
		op = name_to_num(name);
                rt = r_type_args( tokens[0].string() );
                rs = r_type_args( tokens[1].string() );
		imm = tokens[2].integer();
	}			
	else if(name == "slti"){
		op = name_to_num(name);
                rt = r_type_args( tokens[0].string() );
                rs = r_type_args( tokens[1].string() );
		imm = tokens[2].integer();
	}			
	else if(name == "sltiu"){
		op = name_to_num(name);
                rt = r_type_args( tokens[0].string() );
                rs = r_type_args( tokens[1].string() );
		imm = tokens[2].integer();
	}			
	else if(name == "sb"){
		op = name_to_num(name);
                rs = r_type_args( tokens[0].string() );
		imm = tokens[1].integer();
		rt = r_type_args( tokens[2].string() );
	}			
	else if(name == "sc"){
		op = name_to_num(name);
                rs = r_type_args( tokens[0].string() );
		imm = tokens[1].integer();
		rt = r_type_args( tokens[2].string() );
	}			
	else if(name == "sh"){
		op = name_to_num(name);
                rs = r_type_args( tokens[0].string() );
		imm = tokens[1].integer();
		rt = r_type_args( tokens[2].string() );
	}			
	else if(name == "sw"){
		op = name_to_num(name);
                rt = r_type_args( tokens[0].string() );
		imm = tokens[1].integer();
                rs = r_type_args( tokens[2].string() );
	}			
		
	return i_type_machine(op, rs, rt, imm);


}

//name branch_assembler
//purpose: to assemble branch instructions
int branch_assembler(std::vector<string> label_vec, string name, std::vector<lexer::token> tokens, std::vector<int> line, int curr_line){
	
	int op, rs, rt, pc;
	unsigned int imm;
	pc = curr_line + 1;

	bool found_label = false;

	//we will either have bne or beq, eithe way first find the imm
	for(int i=0; i < label_vec.size(); i++){
		//the : might still be there, so we may need to trim this... 
		if( label_vec[i] == tokens[2].string() ){ 
 			imm = line[i] - pc;
			imm &= 65535;
			found_label = true;
		}
//		std::cout << "label_vec[i] = " << label_vec[i] << "tokens[2] is: " << tokens[2].string() << endl;

	}

	op = name_to_num(name);
	rs = r_type_args( tokens[0].string() ); 
	rt = r_type_args( tokens[1].string() ); 


	if(found_label == false){
		cerr << "Could not find label at line: " << curr_line << endl; 
		return 0;
	}
	return i_type_machine(op, rs, rt, imm);


} 




