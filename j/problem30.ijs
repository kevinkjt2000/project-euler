pows =: 5 ^~ i. 10

list =: ~. , pows +/ ~. , pows +/ ~. , pows +/ pows
list2 =: ~. , pows +/ ~. , pows +/ ~. , pows +/ ~. , pows +/ ~. , pows +/ pows

check =: ; +/ each 5 ^~ each 1"."0 each ": each ;/ list2

almost =: check #~ check = list2

ans =: +/ almost #~ almost > 1
