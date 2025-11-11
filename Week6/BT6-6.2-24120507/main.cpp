#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void input(std::string &palin) {
    std::cout << "Enter a string: ";
    std::getline(std::cin , palin);
}

void rm_invalid_key(std::string &palin) {
    auto invalid_key = [] (char c) {
        return !std::isalpha(c);
    };
    // remove invalid character
    palin.erase(std::remove_if(palin.begin() , palin.end() ,
            invalid_key) , palin.end());
}

// convert all characters to lower case
void to_lower(std::string &palin) {
    auto lower = [] (char c) {
        return std::tolower(c);
    };
    std::transform(palin.begin() , palin.end() , palin.begin() , lower);
}

void proccess(std::string &palin) {
    input(palin);
    rm_invalid_key(palin);
    to_lower(palin);
}

int main() {
    std::string palin;
    proccess(palin);
    
    // check if palindrome
    bool is_palin = std::equal(palin.begin() , palin.begin() , palin.rbegin());

    if (is_palin) std::cout << "Palindrome" << "\n";
    else std::cout << "Not a Palindrome" << "\n";
}