#include <iostream>
using namespace std;

bool isStartOfInput(string input) {
	return input == "the";
}
bool isValidNoun(string noun) {
	return noun == "cat" || noun == "dog";
}
bool isValidAdjective(string adj) {
	return adj == "lazy" || adj == "smelly";
}
bool isValidVerb(string verb) {
	return verb == "ate" || verb == "ran";
}
bool isValidAdverb(string adverb) {
	return adverb == "slowly" || adverb == "noisily";
}
bool isEndOfInput(string input) {
	return input == "EOI";
}

int getNextState(int currentState, string nextWord) {
	int nextState = 0;
	switch (currentState) {
		case 0:
			nextState = isStartOfInput(nextWord) ? 1 : -1;
			break;
		case 1:
			if (isValidAdjective(nextWord)) {
				nextState = 2;
			} else if (isValidNoun(nextWord)) {
				nextState = 3;
			} else {
				nextState = -1;
			}
			break;
		case 2:
			if (isValidAdjective(nextWord)) {
				nextState = 2;
			} else if (isValidNoun(nextWord)) {
				nextState = 3;
			} else {
				nextState = -1;
			}
			break;
		case 3:
			nextState = isValidVerb(nextWord) ? 4 : -1;
			break;
		case 4:
			if (isValidAdverb(nextWord)) {
				nextState = 5;
			} else if (isEndOfInput(nextWord)) {
				nextState = 6;
			} else {
				nextState = -1;
			}
			break;
		case 5:
			nextState = isEndOfInput(nextWord) ? 6 : -1;
			break;
		default:
			nextState = -1;
			break;
	}
	return nextState;
}

bool compareToStateMachine(string wordList[], int numWords) {
	int state = 0;
	for (int i = 0; i < numWords; i++) {
		state = getNextState(state, wordList[i]);
		if (state == -1) {
			return false;
		}
	}
	return state == 6;
}

void runTest(string wordList[], int numWords) {
	bool valid = compareToStateMachine(wordList, numWords);
	for (int i = 0; i < numWords; i++) {
		if (i == 0) {
			cout << "\"";
		}
		cout << wordList[i];
		if (i == numWords - 1) {
			cout << "\" ";
		} else {
			cout << " ";
		}
	}
	if (valid) {
		cout << "is a valid sentence" << endl;
	} else {
		cout << "is an invalid sentence" << endl;
	}
}

int main () {
	string sentences[6][10] = {
		{"the", "smelly", "dog", "ran", "EOI"},
		{"the", "dog", "ran", "EOI"},
		{"the", "dog", "ran", "smelly", "EOI"},
		{"dog", "ran", "EOI"},
		{"the", "lazy", "smelly", "cat", "ate", "noisily", "EOI"},
		{"the", "lazy", "smelly", "cat", "noisily", "ate", "EOI"},
	};
	int lengths[] = {5, 4, 5, 3, 7, 7};
	for (int i = 0; i < 6; i++) {
		runTest(sentences[i], lengths[i]);
	}
	
	return 0;
}