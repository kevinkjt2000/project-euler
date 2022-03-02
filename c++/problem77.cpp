#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

// this sequence looks related https://oeis.org/A173244
// actually it is this sequence https://oeis.org/A000607

bool is_prime(unsigned long long x) {
    unsigned long root = std::floor(std::sqrt(x));
    if(x < 2) return false;
    if(x != 2 && x%2 == 0) return false;
    for(unsigned long d = 3; d <= root; d += 2) {
        if(x%d == 0) return false;
    }
    return true;
}

int main() {
    std::vector<unsigned long long> primes;
    std::vector< std::vector<unsigned long long> > table;
    std::vector<unsigned long long> sums(1, 1);
    primes.push_back(2);
    table.emplace_back(1, 1);
    unsigned long long x = 3;
    unsigned long long max = 10000000000;
    
    while(sums.back() <= max) {
        while(!is_prime(x)) { x += 2; }
        primes.push_back(x);
        size_t prev = table[0].size();
        size_t size = prev + (x - prev) - 1;
        table.emplace_back(size, 0);
        for(auto& row : table) {
            row.resize(size, 0);
        }
        sums.resize(size, 0);
        std::cout << "Pushed " << x << std::endl;
        for(size_t j = prev; j < size; ++j) {
            for(size_t p = 0; p < primes.size(); ++p) {
                unsigned long long diff = j + 2 - primes[p];
                if(j + 2 == primes[p]) {
                    table[p][j] = 1;
                    sums[j] += 1;
                } else if(j >= primes[p]) {
                    unsigned long long partialColumnSum = 0;
                    for(size_t i = p; i < table.size(); ++i) {
                        partialColumnSum += table[i][diff - 2];
                    }
                    table[p][j] = partialColumnSum;
                    sums[j] += partialColumnSum;
                }
            }
        }
        //int width = log10(sums.back()) + 1;
        /*
        std::cout << "Table: " << table.size() << " x " << size << std::endl;
        for(size_t i = 0; i < table.size(); ++i) {
            for(size_t j = 0; j < size; ++j) {
                std::cout << std::setw(width) << table[i][j] << " ";
            }
            std::cout << std::endl;
        }
        for(size_t j = 0; j < sums.size(); ++j) {
            std::cout << std::setw(width) << sums[j] << " ";
        }
        std::cout << std::endl << std::endl;
        //*/
        x += 2;
    }
    
    size_t answer = 0;
    while(sums[answer] <= max) {
        answer++;
    }
    std::cout << "Answer: " << answer + 2 << std::endl;
    
    return 0;
}
