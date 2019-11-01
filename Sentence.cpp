#include <iostream>
#include <vector>
#include <map>
#include <set>

bool isSentence(std::vector<std::string>&);

int main()
{
	std::vector<std::string> one = { "the", "dog", "ran", "EOI" };
	std::vector<std::string> two = { "the", "lazy", "dog", "ran", "slowly", "EOI" };
	std::vector<std::string> three = { "dog", "ran", "EOI" };
	std::vector<std::string> four = { "the", "lazy", "lazy", "lazy", "smelly", "dog", "ran", "EOI" };
	std::vector<std::string> five = { "the", "dog", "ran", "noisily" };

	std::vector<std::vector<std::string>> list;
	list.push_back(one);
	list.push_back(two);
	list.push_back(three);
	list.push_back(four);
	list.push_back(five);

	for (int i = 0; i < list.size(); i++)
	{
		bool valid = isSentence(list.at(i));
		std::cout << "Sentence " << i << ": ";
		for (int j = 0; j < list.at(i).size(); j++)
		{
			std::cout << list.at(i).at(j) << " ";
		}
		std::cout << "- Valid: ";
		if (valid == true)
		{
			std::cout << "true" << std::endl;
		}
		else
		{
			std::cout << "false" << std::endl;
		}
	}
	return 0;
}

bool isSentence(std::vector<std::string>& sentence)
{
	std::map<std::pair<std::string, std::string>, std::string> table {{std::make_pair("S0", "the"),    "S1"},
																	  {std::make_pair("S1", "lazy"),   "S2"},  {std::make_pair("S1", "smelly"),  "S2"},
																	  {std::make_pair("S1", "dog"),    "S3"},  {std::make_pair("S1", "cat"),     "S3"},
																	  {std::make_pair("S2", "lazy"),   "S2"},  {std::make_pair("S2", "smelly"),  "S2"},
																	  {std::make_pair("S2", "dog"),    "S3"},  {std::make_pair("S2", "cat"),     "S3"},
																	  {std::make_pair("S3", "ate"),    "S4"},  {std::make_pair("S3", "ran"),     "S4"},
																	  {std::make_pair("S4", "slowly"), "S5"},  {std::make_pair("S4", "noisily"), "S5"},
																	  {std::make_pair("S4", "EOI"),    "END"}, {std::make_pair("S5", "EOI"),     "END"}};

	std::pair<std::string, std::string> temp;
	std::string currState = "S0";
	for (int i = 0; i < sentence.size(); i++)
	{
		temp = std::make_pair(currState, sentence.at(i));
		if (table.count(temp) == 1)
		{
			currState = table.at(temp);
			if (currState == "END")
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
}
