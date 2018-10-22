#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <string>
#include <vector>
#include "pdb.h"
#include "Atom.h"

using namespace std;

Pdb::Pdb(){}
Pdb::~Pdb(){}

inline bool starts_with(const std::string& str, const std::string& start) {
	return str.size() >= start.size() && str.substr(0, start.size()) == start;
}

// Pdb read_pdb(std::string& filename)
// {
// 	ifstream pdbfile;
// 	Pdb tmp;
// 	string str;
// 	pdbfile.open (filename.c_str());
// 	while(std::getline(pdbfile, str)) 
// 	{
// 		if(starts_with(str, "ATOM  ") || starts_with(str, "HETATM")) 
// 		{
// 			// cout << str.substr(6, 6) << endl;
// 			// cout << str.substr(11, 4) << endl;

// 		}
// 	}
// 	pdbfile.close();
// 	return tmp;
// }

void read_XYZ(std::string& filename, vector<Atom> & ATOMS)
{
	ifstream XYZfile;
	Atom tmp;
	string str;
	int counter = 0;
	XYZfile.open (filename.c_str());
	
	while(std::getline(XYZfile, str)) 
	{
		
		XYZfile >> tmp.position.x;
		XYZfile >> tmp.position.y;
		XYZfile >> tmp.position.z;
		tmp.index = counter;
		ATOMS.push_back(tmp);
		counter++;
	}

	XYZfile.close();
}
void write_XYZ(std::string& filename, std::vector<Atom> & ATOMS)
{
	ofstream XYZfile;
	XYZfile.open (filename.c_str());
	for (int i = 0; i < ATOMS.size(); ++i)
		{
			XYZfile << ATOMS[i].position.x << " ";
			XYZfile << ATOMS[i].position.y << " ";
			XYZfile << ATOMS[i].position.z << endl; 
		}	
	XYZfile.close();
}