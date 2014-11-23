#include <string>
#include <vector>
#include <iostream>
/*
Created by Robert Elliot Pahel-Short some time during late October of 2014
who: for anyone who needs to understand a topic
what: an ontologically based, systematic way of studying
when: using this application at least once a day will help solidify an understanding of a topic of study
where: currently, the application is confined to the command prompt, in the future it will be a web app
why: because I'm tired of not having a systematic form of measuring learning of a subject
*/



///////////////////////////////////////////////////////////////////////////////////////////
// These are input wrappers so that this can be easily ported to have other input methods//
std::string get_string(std::string string) {
    std::cin >> string;
    return string;
}
template<typename T>
void output(T thing) noexcept {
    std::cout << thing;
    return;
}
void newline(){
std::cout << std::endl;
}
std::vector<std::string> get_vector(std::vector<std::string> v) {
    std::string string;
    output("Enter a word then press enter. When you are finished, enter the word done.");
    while(string != "done" ) {
        string = get_string(string);
        v.push_back(string);
    }
    return v;
}

std::vector<std::string> get_vector(std::vector<std::string> v, int n) {
    std::string string;
    output("Enter a word then press enter. You must enter "); output(n); output(" words."); newline();
    while(n-- > 0) {

        string = get_string(string);
        v.push_back(string);
    }
    return v;
}

bool yes_or_no() {
    std::string string;
    output( "Please enter yes or no" ); newline();
    while (string != "yes" or string != "no") {
        string = get_string(string);
        if (string == "yes") {
            return true;
        }
        if (string == "no") {
            return false;
        }
    }
    return false;
}
///////////////////////////////////////////////////////////////////////////////////////////
class unqiue_name {
    std::string atomic_name; //this is the name of an object (must be unqiue within the level of abstraction) This also allows for cool proper usage with databases
};

class unique_hierarchy {
    std::vector<std::string> related_concepts; //concepts in the same abstract level in the hierarchical ontology
    std::vector<std::string> dependent_concepts; //concepts in the next level up on the hierarchical ontology
    std::vector<std::string> atomic_name_aliases; //these are all corresponding names for an object
    protected:
    
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

class stack {
private:
    std::vector<flashcard> a_stack;
public:
};


class category {
private:
    std::vector<stack> node;
};

class user{
private:
    std::vector<stack> my_cards;
    std::vector<std::string> my_interests;
};

class stats{
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
