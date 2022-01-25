#include <iostream>
#include <string>

class FileFormatter {
    public:
        virtual ~FileFormatter(){}
        void formmater(std::string infile, std::string outfile) {
            std::string data = ReadFile(infile);
            std::string formattedData = Formatting(data);
            WriteToFile(data, formattedData);
        }
        virtual std::string ReadFile(std::string filename) = 0;
        virtual std::string Formatting(std::string data) = 0;
        virtual void WriteToFile(std::string outfilename, std::string modData) = 0;
        // ↑は純仮想関数だが、仮想関数でもよい
};

class TabToCSVFormatter : public FileFormatter {
    public:
        virtual ~TabToCSVFormatter(){}
        std::string ReadFile(std::string filename) {
            std::cout << "読み込んでまーす" << std::endl;
            return filename;
        }
        std::string Formatting(std::string data) {
            std::cout << "Tab から CSV へ変更してまーす" << std::endl;
            return data;
        }
        void WriteToFile(std::string outfilename, std::string modData) {
            std::cout << "ファイルへ書き込んでいます" << std::endl;
        }
};

class CSVToHTMLFormatter : public FileFormatter {
    public:
        virtual ~CSVToHTMLFormatter(){}
        std::string ReadFile(std::string filename) {
            std::cout << "読み込んでまーす" << std::endl;
            return filename;
        }
        std::string Formatting(std::string data) {
            std::cout << "CSV から HTML へ変更してまーす" << std::endl;
            return data;
        }
        void WriteToFile(std::string outfilename, std::string modData) {
            std::cout << "ファイルへ書き込んでいます" << std::endl;
        }
};

class TextLengthFormatter : public FileFormatter {
    public:
        virtual ~TextLengthFormatter(){}
        std::string ReadFile(std::string filename) {
            std::cout << "読み込んでまーす" << std::endl;
            return filename;
        }
        std::string Formatting(std::string data) {
            std::cout << "TextLengthFormatter " << std::endl;
            return data;
        }
        void WriteToFile(std::string outfilename, std::string modData) {
            std::cout << "ファイルへ書き込んでいます" << std::endl;
        }
};

void test(FileFormatter *file) {
    file->formmater("test", "test123");
}

int main () {
    test(new TabToCSVFormatter());
    test(new CSVToHTMLFormatter());
    test(new TextLengthFormatter());
}