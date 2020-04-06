def checkSentence(s):
    # check for period
    if s.find('.'):
        # get rid of the period first
        s = s.replace('.', '')
        # split the sentence up into words
        words = s.split()
        words.append('.')
    else:
        return False

    # use state to keep track of the current state
    state = 0
    end = False
    # check each word and see if we can move on to the next state
    for w in words:
        w = w.lower()
        # state 0
        if state == 0:
            if w == 'the':
                state += 1
            else:
                return False
        elif state == 1:
            if w == 'smelly' or w == 'lazy':
                continue
            elif w == 'cat' or w == 'dog':
                state = 2
            else:
                return False
        elif state == 2:
            if w == 'ran' or w == 'ate':
                state += 1
            else:
                return False
        elif state == 3:
            if w == 'slowly' or w == 'noisily':
                continue
            elif w == '.':
                end = True
            else:
                return False
    return end


def testSentence():
    assert (checkSentence('The smelly dog ran.'))
    assert (checkSentence('The smelly dog ran slowly.'))
    assert (checkSentence('The cat ate noisily.'))
    assert (checkSentence('The lazy smelly dog ran slowly.'))
    assert (checkSentence('The smelly cat dog ran.') is False)
    assert (checkSentence('The smelly dog ate ran.') is False)
    assert (checkSentence('The smelly dog ran slowly noisily.'))


def main():
    testSentence()


if __name__ == '__main__':
    main()
