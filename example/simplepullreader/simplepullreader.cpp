#include "rapidjson/reader.h"
#include <iostream>
#include <sstream>
#include <string.h>
#include <fstream>
#include <stdlib.h>

using namespace rapidjson;
using namespace std;

// If you can require C++11, you could use std::to_string here
template <typename T> std::string stringify(T x) {
    std::stringstream ss;
    ss << x;
    return ss.str();
}

struct MyHandler {
    const char* type;
    std::string data;
    
    MyHandler() : type(), data() {}

    bool Null() { type = "Null"; data.clear(); return true; }
    bool Bool(bool b) { type = "Bool:"; data = b? "true": "false"; return true; }
    bool Int(int i) { type = "Int:"; data = stringify(i); return true; }
    bool Uint(unsigned u) { type = "Uint:"; data = stringify(u); return true; }
    bool Int64(int64_t i) { type = "Int64:"; data = stringify(i); return true; }
    bool Uint64(uint64_t u) { type = "Uint64:"; data = stringify(u); return true; }
    bool Double(double d) { type = "Double:"; data = stringify(d); return true; }
    bool RawNumber(const char* str, SizeType length, bool) { type = "Number:"; data = std::string(str, length); return true; }
    bool String(const char* str, SizeType length, bool) { type = "String:"; data = std::string(str, length); return true; }
    bool StartObject() { type = "StartObject"; data.clear(); return true; }
    bool Key(const char* str, SizeType length, bool) { type = "Key:"; data = std::string(str, length); return true; }
    bool EndObject(SizeType memberCount) { type = "EndObject:"; data = stringify(memberCount); return true; }
    bool StartArray() { type = "StartArray"; data.clear(); return true; }
    bool EndArray(SizeType elementCount) { type = "EndArray:"; data = stringify(elementCount); return true; }
private:
    MyHandler(const MyHandler& noCopyConstruction);
    MyHandler& operator=(const MyHandler& noAssignment);
};

int main(int argc, char *argv[]) {
    if(argc != 2){
    std::cerr << "Must supply a text file\n";
    return -1;
  }

  std::ifstream infile;
  infile.open(argv[1]);

  if (infile.fail()) {
    std::cerr << "Could not open " << argv[1];
    return -1;
  }

  else {
    char buf[12] = "";
    infile.read(buf, sizeof(buf));

    MyHandler handler;
    Reader reader;
    StringStream ss(buf);
    reader.IterativeParseInit();
    while (!reader.IterativeParseComplete()) {
        reader.IterativeParseNext<kParseDefaultFlags>(ss, handler);
    }
    return 0;
  }
   

}
