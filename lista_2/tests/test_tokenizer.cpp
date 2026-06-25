#include <catch2/catch_test_macros.hpp>
#include "C:\Users\sebci\CLionProjects\Dudzik_275762_ztp\testy\src\tokenizer.hpp"

TEST_CASE("Podział prostego zdania na słowa", "[tokenizer]") {
	auto tokens = nlp::tokenize("Ala ma kota", " ");
	std::vector<std::string> expected = {"Ala", "ma", "kota"};
	REQUIRE(tokens == expected);
}

TEST_CASE("Podział napisu z wieloma separatorami", "[tokenizer]") {
	auto tokens = nlp::tokenize("Jeden,dwa;trzy kropka.koniec", " ,;.");
	std::vector<std::string> expected = {"Jeden", "dwa", "trzy", "kropka", "koniec"};
	REQUIRE(tokens == expected);
}

TEST_CASE("Podział napisu zaczynającego się/kończącego separatorem", "[tokenizer]") {
	auto tokens = nlp::tokenize("  test spacji   ", " ");
	std::vector<std::string> expected = {"test", "spacji"};
	REQUIRE(tokens == expected);
}

TEST_CASE("Obsługa pustego napisu", "[tokenizer]") {
	auto tokens = nlp::tokenize("", " ");
	REQUIRE(tokens.empty());
}

TEST_CASE("Obsługa napisu z Unicode", "[tokenizer]") {
	auto tokens = nlp::tokenize("Zażółć gęślą jaźń", " ");
	std::vector<std::string> expected = {"Zażółć", "gęślą", "jaźń"};
	REQUIRE(tokens == expected);
}

TEST_CASE("Sprawdzenie poprawności zwróconych tokenów w trybie zachowania separatorów", "[tokenizer]") {
	auto tokens = nlp::tokenize("A,B,,C", ",", true);
	std::vector<std::string> expected = {"A", ",", "B", ",", ",", "C"};
	REQUIRE(tokens == expected);
}