#include <iostream>
#include <memory>
#include <vector>

// Klasa bazowa
class Bird {
public:
	virtual ~Bird() = default;

	// Funkcja wirtualna
	virtual void makeSound() const {
		std::cout << "Some generic bird sound\n";
	}
};

// Klasa pochodna 1
class Duck : public Bird {
public:
	void makeSound() const override {
		std::cout << "Quack quack!\n";
	}
};

// Klasa pochodna 2
class Owl : public Bird {
public:
	void makeSound() const override {
		std::cout << "Hoot hoot!\n";
	}
};

int main() {
	std::cout << "--- Zadanie 1: Funkcje wirtualne i LSP ---\n";

	std::vector<std::unique_ptr<Bird>> birds;
	birds.push_back(std::make_unique<Duck>());
	birds.push_back(std::make_unique<Owl>());

	for (const auto& bird : birds) {
		bird->makeSound();
	}

	return 0;
}