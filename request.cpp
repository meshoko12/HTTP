#include<iostream>
#include<string>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <map>
#include <boost/algorithm/string.hpp>

using namespace std;

class Headers{
private:
std::map<std::string, std::string> m;
public:

void set(std::string s){

std::istringstream resp(s);
  std::string header;
  std::string::size_type index;
  while (std::getline(resp, header) && header != "\r") {
    index = header.find(':', 0);
    if(index != std::string::npos) {
      m.insert(std::make_pair(
        boost::algorithm::trim_copy(header.substr(0, index)),
        boost::algorithm::trim_copy(header.substr(index + 1))
      ));
    }
  }

  for(auto& kv: m) {
    std::cout << "KEY: `" << kv.first << "`, VALUE: `" << kv.second << '`' << std::endl;
  }
}
};

class Request{
private:
string method;
string url ;
string version;
Headers h;
//string data;
public:
void set (std::string l)
{
  std::istringstream resp(l);
  resp >> method >> url >> version;
  h.set(l);
}

void print() {
  std::cout << "method: " << method << " url: " << url << " version: " << version << std::endl;
}
};

int main(){
 const std::string s = "GET  /test.html Http/1.1\r\n"
    "Content-Type: image/jpeg; charset=utf-8\r\n"
    "Test123: hi 123\r\n"
    "Content-Length: 19912\r\n\r\n";
Request r;
r.set(s);
r.print();



return 0;}
