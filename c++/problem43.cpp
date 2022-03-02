#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    long double sum = 0;
    for(long long d1 = 1; d1 <= 9; d1++) {
    for(long long d2 = 0; d2 <= 9; d2++) {
        if(d2 == d1) continue;
    for(long long d3 = 0; d3 <= 9; d3++) {
        if(d3 == d2 || d3 == d1) continue;
    for(long long d4 = 0; d4 <= 8; d4 += 2) {
        //if(d4 % 2 != 0) continue;
    for(long long d5 = 0; d5 <= 9; d5++) {
        if((d3 + d4 + d5) % 3 != 0) continue;
    for(long long d6 = 0; d6 <= 5; d6 += 5) {
        //if(d6 != 0 && d6 != 5) continue;
    for(long long d7 = 0; d7 <= 9; d7++) {
        if((d5*100 + d6*10 + d7) % 7 != 0) continue;
    for(long long d8 = 0; d8 <= 9; d8++) {
        if((d6*100 + d7*10 + d8) % 11 != 0) continue;
    for(long long d9 = 0; d9 <= 9; d9++) {
        if((d7*100 + d8*10 + d9) % 13 != 0) continue;
    for(long long d10 = 0; d10 <= 9; d10++) {
        if((d8*100 + d9*10 + d10) % 17 == 0) {
            long long num = d1*1e9 + d2*1e8 + d3*1e7 +
                            d4*1e6 + d5*1e5 + d6*1e4 +
                            d7*1e3 + d8*1e2 + d9*1e1 + d10;
            stringstream ss;
            ss << d1 << d2 << d3 << d4 << d5 << d6 << d7 << d8 << d9 << d10;
            string str = ss.str();
            sort(str.begin(), str.end());
            if(str == "0123456789") {
                sum += num;
                //cout << num << "\n";
            }
        }
    }}}}}}}}}}
    cout << setprecision(0) << fixed << sum << "\n";
    return 0;
}
