#include <fstream>
#include <string>
#include <map>
#include <iostream>
#include "MorseTree.h"
using namespace std;
void main()
{
	MTree tempNode;
	system("pause");
	map<char, string> morseCodeMap;
	map<char, string>::iterator it;
	char x;
	string morseCode;
	ifstream FINmorse("morse.txt");
	while (FINmorse)
	{
		x = FINmorse.get();
		getline(FINmorse, morseCode);
		morseCodeMap.insert(pair<char, string>(x, morseCode));
	}
	for (it = morseCodeMap.begin(); it != morseCodeMap.end(); it++)
	{
		tempNode.setNode(it->first, it->second);
	}

	system("pause");

	FINmorse.close();
}
