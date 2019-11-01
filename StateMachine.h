#include <vector>
#include <string>
using namespace std;
class StateMachine{
public:
	int state;
	int place;
	bool runStateMachine(vector<string> words);
	void resetStateAndPlace();
};

