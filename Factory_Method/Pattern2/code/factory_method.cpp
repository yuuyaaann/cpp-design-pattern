#include <iostream>
#include <string>

class Dataobject;
class FileDataObject;

class DataObject {
    public:

        static DataObject* Create(int type);
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

class DataObjectFactory {
    public:
        const static int STANDALONE = 0;
        const static int NETWORKING = 1;

        DataObjectFactory(int type) {
            this->type = type;
        }
        DataObject* Create() {
            DataObject* result = NULL;
            if(type == STANDALONE) result = new FileDataObject();
            if(type == NETWORKING) result = new DBDataObject();

            return result;
        }
    private:
        int type;
};

int main () {
    DataObjectFactory* factory = new DataObjectFactory(DataObjectFactory::STANDALONE);
    DataObject* pDataObject01 = factory->Create();
    DataObject* pDataObject02 = factory->Create(); // 型を指定せずに何度も同じオブジェクトが生成可能

    std::cout << pDataObject01->GetName(1) << std::endl;
    std::cout << pDataObject02->GetName(2) << std::endl;

}