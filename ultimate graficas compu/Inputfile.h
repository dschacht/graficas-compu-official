#pragma once
#include <string>
class Inputfile
{
public:
	bool Read(const std::string& filename);
	 std::string GetContents() ;

private:
	std::string _contents;
};

