#include <string>
#pragma once
struct M_Data
{
	//Data Fields
	/** The weight or probability assigned to this HuffData*/
	/** The alphabet symbol if this is a leaf */
	string weight;
	char symbol;
	M_Data *left;
	M_Data *right;
	// Constructor
	M_Data(string w = " ", char s = ' ', M_Data* left = NULL, M_Data* right = NULL) : weight(w), symbol(s), left(left), right(right) {};
};
class MTree {
private:
	M_Data *root = new M_Data;
public:
	void build_tree(vector<M_Data> symbols);
	string encode(string message); //wrapper
	bool encode(char target, M_Data *root, stack<char> & code);
	string decode_wrapper(M_Data *Root, string code); //wrapper
	decode(M_Data *Root, string Code);
	string decode_letter(M_Data *Root, string code, int index);
};
