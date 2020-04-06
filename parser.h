#ifndef INC_20S_PA02_HLAMBSON_PARSER_H
#define INC_20S_PA02_HLAMBSON_PARSER_H
#include <map>
#include <vector>
using namespace std;
class parser {
private:
    map<pair<int,string>, int> machine;
public:
    parser();
    bool check(vector<string>);
};


#endif //INC_20S_PA02_HLAMBSON_PARSER_H
