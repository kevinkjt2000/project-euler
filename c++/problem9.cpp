#include <math.h>
#include <stdio.h>

int main()
{
   for( int a = 1; a < 332; a++ )
      for( int b = a+1; 1000 - a > 2*b; b++ )
      {
         int c = 1000 - b - a;
         if( a*a + b*b == c*c )
         {
            printf( "%d\n%d\n%d\n%d\n", a, b, c, a*b*c );
            return 0;
         }
      }
   return 0;
}