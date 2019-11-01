
string[] column1 = ["S0", "S1", "S1", "S1", "S1", "S2", "S2", "S2", "S2", "S3", "S3", "S4", "S4", "S4", "S5"]
string[] column2 = ["the", "smelly", "lazy", "dog", "cat", "dog", "cat", "smelly", "lazy", "ate", "ran", "slowly", "noisily", "EOI", "EOI"]
string[] column3 = ["S1", "S2", "S2", "S3", "S3", "S3", "S3", "S2", "S2", "S4", "S4", "S5", "S5", "END", "END"]

string [][] stateTable;
stateTable = createAndPrintTable( column1, column2, column3 );
int stateTableLen = column1.len;

string[][] createAndPrintTable( string[] s1, string[] s2, string[] s3 ){
    string[length-1][2] table;
    int i;
    int j;

    table[0][0] = "Current State";
    table[0][1] = "Next Word";
    table[0][2] = "Next State";

    for( i = 0; i < 3; i++ ){
        for ( j = 0; j < stateTableLen; j++ ){
            table[j][i] =  s1[j];
        }
    }
    for( i = 0; i < 3; i++ ){
        for ( j = 0; j < stateTableLen; j++ ){
            table[j][i] =  s2[j];
        }
    }
    for( i = 0; i < 3; i++ ){
        for ( j = 0; j < stateTableLen; j++ ){
            table[j][i] =  s3[j];
        }
    }

    for( i = 0; i < 3; i++ ){
        for( j = 0; j < stateTableLen; j++ ){
            print( table[j][i] );
            print( "   |   " );
        }
    }

    return table; 
}

boolean sentenceChecker( string[] s0 ) {
    int i;
    int j;
    int length = s0.len;
    string word1;
    string word2;
    string nextWord;
    string state;
    int row; 
    int nextRow;

    for( i = 0; i < stateTableLen; i++ ){
        word1 = string[0];
        word2 = stateTable[i][2];
        if( word1 == word2 ){
            state = stateTable[i][3];
            row = i;
            nextWord = string[1];
            nextRow = checkNextState( nextWord, state, row );
        } 
    } 

    if ( nextRow == -1 ){
        return false;
    } 

    for( i = 1; i < length; i++ ){
        nextWord = string[i+1];
        state = stateTable[nextRow][3];
        row = nextRow;
        nextRow = checkNextState( nextWord, state, row );
        if ( nextRow == -1 ){
            return false;
        } 
    }
    
    return true;
}

int checkNextState( string nextWord, string nextState, int currentRow ){
    for( int i = 0; i < stateTableLen; i++ ){
        if( nextState == stateTable[i][1] ){
            if( nextWord == stateTable[i][2]){
                return i;
            }
        }
    }
    return -1;
}