from operator import add

data = open('data13.txt')
nos = [int(line) for line in data]
print str(reduce(add, nos))[:10]
