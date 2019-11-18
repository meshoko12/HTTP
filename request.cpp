
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


}
void add_header(string header ,string value){

  map<string,string>::iterator it =m.find(header);
  if(it !=m.end()){
  if(it->first=="Content-Length" ) it->second=value;
  else

  it->second=it->second+','+ value;

}
  else{
    m.insert(std::make_pair(
      boost::algorithm::trim_copy(header),
      boost::algorithm::trim_copy(value)
    ));

  }

}
void add_header(string header ,string value){

  map<string,string>::iterator it =m.find(header);
  if(it !=m.end()){
  if(it->first=="Content-Length" ) it->second=value;
  else

  it->second=it->second+','+ value;

}
  else{
    m.insert(std::make_pair(
      boost::algorithm::trim_copy(header),
      boost::algorithm::trim_copy(value)
    ));

}}
void div(string s){
  int i=s.find(":");
string header=s.substr(0,i);
string value=s.substr(i+1);
//std::cout << header << '\n';
//std::cout << value << '\n';

add_header(header ,value);}



    void print()    {
      for(auto& kv: m) {
        std::cout << "KEY: `" << kv.first << "`, VALUE: `" << kv.second << '`' << std::endl;
      }
    }
string get_v(string s){
  map<string,string>::iterator it =m.find(s);
  if(it!=m.end())return (it->second);
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
void set (std::string l )
{
  std::istringstream resp(l);
  resp >> method >> url >> version;
  h.set(l);

}



void print() {
  std::cout << "method: " << method << " url: " << url << " version: " << version << std::endl;
  h.print();
}
void get(string s){
cout<<h.get_v(s);
}
};

int main(){
  string  s = "GET  /test.html Http/1.1\r\n"
    "Content-Type: image/jpeg; charset=utf-8\r\n"
    "Test: hi 123 \r\n"
    "Content-Length: 2\r\n\r\n";
Request r;
r.set(s);
//r.print();
/*string l="Test: hi 124 135 \r\n"
"Content-Length: 10\r\n";*/

r.print();

//r.get("Content-Length\n");


return 0;}
