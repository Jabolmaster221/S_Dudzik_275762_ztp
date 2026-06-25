# Sprawozdanie: Algorytmy biblioteki STL
## Lista 4

Celem zadania było zaimplementowanie uproszczonej logiki gry (zarządzanie wrogami i pociskami) przy użyciu standardowych algorytmów biblioteki C++ (STL), eliminując tym samym konieczność ręcznego pisania pętli tam, gdzie to możliwe. Poniżej przedstawiono analizę zastosowanych rozwiązań.

### Zastosowanie algorytmów STL do logiki gry

**1. Znalezienie wroga najbliżej wybranego pocisku**
Do znalezienia szukanego elementu zastosowano algorytm `std::partial_sort`. Jako kryterium posłużyło wyrażenie lambda obliczające dystans euklidesowy. Umożliwiło to częściowe posortowanie kontenera – algorytm zagwarantował, że na samym początku wektora (pod indeksem zerowym) znalazł się wróg znajdujący się najbliżej wskazanego pocisku, ignorując przy tym kolejność pozostałych elementów.

**2. Usuwanie wrogów po kolizji z pociskiem**
Zastosowano idiom *Erase-Remove*, będący standardowym i najbezpieczniejszym sposobem usuwania elementów z kontenerów typu `std::vector`. Funkcja `std::remove_if` przesunęła kolidujących wrogów na koniec wektora, a metoda `std::erase` usunęła ich fizycznie z pamięci.

**3. Sortowanie wrogów względem gracza (oś X)**
Do uporządkowania wektora użyto algorytmu `std::sort`. Jako kryterium podano wyrażenie lambda porównujące wartości bezwzględne różnicy współrzędnych X wrogów oraz gracza.

**4. Mechanika obrażeń i niszczenia obiektów**
Przetwarzanie kolizji podzielono na dwa etapy, by uniknąć problemów z unieważnieniem iteratorów:
* Zastosowano idiom *Erase-Remove* na wektorze pocisków. Wewnętrzna logika lambdy sprawdzała kolizje z wrogami, odejmowała punkty zdrowia (HP) i zwracała flagę logiczną informującą o zniszczeniu pocisku.
* Następnie użyto drugiego idiomu *Erase-Remove* z `std::remove_if` na wektorze wrogów, aby bezpiecznie usunąć tych, których HP spadło poniżej zera.

**5. Obliczenie sumy punktów zdrowia**
Do agregacji danych użyto algorytmu `std::accumulate` z biblioteki `<numeric>`. Pozwoliło to na zwięzłe zredukowanie całego wektora wrogów do pojedynczej wartości całkowitej sumującej ich punkty HP.

**6. Zliczanie wrogów w promieniu gracza**
Zastosowano algorytm `std::count_if`, który przyjął lambdę weryfikującą, czy odległość euklidesowa danego wroga od gracza jest ostro mniejsza od zadanego promienia D.

**7. Globalna modyfikacja pozycji pocisków**
Zamiast klasycznej pętli `for`, wykorzystano algorytm `std::for_each`. Przeszedł on przez wszystkie aktywne pociski, referencyjnie modyfikując ich składową Y ("przesunięcie w górę").

**8. Generowanie pocisków wroga**
Wykorzystano algorytm `std::transform` w połączeniu z adapterem `std::back_inserter`. Pozwoliło to na bezpieczne i automatyczne mapowanie każdego istniejącego wroga (elementu wektora E) na nowo wygenerowany obiekt pocisku i dołączenie go do docelowego wektora PP.