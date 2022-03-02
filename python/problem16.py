def int_to_list(i):
   return [int(x) for x in str(i).zfill(9)]

print sum(int_to_list(2**1000))