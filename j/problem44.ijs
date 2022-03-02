pentagonal =: -:@:(] * <:@:(3&*))
lots =: pentagonal >:i.1000000x
pents =: 3000 {. lots
res =: (e.&lots@-/ * e.&lots@+/)~ pents
index =: ,(2##res) #: I., res
answer =: -/ index { lots