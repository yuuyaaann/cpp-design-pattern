#include <iostream>
#include <vector>

class District {
    public:
        virtual ~District();
        virtual int getPopulation() = 0;
};

class UnitDistrict{
    public:
        virtual int getPopulation() {
            return this->population;
        }

        void setPopulation(int population) {
            this->population = population;
        }
    private:
        int population;
};


class GroupDistrict{
    public:
        ~GroupDistrict() {
            for(int i = 0; i < vec.size(); i++) {
                delete vec[i];
            }
        }
        void add(UnitDistrict* district) {
            vec.push_back(district);
        }
        int getPopulation() {
            int result = 0;
            for(int i = 0; i < vec.size(); i++) {
                result += vec[i]->getPopulation();
            }
            return result;
        }
    private:
        std::vector<UnitDistrict*> vec;
};

int main () {
    GroupDistrict group;

    UnitDistrict * test = new UnitDistrict();
    UnitDistrict * test1 = new UnitDistrict();
    UnitDistrict * test2 = new UnitDistrict();

    test->setPopulation(1);
    test1->setPopulation(2);
    test2->setPopulation(3);

    group.add(test);
    group.add(test1);
    group.add(test2);

    group.getPopulation();

    return 0;
}