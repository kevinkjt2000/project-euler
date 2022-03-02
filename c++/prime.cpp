#include <stdio.h>
#include <math.h>
#include <vector>
using std::vector;

vector< long long > primes;
vector< long long >::iterator iter;
bool isPrime( long long x )
{
   long long sqrt_x = sqrt( x );
   for( iter = primes.begin(); iter != primes.end() &&
        *iter <= sqrt_x + 1; iter++ )
   {
      if( x % *iter == 0 )
         return false;
   }
   return true;
}

void prime_factorization(long x)
{
   long i; /* counter */
   long c; /* remaining product to factor */
   c = x;
   while ((c % 2) == 0)
   {
      printf("%ld\n",2);
      c = c / 2;
   }
   i = 3;
   while (i <= (sqrt(c)+1))
   {
      if ((c % i) == 0)
      {
         printf("%ld\n",i);
         c = c / i;
      }
      else
      i = i + 2;
   }
   if(c > 1)
      printf("%ld\n",c);
}

int main()
{
   long long sum = 2;
   primes.push_back( 2 );
   for( long long i = 3; i < 2e6; i += 2 )
   {
      if( isPrime( i ) )
      {
         primes.push_back( i );
         sum += i;
      }
   }
   //printf( "%lld\n", *(primes.end()-1) );
   printf( "%lld\n", sum );
   return 0;
}