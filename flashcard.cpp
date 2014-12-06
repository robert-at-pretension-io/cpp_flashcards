#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
/*
Created by Robert Elliot Pahel-Short some time during late October of 2014
who: for anyone who needs to understand a topic
what: an ontologically based, systematic way of studying
when: using this application at least once a day will help solidify an understanding of a topic of study
where: currently, the application is confined to the command prompt, in the future it will be a web app and mobile device app (i.e. iphone app, android app, windows phone app)
why: because I'm tired of not having a systematic form of measuring learning of a subject
*/



///////////////////////////////////////////////////////////////////////////////////////////
// These are input wrappers so that this can be easily ported to have other input methods//

std::string get_string(std::string string) {
    std::cin >> string;
    return string;
}

void newline() {
    std::cout << std::endl;
}
template<typename T>
void output(T thing, bool new_line=false) noexcept {
    std::cout << thing;
    if(new_line) {
        newline();
    }
    return;
}
std::vector<std::string> get_vector(std::vector<std::string> v) {
    std::string string;
    output("Enter a word then press enter. When you are finished, enter the word done.",true);
    while(string != "done" ) {
        string = get_string(string);
        v.push_back(string);
    }
    return v;
}

std::vector<std::string> get_vector(std::vector<std::string> v, int n) {
    std::string string;
    output("Enter a word then press enter. You must enter ");
    output(n);
    output(" words.",true);
    newline();
    while(n-- > 0) {

        string = get_string(string);
        v.push_back(string);
    }
    return v;
}

void print_vector(std::vector<std::string> v) {
for (std::string i : v) output(i,true);
}

std::vector<std::string> intersection(std::vector<std::string> v1, std::vector<std::string> v2) {
    std::vector<std::string> overlap;
    std::sort(v1.begin(),v1.end());
    std::sort(v2.begin(),v2.end());
    std::set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(overlap));
    return overlap;
}

std::vector<std::string> remove_item(std::vector<std::string> v, std::string remove_me) {
    v.erase(std::remove(v.begin(), v.end(), remove_me), v.end());
    return v;
}

std::string choose(std::vector<std::string> options){
output("Choose from the following options:",true);
print_vector(options);
std::string choice = get_string(choice);
auto it = std::find(options.begin(),options.end(),choice);
while(choice != *it){
std::string choice = get_string(choice);
output("That was not a choice");
it = std::find(options.begin(),options.end(),choice);
}
return choice;
}

std::vector<std::string> minus(std::vector<std::string> v, std::vector<std::string> take_these_out) {
    std::vector<std::string> overlap = intersection(v,take_these_out);
for (std::string each : overlap) {
        v = remove_item(v, each);
    }
    return v;
}

std::vector<std::string> add_unique_items(std::vector<std::string> v1, std::vector<std::string> v2) {
    std::vector<std::string> overlap = intersection(v1,v2);
    v2 = minus(v2,overlap);
for (std::string add_this : v2) v1.push_back(add_this);
    return v1;
}




bool true_or_false() {
    std::string string;
    output( "(yes or no): ");
    while (string != "yes" or string != "no") {
        string = get_string(string);
        if (string == "yes") {
            return true;
        }
        if (string == "no") {
            return false;
        }
        output("please enter yes or no: ");
    }
    return false;
}

class menu {

std::map<std::string, void(*)()> fmap;


public:
menu(std::map<std::string, void(*)()> m) : fmap{m} {
}

void choose_option(){
std::vector<std::string> v;
for(std::map<std::string,f>::iterator it = fmap.begin(); it != fmap.end(); ++it) {
    v.push_back(it->first);
    output(it->first,true);
}
std::string choice = choose(v);
fmap[choice]();
}

};

///////////////////////////////////////////////////////////////////////////////////////////
class names {
protected:
    std::string unique_name; //This is the name that will be used as the unique key in the database table
    std::vector<std::string> all_names; //these are all corresponding names for an object
    std::string explanation; //this will contain the explaination of the namespace
public:
    names(std::string str="Enter aliases for a singular concept.") : explanation {str}  {
        //name the concept
        output(explanation,true);
        all_names = get_vector(all_names);
        unique_name = all_names[0];
    }
    bool look_for(std::string string) {
for (std::string x : all_names) {
            if (string == x) {
                return true;
            }
        }
        return false;
    }
    std::vector<std::string> return_names() {
        return all_names;
    }
    


};
class object {
public:
    std::string name;
};

