#include <iostream>

struct Node {
	int value;
	Node * left;
	Node * right;

};

class BinaryTree {
	public:
	Node * root = new Node();
	BinaryTree(int value){
		root -> value  = value;
		root -> left  = NULL;
		root -> right = NULL;
	}

	private:
	void recursiveTraverse(Node * node){
		if (node -> left != NULL){
			recursiveTraverse(node->left);
		} if (node -> right != NULL){
			recursiveTraverse(node->right);
		}
		std:: cout << node -> value << " ";

	}

	void recursiveTraverse2(Node* node){
		if (node -> left != NULL && node -> right != NULL){
			std:: cout << node ->left -> value << " ";
			std:: cout << node -> right -> value << " ";
			recursiveTraverse2(node->left);
			recursiveTraverse2(node->right);
		} else {
			if (node -> left != NULL){
				std:: cout << node -> left -> value << " ";
				recursiveTraverse2(node->left);
			} if (node -> right != NULL) {
				std:: cout << node -> right -> value << " ";
				recursiveTraverse2(node -> right);
			}
		}

	}

	public:
	void insert(int value){
		Node * ptr = root;
		while (1) {
			if (value < ptr->value){
				if (ptr->left == NULL){
					ptr->left = new Node();
					ptr->left->value = value;
					break;
				} else {
					ptr = ptr ->left;
				}
			} else {
				if (ptr -> right == NULL){
					ptr->right = new Node();
					ptr -> right -> value = value;
					break;
				} else {
					ptr = ptr -> right;
				}
			}
		}
	}
	
	void traverse() {
		recursiveTraverse(root);
		std:: cout << std:: endl;
	} 

	void traverse2() {
		std:: cout << root -> value << " ";
		recursiveTraverse2(root);
		std:: cout << std:: endl;
	}

	bool search(int value){
		Node * temp = root;
		while(temp != NULL){
			if (temp-> value == value){
				return true;
			} else {
				if (temp -> value > value){
					temp = temp -> left;
				} else {
					temp = temp -> right;
				}
			}
		}
		return false;
	}

	int min () {
		Node *temp = root;
		while(temp-> left != NULL){
			temp = temp->left;
		}
		return temp -> value;
	}

	int max () {
		Node *temp = root;
		while(temp-> right != NULL){
			temp = temp -> right;
		}
		return temp -> value;
	}

};



int main () {
	BinaryTree tree = BinaryTree(5);
	tree.insert(3);
	tree.insert(6);
	tree.insert(9);
	tree.insert(2);
	tree.insert(4);
	tree.insert(13);

	tree.traverse();
	tree.traverse2();
	std:: cout << "min: " << tree.min() << " max: " << tree.max() << " search: " << tree.search(3) << std:: endl;
}
