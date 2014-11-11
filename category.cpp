#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class category{
private:
string name;
string parent;
public:
bool top_level;
category(string n) : name{n},top_level{true}  {};
category(string n, string p) : name{n}, parent{p},top_level{false} {};
void print() { 
if(!top_level) {cout << "category '" << name << "' has parent '" << parent << "'\n"; } 
else { cout << "category '" << name  << "'\n";}}

};


class tree{
private:
vector<category> pool;
vector<string> names;
public:
tree(){}; 
void add_category(string n, string p){
auto fi = binary_search(names.begin(),names.end(),n);
if(fi){cout << "Name already exists\n";} else{category a(n,p); pool.push_back(a); names.push_back(n); } }
void add_category(string n){ category a(n); pool.push_back(a); }
void print_top_level() { for (auto x:pool){ if(x.top_level) { x.print(); }}}
};

int main(){
tree a;
a.add_category("root","lib");
a.add_category("root","lib");

}
