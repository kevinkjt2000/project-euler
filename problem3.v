import math

const number_from_problem = 600851475143

const max_factor = math.ceil(math.sqrt(number_from_problem))

fn generate_primes() []i64 {
	mut primes := []i64{cap: int(1e6)} // large initial capacity avoids costly reallocations
	primes << 2
	primes << 3

	for i := 5; i <= max_factor; i += 2 {
		mut is_prime := true
		for prime in primes {
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

fn get_largest_prime_factor(primes []i64, x i64) i64 {
	for p in primes.reverse() {
		if x % p == 0 {
			return p
		}
	}
	return 1
}

fn main() {
	primes := generate_primes()
	println(get_largest_prime_factor(primes, number_from_problem))
}
