mut sum := 0
max := 1000

for i := 3; i < max; i += 3 {
	sum += i
}

for i := 5; i < max; i += 5 {
	if i % 3 == 0 {
		continue
	}
	sum += i
}

println(sum)
