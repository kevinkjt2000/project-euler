#include <iostream>
#include <map>
#include <vector>

//Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.

int cycle_length(int divisor)
{
   int length = 0;
   std::map<int, int> remainders;
   std::vector<int> remainders_in_order_found;
   int num_times = 0;
   int current_remainder = 1;
   
   while(++remainders[current_remainder] == 1)
   {
      remainders_in_order_found.push_back(current_remainder);
      current_remainder = 10*current_remainder % divisor;
      ++num_times;
   }
   
   if(current_remainder != 0)
   {
      int position;
      for(position = 0; position < remainders_in_order_found.size(); ++position)
      {
         if(remainders_in_order_found[position] == current_remainder)
         {
            break;
         }
         else if(position == remainders_in_order_found.size() - 1)
         {
            position = 0;
            break;
         }
      }
      
      length = num_times - position;
   }
   return length;
}

int main(int argc, char **argv)
{
   int longest_d = 2;
   int longest_cycle_length = 0;
   for(int d = 2; d < 10000; ++d)
   {
      int current_cycle_length = cycle_length(d);
      if(current_cycle_length > longest_cycle_length)
      {
         longest_cycle_length = current_cycle_length;
         longest_d = d;
      }
   }
   std::cout << longest_d << std::endl;
   return 0;
}
