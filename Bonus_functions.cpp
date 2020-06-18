#include "huffman.h"

//
//functions for output
//

string alternativeCode(string original)
{
	string binaryCode = encodedString(original);

	//make the length divisible by 8
	while (binaryCode.length() % 8 != 0)
	{
		binaryCode.insert(0, "0");
	}

	string result = "";

	//make an alternative code for the first 8 chars from the string, delete them and start again
	while (!binaryCode.empty())
	{
		int len = binaryCode.length();
		int base = 1;
		int tempforDecimal = 0;
		for (int i = 7; i >= 0; i--)
		{
			if (binaryCode[i] == '1') { tempforDecimal += base; }
			base *= 2;
		}
		result.append(to_string(tempforDecimal)); result.append(" ");
		binaryCode.erase(0, 8);
	}

	return result;
};


double compressedMemory(string original)
{
	double sizeOriginal = original.size() * 8;
	double sizeCompressed = encodedString(original).size();
	return (100 * sizeCompressed) / sizeOriginal;
};


void prettyPrint(string original)
{
	cout << "The original text is: " << original << endl << endl;

	cout << "The table of chars, frequencies and huffman codes is: " << endl;
	for (auto x : encodedNodes(original))
	{
		cout << "Char: " << x->c << ", frequency: " << x->frequency << ", huffman code: " << x->huffmanCode << endl;
	}
	cout << endl;

	cout << "The encoded text is: " << encodedString(original) << endl << endl;

	cout << "And the decoded: " << decode(buildTree(original), encodedString(original)) << endl << endl;

	cout << "Alternative code is: " << alternativeCode(original) << endl << endl;

	cout << "Compressed memory in percent: " << compressedMemory(original) << endl << endl;
}