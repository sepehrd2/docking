#include <string>
#include <vector>
#include "Atom.h"
#ifndef PDB_H_
#define PDB_H_
class Pdb
{
public:

	Pdb();
	~Pdb();

private:



};

void  read_pdb(std::string&, std::vector<Atom> &); 
void  read_XYZ(std::string&, std::vector<Atom> &);
void write_XYZ(std::string&, std::vector<Atom> &, int);
void write_pdb(std::string&, std::vector<Atom> &);

#endif
