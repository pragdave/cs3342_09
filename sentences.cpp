#include "iostream"
#include "string"
#include <algorithm>

bool contains (std::string word, std::string array[], int size) {
	for (int i = 0; i < size; i++) {
		if (array[i] == word) {
			return true;
		}
	}
	return false;
};

bool isSentence(std::string sentence[]) {
	std::string nouns[] = {"dog", "cat"};
	std::string verbs[] = {"ate", "ran"};
	std::string adjectives[] = {"lazy", "smelly"};
	std::string adverbs[] = {"slowly", "noisily"};
	if (sentence[0] == "the") { //checking if first word is the
		int i = 1;
		while (contains(sentence[i], adjectives, 2)) { //checking if there is an adjective
			i++;
		}
		if (contains(sentence[i], nouns, 2)) { //checking if word following any adjectives is a nounce
			i++;
			if (contains(sentence[i], nouns, 2)) { //checking if there are two nouns
				return false;
			}
			else {
				if (contains(sentence[i], verbs, 2)) { //checking if there is a verb
					i++;
						if (contains(sentence[i], verbs, 2)) { //checking if there are two verbs
							return false;
						}
						else if (sentence[i] == "EOI") { //check if EOI
							return true;
						}
						else {
							if (contains(sentence[i], adverbs, 2)) {
								i++;
								if (contains(sentence[i], adverbs, 2)) { //checking if there are two adverbs
									return false;
								}
								else if (sentence[i] == "EOI") {
									return true;
								}
							}
						}
				}
				else {
					return false;
				}
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
	return false;
};


int main() {
	std::string sentence[] = {"the", "dog", "ate", "EOI"}; //1
	std::string sentence1[] = {"dog", "ate", "EOI"}; //0
	std::string sentence2[] = {"the", "lazy", "smelly", "dog", "ate", "EOI"}; //1
	std::string sentence3[] = {"the", "lazy", "smelly", "ran", "EOI"}; //0
	std::string sentence4[] = {"the", "lazy", "smelly", "dog", "ran", "slowly", "EOI"}; //1
	std::string sentence5[] = {"the", "lazy", "smelly", "dog", "ate", "slowly", "noisily", "EOI"}; //0
	std::string sentence6[] = {"the", "dog", "ate", "slowly", "EOI"}; //1
	std::string sentence7[] = {"the", "dog", "EOI"}; //0
	std::string sentence8[] = {"the", "dog", "ran", "noisily", "EOI"}; //1
	std::cout << isSentence(sentence) << std::endl;
	std::cout << isSentence(sentence1) << std::endl;
	std::cout << isSentence(sentence2) << std::endl;
	std::cout << isSentence(sentence3) << std::endl;
	std::cout << isSentence(sentence4) << std::endl;
	std::cout << isSentence(sentence5) << std::endl;
	std::cout << isSentence(sentence6) << std::endl;
	std::cout << isSentence(sentence7) << std::endl;
	std::cout << isSentence(sentence8) << std::endl;
};