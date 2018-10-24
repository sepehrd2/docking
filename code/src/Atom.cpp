#include <iostream>
#include "Atom.h"
using namespace std;

Atom::Atom(){
	index 		 = 0;
	residue_id   = 0;
	b_factor     = 0.0;
	name         = ""; 
	residue_name = "";
	element      = "";
}
Atom::~Atom(){}
void Atom::out(){
	std::cout << index        << " "
			  <<  name 		  << " "
			  << residue_name << " "
			  << residue_id   << " "
			  << position.x   << " "
			  << position.y   << " "
			  << position.z   << " "
			  << b_factor     << " "
			  << element      << std::endl;
}
