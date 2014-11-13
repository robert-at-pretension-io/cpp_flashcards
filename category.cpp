#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class category {
private:
    string name;
    string parent;
public:
    bool top_level;
    category(string n) : name {n},top_level {true}  {};
    category(string n, string p) : name {n}, parent {p},top_level {false} {};
    void print() {
        if(!top_level) {
            cout << "category '" << name << "' has parent '" << parent << "'\n";
        }
        else {
            cout << "category '" << name  << "'\n";
        }
    }
    string parent(){
    return parent;
}
};

namespace simple {
template<typename T>
bool search(vector<T> v,T t) {
    bool answer =  binary_search(v.begin(),v.end(),t);
    return answer;
}
string expect(vector<string>& v) {
    cout << "Please enter one of these options: ";
for (string x: v) {
        cout << x << " ";
    }
    cout << "\n";
    string input;
    getline(cin,input);
for (string x: v) {
        if (x == input) {
            return input;
        }
    }
    return expect(v);
    return "error";
}
}
class tree {
private:
    vector<category> pool;
    vector<string> names;
    vector<string> top_level;
    unordered_map<string,unordered_set<string>> children;

public:
    tree() {};
    void add_category(string n, string p) {
        //replace these stupid if else statements with invariants enforced with exceptions
        if(simple::search(names,p)) {
            cout << "No parent exists\n";
            return;
        }
        if(simple::search(names,n)) {
            cout << "Name already exists\n";
            return;
        }
        else {
            category a(n,p);
            pool.push_back(a);
            names.push_back(n);
        }
    }
    void add_category(string n) {
        if(simple::search(names,n)) {
            top_level.push_back(n);
            names.push_back(n);
            category a(n);
            pool.push_back(a);
        }
    }
    void print_top_level() {
for (auto x:pool) {
            if(x.top_level) {
                x.print();
            }
        }
    }
};

void add_node(tree& a) {

    cout << "What type of category would you like to enter? A top level category or a category with a parent? \n";
    vector<string> acceptable = {"top","parent"};
    string answer;
    answer = simple::expect(acceptable);
    
    if (answer == "top"){
        cout << "Enter the category name: ";
        string name;
        getline (cin, name);
        a.add_category(name); 
}
    if (answer == "parent"){
        cout << "Enter the category name: ";
        string name1;
        getline (cin, name1);
        cout << "Enter the name of the parent: ";
        string parent;
        getline (cin, parent);
        a.add_category(name1,parent);
    }
}

    int main() {
        tree a;
        add_node(a);
        
    }

