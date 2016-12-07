#include "MorseTree.h"
#include <vector>
#include <stack>
#include <string>
#include <iostream>
using namespace std;

void MTree::build_tree(vector<M_Data> symbols, M_Data *&root) {

	// Build the tree
	int i = 0;

	root->left = &symbols[i];	//Adds left and right child nodes from sorted array
	i++;
	root->right = &symbols[i];
	i++;
	for (i = 2; i < symbols.size(); i++)
	{
		int j = 0;
		struct M_Data *current = root;		//Traverses tree, adding nodes in proper place
		while (j < symbols[i].weight.size()) {
			if (symbols[i].weight[j] == '.') {
				if (current->left != NULL) {
					current = current->left;
					j++;
				}
				else
				{
					current->left = &symbols[i];
					j++;
				}
			}

			if (symbols[i].weight[j] == '_') {
				if (current->right != NULL) {
					current = current->right;
					j++;
				}
				else
				{
					current->right = &symbols[i];
					j++;
				}
			}
		}

	}
	system("pause");
	
}

string MTree::encode_wrapper(string message) { //wrapper
	stack<char> charCode;
	string fullCode = "";

	for (int i = 0; i < message.size(); i++) {
		if (message[i] == ' ') {
			fullCode += " ";
		}
		else {
			encode(message[i], root, charCode);
			while (!charCode.empty()) {
				fullCode += charCode.top();
				charCode.pop();
			}
		}
	}
	return fullCode;
}

bool MTree::encode(char target, M_Data *node, stack<char> & code) {
	if (node == NULL) return false;

	if (node->symbol == target) return true;

	if (encode(target, node->left, code) == true) {
		code.push('.');
		return true;
	}
	else if (encode(target, node->left, code) == true) {
		code.push('-');
		return true;
	}

	return false;
}

string decode_letter(M_Data *Root, string code, int index)
{
if (Root==NULL)
return"";
if (index==code.size())       //last direction in code
{
if(&code[index]==".")
return Root->left->symbol;
if (&code[index] == "_")
return Root->right->symbol
else return Root->symbol;
else                          //still going through code
{
if(code[index]==".")
return decode_letter(Root->left,code,index+1);
if (code[index]=="_")
return decode_letter(Root->right,code,index+1);
}
return "";   //back up in case everything goes wrong
}


string decode_wrapper(M_Data *Root, string code)
{
string letter=decode_letter(Root,code,0)
return letter;
}

string decode(M_Data *Root, string Code)
{
string word="";
string letterCode="";
for(int i=0; i<=Code.size(); i++)
{
if (Code[i]==" ")  //NOT AN EMPTY STRING this is a space specifically. That is what splits letters
{
word=word+decode_wrapper(Root, letterCode)   //finds the next letter from the letterCode created.
letterCode="";
}
else
letterCode=letterCode+Code[i];  //adds character onto string to be decoded for a letter
}
