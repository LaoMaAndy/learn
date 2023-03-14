// Dup2 prints the count and text of lines that appear more than once in the input
// It reads from stdin or from a list of named file.
#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;

void countLines(istream &f, map<string, int> &counts)
{
	string input;
	while (getline(f, input))
			++counts[input];
}

int main(int argc, char *argv[])
{
	map<string, int> counts;
	if (argc <= 1)
		countLines(cin, counts);
	else
		for (int i = 1; i < argc; ++i)
		{
			ifstream f;
			f.open(argv[i]);
			if (!f)
			{
				cerr << "Dup2: " << argv[i] << endl;
				continue;
			}
			countLines(f, counts);
			f.close();
		}
	for (const auto &i : counts)
		if (i.second > 1)
			cout << i.second << "\t" << i.first << endl;
	return 0;
}

