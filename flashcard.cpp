#include <string>

class flashcard {
private:
    std::string name;
    std::string parent;
    std::string front;
    std::string back;
    std::string priority;
    bool admin_approved;
public:
    
};

class stats {
private:
    std::string category;
    flashcard card;
    std::string date_created;
    int times_seen;
    int times_correct;
    int times_incorrect;
    int times_partially_correct;
public:
};

class helper {
private:
    std::string hint;
    std::string question;
    std::string answer;
    std::string feedback;
    flashcard card;
public:
};


int main() {
}

