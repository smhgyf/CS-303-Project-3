#include <string>

using namespace std;

class MTree {
private:
	struct mNode {
		mNode* mRight;
		mNode* mLeft;
		char key;
		string morse;
		mNode() {
			mRight = NULL;
			mLeft = NULL;
			key = ' ';
			morse = "";
		}
	};
	mNode root;
public:
	void setNode(char key, string morse);
	void insertNode(mNode node, mNode root);
	void findNode(struct mNode);
}
