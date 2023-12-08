#### Simple and readable JSON parser in C++

This is a project that only uses simple syntax rules and can achieve nested structure parsing, which is very suitable 
for C++ beginners. 
Its biggest advantage is very simple, without using complex encapsulation and inheritance in code. 

The structure of project includes five files, `JSONValue.h`,`JSONValue.cpp`, `JSONParser.h`, `JSONParser.cpp`, `test.cpp`. 
It's easy to identify what function a file is used for by its file name.

However, there are still many areas for expansion. Now it supports five data types including `string`,`double`,`bool`,
`array`,`object`, you also can define more in the file `JSONValue.h` and then make corresponding modifications in the 
files `JSONParse.h`, `JSONParse.cpp`. This project can complete parsing of the following JSON examples
```JSON
{
  "config": [
    {
      "id": 1,
      "first_name": "Jeanette",
      "last_name": "Penddreth",
      "email": "jpenddreth0@census.gov",
      "gender": "Female",
      "ip_address": "26.58.193.2"
    },
    {
      "id": 2,
      "first_name": "Giavani",
      "last_name": "Frediani",
      "email": "gfrediani1@senate.gov",
      "gender": "Male",
      "ip_address": "229.179.4.212"
    }
  ]
}
```




