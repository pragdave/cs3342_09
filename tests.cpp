#include "tests.h"
#include <cassert>
using namespace std;
void tests::runTests() {
	vector<string> words;
	bool result;
	//minimum valid string
	words = { "the", "dog", "ate", "EOI" };
	this->stateMachine.resetStateAndPlace();
	result = this->stateMachine.runStateMachine(words);
	assert(result == true);

	//medium valid string
	words = { "the", "lazy", "smelly", "cat", "ran", "noisily", "EOI" };
	this->stateMachine.resetStateAndPlace();
	result = this->stateMachine.runStateMachine(words);
	assert(result == true);

	//very long valid string
	words = { "the", "lazy", "smelly", "lazy", "smelly", "lazy", "smelly", "lazy", "smelly", "cat", "ran", "noisily", "EOI" };
	this->stateMachine.resetStateAndPlace();
	result = this->stateMachine.runStateMachine(words);
	assert(result == true);

	//empty invalid string
	words = {};
	this->stateMachine.resetStateAndPlace();
	result = this->stateMachine.runStateMachine(words);
	assert(result == false);
	
	//invalid string
	words = {"this", "is", "an", "invalid", "string"};
	this->stateMachine.resetStateAndPlace();
	result = this->stateMachine.runStateMachine(words);
	assert(result == false);

	//valid string with no EOI
	words = { "the", "lazy", "smelly", "cat", "ran", "noisily" };
	this->stateMachine.resetStateAndPlace();
	result = this->stateMachine.runStateMachine(words);
	assert(result == false);
}