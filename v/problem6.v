mut sum_of_squares := 0
mut sum := 0
for i in 1 .. 101 {
	sum_of_squares += i * i
	sum += i
}

println(sum * sum - sum_of_squares)
