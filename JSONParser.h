#include "JSONValue.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

class JSONParser {
public:
    JSONParser(std::istringstream &jsonStream) : jsonStream_(jsonStream) {}
    JSONValue parse();

private:
    std::istringstream& jsonStream_;

    void skipWhitespace();
    JSONValue parseObject();
    std::string parseString();
    double parseNumber();
    bool parseBool();
    std::string parseUnicode();
    std::vector<JSONValue> parseArray();
};