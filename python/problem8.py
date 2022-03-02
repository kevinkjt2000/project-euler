from string import whitespace
from operator import mul

data = open('data8.txt') # Number pasted to file.
nos = [int(c) for line in data for c in line if c not in whitespace]
print max([reduce(mul, nos[i:i+5]) for i in range(len(nos)-5)])