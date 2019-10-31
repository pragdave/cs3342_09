class StateMachine():

    def __init__(self, words):
        self.words = words
        self.adjectives = ["lazy", "smelly"]
        self.nouns = ["dog", "cat"]
        self.verbs = ["ate", "ran"]
        self.adverbs = ["slowly", "noisily"]
        self.result = self.S0()
        print(self.result)

    def get_result(self):
        return self.result

    def S0(self):
        if self.words[0] == "The" or self.words[0] == "the":
            ret = self.S1(1)
            if ret == False or ret == None:
                return False
            else:
                return True
        else:
            return False

    def S1(self, idx):
        for i in range(idx, len(self.words)):
            if self.words[i] in self.adjectives:
                self.adjectives.remove(self.words[i])
                continue
            elif self.words[i] in self.nouns:
                return self.S2(i)
            else:
                return False

    def S2(self, idx):
        for i in range(idx, len(self.words)):
            if self.words[i] in self.nouns:
                self.nouns.remove(self.words[i])
                return self.S3(i + 1)
            else:
                return False

    def S3(self, idx):
        for i in range(idx, len(self.words)):
            if self.words[i] in self.verbs:
                self.verbs.remove(self.words[i])
                return self.S4(i + 1)
            else:
                return False

    def S4(self, idx):
        flag = True
        for i in range(idx, len(self.words)):
            if self.words[i] in self.adverbs and flag:
                self.adverbs.remove(self.words[i])
                flag = False
                continue
            elif self.words[i] == "EOI":
                return True
            else:
                return False


import unittest


class TestRunner(unittest.TestCase):
    def test_state(self):
        self.assertTrue(StateMachine(['the', 'smelly', 'cat', 'ate', 'slowly', 'EOI']).get_result(), 'Incorrect')
        self.assertTrue(StateMachine(['the', 'lazy', 'smelly', 'dog', 'ate', 'noisily', 'EOI']).get_result(), 'Incorrect')
        self.assertTrue(StateMachine(['the', 'dog', 'ate', 'EOI']).get_result(), 'Incorrect')
        self.assertFalse(StateMachine(['the', 'cool', 'cat', 'ate', 'EOI']).get_result(), 'Incorrect')
        self.assertFalse(StateMachine(['the', 'ate']).get_result(), 'Incorrect')
        self.assertFalse(StateMachine(['the', 'smelly', 'cat', 'ate']).get_result(), 'Incorrect')
        self.assertFalse(StateMachine(['the', 'lazy', 'smelly', 'lazy', 'dog', 'ate', 'EOI']).get_result(), 'Incorrect')
        self.assertFalse(StateMachine(['the', 'dog', 'ate', 'slowly', 'noisily', 'EOI']).get_result(), 'Incorrect')


unittest.main()