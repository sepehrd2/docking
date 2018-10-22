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

Pdb read_pdb(std::string& );
void read_XYZ(std::string&, std::vector<Atom> &);
void write_XYZ(std::string&, std::vector<Atom> &);
#endif
