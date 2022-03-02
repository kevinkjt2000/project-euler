pows =: ! i. 10

list =: ~. , pows +/ ~. , pows +/ ~. , pows +/ pows
list2 =: ~. , pows +/ ~. , pows +/ ~. , pows +/ ~. , pows +/ ~. , pows +/ ~. , pows +/ ~. , pows +/ ~. , pows +/ pows

check =: ; +/ each ! each 1"."0 each ": each ;/ list2

almost =: check #~ check = list2

ans =: +/ almost #~ almost > 1
