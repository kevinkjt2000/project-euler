#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<long long> pents;
void generate_pents(long long index) {
    for(long long i = pents.size()+1; i <= index; i++) {
        pents.push_back(i * (3*i - 1) / 2);
    }
}

bool isPent(long long n) {
    return binary_search(pents.begin(), pents.end(), n);
}

int main() {
    generate_pents(1000000000);
    
    for(size_t n = 3; n < pents.size(); n += 3) {
        size_t x = pents[n]/3;
        /*cout << x << " ";
        if(x+1 < pents.size()) {
            cout << pents[x] << "\n";
        }*/
        if(x < pents.size() && isPent(pents[x]+pents[x-1])) {
            cout << pents[n] << " " << pents[x];
            break;
        }
    }
    
    return 0;
}
