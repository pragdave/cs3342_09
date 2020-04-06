//Ausitn Smith
//Finite State Machine Implementation

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
vector<string> tokString(string);
bool FSM(string);

int main()
{
	string test1 = "the dog ate noisily",
		test2 = "the lazy smelly cat ran",
		test3 = "The lazy lazy lazy smelly lazy smelly cat ran noisily",
		test4 = "the smelly cat dog ran",
		test5 = "the dog",
		test6 = "lazy cat ate noisily",
		test7 = "the lazy dog ran slowly",
		test8 = "",
		test9 = "the",
		test10 = "The cat ate";
	cout << FSM(test1) << " - " << test1 << "\n";  // 1 true
	cout << FSM(test2) << " - " << test2 << "\n";  // 1 true
	cout << FSM(test3) << " - " << test3 << "\n";  // 1 true
	cout << FSM(test4) << " - " << test4 << "\n";  // 0 false
	cout << FSM(test5) << " - " << test5 << "\n";  // 0 false
	cout << FSM(test6) << " - " << test6 << "\n";  // 0 false
	cout << FSM(test7) << " - " << test7 << "\n";  // 1 true
	cout << FSM(test8) << " - " << test8 << "\n";  // 0 false
	cout << FSM(test9) << " - " << test9 << "\n";  // 0 false
	cout << FSM(test10) << " - " << test10 << "\n"; // 1 true
}

//<sentence> ::= "The" {"lazy" | "smelly"} ("dog" | "cat") ("ate" | "ran") ["slowly" | "noisily"]
bool FSM(string sentence) 
{
	vector<string> words = tokString(sentence);
	string adjective[] = { "smelly", "lazy" }, noun[] = { "dog", "cat" }, 
		verbs[] = { "ate", "ran" }, adverb[] = {"slowly", "noisily"};

	if (words[0] == "the" || words[0] == "The") { //check for initial "the" or "The"
		int index = 1;
		while (words[index] != "cat" && words[index] != "dog"){ //keep checking for adjective until word is noun
			if (words[index] == "smelly" || words[index] == "lazy") { //check for adjective(s)
				index++;
				continue;
			}
			return false;
		}
		index++;
		if (words[index] == "ate" || words[index] == "ran") { //check for verb
			if (words[index+1] == "EOI") //check for end of input
				return true;
			if (words[index+1] == "slowly" || words[index+1] == "noisily") //check for adverb
				if (words[index+2] == "EOI") //check for end of input
					return true;
		}
	} 
	return false;
}

/* This function just parses the string so inputing a complete
 *      sentence as a string is possible. Adds EOI to end. */
vector<string> tokString(string sentence)
{
	istringstream ss(sentence);
	vector<string> words;
	while (ss) {
		string word;
		ss >> word;
		if(word.size()>0)
			words.push_back(word);
	}
	words.push_back("EOI");
	return words;
}