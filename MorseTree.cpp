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
