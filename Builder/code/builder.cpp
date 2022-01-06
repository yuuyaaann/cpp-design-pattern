#include <iostream>
#include <string>

class BuildHome {
    public:
        void SetWall(std::string wall_) {
            this->wall = wall_;
        }
        std::string GetWall(){
            return this->wall;
        }
    private:
        std::string wall; // 壁の種類
};

class HomeBuilder {
    public:
        virtual void SetStructure() = 0;
        virtual BuildHome* GetResult() = 0;
};

class ModernBuilder : public HomeBuilder {
    public:
        ModernBuilder() {
            buildhome = new BuildHome();
        }
        ~ModernBuilder() {
            delete buildhome;
        }
        virtual void SetStructure() {
            buildhome->SetWall("コンクリート");
        }
        virtual BuildHome* GetResult() {
            return buildhome;
        }
    private:
        BuildHome *buildhome;
};

class JapaneseHomeBuilder : public HomeBuilder {
    public:
        JapaneseHomeBuilder() {
            buildhome = new BuildHome();
        }
        ~JapaneseHomeBuilder() {
            delete buildhome;
        }
        virtual void SetStructure() {
            buildhome->SetWall("木造");
        }
        virtual BuildHome* GetResult() {
            return buildhome;
        }
    private:
        BuildHome *buildhome;
};

class EuropeanHomeBuilder : public HomeBuilder {
    public:
        EuropeanHomeBuilder() {
            buildhome = new BuildHome();
        }
        ~EuropeanHomeBuilder() {
            delete buildhome;
        }
        virtual void SetStructure() {
            buildhome->SetWall("ヨーロピアン");
        }
        virtual BuildHome* GetResult() {
            return buildhome;
        }
    private:
        BuildHome *buildhome;
};

class Director {
    public:
        void construct(HomeBuilder *builder) {
            builder->SetStructure();
        }
};

int main () {
    HomeBuilder* builder;
    Director* director = new Director();

    int build_type = 1;
    if(build_type == 1) builder = new JapaneseHomeBuilder();
    if(build_type == 2) builder = new EuropeanHomeBuilder();

    director->construct(builder); // 監督が builder 情報をもとに家を立てるように指示
    BuildHome* buildhome = builder->GetResult();

    std::cout << buildhome->GetWall() << std::endl;

    delete builder;
    delete director;
    delete buildhome;

    return 0;
}