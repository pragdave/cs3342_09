//grammar_Ans.cpp
#define CATCH_CONFIG_MAIN
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "catch.hpp"
using namespace std;

int NextState(int currentState, string nextWord, map<int, map<string, int>> statesTable){
  map<string, int> transitions = statesTable[currentState];
  if (transitions.count(nextWord))
    return transitions[nextWord];
  else
    return -1;
}

bool trySentence(vector<string> words){
  map<int, map<string, int>> states = {
    {0, {{"the", 1}}},
    {1, {{"smelly", 2}, {"lazy", 2}, {"dog", 3}, {"cat", 3}}},
    {2, {{"smelly", 2}, {"lazy", 2}, {"dog", 3}, {"cat", 3}}},
    {3, {{"ate", 4}, {"ran", 4}}},
    {4, {{"slowly", 5}, {"noisily", 5},{"EOI", 99}}},
    {5, {{"EOI", 99}}}
  };
  int current;
  if (words[0]=="the")
    current = 0;
  else
    return false;
  while (current != words.size()){
    if (current == -1)
      return false;
    else
      current = NextState(current, words[current+1], states);
  }
  return true;
}

//Testing
TEST_CASE( "Sentences fit grammar", "[vector]" ) {
    vector<string> v1;
        v1.push_back("the");
        v1.push_back("cat");
        v1.push_back("ate");
        v1.push_back("noisily");
        v1.push_back("EOI");

    vector<string> v2;
        v2.push_back("the");
        v2.push_back("bird");
        v2.push_back("ate");
        v2.push_back("slowly");
        v2.push_back("EOI");

    vector<string> v3;
        v3.push_back("the");
        v3.push_back("lazy");
        v3.push_back("dog");
        v3.push_back("ate");
        v3.push_back("EOI");

    vector<string> v4;
        v4.push_back("the");
        v4.push_back("lazy");
        v4.push_back("dog");
        v4.push_back("ate");

    vector<string> v5;
        v5.push_back("the");
        v5.push_back("lazy");
        v5.push_back("ate");
        v5.push_back("slowly");
        v5.push_back("EOI");

    vector<string> v6;
        v6.push_back("the");
        v6.push_back("lazy");
        v6.push_back("smelly");
        v6.push_back("smelly");
        v6.push_back("dog");
        v6.push_back("ate");
        v6.push_back("EOI");

    vector<string> v7;
        v7.push_back("the");
        v7.push_back("lazy");
        v7.push_back("smelly");
        v7.push_back("smelly");
        v7.push_back("dog");
        v7.push_back("ate");
        v7.push_back("EOI");

    vector<string> v8;
        v8.push_back("lazy");
        v8.push_back("smelly");
        v8.push_back("smelly");
        v8.push_back("dog");
        v8.push_back("ate");
        v8.push_back("EOI");

    vector<string> v9;
        v9.push_back("");

    vector<string> v10;
        v10.push_back("the");
        v10.push_back("smelly");
        v10.push_back("smelly");
        v10.push_back("smelly");
        v10.push_back("dog");
        v10.push_back("ate");
        v10.push_back("EOI");

    vector<string> v11;
        v11.push_back("the");
        v11.push_back("lazy");
        v11.push_back("smelly");
        v11.push_back("cat");
        v11.push_back("ate");
        v11.push_back("EOI");

    vector<string> v12;
        v12.push_back("the");
        v12.push_back("smelly");
        v12.push_back("lazy");
        v12.push_back("cat");
        v12.push_back("ate");
        v12.push_back("EOI");

    vector<string> v13;
        v13.push_back("the");
        v13.push_back("dog");
        v13.push_back("ran");
        v13.push_back("slowly");
        v13.push_back("EOI");

    vector<string> v14;
        v14.push_back("the");
        v14.push_back("lazy");
        v14.push_back("dog");
        v14.push_back("ran");
        v14.push_back("slowly");
        v14.push_back("EOI");

    vector<string> v15;
        v15.push_back("the");
        v15.push_back("smelly");
        v15.push_back("cat");
        v15.push_back("ate");
        v15.push_back("slowly");
        v15.push_back("EOI");

    vector<string> v16;
        v16.push_back("the");
        v16.push_back("smelly");
        v16.push_back("dog");
        v16.push_back("ate");
        v16.push_back("noisily");
        v16.push_back("EOI");

    vector<string> v17;
        v17.push_back("the");
        v17.push_back("smelly");
        v17.push_back("ate");
        v17.push_back("noisily");
        v17.push_back("EOI");

    vector<string> v18;
        v18.push_back("the");
        v18.push_back("smelly");
        v18.push_back("dog");
        v18.push_back("ate");
        v18.push_back("EOI");

    vector<string> v19;
        v19.push_back("the");
        v19.push_back("lazy");
        v19.push_back("cat");
        v19.push_back("ran");
        v19.push_back("EOI");

    vector<string> v20;
        v20.push_back("the");
        v20.push_back("smelly");
        v20.push_back("cat");
        v20.push_back("ran");
        v20.push_back("EOI");

    vector<string> v21;
        v21.push_back("the");
        v21.push_back("dog");
        v21.push_back("ate");
        v21.push_back("slowly");
        v21.push_back("EOI");

    vector<string> v22;
        v22.push_back("the");
        v22.push_back("cat");
        v22.push_back("ran");
        v22.push_back("noisily");
        v22.push_back("EOI");

    vector<string> v23;
        v23.push_back("the");
        v23.push_back("lazy")
        v23.push_back("dog");
        v23.push_back("ate");
        v23.push_back("noisily");
        v23.push_back("EOI");

    vector<string> v24;
        v24.push_back("the");
        v24.push_back("lazy");
        v24.push_back("cat");
        v24.push_back("ate");
        v24.push_back("noisily");
        v24.push_back("EOI");

    vector<string> v25;
        v25.push_back("the");
        v25.push_back("lazy");
        v25.push_back("cat");
        v25.push_back("ate");
        v25.push_back("slowly");
        v25.push_back("EOI");

    vector<string> v26;
        v26.push_back("lazy");
        v26.push_back("cat");
        v26.push_back("ate");
        v26.push_back("slowly");
        v26.push_back("EOI");

    vector<string> v27;
        v27.push_back("cat");
        v27.push_back("ate");
        v27.push_back("EOI");

    vector<string> v28;
        v28.push_back("the");
        v28.push_back("smelly");
        v28.push_back("ate");
        v28.push_back("slowly");
        v28.push_back("EOI");

    vector<string> v29;
        v29.push_back("the");
        v29.push_back("lazzy");
        v29.push_back("cat");
        v29.push_back("ate");
        v29.push_back("slowly");
        v29.push_back("EOI");

    vector<string> v30;
        v30.push_back("the");
        v30.push_back("lazy");
        v30.push_back("catt");
        v30.push_back("ate");
        v30.push_back("slowly");
        v30.push_back("EOI");

    vector<string> v31;
        v31.push_back("the");
        v31.push_back("lazy");
        v31.push_back("cat");
        v31.push_back("ate");
        v31.push_back("slowly");

    vector<string> v32;
        v32.push_back("the");
        v32.push_back("lazy");
        v32.push_back("lazy");
        v32.push_back("cat");
        v32.push_back("ate");
        v32.push_back("slowly");
        v32.push_back("EOI");

    vector<string> v33;
        v33.push_back("the");
        v33.push_back("cat");
        v33.push_back("ate");
        v33.push_back("lazy");
        v33.push_back("slowly");
        v33.push_back("EOI");

    vector<string> v34;
        v34.push_back("the");
        v34.push_back("noisily");
        v34.push_back("smelly");
        v34.push_back("cat");
        v34.push_back("ate");
        v34.push_back("EOI");

    vector<string> v35;
        v35.push_back("the");
        v35.push_back("cat");
        v35.push_back("ate");
        v35.push_back("slowly");
        v35.push_back("lazy")
        v35.push_back("EOI");

    SECTION("Function handles basic sentences with adjectives"){
      REQUIRE( trySentence(v3) == true );
      REQUIRE( trySentence(v18) == true );
      REQUIRE( trySentence(v19) == true );
      REQUIRE( trySentence(v20) == true );
    }
    SECTION("Function handles basic sentences with adverbs"){
      REQUIRE( trySentence(v1) == true );
      REQUIRE( trySentence(v13) == true );
      REQUIRE( trySentence(v21) == true );
      REQUIRE( trySentence(v22) == true );
    }
    SECTION("Function handles basic sentences with adverbs and adjectives"){
      REQUIRE( trySentence(v14) == true );
      REQUIRE( trySentence(v15) == true );
      REQUIRE( trySentence(v16) == true );
      REQUIRE( trySentence(v24) == true );
      REQUIRE( trySentence(v25) == true );
    }
    SECTION("Function allows multiple adjectives"){
      REQUIRE( trySentence(v11) == true );
      REQUIRE( trySentence(v12) == true );
    }
    SECTION("Function allows repeating adjectives"){
      REQUIRE( trySentence(v7) == true );
      REQUIRE( trySentence(v6) == true );
      REQUIRE( trySentence(v10) == true );
      REQUIRE( trySentence(v32) == true );
    }
    SECTION("Function fails without noun"){
      REQUIRE( trySentence(v5) == false );
      REQUIRE( trySentence(v17) == false );
      REQUIRE( trySentence(v28) == false );
    }
    SECTION("Function fails without 'the' as first word"){
      REQUIRE( trySentence(v8) == false );
      REQUIRE( trySentence(v27) == false );
      REQUIRE( trySentence(v26) == false );
    }
    SECTION("Function fails with unrecognized word"){
      REQUIRE( trySentence(v2) == false );
      REQUIRE( trySentence(v29) == false );
      REQUIRE( trySentence(v30) == false );
    }
    SECTION("Function fails without ending EOI"){
      REQUIRE( trySentence(v4) == false );
      REQUIRE( trySentence(v31) == false );
    }
    SECTION("Function fails with empty words vector"){
      REQUIRE( trySentence(v9) == false );
    }
    SECTION("Function fails with words out of order"){
      REQUIRE( trySentence(v33) == false );
      REQUIRE( trySentence(v34) == false );
      REQUIRE( trySentence(v35) == false );
    }
}
