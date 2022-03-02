#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while(a != b) {
        if(a > b) {
            a -= b;
        } else {
           b -= a;
        }
    }
    return a;
}

bool test(short i, short j) {
    short a = i / 10;
    short b = i % 10;
    short c = j / 10;
    short d = j % 10;
    
    double r = (double)i/j;
    
    return (a == c && (double)b/d == r)
        || (a == d && (double)b/c == r)
        || (b == c && (double)a/d == r)
        || (b == d && (double)a/c == r);
}

int main() {
    int num = 1;
    int den = 1;
    for(short i = 10; i < 100; i++) {
        if(i % 10 == 0) continue;
        for(short j = i+1; j < 100; j++) {
            if(test(i,j)) {
                cout << i << "/" << j << "\n";
                num *= i;
                den *= j;
            }
        }
    }
    cout << den / gcd(num, den) << "\n";
    
    return 0;
}
