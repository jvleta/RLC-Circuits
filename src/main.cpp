#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/stringbuffer.h>

#include <cmath>
#include <cstdio>
#include <vector>

#include "menus.h"
#include "rapidjson/filereadstream.h"

int main() {
  FILE* fp = fopen("/home/jimmy/code/cats/src/stuff.json",
                   "rb");  // non-Windows use "r"

  char readBuffer[65536];
  rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));

  rapidjson::Document d;
  d.ParseStream(is);
  rapidjson::StringBuffer buffer;
  rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
  d.Accept(writer);

  std::cout << buffer.GetString() << std::endl;
  std::cout << d["abc"]["resistance"].GetDouble() << std::endl;
  std::cout << d["def"]["resistance"].GetDouble() << std::endl;

  return 0;
}
