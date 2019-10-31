#pragma once
#include <vector>
#include <string>
using namespace std;

class FSM {
public:
	//table[0] = currentState
	//table[1] = nextWord
	//table[2] = nextState
	
	//runs a vector of words through the state machine and returns a bool of whether or not it passed
	bool runList(vector<string> wordList, vector<vector<string>> table) {
		int numRows = table[1].size();
		string state = "S0";
		for (int i = 0; i < wordList.size(); i++) { //checks each word sequentially
			bool valid = false;
			string currentWord = wordList[i];
			if (currentWord.compare("EOI") == 0 && state.compare("S3") == 0 || state.compare("S4") == 0) //returns true if the word is EOI and the state machine is in state 3 or 4
				return true;
			for (int j = 0; j < numRows; j++) {
				if (table[0][j].compare(state) == 0 && table[1][j].compare(currentWord) == 0) { //if the state and word is in the same row
					state = table[2][j]; //set new state
					valid = true; //continue
				}
			}
			if (!valid)
				return false;
		}
		//return false;
		if (state.compare("END") == 0)
			return true;
		return false;
	}

	//used to format sentences to output (used in runUnitTests)
	void printSentence(vector<string> wordList) {
		for (int i = 0; i < wordList.size()-1; i++) { //skips last word of wordList (EOI)
			cout << " " << wordList[i];
		}
		cout << "." << endl;
	}

	//runs tests on the FSM
	bool runUnitTests(vector<vector<string>> table) {
		bool passedAll = true;
		int failedTests = 0;

		cout << "Running Test 1: " << endl;
		vector<string> wordList = { "The", "dog", "ate", "EOI" };
		cout << "Sentence:";
		printSentence(wordList);
		cout << "Expected Answer: True" << endl;
		if (!runList(wordList, table)) {
			passedAll = false;
			failedTests++;
			cout << "Test failed." << endl;
			cout << "Got: False" << endl;
		}
		else
			cout << "Test Passed." << endl;
		cout << endl;

		cout << "Running Test 2: " << endl;
		wordList = { "The", "lazy", "cat", "ran", "EOI" };
		cout << "Sentence:";
		printSentence(wordList);
		cout << "Expected Answer: True" << endl;
		if (!runList(wordList, table)) {
			passedAll = false;
			failedTests++;
			cout << "Test failed." << endl;
			cout << "Got: False" << endl;
		}
		else
			cout << "Test Passed." << endl;
		cout << endl;


		cout << "Running Test 3: " << endl;
		wordList = { "The", "lazy", "smelly", "cat", "ate", "noisily", "EOI" };
		cout << "Sentence:";
		printSentence(wordList);
		cout << "Expected Answer: True" << endl;
		if (!runList(wordList, table)) {
			passedAll = false;
			failedTests++;
			cout << "Test failed." << endl;
			cout << "Got: False" << endl;
		}
		else
			cout << "Test Passed." << endl;
		cout << endl;


		cout << "Running Test 4: " << endl;
		wordList = { "The", "cat", "noisily", "EOI" };
		cout << "Sentence:";
		printSentence(wordList);
		cout << "Expected Answer: False" << endl;
		if (runList(wordList, table)) {
			passedAll = false;
			failedTests++;
			cout << "Test failed." << endl;
			cout << "Got: True" << endl;
		}
		else
			cout << "Test Passed." << endl;
		cout << endl;

		cout << "Running Test 5: " << endl;
		wordList = { "Smelly", "dog", "ran", "slowly", "EOI" };
		cout << "Sentence:";
		printSentence(wordList);
		cout << "Expected Answer: False" << endl;
		if (runList(wordList, table)) {
			passedAll = false;
			failedTests++;
			cout << "Test failed." << endl;
			cout << "Got: True" << endl;
		}
		else
			cout << "Test Passed." << endl;
		cout << endl;

		cout << "Running Test 6: " << endl;
		wordList = { "The", "cat", "dog", "ran", "EOI" };
		cout << "Sentence:";
		printSentence(wordList);
		cout << "Expected Answer: False" << endl;
		if (runList(wordList, table)) {
			passedAll = false;
			failedTests++;
			cout << "Test failed." << endl;
			cout << "Got: True" << endl;
		}
		else
			cout << "Test Passed." << endl;
		cout << endl;

		cout << failedTests << " failed" << endl;
		cout << 6 - failedTests << " passed" << endl;
		return passedAll;
	}

};