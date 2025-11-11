#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#define OUTPUT_NAME "OUTPUT"
#define INPUT_NAME "INPUT"

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

void input(std::vector<int> &numbers) {
    std::ifstream infile("INPUT.TXT");
    std::stringstream ss;
    std::string buffer;

    auto o = std::back_inserter(numbers);
    // Input
    while(std::getline(infile , buffer)) {
        ss.clear();
        ss.str(buffer);
        int num;
        while (ss >> num) *o++ = num;
        if (!ss.eof() && ss.fail())
            throw std::invalid_argument("Invalid input");
    }
    infile.close();
}

void output(std::vector<int> &numbers) {
    std::ofstream outfile(OUTPUT_NAME".TXT");

    // Remove prime numbers
    numbers.erase(std::remove_if(numbers.begin() , numbers.end() , 
            is_prime) , numbers.end());

    for (auto it : numbers)
        outfile << it << "\n";
    outfile.close();

}

int main() {
    std::vector<int> numbers;
    input(numbers);
    output(numbers);
}