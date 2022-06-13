#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"


#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace rapidjson;
using namespace std;

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
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.Key(buf);
    writer.String(buf);
    writer.EndObject();
    return 0;
  }
    
}
