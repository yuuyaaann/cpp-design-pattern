#include <iostream>
#include <string>

class Singleton;

static Singleton* singleton_ = NULL;

class Singleton {
    public:
        static Singleton* GetInstance() {
            if(singleton_ == NULL) singleton_ = new Singleton;
            return singleton_;
            // static Singleton singleton_ でもいい
            // クラス内の static は生成されたすべてのクラスで同じ値を使うことになる
        }
        void PrintTest(std::string data) {
            std::cout << data << std::endl;
            return;
        }
    private:
        Singleton(){}
        Singleton(const Singleton& obj){}
        Singleton& operator=(const Singleton& obj){}
        ~Singleton(){ delete singleton_ ;}
};


int main () {
    Singleton *singleton_test =  Singleton::GetInstance();

    std::cout << singleton_test << std::endl;
    singleton_test->PrintTest("TEST");

    Singleton *singleton_test2 =  Singleton::GetInstance();
    std::cout << singleton_test2 << std::endl;


    return 0;
}