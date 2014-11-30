#include <string>
#include <vector>
#include <iostream>
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
///////////////////////////////////////////////////////////////////////////////////////////
class names {
protected:
    std::string unique_name; //This is the name that will be used as the unique key in the database table
    std::vector<std::string> all_names; //these are all corresponding names for an object
    std::string explanation; //this will contain the explaination of the namespace
public:
    names(std::string str="Enter all names of the conceptual node.") : explanation{str}  {
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


};

class relations : public names {
protected:
    bool atomic; //this flag means that there are no related or dependent concepts, essentially it means it's the highest level in the ontological framework
    std::vector<std::string> dependent_names; //concepts in the next level up on the hierarchical ontology
public:
    relations() : names() {
        output("Does ");
        output(unique_name);
        output(" have any concepts that it relies on? ");
        bool relies_on = true_or_false();
        if(relies_on) {
            dependent_concepts = get_vector(dependent_concepts);
        }
        if(!relies_on) {
            atomic = true;
        }

    };
    std::vector<std::string> dependencies(){
    return dependent_concepts;
}

};

class domain {
    std::vector<relations> pool_of_names_and_relations;
    std::vector<std::string> pool_of_unconnected_concepts;

public:
    domain() { 
    
    }

    void add(){
    relations new_relation {};
    // Add functions here that will add the new_relation to the pool_of_names_and_relations if there are no namespace overlap. If there is namespace overlap then try to resolve it by appending the dependent and aliases to the pre-existing relations object


    }
};



class flashcard {
private:
    std::string question;
    std::string answer;
    std::vector<std::string> mention_these_terms; //all these terms must be mentioned to get the card 100% correct
public:
    flashcard() {};
    ~flashcard() {};
};

class concept {
    domain concept_domain;
    std::vector<flashcard> topic;
public:
    concept() {  };
};


class category {
private:
    std::vector<concept> node;
};

class user {
private:
    std::vector<category> my_current_study;
    std::vector<std::string> my_interests;
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


int main() {
}
