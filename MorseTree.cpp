
#include "MorseTree.h"
#include <vector>

using namespace std;


void MTree::build_tree(vector<M_Data> symbols) {

	// Build the tree
	int i = 0;

	root->left = &symbols[i];
	i++;
	root->right = &symbols[i];
	i++;
	for (i = 2; i < symbols.size(); i++)
	{
		int j = 0;
		M_Data *current = root;
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
}

string MTree::encode(string message) { //wrapper
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
}

bool MTree::encode(char target, mNode *root, stack<char> & code) {
	if (root == NULL) return false;

	if (root->key == target) return true;

	if (encode(target, root->mLeft, code) == true) {
		code.push('.');
		return true;
	}
	else if (encode(target, root->mRight, code) == true) {
		code.push('-');
		return true;
	}

	return false;
}

