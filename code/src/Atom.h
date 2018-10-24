#include <string>
#include "Vector.h"
#ifndef ATOM_H_
#define ATOM_H_
class Atom
{
public:
	Vector position;
	int index, residue_id;
	std::string name, residue_name, element;
	float b_factor;
	Atom();
	~Atom();
	void out();

private:

};

#endif 
