#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <numeric>

std::mt19937 rd(std::chrono::steady_clock::now().time_since_epoch().count());

int random_function () {
    std::uniform_int_distribution<int> dist(0 , 1e9);
    return dist(rd);
}

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

void random_vector(std::vector<int> &value) {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    // fill the random values in the vector
    int even_value = 1 , idx = 0;
    value.resize(n);
    auto set_value = [&even_value , &idx](int x) mutable{
        // idx++;
        // std::cout << idx << "\n";
        if ((idx++) & 1) return random_function();
        return even_value++;
    };

    std::transform(value.begin() , value.end() ,value.begin() , set_value);
}

void print_vec(const std::vector<int> &vec) {
    for (auto it : vec)
        std::cout << it << " ";
    std::cout << "\n";
}

// fill the prime numbers in the vector
void fill_prime(std::vector<int> &prime) {
    int current = 0;
    // find the next prime
    auto find_prime = [&current] (int x) {
        while(!is_prime(current))
            current++;
        return current++;
    };

    std::transform(prime.begin() , prime.end() , prime.begin() , find_prime);
}

int main() {
    srand(time(NULL));
    std::vector<int> values;
    
    // mission a
    random_vector(values);
    std::cout << "Print the list following initialization: " << "\n";
    std::cout << " +Even indexs : [1 ... (N + 1) / 2]" << "\n";
    std::cout << " +Odd indexs : Random numbers" << "\n";
    print_vec(values);

    // mission b
    std::vector<int> prime(values.size());
    fill_prime(prime);
    std::cout << "Print the list of first N prime numbers: " << "\n";
    print_vec(prime);
}