class flashcard : public object {
private:
    std::string question;
    std::string answer;
    std::vector<std::string> mention_these_terms; //all these terms must be mentioned to get the card 100% correct
public:
    flashcard() {
        name = "flashcard";
        output("Q: ");
        question = get_string(question);
        newline();
        output("A: ");
        answer = get_string(answer);
        newline();
        output("What terms must be mentioned to get this card completely correct?");
        mention_these_terms = get_vector(mention_these_terms);
    };
    ~flashcard() {};
};




class relations : public names {
protected:
    bool atomic; //this flag means that there are no related or dependent concepts, essentially it means it's the highest level in the ontological framework
    std::vector<std::string> dependency_names; //concepts in the next level up on the hierarchical ontology
    std::vector<object> objects;
public:
    relations() : names() {
        output("Does ");
        output(unique_name);
        output(" have any more simple concepts that it relies on? ");
        bool relies_on = true_or_false();
        if(relies_on) {
            dependency_names = get_vector(dependency_names);
        }
        if(!relies_on) {
            atomic = true;
        }

    };
    void add_object(object o){
    objects.push_back(o);
}

    std::vector<std::string> dependencies() {
        return dependency_names;
    }
    bool operator==(relations r1){
    if ((this->all_names == r1.all_names) and (this->dependency_names == r1.dependency_names)) return true;
    else return false;
}
    bool operator!=(relations r1){
    if ((r1.all_names == this->all_names) and (r1.dependency_names == this->dependency_names)) return false;
    else return true;
}
    
    void merge(relations r1){
    all_names = add_unique_items(all_names, r1.all_names);
    dependency_names = add_unique_items(dependency_names, r1.dependency_names);
}
    
    void print_dependenies_and_names(){
   output("The name of the concept is: ",true);
    output(this->unique_name,true);
    output("The concepts that this depends on are: ",true);
    print_vector(this->dependency_names);
}
    
};



class domain {
    std::string name_of_domain; //the name of the domain must not exist in the namespace, in other words, it must be unique as well.
    std::vector<relations> pool_of_relations;
    std::vector<std::string> pool_of_unconnected_concepts;

public:
    domain() {
        output("What would you like to name this domain? ");
        name_of_domain = get_string(name_of_domain);
        relations first {};
        pool_of_relations.push_back(first);
        pool_of_unconnected_concepts = first.dependencies();
    };
    relations name_space_overlap(relations this_relation) {
    
        std::vector<std::string> new_relation_names = this_relation.return_names();
for (relations& existing_relation : pool_of_relations) {
for (std::string new_name : new_relation_names) {
                if(existing_relation.look_for(new_name)) {
                    
                return existing_relation;
                }
            }
        }
    return this_relation;

    }

        void update_unconnected_concepts(relations& newr){
        
        std::vector<std::string> new_relation_dependencies = newr.dependencies();
        std::vector<std::string> new_relation_names = newr.return_names();
        pool_of_unconnected_concepts = minus(pool_of_unconnected_concepts, new_relation_names);
        pool_of_unconnected_concepts = add_unique_items(pool_of_unconnected_concepts, new_relation_dependencies);
}

    void add() {
        relations new_relation {};
        std::vector<std::string> new_relation_dependencies = new_relation.dependencies();
        std::vector<std::string> new_relation_names = new_relation.return_names();
       //if the relation namespace already exists within our pool of relations then merge the newly created relation with the pre-existing relation 
relations temp = name_space_overlap(new_relation);
        if(temp != new_relation){
            
            temp.merge(new_relation);
            output("The concept that you just created already exists within the domain, so it has been merged with the existing namespace",true);
            update_unconnected_concepts(temp);
        } 

            //Would you like to see the overlap? You'll be given the option to merge relations, choose which relation is better or disregard the newly created concept entirely.
        

//we got through all the aliases and there are no overlaps, cool, let's modify the pool_of_unconnected_concepts to be only those concepts that have no definition
        output("Would you like to add a flashcard? ");
        bool answer = true_or_false();
        if(answer) {
            flashcard new_card {};
            new_relation.add_object(new_card);
            flashcard this_card {};
        }
    }
};




class user {
std::string username;
std::vector<domain> studying_these_topics;
public:
user() {output("What is your username? ");
username = get_string(username);
domain newd {};
studying_these_topics.push_back(newd);
};

};

class stats {
    user this_guy;
    flashcard this_flashcard;
    short priority;
    short times_seen;
    short times_correct;
    short times_incorrect;
    short correct_streak;
};

void print_1(){
output(1,true);
return;
}

int main() {
std::map<std::string, void (*)()> m;
m["output"] = print_1;
menu newm = m;
newm.choose_option();
}
