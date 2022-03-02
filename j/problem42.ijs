isTriangle =: (+/\ >: i.100) e.~ ]
file=: ;: 1!:1 <'words.txt'
list =: file {~ >:4* i.n ] n=: 1 + 4%~ 3-~ #file
answer =: +/ isTriangle ;+/ each ' ABCDEFGHIJKLMNOPQRSTUVWXYZ'&i. each list
