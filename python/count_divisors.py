#count of numbers less than i which divide evenly into i
def count_divisors(i):  #it is assumed that i >= 2
   count = 1 #all numbers are divisible by 1
   add = 2
   sqrt = i**0.5
   if i % 2 == 0:
      count = count + 1 #divisible by 2
      add = 1
   if i == 2:
      return 2
   if i == 4:
      return 3
   d = 3
   while d < sqrt:
      if i % d == 0:
         count = count + 1
      d = d + add
   count = 2*count
   if sqrt == int(sqrt):
      count = count + 1
   return count

#count of numbers less than i which divide evenly into i
def working_count_divisors(i):  #it is assumed that i >= 2
   count = 1  #all numbers are divisible by 1
   add = 2
   if i % 2 == 0:
      count = count + 1 #divisible by 2
      add = 1
   d = 3
   while d <= i:
      if i % d == 0:
         count = count + 1
      d = d + add
   return count

print sum([count_divisors(i) for i in range(2,10001)])
print sum([working_count_divisors(i) for i in range(2,10001)])