// Example program
#include <iostream>
#include <string>
#include <cmath>
#include <chrono>

bool is_guessed_num(const int& num, const int& divisible, const int& non_divisible, const int& multiple, const int& non_multiple) {
    return num % divisible == 0 && num % non_divisible != 0 && multiple % num == 0 && non_multiple % num != 0;
}

int main() {
    std::chrono::steady_clock::time_point begin{std::chrono::steady_clock::now()};
    std::chrono::steady_clock::time_point end;
    
    int divisible{0};
    int non_divisible{0};
    int multiple{0};
    int non_multiple{0};
    
    std::cin >> divisible >> non_divisible >> multiple >> non_multiple;
    
    int number{divisible * 2};
    
    while (number <= std::pow(10, 9)) {
        if (is_guessed_num(number, divisible, non_divisible, multiple, non_multiple)) {
            std::cout << number << std::endl;
            end = std::chrono::steady_clock::now();
            std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " milliseconds" << std::endl;
            return 0;
        }
        
        number++;
        std::cout << number << std::endl;
    }
    
    std::cout << -1 << std::endl;
    end = std::chrono::steady_clock::now();
    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " milliseconds" << std::endl;
    
    return 0;
}