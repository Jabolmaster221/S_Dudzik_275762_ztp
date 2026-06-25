#include "tokenizer.hpp"

namespace nlp {

	std::vector<std::string> tokenize(const std::string& input, const std::string& separators, bool keep_separators) {
		std::vector<std::string> tokens;
		size_t start = 0;
		size_t end = 0;

		while ((end = input.find_first_of(separators, start)) != std::string::npos) {
			if (end != start) {
				tokens.push_back(input.substr(start, end - start));
			}

			if (keep_separators) {
				tokens.push_back(input.substr(end, 1));
			}

			start = end + 1;
		}

		if (start < input.length()) {
			tokens.push_back(input.substr(start));
		}

		return tokens;
	}

}
