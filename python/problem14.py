def gen_sequence(i):
   list = [i]
   while i != 1:
      if i % 2 == 0:
         i = i / 2
      else:
         i = 3*i + 1
      list.append(i)
   return len(list)

gen_sequence(1000000)
sizes = [gen_sequence(i) for i in range(1,1000000)]
print sizes.index(max(sizes))