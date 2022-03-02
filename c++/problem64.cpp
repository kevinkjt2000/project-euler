#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct thing {
    int left;
    int numer;
    int right;
    
    thing(int l, int d, int r): left(l), numer(d), right(r) {}
    bool operator== (thing rhs) {
        return this->left  == rhs.left &&
               this->numer == rhs.numer &&
               this->right == rhs.right;
    }
    
    friend std::ostream& operator<< (std::ostream& out, thing& rhs) {
        out << rhs.left << " " << rhs.numer << " " << rhs.right << "\n";
    }
};

int gcd(int a, int b)
{
   if(a == 0)
      return b;
   else if(b == 0)
      return a;
   else if(a > b)
      return gcd(a % b, b);
   else
      return gcd(a, b % a);
}

int periodLength(int x) {
    std::cerr << x << "\n";
    std::vector<thing> things;
    
    int s = sqrt(x);
    things.push_back(thing(s, 1, s));
    std::cerr << things.back();
    
    bool found;
    int index;
    thing next(s, 1, s);
    do {
        thing prev = things.back();
        next.numer = (x - prev.right * prev.right) / prev.numer;
        next.right = abs(prev.right - next.numer);
        next.left = s; //prev.left / (2*prev.right) ;
        std::cerr << next;
        
    //while next is not in things
        auto iter = std::find(things.begin(), things.end(), next);
        found = (things.end() != iter);
        index = iter - things.begin();
        things.push_back(next);
    } while(!found);
    
    return index;
}

bool isPerfectSquare(int x) {
    return (sqrt(x) == (int)sqrt(x));
}

int main(int argc, char* argv[]) {
    int numOfOddLengths = 0;
    for(int i = 2; i <= 23; i++) {
        if(!isPerfectSquare(i) && periodLength(i) % 2 == 1) {
            numOfOddLengths++;
        }
    }
    
    std::cout << numOfOddLengths << "\n";
    
    return 0;
}

