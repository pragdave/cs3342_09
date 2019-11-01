# Answer for Q2.5

adjectives 	= ['lazy', 'smelly']
nouns 			= ['dog', 'cat']
verbs 			= ['ran', 'ate']
adverbs 		= ['slowly', 'noisily']

def S0(sentence):
  if sentence[0].lower() != 'the':
    return False

  return S1(sentence, 1)

#Adjective state
def S1(sentence, index):
  for i in range(index, index + 3):
    if sentence[i] in nouns:
      return S2(sentence, i)
    if sentence[i] not in adjectives:
      break
  return False

    
def S2(sentence, index):
  if sentence[index] in nouns:
    return S3(sentence, index + 1)
  return False

#Verb state
def S3(sentence, index):
  if sentence[index] in verbs:
    return S4(sentence, index + 1)
  return False


def S4(sentence, index):
  if sentence[index] in adverbs:
    if sentence[index + 1] == 'EOI':
      return True
  elif sentence[index] == 'EOI':
    return True
  return False


import unittest

class TestRunner(unittest.TestCase):
  def test_parser(self):
    self.assertTrue(S0(['the', 'lazy', 'dog', 'ran', 'slowly', 'EOI']), 'Incorrect')
    self.assertFalse(S0(['the', 'fun', 'cat', 'ate', 'EOI']), 'Incorrect')
    self.assertFalse(S0(['dog', 'ate', 'EOI']), 'Incorrect')
    self.assertTrue(S0(['the', 'lazy', 'smelly', 'dog', 'ate', 'noisily', 'EOI']), 'Incorrect')

unittest.main()