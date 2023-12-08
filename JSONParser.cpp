#include "JSONParser.h"

JSONValue JSONParser::parse() {
    // Remove the prefix spaces
    skipWhitespace();

    char ch;
    ch = jsonStream_.peek();

    switch (ch) {
        case '{':
            jsonStream_ >> ch;
            return parseObject();
        case '[':
            jsonStream_ >> ch;
            return parseArray();
        case '\"':
            jsonStream_ >> ch;
            return parseString();
        case 't':
        case 'f':
            return parseBool();
        default:
            jsonStream_ >> ch;
            if (isdigit(ch) || ch == '-') {
                jsonStream_.putback(ch);
                return parseNumber();
            } else {
                std::cerr << "Invalid Json data" << std::endl;
                return JSONValue();
            }

    }
}

void JSONParser::skipWhitespace() {
    char ch;
    while (jsonStream_ >> ch) {
        if (!isspace(ch)) {
            jsonStream_.putback(ch);
            break;
        }
    }
}

JSONValue JSONParser::parseObject() {
    std::map<std::string, JSONValue> jsonObject;

    char ch;

    while (jsonStream_ >> std::ws >> ch && ch != '}') {
        std::string key;
        if (ch == '\"') {
            key = parseString();
        }

        jsonStream_ >> std::ws >> ch;

        if (ch == ':') {
            JSONValue value = parse();
            jsonObject[key] = value;

            jsonStream_ >> std::ws >> ch;
            if (ch == ',') {
                jsonStream_ >> std::ws;
            } else if (ch == '}') {
                break;
            }
        }
    }


    return jsonObject;
}

std::string JSONParser::parseString() {
    std::string str;

    char ch;

    while (jsonStream_ >> ch && ch != '\"') {
        if (ch == '\\') {
            jsonStream_ >> ch;

            switch (ch) {
                case '\"':
                    str += '\"';
                    break;
                case '\\':
                    str += '\\';
                    break;
                case '/':
                    str += '/';
                    break;
                case 'b':
                    str += '\b';
                    break;
                case 'f':
                    str += '\f';
                    break;
                case 'n':
                    str += '\n';
                    break;
                case 'r':
                    str += '\r';
                    break;
                case 't':
                    str += '\t';
                    break;
                case 'u':
                    // Process unicode character
                    str += parseUnicode();
                    break;
                default:
                    str += '\\';
                    str += ch;
                    break;
            }
        } else {
            str += ch;
        }
    }
    return str;
}

double JSONParser::parseNumber() {
    double num;
    jsonStream_ >> num;
    return num;
}

bool JSONParser::parseBool() {
    std::string boolStr;
    char ch;
    while (ch = jsonStream_.peek()) {
        if (ch == ' ' || ch == '\\' || ch == '/' || ch == ',' ||
            ch == '{' || ch == '}' || ch == '[' || ch == ']') {
            break;
        }
        jsonStream_ >> ch;
        boolStr += ch;
    }
    if (boolStr == "true") {
        return true;
    } else if (boolStr == "false") {
        return false;
    }
    std::cerr << "Invalid bool data : " << boolStr << std::endl;
    return false;
}

std::vector<JSONValue> JSONParser::parseArray() {
    std::vector<JSONValue> jsonArray;

    char ch;
    ch = jsonStream_.peek();

    while (ch != ']') {
        JSONValue element = parse();
        jsonArray.push_back(element);
        // Remove the prefix spaces
        jsonStream_ >> std::ws >> ch;
        if (ch == ',') {
            jsonStream_ >> std::ws;
        } else if (ch != ']') {
            std::cerr << "Invalid array data" << std::endl;
            break;
        }
    }
    return jsonArray;
}

std::string JSONParser::parseUnicode() {
    std::string hexCode, unicodeString;
    char ch;

    // Read the next four characters and append them to the Unicode string
    for (int i = 0; i < 4; i++) {
        jsonStream_ >> ch;
        hexCode += ch;
    }

    // Convert the hexadecimal string to an integer
    int unicodeValue;
    std::istringstream(hexCode) >> std::hex >> unicodeValue;

    // Append the Unicode character to the final string
    unicodeString = static_cast<wchar_t>(unicodeValue);
    return unicodeString;
}

