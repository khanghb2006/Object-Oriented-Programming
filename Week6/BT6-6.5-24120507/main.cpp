#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <algorithm>
#include <unordered_map>

// void input(std::unordered_map<double , int>& freq) {
//     std::string buffer;
//     std::getline(std::cin , buffer);
//     if (!buffer.size())
//         throw std::invalid_argument("Empty input");

//     // initialize frequency map
//     freq.clear();

//     // regex to match valid marks {"Name", Mark}}
//     std::regex input_pattern(R"(\{\s*\"([A-Za-z]+)\"\s*,\s*([0-9]+)\s*\})");
//     auto input_begin = std::sregex_iterator(buffer.begin() , buffer.end() , input_pattern);
//     auto input_end = std::sregex_iterator();

//     if (input_begin == input_end) 
//         throw std::invalid_argument("No valid input");

//     // iterate through all matches and count the frequency of each mark
//     for (auto it = input_begin; it != input_end; it++) {
//         std::string name = it->str(1);
//         double mark = std::stof(it -> str(2));
//         // std::cout << "Name: " << name << ", Mark: " << mark << std::endl;
//         freq[mark]++;
//     }
// }

void input(std::unordered_map<double , int> &freq) {
    std::string buffer;
    std::stringstream ss;

    std::cout << "Enter the list of student's name and student's mark" << "\n";
    std::cout << "If want to stop, just enter an empty line" << "\n";
    int cnt = 1;
    while(true) {
        std::cout << "Enter the " << cnt << " student" << "\n";
        std::getline(std::cin , buffer);
        
        //End of the input
        if (!buffer.size()) break;

        ss.clear();
        ss.str(buffer);
        
        std::vector<std::string> data;
        std::string temp;
        while(ss >> temp) data.push_back(temp);
        
        //valid name is only alphabetic characters
        auto valid_name = [] (const std::string &name) {
            for (char c : name) 
                if (!isalpha(c)) return false;
            return true;
        };

        // get the student's mark
        ss.clear();
        ss.str(data.back());
        double mark;
        if (!(ss >> mark)) 
            throw std::invalid_argument("Invalid student's mark input");
        data.pop_back(); // remove the mark from data
        if (mark < 0 || mark > 10)
            throw std::invalid_argument("Student's mark out of range");

        // check if valid student's name
        for (auto it = data.begin() ; it != data.end() ; it++) 
            if (!valid_name(*it))
                throw std::invalid_argument("Invalid student's name input");

        // increase the frequency of the mark
        freq[mark]++;
        cnt++;
    }
}

void output(const std::unordered_map<double, int>& freq) {
    if (!freq.size()) 
        throw std::invalid_argument("No valid data");
    
    std::vector<std::pair<double, int>> mark_freq;

    // iterator insert_back
    auto is = std::back_inserter(mark_freq);
    for (auto it : freq)
        *is++ = it;
    
    // lamda to compare two pairs based on frequency
    auto cmp = [] (const std::pair<double , int>& a , const std::pair<double , int>& b) {
        return a.second > b.second;
    };

    std::sort(mark_freq.begin() , mark_freq.end() , cmp);

    for (auto it : mark_freq) {
        std::cout << "GPA " << it.first << " : " << it.second;
        if (it.second > 1)
            std::cout << " students" << "\n";
        else std::cout << " student" << "\n";
    }
}

int main() {
    try {
        std::unordered_map<double , int> freq;
        input(freq);
        output(freq);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << "\n";
    }
}
