#include <iostream>
#include <fstream>
#include "inputfunctions.hpp"
using namespace std;
void readfromtxtfile()
{
	char filename[] = "example.txt";
	std::ifstream file(filename);
	char input[1024];
	if (file.fail())
	{
		cout << "error with file" << endl;
		return;
	}
	cout << filename<<" is opened." << endl;

	while (!file.eof())
	{
		char buff[1024];
		file.getline(buff, 1024);
		cout << buff << endl;
		inputfunctions(buff);
	}

	file.close();


}

int main()
{
	readfromtxtfile();
}
