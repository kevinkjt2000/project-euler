import timing

# http://www.codecodex.com/wiki/Calculate_an_integer_square_root#Python
def isqrt(n):
    xn = 1
    xn1 = (xn + n/xn)/2
    while abs(xn1 - xn) > 1:
        xn = xn1
        xn1 = (xn + n/xn)/2
    while xn1*xn1 > n:
        xn1 -= 1
    return xn1

def memoize(f):
    memo = {}
    def helper(x):
        if x not in memo:
            memo[x] = f(x)
        return memo[x]
    return helper

#@memoize
def is_prime(x):
    if x < 2:
        return False
    if x != 2 and x%2 == 0:
        return False
    root = 1 + isqrt(x)
    for d in xrange(3, root, 2):
        if x%d == 0:
            return False
    return True

primes = []
for i in range(8400):
    if is_prime(i):
        primes.append(i)
#print(primes)
num_primes = len(primes)

from collections import defaultdict
pair_sets = defaultdict(lambda: [])
for i in xrange(num_primes):
    for j in xrange(i+1, num_primes):
        x = str(primes[i])
        y = str(primes[j])
        if is_prime(int(x + y)) and is_prime(int(y + x)):
            pair_sets[x].append(y)
            pair_sets[y]
#print(pair_sets)

def main():
    for p1 in pair_sets:
        s1 = set(pair_sets[p1])
        for p2 in s1:
            s2 = set.intersection(s1, set(pair_sets[p2]))
            for p3 in s2:
                s3 = set.intersection(s2, set(pair_sets[p3]))
                #print(p1, p2, p3)
                for p4 in s3:
                    s4 = set.intersection(s3, set(pair_sets[p4]))
                    #print(p1,p2,p3,p4)
                    for p5 in s4:
                        print(p1,p2,p3,p4,p5)

#profile run with python -m cProfile problem60.py
main()
