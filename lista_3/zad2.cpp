#include <iostream>

struct Empty {};

struct Normal {
	void func1() {}
	void func2() {}
};

struct VirtualOne {
	virtual void func1() {}
};

struct VirtualMany {
	virtual void func1() {}
	virtual void func2() {}
	virtual void func3() {}
};

struct DerivedVirtual : public VirtualOne {
	void func1() override {}
};

int main() {
	std::cout << "--- Zadanie 2: Koszt pamieciowy funkcji wirtualnych ---\n";
	std::cout << "Rozmiar Empty: " << sizeof(Empty) << " bajt(y)\n";
	std::cout << "Rozmiar Normal: " << sizeof(Normal) << " bajt(y)\n";
	std::cout << "Rozmiar VirtualOne: " << sizeof(VirtualOne) << " bajtow\n";
	std::cout << "Rozmiar VirtualMany: " << sizeof(VirtualMany) << " bajtow\n";
	std::cout << "Rozmiar DerivedVirtual: " << sizeof(DerivedVirtual) << " bajtow\n";
	return 0;
}