comb=: dyad define M.
  if. (x>:y)+.0=x do. i.(x<:y),x else. (0,.x comb&.<: y),1+x comb y-1 end.
)

divisors =: monad define
  _1 }. ; */"1 each ~. each ((>:i.#primes) comb each <"0 (# $ #) primes) { each < primes [ primes=: q: y
  NB. (/:list) { list NB. sort list
)

ints =: 12 }. i. 28123

abundants =: ((+/"1 (divisors"0) ints) > <: ints) # ints

sum_of_two =: monad define
  1 e. (y - s) e. s [ s =: (abundants < y) # abundants
)

answer =: +/(-. sum_of_two"0 i. 28123) # i. 28123

NB. sums =: ints #~ 1 e."1 (s -~ ints) e."0 0 s [ s =: (abundants (<"1 0) ints) # abundants
