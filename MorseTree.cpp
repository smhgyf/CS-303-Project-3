#include "MorseTree.h"

using namespace std;

void MTree::setNode(char key, string morse) {
	mNode node;
	node.key = key;
	node.morse = morse;
	insertNode(node, root);
}
void MTree::insertNode(mNode node, mNode root) {

}
void MTree::findNode(mNode node) {}

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

