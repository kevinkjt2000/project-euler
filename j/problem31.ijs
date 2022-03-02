NB. https://projecteuler.net/problem=31

NB. In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

NB. 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
NB. It is possible to make £2 in the following way:

NB. 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
NB. How many different ways can £2 be made using any number of coins?

require 'format/printf'

solve=. verb define
coins=. 100 50 20 10 5 2 1
counter=. 0
for_g. i.3 do.
for_f. i.5 - >.50%~+/(_6}.coins)*g do.
for_e. i.11 - >.20%~+/(_5}.coins)*g,f do.
for_d. i.21 - >.10%~+/(_4}.coins)*g,f,e do.
for_c. i.41 - >.5%~+/(_3}.coins)*g,f,e,d do.
for_b. i.101 - >.2%~+/(_2}.coins)*g,f,e,d,c do.
for_a. i.201 - +/(_1}.coins)*g,f,e,d,c,b do.
  counter=. counter + 200=+/coins * g,f,e,d,c,b,a
end.
end.
end.
end.
end.
end.
end.
1 + counter NB. add 1 because the 200 coin was left out
)

'number of ways: %d' printf solve''




NB. brute force is too inefficient (takes way too long to complete)
solve1=. verb define
coins=. 100 50 20 10 5 2 1
counter=. 0
for_g. i.3 do.
for_f. i.5 do.
for_e. i.11 do.
for_d. i.21 do.
for_c. i.41 do.
for_b. i.101 do.
for_a. i.201 do.
  counter=. counter + 200=+/coins * g,f,e,d,c,b,a
end.
end.
end.
end.
end.
end.
end.
1 + counter NB. add 1 because the 200 coin was left out
)