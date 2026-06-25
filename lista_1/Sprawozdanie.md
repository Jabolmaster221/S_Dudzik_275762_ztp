# Sprawozdanie - Lista 1

## Przebieg prac
1. **Kod**: Zaimplementowano bibliotekę `hello` oraz dwa programy. W `prog1` użyto standardowej biblioteki wątków, a w `prog2` biblioteki nlohmann/json.
2. **Budowanie ręczne**: Skrypt `build.sh` pozwolił na zrozumienie etapów kompilacji i linkowania (flaga `-lp thread`).
3. **Makefile**: Stworzono system zależności, dzięki któremu modyfikacja jednego programu nie wymusza przebudowy całego projektu.
4. **CMake**:
    - `add_library` i `add_executable`: Zdefiniowano strukturę binariów.
    - `find_package(Threads)`: Zastosowano przenośny sposób obsługi wątków.
    - `FetchContent`: Skonfigurowano automatyczne pobieranie biblioteki JSON w wersji 3.12.0. Było to niezbędne, aby zapewnić kompatybilność z użytą wersją CMake 4.0.2.

## Dyrektywy CMake
- `target_link_libraries`: Łączy skompilowane obiekty i dba o przekazanie zależności.
- `target_include_directories`: Ustawia ścieżki nagłówków.
- `FetchContent_MakeAvailable`: Automatycznie pobiera, konfiguruje i dołącza zewnętrzne źródła do drzewa budowania.