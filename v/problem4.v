fn get_digits(x int) []int {
	mut digits := []int{cap: 6}
	for i := x; i > 0; i /= 10 {
		digits << i % 10
	}
	return digits
}

fn is_palindrome(x int) bool {
	digits := get_digits(x)
	return digits == digits.reverse()
}

fn main() {
	mut largest_palindrome := 0

	for i := 999; i >= 100; i-- {
		for j := 999; j >= 100; j-- {
			product := i * j
			if product <= largest_palindrome {
				break
			}
			if is_palindrome(product) {
				largest_palindrome = product
			}
		}
	}

	println(largest_palindrome)
}
