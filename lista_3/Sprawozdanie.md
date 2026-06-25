# Sprawozdanie: Dziedziczenie i funkcje wirtualne
## Lista 3

### Zadanie 2: Koszty funkcji wirtualnych

**1. Analiza kosztów pamięciowych**
* **Czy istnienie funkcji wirtualnej ma wpływ na rozmiar obiektu?**
  Tak. Rozmiar obiektu powiększa się o ukryty wskaźnik (tzw. `vptr`), który wskazuje na tablicę metod wirtualnych (`vtable`).
* **Czy zależy to od liczby funkcji wirtualnych?**
  Nie. W pamięci danego obiektu zawsze znajduje się wyłącznie jeden wskaźnik `vptr` (zajmujący zwykle 8 bajtów na architekturze 64-bitowej). Liczba funkcji wirtualnych wpływa tylko na rozmiar tablicy `vtable`, a nie samego obiektu.
* **Czy dotyczy to typu bazowego czy pochodnego?**
  Zjawisko to dotyczy obu typów. Klasa pochodna, dziedzicząc z polimorficznej klasy bazowej, również posiada wskaźnik `vptr` (który wskazuje na jej własną implementację tablicy `vtable`).
* **Czy jest jakiś dodatkowy "koszt pamięciowy"?**
  Tak. Oprócz powiększenia każdego obiektu o `vptr`, kompilator musi wygenerować i przechowywać w pamięci statycznej programu (często w sekcji `rodata`) po jednej tablicy `vtable` dla każdej klasy polimorficznej oraz wygenerować struktury RTTI (Run-Time Type Information).

**2. Analiza kodu ASM (koszt wywołania funkcji wirtualnej)**
W celu zbadania narzutu wywołań wygenerowano i przeanalizowano kod asemblera dla obu przypadków, pomijając procedury inicjalizacyjne i skupiając się na samym wywołaniu:

* **Wywołanie zwykłej funkcji:** Występuje tu tzw. wczesne wiązanie (*early binding*). Kompilator zna adres funkcji. Kod ASM sprowadza się do załadowania wskaźnika `this` do rejestru, a następnie wykonania bezpośredniego skoku (instrukcja `call`) pod ustalony adres. Jest to proces optymalny i przyjazny dla predyktora skoków w procesorze.

* **Wywołanie funkcji wirtualnej:** Występuje tu tzw. późne wiązanie (*dynamic dispatch*). Przed wywołaniem w kodzie ASM widoczne są dwie dodatkowe operacje dostępu do pamięci. Program najpierw dokonuje dereferencji wskaźnika obiektu, aby pobrać `vptr`, a następnie dokonuje dereferencji samego `vptr`, aby odczytać z tablicy `vtable` odpowiedni adres skoku. Następnie wywoływana jest instrukcja `call` dla wartości w rejestrze (skok pośredni). Głównym kosztem nie jest sama ilość instrukcji ASM, lecz dodatkowe odczyty z pamięci i związane z tym ryzyko tzw. *cache miss* oraz wyższe prawdopodobieństwo błędnej predykcji skoku.

---

### Zadanie 3: Kwestia wirtualnego destruktora

Zdefiniowanie wirtualnego destruktora w abstrakcyjnej klasie bazowej (jak zaprezentowany sterownik przetwornika A/C) jest absolutnie konieczne. Polimorfizm opiera się na operowaniu wskaźnikami typu bazowego. Brak słowa kluczowego `virtual` przy destruktorze powoduje, że instrukcja `delete` wywołana na takim wskaźniku usunie wyłącznie część bazową obiektu, ignorując destruktor klasy pochodnej. Prowadzi to bezpośrednio do wycieków pamięci i niezamkniętych uchwytów (np. niezwolnionych portów I2C lub pinów mikrokontrolera). `zad1.cpp` przedstawia poprawną implementację hierarchii klas spełniającą warunki LSP, gdzie różne gatunki ptaków są zarządzane w sposób jednolity za pomocą wskaźników klasy bazowej.