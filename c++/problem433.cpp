#include <iostream>
#include <vector>

int E(long x, long y)
{
   long xn, yn;
   int n = 0;
   do
   {
      ++n;
      xn = y;
      yn = x % y;
      x = xn;
      y = yn;
   } while(yn != 0);
   return n;
}

long long Ss = 0;
long SN = 0;

long long S(long N)
{
   long long sum = Ss;
   while(SN < N)
   {
      std::cout << "S(" << ++SN << ") = ";
      for(long i = 1; i <= SN; ++i)
      {
         for(long j = (i == SN ? 1 : SN); j <= SN; ++j)
         {
            sum += E(i, j);
         }
      }
      std::cout << sum << std::endl;
   }
   return Ss = sum;
}

int main(int argc, char **argv)
{
   std::cout << (S(1) == 1) << std::endl;
   std::cout << (S(10) == 221) << std::endl;
   std::cout << (S(100) == 39826) << std::endl;
   std::cout << (E(1,1) == 1) << std::endl;
   std::cout << (E(10,6) == 3) << std::endl;
   std::cout << (E(6,10) == 4) << std::endl;
   std::cout << S(5e6) << std::endl;
   return 0;
}