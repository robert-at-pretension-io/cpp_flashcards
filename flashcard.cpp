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

std::vector<std::string> get_vector(std::vector<std::string> v) {
    std::string string;
        std::cout << "Enter a word then press enter. When you are finished, enter the word done." << std::endl;
        while(string != "done" ) {
        string = get_string(string);
        v.push_back(string);
        }
    return v;
}

std::vector<std::string> get_vector(std::vector<std::string> v, int n) {
std::string string;
std::cout <<"Enter a word then press enter. You must enter " << n << " words." << std::endl;
    while(n-- > 0){

        string = get_string(string);
        v.push_back(string);
}
return v;
}

bool yes_or_no() {
    std::string string;
    std::cout << "Please enter yes or no" << std::endl;
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


class flashcard {
private:
    std::string question;
    std::string answer;
    std::vector<std::string> tags; //all of the tags must be mentioned in the user entered answer for the flash card to be marked as correct
    bool atomic; //this flag determines if a particular flashcard is the most simple and/or most general definition. For instance, "red" is the most simple concept in the domain of primary colors and this flag would be set to true. But "red," in the domain of physics, could have many different tags. So a flashcard may only have one tag, in this case the atomic field is set to false. If the flashcard has one tag and atomic is set to true then that flashcard is atomic- as defined above.
    short priority;
    short times_seen;
    short times_correct;
    short times_incorrect;
    short correct_streak;
public:
    flashcard() : priority {4} ,times_seen {0},  times_correct {0}, times_incorrect {0}, correct_streak {0} {
        std::cout << "Enter the question that will appear on the flashcard" << std::endl;
        question = get_string(question);
        std::cout << "Enter the answer that will appear on the flashcard" << std::endl;
        answer = get_string(answer);
        std::cout << "Is this a basic concept that cannot be defined in terms of other related concepts?" << std::endl;
        atomic = yes_or_no();
        if (atomic == false) {
            std::cout << "Enter the concepts that are directly related to answering this card correctly." << std::endl;
            tags = get_vector(tags);
        }
        else {
            std::cout << "Various ways this concept could be uniquely refered to as." << std::endl;
            get_vector(tags);

}
        };
        ~flashcard() {};
    };

    class stack {
    private:
        std::string name;
        std::vector<flashcard> stck;
    public:
        stack(std::string nm) : name {nm} {};
        void add_card() {
            flashcard card;
            stck.push_back(card);
            return;
        }
    };
    int main() {
    
std::vector<std::string> vs;
vs = get_vector(vs,3);
for (auto x : vs){
std::cout << x << std::endl;
}

}
