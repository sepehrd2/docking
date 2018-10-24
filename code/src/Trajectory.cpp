#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Trajectory.h"
#include "Atom.h"


void writing_trajectory(ofstream & XYZfile, const vector<Atom> & ATOMS, const int &frame)
{
	XYZfile << ATOMS.size() << std::endl;
	XYZfile << frame        << std::endl;
	for (int i = 0; i < ATOMS.size(); ++i)
	{
		XYZfile << ATOMS[i].name 	   << " ";
		XYZfile << ATOMS[i].position.x << " ";
		XYZfile << ATOMS[i].position.y << " ";
		XYZfile << ATOMS[i].position.z << std::endl; 
	}	
}