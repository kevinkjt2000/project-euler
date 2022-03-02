readfile =: 1!:1

filename =: < 'C:/Users/Kevin/Desktop/coding/project euler/data22.txt'

noquotes =: s #!.'*'~ '"' i. s=: readfile filename

sq=: 4 2 2$ 1 1 2 1  1 0 2 2  2 0 3 0  1 2 2 0

commasplit =: (0;sq;','=a.) ;: noquotes

nocommas =: s #!.'*'"1~ ',' i. s=: > commasplit

sorted =: (/:nocommas) { nocommas

score =: 3 : '+/'' ABCDEFGHIJKLMNOPQRSTUVWXYZ'' i. y'

total =: +/ (>:i.#sorted) * score"1 sorted
