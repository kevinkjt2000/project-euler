/* Problem 39
 * If p is the perimeter of a right angle triangle with integral
 * length sides, {a,b,c}, there are exactly three solutions
 * for p = 120.
 *
 * {20,48,52}, {24,45,51}, {30,40,50}
 *
 * For which value of p <= 1000, is the number of solutions maximised?
 **/

#include <iostream>

int count_solutions(int perim)
{
    int num_solutions = 0;
    std::cerr << "perim: " << perim << "\n";
    int last_b = -1;
    for(int a = 1; a < perim/3; ++a)
    {
        if(a == last_b)
        {
            break;
        }

        for(int x = 1; x <= a/2; ++x)
        {
            if(a*a % x == 0)
            {
                int y = a*a / x;
                if((y-x) % 2 == 0)
                {
                    int b = (y-x) / 2;
                    int c = (y+x) / 2;
                    if(a+b+c == perim)
                    {
                        std::cerr << a << ", " << b << ", " << c << "\n";
                        num_solutions++;
                        last_b = b;
                    }
                }
            }
        }
    }
    //std::cin.get();
    return num_solutions;
}

int main(int argc, char** argv)
{
    int max_solution = 0;
    int max_perim = 0;
    for(int p = 0; p <= 1000; ++p)
    {
        int num_solutions = count_solutions(p);
        if(num_solutions > max_solution)
        {
            max_solution = num_solutions;
            max_perim = p;
        }
    }

    std::cout << max_perim << "\n";
    return 0;
}

