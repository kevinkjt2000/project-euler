NB. http://projecteuler.net/problem=49
0 : 0
The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this sequence?
)

require 'format/printf'

NB. comb verb is taken from here
NB. http://www.jsoftware.com/jwiki/Essays/Combinations
comb=: 4 : 0
  if. x e. 0 1 do. z=.<((x!y),x)$ i.y
  else. t=. |.(<.@-:)^:(i.<. 2^.x)x
    z=.({.t) ([:(,.&.><@;\.)/ >:@-~[\i.@]) ({.t)+y-x
    for_j. 2[\t do.
      z=.([ ;@:(<"1@[ (,"1 ({.j)+])&.> ])&.> <@;\.({&.><)~ (1+({.j)-~{:"1)&.>) z
      if. 2|{:j do. z=.(i.1+y-x)(,.>:)&.> <@;\.z end.
    end.
  end.
  ;z
)

NB. fourDigitPrimes=: p: 168 + i.1061
countDigits=: [:<. [:>: 10&^.
fourDigitPrimes=: (#~ countDigits = 4:) p: i. 1e4
indices=: (#~ (# > 2:)@>) (~. <@I.@:="0 1 ]) /:~&.":"0 fourDigitPrimes

NB. (2 -~/\ ])  NB. foward differences
res=: (((<./ = >./)"1@:(2 -~/\ ])"1@:{&fourDigitPrimes) # ])@:(3&comb@# { ])&.> indices
answer=: ;{&fourDigitPrimes&.> res

qprintf 'answer '