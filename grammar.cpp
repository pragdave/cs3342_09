#include <vector>
#include <iostream>

static bool interpreter(std::vector<std::string> sentence) {
	bool isValid = true;
	int node = 0;
	int curr = 0;
	while (curr < sentence.size()) {
		if (node == 0 && sentence[curr] == "the") {
			node = 1;
			curr++;
		}
		else if (node == 1 && (sentence[curr] == "lazy" || sentence[curr] == "smelly")) {
			node = 3;
			curr++;
		}
		else if (node == 1 && (sentence[curr] == "dog" || sentence[curr] == "cat")) {
			node = 2;
			curr++;
		}
		else if (node == 3 && (sentence[curr] == "lazy" || sentence[curr] == "smelly")) {
			curr++;
		}
		else if (node == 3 && (sentence[curr] == "dog" || sentence[curr] == "cat")) {
			node = 2;
			curr++;
		}
		else if (node == 2 && (sentence[curr] == "ate" || sentence[curr] == "ran")) {
			node = 4;
			curr++;
		}
		else if (node == 4 && (sentence[curr] == "slowly" || sentence[curr] == "noisily")) {
			node = 5;
			curr++;
		}
		else if (node == 4 && (sentence[curr] == "EOI")) {
			return true;
		}
		else if (node == 5 && sentence[curr] == "EOI") {
			return true;
		}
		else { return false; }

	}
	isValid = false;
	return isValid;

}



int main() {
	//check passing
	std::vector<std::string> shouldPass1 = { "the", "cat", "ate", "EOI" };
	std::vector<std::string> shouldPass2 = { "the", "lazy", "dog", "ate", "EOI" };
	std::vector<std::string> shouldPass3 = { "the", "cat", "ran", "noisily", "EOI" };
	std::vector<std::string> shouldPass4 = { "the", "lazy", "smelly", "lazy", "smelly", "cat", "ate", "EOI" };
	bool isValid = interpreter(shouldPass1);
	if (isValid) {
		std::cout << "good 1" << std::endl;
	}
	else {
		std::cout << "fail 1" << std::endl;
	}

	isValid = interpreter(shouldPass2);
	if (isValid) {
		std::cout << "good 2" << std::endl;
	}
	else {
		std::cout << "fail 2" << std::endl;
	}

	isValid = interpreter(shouldPass3);
	if (isValid) {
		std::cout << "good 3" << std::endl;
	}
	else {
		std::cout << "fail 3" << std::endl;
	}

	isValid = interpreter(shouldPass4);
	if (isValid) {
		std::cout << "good 4" << std::endl;
	}
	else {
		std::cout << "fail 4" << std::endl;
	}


	//check failing
	std::vector<std::string> shouldFail1 = { "the", "ate", "EOI" };
	std::vector<std::string> shouldFail2 = { "the", "lazy", "dog", "cat", "ate", "EOI" };
	std::vector<std::string> shouldFail3 = { "the", "cat", "ran", "noisily" };
	std::vector<std::string> shouldFail4 = { "the", "lazy", "EOI" };
	std::vector<std::string> shouldFail5 = { "the", "EOI" };
	std::vector<std::string> shouldFail6 = { "lazy", "dog", "cat", "ate", "EOI" };
	std::vector<std::string> shouldFail7 = { "the", "cat", "ran", "slowly", "noisily" };
	std::vector<std::string> shouldFail8 = { "the", "lazy", "slowly", "EOI" };

	isValid = interpreter(shouldFail1);
	if (!isValid) {
		std::cout << "good 1" << std::endl;
	}
	else {
		std::cout << "fail 1" << std::endl;
	}

	isValid = interpreter(shouldFail2);
	if (!isValid) {
		std::cout << "good 2" << std::endl;
	}
	else {
		std::cout << "fail 2" << std::endl;
	}

	isValid = interpreter(shouldFail3);
	if (!isValid) {
		std::cout << "good 3" << std::endl;
	}
	else {
		std::cout << "fail 3" << std::endl;
	}

	isValid = interpreter(shouldFail4);
	if (!isValid) {
		std::cout << "good 4" << std::endl;
	}
	else {
		std::cout << "fail 4" << std::endl;
	}
	isValid = interpreter(shouldFail5);
	if (!isValid) {
		std::cout << "good 1" << std::endl;
	}
	else {
		std::cout << "fail 1" << std::endl;
	}

	isValid = interpreter(shouldFail6);
	if (!isValid) {
		std::cout << "good 2" << std::endl;
	}
	else {
		std::cout << "fail 2" << std::endl;
	}

	isValid = interpreter(shouldFail7);
	if (!isValid) {
		std::cout << "good 3" << std::endl;
	}
	else {
		std::cout << "fail 3" << std::endl;
	}

	isValid = interpreter(shouldFail8);
	if (!isValid) {
		std::cout << "good 4" << std::endl;
	}
	else {
		std::cout << "fail 4" << std::endl;
	}


	return 0;
}