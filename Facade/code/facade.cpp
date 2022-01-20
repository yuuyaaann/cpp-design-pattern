#include <iostream>
#include <string>

class SubSystemA {
    public:
        void lightOn() {
            std::cout << "Light ON" << std::endl;
        }
        void lightOff() {
            std::cout << "Light Off" << std::endl;
        }
};

class SubSystemB {
    public:
        void TVOn() {
            std::cout << "TV Off" << std::endl;
        }
        void TVOff() {
            std::cout << "TV Off" << std::endl;
        }
};

class Facade {
    public:
        void SubSystemOn() {
            a.lightOn();
            b.TVOn();
        }
        void SubSystemOff() {
            a.lightOff();
            b.TVOff();
        }
    private:
        SubSystemA a;
        SubSystemB b;
};

int main () {
    Facade facade;
    facade.SubSystemOn();
    facade.SubSystemOff();

    return 0;
}