#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool is_not_space(char c) {
    return (!isspace(c));
}

bool is_word(char c) {
    return (isalpha(c) || isdigit(c));
}

bool is_punc_and_space(char c) {
    return (isspace(c) || ispunct(c));
}

void input(std::string  &s) {
    std::cout << "Enter a string: ";
    std::getline(std::cin , s);
}

void rm_space (std::string &s) {
    // remove leading and trailing spaces
    // find the first character
    auto first_char = std::find_if(s.begin() , s.end() , is_not_space);
    auto last_char = std::find_if(s.rbegin() , s.rend() , is_not_space).base();

    s.erase(s.begin() , first_char);
    s.erase(last_char , s.end());
}

void rm_doubly_punc(std::string &s) {
    // remove multiple punctuations between words
    char punc = ' ';
    auto doubly_punc = [&punc] (char x) {
        if (is_word(x) || is_word(punc)) {
            punc = x;
            return false;
        }
        if (x == punc) 
            return true;
        punc = x;
        return false;
    };

    s.erase(std::remove_if(s.begin() , s.end() , doubly_punc) , s.end());
}

void upper_first_char(std::string &s) {
    // Uppercase the first character of each word
    char prev = ' ';
    auto upper_first = [&prev] (char x) mutable {
        if (isalpha(x) && isalpha(prev)) {
            prev = x;
            return std::tolower(x);
        }
        prev = x;
        return std::toupper(x);
    };

    std::transform(s.begin() , s.end() , s.begin() , upper_first);
}

void process(std::string &s) {
    rm_space(s);
    rm_doubly_punc(s);
    upper_first_char(s);
}

int main() {
    std::string s;
    input(s);
    process(s);
    std::cout << s << "\n";
}
