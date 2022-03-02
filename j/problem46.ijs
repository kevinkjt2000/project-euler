composites=: (-.@(1&p:) # ]) >:+: >:i.100000

NB. numbers that can be written as the sum of a prime and twice a square
numbers=: /:~ ~., (p: i.1000) +/ +: *: >:i.1000

index=: (i.&composites i. #) numbers

answer=: index { composites