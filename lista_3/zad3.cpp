#include <iostream>
#include <memory>

// Abstrakcyjna klasa bazowa - sterownik przetwornika A/C
class ADC_Driver {
public:
    // WIRTUALNY DESTRUKTOR JEST KLUCZOWY
    // Zapewnia, że niszcząc obiekt pochodny przez wskaźnik bazowy, 
    // wywoła się też destruktor klasy pochodnej.
    virtual ~ADC_Driver() {
        std::cout << "~ADC_Driver() (Czyszczenie bazy)\n";
    }

    // Czysto wirtualna funkcja
    virtual int readValue() = 0; 
};

// Pierwsza implementacja
class InternalADC : public ADC_Driver {
public:
    InternalADC() { std::cout << "Konstruktor InternalADC\n"; }
    ~InternalADC() override { std::cout << "~InternalADC() (Zwalnianie zasobow wewnetrznych)\n"; }

    int readValue() override {
        std::cout << "[InternalADC] Odczytuje z wewnetrznego pinu...\n";
        return 512;
    }
};

// Druga implementacja
class ExternalI2C_ADC : public ADC_Driver {
public:
    ExternalI2C_ADC() { std::cout << "Konstruktor ExternalI2C_ADC\n"; }
    ~ExternalI2C_ADC() override { std::cout << "~ExternalI2C_ADC() (Zamykanie szyny I2C)\n"; }

    int readValue() override {
        std::cout << "[ExternalI2C_ADC] Odczytuje z zewnetrznego modulu po I2C...\n";
        return 1023;
    }
};

void processSensorData(ADC_Driver* driver) {
    int val = driver->readValue();
    std::cout << "Przetworzona wartosc: " << val << "\n";
}

int main() {
    std::cout << "--- Zadanie 3: Abstrakcja i Wirtualny Destruktor ---\n\n";

    std::cout << "=== Test implementacji wewnetrznej ===\n";
    ADC_Driver* myInternalSensor = new InternalADC();
    processSensorData(myInternalSensor);
    
    // Gdyby ADC_Driver nie mial wirtualnego destruktora, ~InternalADC() nigdy by sie nie wywolal
    delete myInternalSensor; 

    std::cout << "\n=== Test implementacji zewnetrznej ===\n";
    ADC_Driver* myExternalSensor = new ExternalI2C_ADC();
    processSensorData(myExternalSensor);
    delete myExternalSensor;

    return 0;
}