/** In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:
*  1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
*
*  It is possible to make £2 in the following way:
*  1*£1 + 1*50p + 2*20p + 1*5p + 1*2p + 3*1p
*
*  How many different ways can £2 be made using any number of coins?
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

template <typename T>
class Backtrack
{
public:
    Backtrack() {}
    virtual ~Backtrack() {}

    void backtrack(T P)
    {
        this->P = P;
        bt(root(this->P));
    }

protected:
    virtual T root(T) = 0;
    virtual bool reject(T, T) = 0;
    virtual bool accept(T, T) = 0;
    virtual T first(T, T) = 0;
    virtual T next(T, T) = 0;
    virtual void output(T, T) = 0;

private:
    T P;

    void bt(T c)
    {
        if (reject(P, c))
            return;
        if (accept(P, c))
            output(P, c);

        T s = first(P, c);
        while (!s.empty())
        {
            bt(s);
            s = next(P, s);
        }
    }
};

int sum(std::vector<int> nums)
{
    int s = 0;
    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
        s += *it;
    }
    return s;
}

class Coins : public Backtrack< std::vector<int> >
{
private:
    std::vector<int> COIN_VALS;// = {1, 2, 5, 10, 20, 50, 100, 200};
    int count;
    std::map< std::vector<int>, int > m;

public:
    Coins()
    {
        COIN_VALS.push_back(1);
        COIN_VALS.push_back(2);
        COIN_VALS.push_back(5);
        COIN_VALS.push_back(10);
        COIN_VALS.push_back(20);
        COIN_VALS.push_back(50);
        COIN_VALS.push_back(100);
        COIN_VALS.push_back(200);
        count = 0;
        backtrack(COIN_VALS);
    }

    std::vector<int> root(std::vector<int> P)
    {
        return std::vector<int>(0);
    }

    bool reject(std::vector<int> P, std::vector<int> c)
    {
        return (sum(c) > 200);
    }

    bool accept(std::vector<int> P, std::vector<int> c)
    {
        return (sum(c) == 200);
    }

    std::vector<int> first(std::vector<int> P, std::vector<int> c)
    {
        c[0]++;
        return c;
    }

    std::vector<int> next(std::vector<int> P, std::vector<int> s)
    {
        if (s.size() > 0)
        {
            int last = s.back();
            for (auto it = P.begin(); it != P.end(); ++it)
            {
                if (last < *it)
                {
                    s.pop_back();
                    s.push_back(*it);
                    return s;
                }
            }
        }
        return std::vector<int>(0);
    }

    void output(std::vector<int> P, std::vector<int> c)
    {
        if (m[c]++ > 0)
            return;

        std::stringstream ss;
        ss << count << " = ";
        for (auto it = c.begin(); it != c.end(); ++it)
        {
            ss << *it << ", ";
        }
        std::cout << ss.str() << std::endl;
        count++;
    }

    int getCount()
    {
        return count;
    }
};

int main(int argc, char** argv)
{
    Coins c;
    std::cout << c.getCount() << std::endl;
    std::cin.get();
    return 0;
}
