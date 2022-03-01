struct FibonacciIterator {
mut:
	a i64 = 1
	b i64 = 1
}

fn (mut iter FibonacciIterator) next() ?i64 {
	defer {
		iter.a, iter.b = iter.b, iter.a + iter.b
	}
	return iter.b
}

mut iter := FibonacciIterator{}
mut even_sum := i64(0)
for x in iter {
	if x > 4e6 {
		break
	}
	if x % 2 == 0 {
		even_sum += x
	}
}

println(even_sum)
