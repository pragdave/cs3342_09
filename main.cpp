#include <vector>
#include <string>
#include <iostream>
#include "FSM.h";
using namespace std;


int main() {
	//creates the FSM table
	vector<string> currentState = { "S0", "S1", "S1", "S1", "S1", "S2", "S2", "S3", "S3", "S3", "S3", "S4" };
	vector<string> nextWord = { "The", "lazy",	"smelly", "dog", "cat",	"ate", "ran", "slowly",	"noisily", "EOI", "EOI" };
	vector<string> nextState = { "S1",	"S1", "S1",	"S2", "S2",	"S3", "S3",	"S4", "S4",	"END", "END" };
	
	vector<vector<string>> table;
	table.push_back(currentState);
	table.push_back(nextWord);
	table.push_back(nextState);

	//creates instance of FSM class and runsUnitTests with the given table
	FSM state_machine;
	state_machine.runUnitTests(table);
	return 0;
}