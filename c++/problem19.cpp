/*
Counting Sundays
Problem 19

You are given the following information, but you may prefer to do some research for yourself.
1 Jan 1900 was a Monday.
Thirty days has September,
 April, June and November.
 All the rest have thirty-one,
 Saving February alone,
 Which has twenty-eight, rain or shine.
 And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

#include <iostream>
using namespace std;

enum months_t {JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

bool is_leap_year(int year)
{
   return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

int days_in_month(months_t month, int year)
{
   switch(month)
   {
      case APRIL: case JUNE: case SEPTEMBER: case NOVEMBER:
         return 30;
      case FEBRUARY:
         return is_leap_year(year) ? 29 : 28;
      default:
         return 31;
   }
}

int main(int argc, char * argv[])
{
   int sunday_count = 0;
   int day = 1;
   for(int year = 1900; year <= 2000; year++)
   {
      for(months_t month = JANUARY; month <= DECEMBER; month = static_cast<months_t>(month + 1))
      {
         for(int day_number = 1; day_number <= days_in_month(month, year); day_number++)
         {
            if(year != 1900 && day_number == 1 && day == 0)
            {
               sunday_count++;
            }
            day++;
            day %= 7;
         }
      }
   }
   cout << sunday_count << endl;
   return 0;
}