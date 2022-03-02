//n² + an + b, where |a| < 1000 and |b| < 1000
//find the borduct of a and b that produces the most consective primes for n >= 0

#include <iostream>
#include <vector>
#include <cmath>
#include <vector>

std::vector<long> primes;

void init_primes_list()
{
   primes.push_back(2);
   primes.push_back(3);
   return;
}

bool is_prime(long x)
{
   std::vector<long>::iterator iter;
   if(x != 2 && x % 2 == 0)
   {
      return false;
   }
   
   if(*primes.rbegin() > x)
   {
      for(iter = primes.begin(); iter != primes.end(); ++iter)
      {
         if(*iter == x)
         {
            return true;
         }
      }
   }
   else if(*primes.rbegin() < x)
   {
      long sqrt_x = sqrt(x);
      for(iter = primes.begin(); iter != primes.end() && *iter <= sqrt_x + 1; ++iter)
      {
         if(x % *iter == 0)
         {
            return false;
         }
      }
      for(long i = *primes.rbegin() + 2; i < x; i += 2)
      {
         if(is_prime(i))
         {
            primes.push_back(i);
            if(x % i == 0)
            {
               return false;
            }
         }
      }
      return true;
   }
   else
   {
      return true;
   }
   
   return false;
}

int main(int argc, char **argv)
{
   long a, b, n;
   int max_consecutive = 0;
   long max_product;
   init_primes_list();
   
   for(a = -999; a < 1000; ++a)
   {
      for(b = -999; b < 1000; ++b)
      {
         for(n = 0; is_prime(n*n + a*n + b); ++n);
         if(n > max_consecutive)
         {
            max_product = a * b;
            max_consecutive = n;
         }
      }
   }
   
   std::cout << max_product << std::endl;
   
   return 0;
}