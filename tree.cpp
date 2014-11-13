#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>

void print_set(std::unordered_set<std::string> s) {
    while (!s.empty()) {
        std::cout <<  *s.begin() << " ";
        s.erase(s.begin());
    }
    std::cout << "\n";
}

template<typename Container>
void insert_until(Container& c, std::string s) {
    std::string stop;
    getline(std::cin,stop);
    while(stop != s) {
        c.insert(stop);
        getline(std::cin,stop);
    }
}
template<typename O> //this will be the object the the node contains (in this case a flashcard)
class node {
    public:
    std::string name;
    std::string parent;
    O object;
    node(std::string n, std::string p, O obj) : name {n}, parent {p}, object {obj} {};
    node(std::string n, O obj) : name {n}, object {obj} {};
};

struct tree {
    //std::unordered_set<node> nodes;
    std::unordered_map<std::string, std::unordered_set<std::string>> children;
    tree() {};
};



int main() {
    std::unordered_set<std::string> s;
    std::cout << "Adding 'hello' and 'world' to the set twice\n";
    s.insert("hello");
    s.insert("hello");
    s.insert("world");
    s.insert("world");
    std::cout << "Set contains: ";
    print_set(s);
    std::cout << "Set still contains: ";
    print_set(s);
// now on to maps
    std::unordered_map<std::string,std::unordered_set<std::string>> um;
    insert_until(s,"stop");
    print_set(s);
    std::cout << "what name would you like to map to your set? \n";
    std::string name;
    getline(std::cin,name);
//make a function that returns a map of string to set
}

