#include "JSONValue.h"
#include <iostream>

void JSONValue::print() const {
    printRecursive(*this ,0);
}

void JSONValue::printRecursive(const JSONValue& value, int indentation) const {
    printIndentation(indentation);
    if (type_ == Type::OBJECT) {
        std::cout << "{\n";
        for (const auto& pair : value.getObject()) {
            printIndentation(indentation + 1);
            std::cout << "\"" << pair.first << "\": ";
            pair.second.printRecursive(pair.second, indentation + 1);
            std::cout << ",\n";
        }
        printIndentation(indentation);
        std::cout << "}";
    } else if (type_ == Type::ARRAY) {
        std::cout << "[\n";
        for (const auto& element : value.getArray()) {
            printIndentation(indentation + 1);
            element.printRecursive(element, indentation + 1);
            std::cout << ",\n";
        }
        printIndentation(indentation);
        std::cout << "]";
    } else if (type_ == Type::STRING) {
        std::cout << "\"" << value.getString() << "\"";
    } else if (type_ == Type::NUMBER) {
        std::cout << value.getNumber();
    } else if (type_ == Type::BOOL) {
        std::cout << (value.getBool()) ? "true" : "false";
    } else {
        std::cout << "null";
    }
}

void JSONValue::printIndentation(int indentation) const{
    for (int i = 0; i < indentation * 2; ++i) {
        std::cout << ' ';
    }
}
