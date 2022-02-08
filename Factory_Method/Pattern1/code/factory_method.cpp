#include <iostream>
#include <string>

class Dataobject;
class FileDataObject;

class DataObject {
    public:
        static DataObject* Create();
        virtual std::string GetName(int id) = 0;
};

class FileDataObject : public DataObject {
    public:
        std::string GetName(int id) {
            return "FileDataObject";
        }
};

class DBDataObject : public DataObject {
    public:
        std::string GetName(int id) {
            return "DBObject";
        }
};

// DataObject 内では new できないので（抽象クラスのため）
DataObject* DataObject::Create() {
    return new FileDataObject();
}

int main () {
    DataObject* dataobj = DataObject::Create();
    std::cout << dataobj->GetName(1) << std::endl;
}