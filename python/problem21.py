#sum of numbers less than i which divide evenly into i
def sum_divisors(i):  #it is assumed that i >= 2
   sum = 1  #all numbers are divisible by 1
   d = 2
   while d < i:
      if i % d == 0:
         sum = sum + d
      d = d + 1
   return sum

#d = [sum_divisors(i) for i in range(2,10000)]
#e = [(i)*(i!=d[i-2] and ((d[i-2]<len(d) and d[i-2]==d[d[i-2]]) or d[i-2]==sum_divisors(d[i-2]))) for i in range(2,10000)]

sum = 0
for a in range(2,10000):
   b = sum_divisors(a)
   if a != b and a == sum_divisors(b):
      sum += a

print sum