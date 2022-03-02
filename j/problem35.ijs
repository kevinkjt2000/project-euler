NB. https://projecteuler.net/problem=35

NB. The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

NB. There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

NB. How many circular primes are there below one million?

require 'format/printf'

NB. answer1=. #(1&p: # ])@:(1&|."1&.":"0)^:10 (<&1e6 # ]) p: i.1e5
answer=. +/(*./@(1&p:)@((i.@# |."0 1 ])"1&.":"0)) (<&1e6 # ]) p: i.1e5
'answer: %d' printf answer
