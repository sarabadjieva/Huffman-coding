#include "huffman.h"


void encode(node* n, string codeString)
{
	if (n == NULL) return;
	if (n->left == NULL && n->right == NULL)
	{
		n->huffmanCode = codeString;
	}
	encode(n->left, codeString + "0");
	encode(n->right, codeString + "1");

};


string decode(node* root, string encoded)
{
	string decoded = "";
	node* curr = root;

	for (unsigned i = 0; i < encoded.length(); i++)
	{
		//if the number at pos i is 0 we go to the left subtree
		//if the number at pos i is 1 we go to the right subtree
		if (encoded[i] == '0')
		{
			curr = curr->left;
		}
		else
		{
			curr = curr->right;
		}

		//if a leaf is reached, attach the letter, which the leaf contains, to the decoded string
		if (curr->right == NULL && curr->left == NULL)
		{
			decoded += curr->c;
			//to start from the root for the next number
			curr = root;
		}
	}

	return decoded + '\0';
};



void findAndAttach(node* root, node* n)
{
	if (root == NULL) return;
	if (root->c == n->c)
	{
		n->huffmanCode = root->huffmanCode;
	}

	findAndAttach(root->left, n);
	findAndAttach(root->right, n);

}


deque<node*> encodedNodes(string text)
{
	deque<node*> nodes = buildTable(text);
	node* root = buildTree(text);

	for (auto x : nodes)
	{
		findAndAttach(root, x);
	}

	return nodes;
};


string encodedString(string original)
{
	string encoded = "";

	for (unsigned i = 0; original[i] != '\0'; i++)
	{
		//search the huffman code for the current letter in the nodes queue
		deque<node*> nodes = encodedNodes(original);
		for (auto y : nodes)
		{
			if (original[i] == y->c)
			{
				encoded.append(y->huffmanCode);
			}
		}
	}
	return encoded;
};