#include <string>
#include <vector>
#include <stack>
#pragma once
using namespace std;
struct M_Data
{
	string weight;
	char symbol;
	struct M_Data *left;
	struct M_Data *right;
	// Constructor
	M_Data(string w = " ", char s = ' ', M_Data* left = NULL, M_Data* right = NULL) : weight(w), symbol(s), left(left), right(right) {};
};
class MTree {
public:
	void build_tree(vector<M_Data> symbols, M_Data *&root);
	string encode_wrapper(string message);
	bool encode(char target, M_Data *node, stack<char> & code);
	string decode_letter(M_Data *Root, string code, int indedx);
	string decode_wrapper(M_Data *Root, string Code);
	string decode(M_Data *Root, string Code);
};
