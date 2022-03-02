#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    long long sum = 0;
    for(long product = 999999; product > 0; product--) {
        for(int multiplier = 2; multiplier < sqrt(product); multiplier++) {
//test if an multiplicand/multiplier/product identity is 1-9 pandigital
            if(product % multiplier == 0) {
                stringstream ss;
                ss << product << multiplier << product/multiplier;
                string str = ss.str();
                sort(str.begin(), str.end());
                if(str == "123456789") {
                    sum += product;
                    cerr << product << "\n";
                    break;
                }
            }
        }
    }
    cout << sum;
    
    return 0;
}
