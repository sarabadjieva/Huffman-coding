#pragma once
#include <string>
#include <queue>
#include <iostream>
#include <fstream>

using namespace std;

struct node
{
	char c = '\0';
	int frequency = 0;
	string huffmanCode = "";
	node* left = NULL;
	node* right = NULL;
};

//this struct will be used in a priority queue, which compares nodes by their frequency
struct compare;

//return a deque with all the different nodes (letter + frequency)
deque<node*> buildTable(string text = "");

//get the deque from buildTable, transform it into a tree, set prices to branches
node* buildTree(string text);

//functions to encode and decode
void encode(node* n, string codeString = "");
string decode(node* n, string text = "");

//a helper function to attach the huffman codes from the tree to eq letter from deque
void findAndAttach(node* root, node* n);

//return a deque with all the different nodes (letter + frequency + huffman code)
deque<node*> encodedNodes(string text = "");

//get the original string and return the encoded one
string encodedString(string original="");

//binary to decimal
string alternativeCode(string original="");

//how much memory have we saved in %
double compressedMemory(string original = "");

//print everything
void prettyPrint(string origina = "");
