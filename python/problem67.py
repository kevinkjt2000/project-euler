from string import whitespace
from operator import add

data = open('data67.txt')
array = [map(int, line.split(' ')) for line in data]
for row in range(len(array)):
   for col in range(len(array[row])):
      above_left = 0
      above = 0
      if row-1 >= 0:
         if col-1 >= 0:
            above_left = array[row-1][col-1]
         if col < len(array[row-1]):
            above = array[row-1][col]
      array[row][col] = array[row][col] + max(above_left, above)
         
print max(array[len(array)-1])