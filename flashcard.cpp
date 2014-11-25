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
    if(new_line){ newline();}
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
    output( "Please enter yes or no" ,true);
    newline();
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
class name {
protected:
    std::string concept; //This is the name that will be used as the unique key in the database table
    std::vector<std::string> aliases; //these are all corresponding names for an object
public:
    name() {
        output("Please enter a name for the concept.",true);
        concept = get_string(concept);
        output("Does this name have any aliases?",true);
        if(true_or_false()) {
            aliases = get_vector(aliases);
        }
    };

};

class name_connector : public name {
protected:
    bool atomic; //this flag means that there are no related or dependent concepts, essentially it means it's the highest level in the ontological framework
    std::vector<std::string> related_concepts; //concepts in the same abstract level in the hierarchical ontology
    std::vector<std::string> dependent_concepts; //concepts in the next level up on the hierarchical ontology
public:
    name_connector() : name() {
        output("Does ");
        output(concept);
        output(" have any concepts that it relies on?",true);
        bool relies_on = true_or_false();
        if(relies_on) {
            related_concepts = get_vector(related_concepts);
        }
        output("Does ");
        output(concept);
        output(" have any concepts that are related to it?",true);
        bool related_to = true_or_false();
        if(related_to) {
            dependent_concepts = get_vector(dependent_concepts);
        }
        if(!related_to and !relies_on) {
            atomic = true;
        }

    };

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
    name_connector concept_connector;
    std::vector<flashcard> topic;
public:
concept() { concept_connector {}; };
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
concept rocket_science {};
}
