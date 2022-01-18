#include <iostream>
#include <string>
#include <fstream>

class Writer{
    public:
        virtual void WriteData(std::string str) = 0;
};

class ConsoleWriter : public Writer {
    public:
        virtual void WriteData(std::string str) {
            std::cout << str << std::endl;
        }
};

class LocalFileWriter : public Writer {
    public:
        LocalFileWriter(std::string fileName_) {
            this->fileName = fileName_;
        }
        virtual void WriteData(std::string str) {
            std::ofstream* ofs = new std::ofstream();

            ofs->open(fileName.c_str());
            ofs->write(str.c_str(), (std::streamsize)str.length());
            ofs->close();

            delete ofs;
        }
    private:
        std::string fileName;
};

class BRWriter : public Writer {
    public:
        BRWriter(Writer* pOut) {
            this->pOut = pOut;
        }
        virtual void WriteData(std::string str) {
            std::string before = "\n";
            std::string after = "<br>";
            
            // 変換処理が入るみたいだがめんどくさいので割愛する
            std::cout << str << std::endl;

        }
    private:
        Writer* pOut;
};

int main() {
    ConsoleWriter* pConsole = new ConsoleWriter();
    BRWriter* pbrwrite = new BRWriter(pConsole);

    pbrwrite->WriteData("test");
}