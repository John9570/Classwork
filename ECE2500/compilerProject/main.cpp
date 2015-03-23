#include <fstream>
#include <iostream>
#include <iomanip>
#include <memory>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>

#include "exceptions.h"
#include "lexer.h"
#include "util.h"
#include "functions.h"

using namespace std;


std::string read_file(const std::string& name) {
  std::ifstream file(name);
  if (!file.is_open()) {
    std::string error = "Could not open file: ";
    error += name;
    throw std::runtime_error(error);
  }
  std::stringstream stream;
  stream << file.rdbuf();
  return std::move(stream.str());
}

int main(int argc, char** argv) {
  // Adjusting -- argv[0] is always filename.
  --argc;
  ++argv;

  if (argc == 0) {
    std::cerr << "Need a file, leave off the .asm" << std::endl;
    return 1;
  }

  for (int i = 0; i < argc; ++i) {
    std::string asmName(argv[i]);
    std::string dotASM = ".asm";
    std::string dotTXT = ".txt";
    std::string outfile = asmName;

    outfile.append(dotTXT);
    asmName.append(dotASM);

    std::ofstream out(outfile);




    if (!util::ends_with_subseq(asmName, std::string(".asm"))) {
      std::cerr << "Need a valid file name (that ends in .asm, but leave off the .asm)" << std::endl;
      std::cerr << "(Bad name: " << asmName << ")" << std::endl;
      return 1;
    }

    // 4 is len(".asm")
    auto length = asmName.size() - string_length(".asm");
    std::string baseName(asmName.begin(), asmName.begin() + length);
    std::string objName = baseName + ".obj";
    try {
      auto text = read_file(asmName);
      try {
		auto lexed = lexer::analyze(text);		// Parses the entire file and returns a vector of instructions


		//CREATE A VECTOR OF LABELS
		std::vector<std::string> label_vec;
		std::vector<int> lines;
		for(int i= 0; i < (int)lexed.size(); i++){
		
			if(lexed[i].labels.size() > 0){		// Checking if there is a label in the current instruction
				label_vec.push_back( lexed[i].labels[0] );
				lines.push_back( i+1 ); //vector of line of corresponding to label
			}
		}
		
		// ... continue
		for (int i =0; i < (int)lexed.size(); i++){
			
//			if(lexed[i].labels.size() > 0)		// Checking if there is a label in the current instruction
//				std::cout << "label = " << lexed[i].labels[0] << "\n";		// Prints the label
			
//			std::cout<< "instruction name = " << lexed[i].name<< "\n";		// Prints the name of instruction
			
//			std::cout << "tokens = ";
			std::vector<lexer::token> tokens = lexed[i].args;	

			//other proto area:
			if( determine_type( lexed[i].name ) == 0 ){
				//all r type 
				out << std::setw(8) << std::hex << std::setfill('0') << extractor_r(lexed[i].name, tokens) << endl;

			}
			else if( determine_type( lexed[i].name ) == 1){
				//all i type except branches
				out << std::setw(8) << std::hex << std::setfill('0') << extractor_i(lexed[i].name, tokens) << endl;

			}
			else if( determine_type( lexed[i].name ) == 2){
				//this is for branch instructions
				int temp = branch_assembler(label_vec, lexed[i].name, tokens, lines, i+1);
	
				if(temp == 0) return 1; 

				out << std::setw(8) << std::hex << std::setfill('0') << temp << endl;
			}	
			else{
				std::cout << "BAD instruction on line: " << i+1 << std::endl;
				return 1;
			} 


		//	for(int j=0; j < (int)tokens.size(); j++){       // Prints all the tokens of this instruction like $t1, $t2, $t3
			//	if (tokens[j].type == lexer::token::Integer)
			//		std::cout<<tokens[j].integer()<<" ";
			//	else
			//		std::cout<<tokens[j].string()<<" ";
			}
		//	std::cout << "\n\n\n";
	//	}
		
	  } catch(const bad_asm& e) {
		std::stringstream error;
		error << "Cannot assemble the assembly code at line " << e.line;
		throw std::runtime_error(error.str());
		} catch(const bad_label& e) {
		 std::stringstream error;
		error << "Undefined label " << e.what() << " at line " << e.line;
		throw std::runtime_error(error.str());
		}
	  
    } catch (const std::runtime_error& err) {
      std::cout << err.what() << std::endl;
      return 1;
    }
  }
 // getchar();
  return 0;
}
