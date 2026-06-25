#include <iostream>
#include "tokenizer.hpp"

void print_tokens(const std::vector<std::string>& tokens) {
	std::cout << "[";
	for (size_t i = 0; i < tokens.size(); ++i) {
		std::cout << "\"" << tokens[i] << "\"";
		if (i < tokens.size() - 1) std::cout << ", ";
	}
	std::cout << "]\n";
}

int main() {
	std::string text = "Witaj świecie! To jest, krótki test - zażółć gęślą jaźń.";
	std::string separators = " ,.!-";

	std::cout << "Tekst oryginalny: " << text << "\n";
	std::cout << "Separatory: '" << separators << "'\n\n";

	std::cout << "1. Standardowy podział (pomijanie separatorów):\n";
	auto tokens_normal = nlp::tokenize(text, separators);
	print_tokens(tokens_normal);

	std::cout << "\n2. Podział z zachowaniem separatorów:\n";
	auto tokens_keep = nlp::tokenize(text, separators, true);
	print_tokens(tokens_keep);

	return 0;
}