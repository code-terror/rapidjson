// JSON simple example
// This example does not handle errors.

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace rapidjson;

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
    Document d;
    d.Parse(buf);
    return 0;
  }
    
}
