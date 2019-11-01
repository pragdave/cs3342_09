#include "StateMachine.h"

void StateMachine::resetStateAndPlace() {
	this->state = 0;
	this->place = 0;
}
bool StateMachine::runStateMachine(vector<string> words) {
	if (words.empty() || place > words.size()-1) { //guard against out of bounds errors
		return false;
	}

	switch (this->state) {
	case 0:
		if (words[place] == "the") {
			place++;
			this->state = 1;
			return runStateMachine(words);
		}
	case 1:
		if (words[place] == "lazy" || words[place] == "smelly") {
			place++;
			this->state = 1;
			return runStateMachine(words);
		}
		else if (words[place] == "dog" || words[place] == "cat") {
			place++;
			this->state = 2;
			return runStateMachine(words);
		}
	case 2:
		if (words[place] == "ate" || words[place] == "ran") {
			place++;
			this->state = 3;
			return runStateMachine(words);
		}
	case 3:
		if (words[place] == "noisily" || words[place] == "slowly") {
			place++;
			this->state = 4;
			return runStateMachine(words);
		}
		else if (words[place] == "EOI") {
			return true;
		}
	case 4:
		if (words[place] == "EOI") {
			return true;
		}
	}
	return false;
}