NB. https://projecteuler.net/problem=50

0 : 0
The prime 41, can be written as the sum of six consecutive primes:

41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?
)

require 'format/printf'

answer=. >./ (1&p: # ]) ~.;+/\\. p: i.546
'answer: %d' printf answer

answer2=. {:@((1&p: *. <&1e6) # ])@,@|:@(+/\.&.|.\.) (<&1e4 # ]) p:i.1e6
'answer2: %d' printf answer2