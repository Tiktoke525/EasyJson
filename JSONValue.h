#include <iostream>
#include <string>
#include <vector>
#include <map>

class JSONValue {
public:
    enum class Type {
        STRING,
        NUMBER,
        BOOL,
        ARRAY,
        OBJECT
    };

    JSONValue() : type_(Type::STRING), strValue_("") {}
    JSONValue(const std::string& strValue) : type_(Type::STRING), strValue_(strValue) {}
    JSONValue(double numValue) : type_(Type::NUMBER), numValue_(numValue) {}
    JSONValue(bool boolValue) : type_(Type::BOOL), boolValue_(boolValue) {}
    JSONValue(const std::vector<JSONValue>& arrayValue) : type_(Type::ARRAY), arrayValue_(arrayValue) {}
    JSONValue(const std::map<std::string, JSONValue> objectValue) : type_(Type::OBJECT), objectValue_(objectValue) {}

    Type getType() const {
        return type_;
    }

    const std::string& getString() const {
        return strValue_;
    }

    double getNumber() const {
        return numValue_;
    }

    bool getBool() const {
        return boolValue_;
    }

    const std::vector<JSONValue>& getArray() const {
        return arrayValue_;
    }

    const std::map<std::string, JSONValue>& getObject() const {
        return objectValue_;
    }

    void print() const;

private:
    Type type_;
    std::string strValue_;
    double numValue_;
    bool boolValue_;
    std::vector<JSONValue> arrayValue_;
    std::map<std::string, JSONValue> objectValue_;

    void printRecursive(const JSONValue& value, int i) const;

    void printIndentation(int indentation) const;
};