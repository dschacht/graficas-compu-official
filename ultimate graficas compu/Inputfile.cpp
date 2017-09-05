#include "Inputfile.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

bool Inputfile::Read(const std::string& filename)
{
	if (filename.empty() ){
		std::cout << "No Filename provided" << std::endl;
		return false;
	}

	std::fstream inputFile(filename, std::fstream::in);
	if (!inputFile.is_open())
	{
		std::cout << "could not open file" << filename << std::endl;
		return false;
	}
	std::stringstream ss;
	ss << inputFile.rdbuf();
	_contents = ss.str();
	return true;
}

std::string Inputfile::GetContents()
{
	return _contents;
}
