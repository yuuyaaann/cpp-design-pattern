#include <iostream>
#include <string>

class Mediator;

class Colleague {
    public:
        virtual void SetMediator(Mediator* mediator) = 0;
};

class Mediator{
    public:
        virtual void ColleagueChanged(Colleague* c) = 0;
};

class YearList : public Colleague {
    public:
        void ItemStateChanged() { //「年」のリストが変更された際に呼ばれるメソッド
            std::cout << "YearList" << __func__ << std::endl;
            mediator->ColleagueChanged(this);
        }
        void SetMediator(Mediator* mediator) {
            this->mediator  = mediator;
        }
    private:
        Mediator *mediator;
};

class MainFrame : public Mediator {
    public:
        void MakeObject() {
            yearlist = new YearList();

            // オブジェクトに Mediator を登録
            yearlist->SetMediator(this);
        }
        void ColleagueChanged(Colleague *c) {
            if(c== yearlist) {
                std::cout << "年を更新するぜー" << std::endl;
            }
        }
    private:
        YearList *yearlist;
};



int main () {
    MainFrame mainf;
    mainf.MakeObject();

    

}