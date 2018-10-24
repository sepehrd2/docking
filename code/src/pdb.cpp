#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <string>
#include <vector>
#include "pdb.h"
#include "Atom.h"
#include <stdlib.h>     /* strtof */
#include <sstream>
#include <iomanip> // setprecision

// #include <boost/lexical_cast.hpp>

using namespace std;

Pdb::Pdb(){}
Pdb::~Pdb(){}

inline bool starts_with(const std::string& str, const std::string& start) {
	return str.size() >= start.size() && str.substr(0, start.size()) == start;
}

// template<typename T>
float convert_substring_f(const std::string& str, int i, int j) { // indexes are 1-based, the substring should be non-null
	float tmp;
	string temp;
	temp = str.substr(i-1, j-i+1);
	tmp = atof(temp.c_str());
	return tmp;
}

int convert_substring_i(const std::string& str, int i, int j) { // indexes are 1-based, the substring should be non-null
	int tmp;
	string temp;
	temp = str.substr(i-1, j-i+1);
	tmp = atoi(temp.c_str());
	return tmp;
}

string convert_substring_s(const std::string& str, int i, int j) { // indexes are 1-based, the substring should be non-null
	return str.substr(i-1, j-i+1);
}
Atom string_to_pdb_atom(const std::string& str) {
	Atom tmp;

	tmp.index        = convert_substring_i(str,  7, 11);
	tmp.name         = convert_substring_s(str, 13, 16);
	tmp.residue_id   = convert_substring_i(str, 23, 26);
	tmp.residue_name = convert_substring_s(str, 18, 20);
	tmp.position.x   = convert_substring_f(str, 31, 38);
	tmp.position.y   = convert_substring_f(str, 39, 46);
	tmp.position.z   = convert_substring_f(str, 47, 54);
	tmp.b_factor     = convert_substring_f(str, 61, 66);
	tmp.element      = convert_substring_s(str, 77, 78);
	return tmp;

}
template<typename T>
string convert_to_string(const T var, const int L)
{
	stringstream stream;
	stream << fixed << setprecision(3) << var;
	string s = stream.str();
	while (s.length() < L)
	{
  		s  = " " + s;
	}
	return s;
}

void read_pdb(std::string& filename, vector<Atom> & ATOMS)
{
	ifstream pdbfile;
	string str, x_str, y_str, z_str;
	Atom tmp;
	int i = 0;
	pdbfile.open (filename.c_str());
	while(std::getline(pdbfile, str)) 
	{
		if(starts_with(str, "ATOM  ") || starts_with(str, "HETATM")) 
		{
			tmp = string_to_pdb_atom(str);
			ATOMS.push_back(tmp);
			// cout << str.substr(7 , 5) << endl;
			// cout << str.substr(12, 4) << endl;
			// cout << str.substr(17, 4) << endl;
			// cout << str.substr(23, 4) << endl;
			// cout << str.substr(61, 6) << endl;
			// cout << str.substr(77, 2) << endl;
			// x_str = str.substr(31, 8);
			// y_str = str.substr(39, 8);
			// z_str = str.substr(47, 8);
			// cout << ATOMS[i].position.x;
			// cout << ATOMS[i].position.y;
			// cout << ATOMS[i].position.z << endl;
			// ATOMS[i].out();
			// i++;


		}
	}
	pdbfile.close();
}
// void write_pdb(std::string& filename, vector<Atom> & ATOMS)
// {
// 	ofstream pdbfile;
// 	pdbfile.open (filename.c_str());
// 	for (int i = 0; i < 1; ++i)
// 		{
// 			// ATOM      1  N   ILE A  16      26.051  27.381   7.142  1.00 10.47           N

// 			pdbfile << "ATOM   "
// 					<< convert_to_string(ATOMS[i].index, 4)        << " " 
// 			  		<< ATOMS[i].name 		 << " "
// 			  		<< ATOMS[i].residue_name << " "			 
// 			  		<< "A  "               
// 			  		<< ATOMS[i].residue_id   << " "
// 			  		<< ATOMS[i].position.x   << " "
// 			  		<< ATOMS[i].position.y   << " "
// 			  		<< ATOMS[i].position.z   << " "
// 			  		<< ATOMS[i].b_factor     << " "
// 			  		<< ATOMS[i].element      << std::endl;

// 		}	
// 	pdbfile.close();

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
		XYZfile >> tmp.name;
		// std::cout << tmp.name << std::endl;
		XYZfile >> tmp.position.x;
		XYZfile >> tmp.position.y;
		XYZfile >> tmp.position.z;
		tmp.index = counter;
		ATOMS.push_back(tmp);
		counter++;
	}

	XYZfile.close();
}
void write_XYZ(std::string& filename, std::vector<Atom> & ATOMS, int frame)
{
	ofstream XYZfile;
	XYZfile.open (filename.c_str());
	XYZfile << ATOMS.size() << endl;
	XYZfile << frame  << endl;
	for (int i = 0; i < ATOMS.size(); ++i)
		{
			XYZfile << ATOMS[i].name 	   << " ";
			XYZfile << ATOMS[i].position.x << " ";
			XYZfile << ATOMS[i].position.y << " ";
			XYZfile << ATOMS[i].position.z << endl; 
		}	
	XYZfile.close();
}