# Zmienne
CXX = g++
CXXFLAGS = -Ilib/hello -Wall
BIN_DIR = build_manual

# Pliki końcowe
TARGETS = $(BIN_DIR)/prog1

all: $(TARGETS)

# Reguła tworzenia folderów
$(BIN_DIR):
	mkdir  $@

# Kompilacja biblioteki hello
$(BIN_DIR)/hello.o: lib/hello/hello.cpp lib/hello/hello.h | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c lib/hello/hello.cpp -o $@

# Reguły dla prog1
$(BIN_DIR)/main1.o: src/prog1/main.cpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c src/prog1/main.cpp -o $@

$(BIN_DIR)/prog1: $(BIN_DIR)/main1.o $(BIN_DIR)/hello.o | $(BIN_DIR)
	$(CXX) $^ -o $@

# Plik prog2 nie został wygenerowany przez potrzebę użycia cmake (ze względu na FetchContent)

clean:
	rm -rf $(BIN_DIR)

.PHONY: all clean