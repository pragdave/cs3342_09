# Name: John Park
# ID:   446 88 167

table = {}
#   state  word    next possible states
table[(0, 'the'    )] = [1, 2]
table[(1, 'lazy'   )] = [1, 2]
table[(1, 'smelly' )] = [1, 2]
table[(2, 'dog'    )] = [3]
table[(2, 'cat'    )] = [3]
table[(3, 'ate'    )] = [4]
table[(3, 'ran'    )] = [4]
table[(4, 'slowly' )] = [5]
table[(4, 'noisily')] = [5]
table[(4, 'EOI'    )] = ['END']
table[(5, 'EOI'    )] = ['END']

def isValid(sentence):
    state = 0
    words = sentence.split(' ')
    for index, word in enumerate(words):
        try:
            # reached END with valid input
            if table[(state, word)][0]=='END' and (state==4 or state==5): 
                return True
            
            # reached end of sentence without reaching END
            elif word==words[-1]: 
                return False
            
            # move to next state
            else:
                next = table[(state, word)]
                if len(next)==1: state = next[0]
                else:
                    if words[index + 1]=='dog' or words[index + 1]=='cat': 
                        state = next[1]
                    else: 
                        state = next[0]

        # invalid state and word input
        except:
            return False

def test():
    assert(isValid('the lazy smelly dog ate slowly EOI' ))
    assert(isValid('the smelly lazy smelly cat ran EOI' ))
    assert(isValid('the smelly dog ate noisily EOI'     ))
    assert(isValid('the lazy cat ran noisily EOI'       ))
    assert(isValid('the lazy smelly cat ran EOI'        ))
    assert(isValid('the lazy dog ate slowly EOI'        ))
    assert(isValid('the cat ran EOI'                    ))
    assert(isValid('the dog ate EOI'                    ))
    assert(isValid('the lazy lazy smelly dog ran')==False)
    assert(isValid('the smelly cat ran noisily'  )==False)
    assert(isValid('the cat ate ate EOI'         )==False)
    assert(isValid('the ate slowly EOI'          )==False)
    assert(isValid('dog ate EOI'                 )==False)
    assert(isValid('cat ran'                     )==False)
    assert(isValid('the EOI'                     )==False)
    assert(isValid('the'                         )==False)
    assert(isValid('EOI'                         )==False)
    assert(isValid(''                            )==False)
    print('All tests passed')

def main():
    test()

if __name__ == '__main__':
    main()