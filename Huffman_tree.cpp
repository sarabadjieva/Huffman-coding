#include "huffman.h"

//
//functions for working with the Huffman tree
//

struct compare
{
	bool operator()(node* n1, node* n2)
	{
		return n1->frequency > n2->frequency;
	}
};


deque<node*> buildTable(string text)
{
	deque<node*> nodes;
	node* firstNode = new node;
	firstNode->c = text[0];
	firstNode->frequency++;
	nodes.push_back(firstNode);
	int endIndex = 0;

	for (unsigned i = 1; text[i] != '\0'; i++)
	{
		bool isFound = false;

		for (auto y : nodes)
		{
			if (text[i] == y->c)
			{
				y->frequency++;
				isFound = true;
			}
		}

		if (isFound == false)
		{
			node* newNode = new node;
			newNode->c = text[i];
			newNode->frequency++;
			nodes.push_back(newNode);
			endIndex++;
		}
	}

	return nodes;
};

node* buildTree(string text)
{
	deque<node*> nodes = buildTable(text);

	//compare these nodes by their frequency 
	//the letter with smallest frequency will be first
	priority_queue <node*, vector<node*>, compare> pqNodes;
	for (auto x : nodes)
	{
		pqNodes.push(x);
	}

	while (pqNodes.size() > 1)
	{
		node* newNode = new node;
		node* first = pqNodes.top(); pqNodes.pop();
		node* second = pqNodes.top(); pqNodes.pop();
		newNode->left = first;	newNode->right = second;
		newNode->frequency = first->frequency + second->frequency;
		pqNodes.push(newNode);
	}

	encode(pqNodes.top());
	return pqNodes.top();
};
