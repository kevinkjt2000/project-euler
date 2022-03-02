#include <string>
#include <sstream>
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::stringstream;
using std::string;

bool isPalindrome( string str )
{
   int length = str.length();
   for( int i = 0; i < length/2; i++ )
   {
      if( str[ i ] != str[ length - i - 1 ] )
         return false;
   }
   return true;
}

int main()
{
   int max = 0;
   for( int i = 999; i > 600; i-- )
      for( int j = 999; j > 600; j-- )
      {
         stringstream ss;
         ss << i * j;
         if( isPalindrome( ss.str() ) )
         {
            if( i * j > max )
               max = i * j;
         }
      }
   cout << max << endl;
   return 0;
}