#include <iostream>
#include <sstream>
#include <fstream>
#include "JSONParser.h"  // Include your JSONParser header file
#include <time.h>

int main() {

    // Open a file for Testing
    std::ifstream inputFile("../test.json");
    // Check if the file is open
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file. " << std::endl;
        return 1;
    }

    std::stringstream  buffer;
    buffer << inputFile.rdbuf();
    inputFile.close();
    std::istringstream  inputStream(buffer.str());

    JSONParser parser1(inputStream);

    // Create more parsers as needed

    // Test Case 1
    clock_t start, end;
    start = clock();
    std::cout << "Parsing JSON 1:" << std::endl;
    JSONValue result1 = parser1.parse();
    end = clock();
    std::cout << "Parse procedure consumes time = " << double(end-start) / CLOCKS_PER_SEC << "s" << std:: endl;
    start = clock();
    result1.print();  // Implement a print() function in JSONValue for debugging
    end = clock();
    std::cout << std::endl;
    std::cout << "Print procedure consumes time = " << double(end-start) / CLOCKS_PER_SEC << "s" << std:: endl;
    std::cout << std::endl;

    // Add more test cases as needed

    return 0;
}
