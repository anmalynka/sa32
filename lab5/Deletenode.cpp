#include "Deletenode.h"


Node* getFreeNode(int value, Node *parent) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->left = tmp->right = NULL;
	tmp->data = value;
	tmp->parent = parent;
	return tmp;
}
Node* getMinNode(Node *root) {
	while (root->left) {
		root = root->left;
	}
	return root;
}

Node* getMaxNode(Node *root) {
	while (root->right) {
		root = root->right;
	}
	return root;
}

Node *getNodeByValue(Node *root, int value) {
	while (root) {
		if (CMP_GREAT(root->data, value)) {
			root = root->left;
			continue;
		}
		else if (CMP_LESST(root->data, value)) {
			root = root->right;
			continue;
		}
		else {
			return root;
		}
	}
	return NULL;
}
void Tree::insert(Node **head, int value) {
	Node *tmp = NULL;
	Node *ins = NULL;
	if (*head == NULL) {
		*head = getFreeNode(value, NULL);
		return;
	}

	tmp = *head;
	while (tmp) {
		if (CMP_GREAT(value, tmp->data) || CMP_EQUIL(value, tmp->data)) {
			if (tmp->right) {
				tmp = tmp->right;
				continue;
			}
			else {
				tmp->right = getFreeNode(value, tmp);
				return;
			}
		}
		else if (CMP_LESST(value, tmp->data)) {
			if (tmp->left) {
				tmp = tmp->left;
				continue;
			}
			else {
				tmp->left = getFreeNode(value, tmp);
				return;
			}
		}
		//else {
		//exit(2);
		//}
	}
}


void Tree::removeNodeByPtr(Node *target) {
	if (target->left && target->right) {
		Node *localMax = getMaxNode(target->left);
		target->data = localMax->data;
		removeNodeByPtr(localMax);
		return;
	}
	else if (target->left) {
		if (target == target->parent->left) {
			target->parent->left = target->left;
		}
		else {
			target->parent->right = target->left;
		}
	}
	else if (target->right) {
		if (target == target->parent->right) {
			target->parent->right = target->right;
		}
		else {
			target->parent->left = target->right;
		}
	}
	else {
		if (target == target->parent->left) {
			target->parent->left = NULL;
		}
		else {
			target->parent->right = NULL;
		}
	}
	free(target);
}

void Tree::deleteValue(Node *root, int value) {
	Node *target = getNodeByValue(root, value);
	removeNodeByPtr(target);
}

void Tree::printTree(Node *root, const char *dir, int level) {
	if (root) {
		cout << "lvl " << level << " " << dir << " = " << root->data << endl;
		printTree(root->left, "left", level + 1);
		printTree(root->right, "right", level + 1);
	}
}

void Tree::Display(Node *root, int indent)
{
	if (root != nullptr)
	{
		Display(root->right, indent + 4);
		if (indent > 0)
			cout << setw(indent) << " ";
		cout  << root->data << endl;
		Display(root->left, indent + 4);
	}
}

void CSV::OpenFile(vector<int>&myValues, int numbers, int lines)
{
	int x = 0;
	ifstream ifs("test.csv");
	if (ifs.fail())
	{
		throw 1;
	}
	if (ifs.eof()) {
		throw 2;
	}
	char tmp;
	for (int i = 0; i < lines; ++i) {
		for (int i = 0; i < numbers; ++i) {
			ifs >> x;
			myValues.push_back(x);
			if (i < (numbers - 1))
				ifs >> tmp;
		}
	}

}
void CSV::ShowArray(vector<int>&myValues, int numbers, int lines)
{
	for (int i = 0; i < lines; ++i) {
		for (int i = 0; i < numbers; ++i) {
			cout << myValues[i] << ' ';
		}
	}
	cout << endl;

}
