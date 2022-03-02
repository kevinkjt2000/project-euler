fn gcd(a int, b int) int {
	if a == 0 {
		return b
	} else if b == 0 {
		return a
	} else if a > b {
		return gcd(a % b, b)
	}
	return gcd(a, b % a)
}

fn lcm(a int, b int) int {
	return a / gcd(a, b) * b
}

fn main() {
	mut answer := lcm(1, 2)
	for i in 3 .. 21 {
		answer = lcm(answer, i)
	}
	println(answer)
}
