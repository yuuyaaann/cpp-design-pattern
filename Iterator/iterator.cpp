#include <iostream>
#include <string>
#include <vector>

class IteratorMachine;
class Machine;

class Parts {
    public:
        Parts(std::string name, int qunatity) {
            this->name = name;
            this->quantity = qunatity;
        }

        std::string GetName() {
            return name;
        }

        int GetQuantity() {
            return quantity;
        }

    private:
        std::string name;
        int quantity;
};

class Iterator {
    public:
        virtual bool hasNext() = 0;
        virtual Parts* next() = 0;
};

class Aggregate {
    public:
        virtual Iterator* iterator() = 0;
};

class Machine : public Aggregate {
    private:
        std::vector<Parts*> vctParts;
    public:
        ~Machine() {
            for(int i = 0; i < vctParts.size(); i++) {
                delete vctParts[i];
            }
        }

        void add(Parts* parts) {
            vctParts.push_back(parts);
        }

        Parts* get(int index){
            return vctParts.at(index);
        }

        int size() {
            return (int) vctParts.size();
        }

        Iterator* iterator() {
            return new IteratorMachine(this);
        }
};

class IteratorMachine : public Iterator {
    private:
        Machine *m_pMachine;
        int m_cursor;
    public:

        IteratorMachine(Machine* machine_) {
            m_pMachine = machine_;
            m_cursor = 0;
        }

        bool hasNext() {
            if(m_cursor < m_pMachine->size()) return true;
            else return false;
        }
        Parts* next() {
            Parts* parts = m_pMachine->get(m_cursor);
            m_cursor++;
            return parts;
        }
};

int main () {
    Machine *pmachine = new Machine();

    pmachine->add(new Parts("テスト", 1));
    pmachine->add(new Parts("テスト2", 2));
    pmachine->add(new Parts("テスト3", 3));
    pmachine->add(new Parts("テスト4", 4));

    Iterator* it = pmachine->iterator();
    while(it->hasNext()) {
        Parts* parts = it->next();
        std::cout << parts->GetName() << "\t";
        std::cout << parts->GetQuantity() << std::endl;
    }
    delete it;
    delete pmachine;
    return 0;
}