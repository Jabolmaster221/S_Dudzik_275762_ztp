#pragma once

#include <string>
#include <vector>

namespace nlp {

	std::vector<std::string> tokenize(
		const std::string& input,
		const std::string& separators = " \t\n\r",
		bool keep_separators = false
	);

}