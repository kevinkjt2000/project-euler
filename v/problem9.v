import math

for a in 1 .. (1000 / 3) {
	mut b := 1
	mut c := 1000 - a - b
	for b <= c {
		assert a + b + c == 1000
		if math.tolerance(a, math.sqrt(c * c - b * b), 0.0000000001) {
			println('$a, $b, $c')
			println(a * b * c)
			break
		}
		b++
		c--
	}
}
