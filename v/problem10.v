import arrays
import math

fn generate_primes() []i64 {
	mut primes := []i64{cap: int(300_000)} // large initial capacity avoids costly reallocations
	primes << 2
	primes << 3

	for i := 5; i < 2_000_000; i += 2 {
		mut is_prime := true
		for prime in primes {
			if prime > math.sqrt(i) {
				break // factor pairs past the square root are a mirrored version of previos pairs
			}
			if i % prime == 0 {
				is_prime = false
				break
			}
		}
		if is_prime {
			primes << i
		}
	}

	return primes
}

fn main() {
	primes := generate_primes()
	println(arrays.sum(primes) ?)
}
