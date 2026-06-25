#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iterator>

struct Vec2 {
    float x, y;
};

float distance(const Vec2& a, const Vec2& b) {
    return std::hypot(a.x - b.x, a.y - b.y);
}

struct Projectile {
    Vec2 pos;
};

struct Enemy {
    Vec2 pos;
    float size; // Promień kolizji
    int hp;
};

bool isColliding(const Enemy& e, const Projectile& p) {
    return distance(e.pos, p.pos) <= e.size;
}

void printEnemies(const std::vector<Enemy>& E, const std::string& msg) {
    std::cout << "--- " << msg << " ---\n";
    for (size_t i = 0; i < E.size(); ++i) {
        std::cout << "Wrog " << i << ": Pos(" << E[i].pos.x << ", " << E[i].pos.y
                  << "), HP: " << E[i].hp << "\n";
    }
    std::cout << "\n";
}

int main() {
    // --- Inicjalizacja danych początkowych ---
    std::vector<Enemy> E = {
        {{10.0f, 10.0f}, 2.0f, 3}, // Wrog 0
        {{20.0f, 5.0f}, 1.5f, 1},  // Wrog 1
        {{5.0f, 30.0f}, 3.0f, 5},  // Wrog 2
        {{-5.0f, 10.0f}, 2.0f, 0}  // Wrog 3
    };

    std::vector<Projectile> P = {
        {{11.0f, 11.0f}}, // Pocisk 0 (koliduje z Wrogiem 0)
        {{20.0f, 5.0f}},  // Pocisk 1 (koliduje z Wrogiem 1)
        {{100.0f, 100.0f}}// Pocisk 2 (nie koliduje z nikim)
    };

    Vec2 G = {0.0f, 0.0f}; // Pozycja gracza

    printEnemies(E, "Stan poczatkowy wrogow");

    if (!P.empty() && !E.empty()) {
        std::partial_sort(E.begin(), E.begin() + 1, E.end(), [&](const Enemy& a, const Enemy& b) {
            return distance(a.pos, P[0].pos) < distance(b.pos, P[0].pos);
        });

        std::cout << "Najblizszy wrog pierwszego pocisku ma pozycje: X="
                  << E[0].pos.x << ", Y=" << E[0].pos.y << "\n\n";
    }


    if (!P.empty()) {
        E.erase(std::remove_if(E.begin(), E.end(), [&](const Enemy& e) {
            return isColliding(e, P[0]);
        }), E.end());
        printEnemies(E, "Po usunieciu wrogow kolidujacych z P[0]");
    }

    std::sort(E.begin(), E.end(), [&](const Enemy& a, const Enemy& b) {
        return std::abs(a.pos.x - G.x) < std::abs(b.pos.x - G.x);
    });
    printEnemies(E, "Posortowani wg odleglosci X od gracza");

    P.erase(std::remove_if(P.begin(), P.end(), [&](Projectile& p) {
        bool hit = false;
        for (auto& e : E) {
            if (e.hp >= 0 && isColliding(e, p)) {
                e.hp -= 1;
                hit = true;
                break;
            }
        }
        return hit;
    }), P.end());

    E.erase(std::remove_if(E.begin(), E.end(), [](const Enemy& e) {
        return e.hp < 0;
    }), E.end());

    printEnemies(E, "Po przetworzeniu trafien i usunieciu martwych");

    int totalHP = std::accumulate(E.begin(), E.end(), 0, [](int sum, const Enemy& e) {
        return sum + e.hp;
    });
    std::cout << "Suma HP wszystkich zyjacych wrogow: " << totalHP << "\n\n";

    float D = 30.0f;
    int closeEnemiesCount = std::count_if(E.begin(), E.end(), [&](const Enemy& e) {
        return distance(e.pos, G) < D;
    });
    std::cout << "Liczba wrogow w odleglosci mniejszej niz " << D << ": " << closeEnemiesCount << "\n\n";

    std::for_each(P.begin(), P.end(), [](Projectile& p) {
        p.pos.y += 1.0f;
    });
    std::cout << "[Zad 7] Przesunieto pociski do gory.\n\n";

    std::vector<Projectile> PP;

    std::transform(E.begin(), E.end(), std::back_inserter(PP), [](const Enemy& e) {
        return Projectile{e.pos};
    });

    std::cout << "[Zad 8] Wygenerowano wektor PP z " << PP.size() << " nowymi pociskami.\n";

    return 0;
}