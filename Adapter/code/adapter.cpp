#include <iostream>
#include <string>
#include <fstream>

class Writer {
    public:
        virtual void OpenFile() = 0;
        virtual void WrtiteData(std::string stringdata) = 0;
        virtual void CloseFile() = 0;
};

class HTMLWriter {
    public:
        HTMLWriter(std::string filename) {
            this->filename = filename;
        }
        virtual void fileOpen() {
            std::cout << "ファイルを開ける" << std::endl;
        }
        virtual void Data(std::string stringdata) {
            std::cout << "ファイルに書き込む" << std::endl;
        }
        virtual void fileClose() {
            std::cout << "ファイルを閉じる" << std::endl;
        }
        virtual void ConversionString(std::string stringdata) {
            std::cout << "変換しているなりー" << std::endl;
        }
    private:
        std::string filename;
};

class FileWrite : public Writer {
    public:
        FileWrite(std::string file_name) {
            this->filename = file_name;
        }
        void OpenFile() {
            ofs.open(filennamme.c_str(), std::ios::trunc);
        }
        void CloseFile() {
            ofs.close();
        }
        void WrtiteData(std::string stringdata) {
            ofs << stringdata.c_str() << std::endl;
        }
    private:
        std::ofstream ofs;
        std::string filename;
};

class ConsoleWrite : public Writer {
    public:
        void OpenFile() {}
        void WrtiteData(std::string stringdata){}
        void CloseFile() {}
};


class HTMLWriterClassAdapter : public HTMLWriter, public Writer {
    public:
        HTMLWriterClassAdapter (std::string filename) : HTMLWriter(filename) {
        }
        void OpenFile() {
            fileOpen();
        }
        void WrtiteData(std::string stringdata){
            Data(stringdata);
        }
        void CloseFile() {
            fileClose();
        }
};

void WriteString(std::string stringdata, Writer* writer) {
    writer->OpenFile();
    writer->WrtiteData();
    writer->CloseFile();
}




void main(){
    WriteString("test", new ConsoleWrite())
    WriteString("test file", new FileWrite("test.txt"))
    WriteString("test", new HTMLWriterClassAdapter())
    return ;
}