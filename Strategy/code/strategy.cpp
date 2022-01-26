#include <iostream>
#include <string>

class Dialect {
    public:
        virtual void SayWelcome() = 0;
        virtual void SayThanks() = 0;
};

class KyotoDialect : public Dialect{
    public:
        void SayWelcome() {
            std::cout << "oideyasu" << std::endl;
        }
        void SayThanks() {
            std::cout << "ookini" << std::endl;
        }
};

class NagoyaDialect : public Dialect{
    public:
        void SayWelcome() {
            std::cout << "iryaase" << std::endl;
        }
        void SayThanks() {
            std::cout << "arigatou" << std::endl;
        }
};

class DialectSpeaker {
    public:
        const static int kyoto = 1;
        const static int nagoya = 2;

        DialectSpeaker(int dialect) {
            switch (dialect) {
                case kyoto:
                    this->dialect = new KyotoDialect();
                    break;
                case nagoya:
                    this->dialect = new NagoyaDialect();
                    break;
            }
        }
        ~DialectSpeaker(){ delete dialect;}
        void SayWelcome() {
            dialect->SayWelcome();
        }
        void SayThanks() {
            dialect->SayThanks();
        }
    private:
        Dialect *dialect;
};

int main () {
    DialectSpeaker *test = new DialectSpeaker(DialectSpeaker::kyoto);
    test->SayThanks();
    test->SayWelcome();
    delete test;
}