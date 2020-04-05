#include <iostream>
#include <vector>
#include <string>

using namespace std;
class parser{
public:
    parser();
    bool nounCheck(string);
    bool verbCheck(string);
    bool adjCheck(string);
    bool advCheck(string);
    bool FSManalyze(vector<string> vec);
};