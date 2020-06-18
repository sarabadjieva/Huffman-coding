#include "huffman.h"


int main()
{ 
	cout << "Choose if you want to read from a file or write text directly (file/text): ";
	string choice;
	cin >> choice;
	std::cin.clear();
	std::cin.ignore();
	if (choice == "file")
	{
		cout << "Now choose if you want to compress or decompress (c/d): ";
		char c;
		cin >> c;
		if (c == 'c')
		{
			cout << "Write input file: ";
			string inputFile;
			cin >> inputFile;

			cout << '\n' << "Write output file: ";
			string outputFile;
			cin >> outputFile;

			ifstream infile(inputFile);
			string original((istreambuf_iterator<char>(infile)), (istreambuf_iterator<char>()));
			infile.open(inputFile);
			infile.close();

			ofstream outfile;
			outfile.open(outputFile);
			outfile << encodedString(original);
			outfile.close();
		}
		else
		{
			cout << "In making...";
		}
		
	}
	else
	{
		cout << "Write text: ";
		char text[100000];
		cin.getline(text, 100000); 
		prettyPrint(text);
	}

	system("pause");
	return 0;
}