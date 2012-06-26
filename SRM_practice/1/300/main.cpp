#include "BinaryCode.h"
#include <iostream>

int main(int argc, char* argv[])
{
	BinaryCode decoder;
	vector<string> temp = decoder.decode("123210120");

	cout << temp[0] << endl;
	cout << temp[1] << endl;
}