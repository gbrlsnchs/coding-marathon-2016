// Example program
#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>

bool is_vowel(const char& letter) {
    return letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u';
}

int main() {
    std::chrono::steady_clock::time_point begin{std::chrono::steady_clock::now()};
    std::chrono::steady_clock::time_point end;
    std::string laughter{};
    std::string reverse_laughter{};
    
    std::cin >> laughter;
  
    for (unsigned int i = 0; i < laughter.size(); i++) {
        if (is_vowel(laughter.at(i))) {
            reverse_laughter += laughter.at(i);
        }
    }
    
    laughter = reverse_laughter;
    std::reverse(reverse_laughter.begin(), reverse_laughter.end());
    
    if (laughter == reverse_laughter) {
        std::cout << 'S' << std::endl;
        end = std::chrono::steady_clock::now();
        std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " milliseconds" << std::endl;
        return 0;
    }
    
    std::cout << 'N' << std::endl;
    end = std::chrono::steady_clock::now();
    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " milliseconds" << std::endl;
    return 0;
}