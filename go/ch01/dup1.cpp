// Dup1 prints the text of each line that appears more than once in the standard input, preceded its count.
#include <iostream>
#include <map>
#include <string>

int main()
{
	std::map<std::string, int> counts;
	std::string input;

	while (std::cin >> input)
		++counts[input];
	for (const auto i : counts)
		if (i.second > 1)
			std::cout << (i.second) << "\t" << (i.first) << std::endl;

	return 0;
}
