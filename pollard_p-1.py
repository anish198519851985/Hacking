# euler way of finding gcd
def gcd(a, b):
	if not b:
		return a
	return gcd(b, a%b)
	
def get_factor(input):
	a = 2
	for factorial in range(2, input-1):
		a = a**factorial % input
		factor = gcd(a - 1, input)
		if factor == 1:
			continue
		elif factor == input:
			a += 1
		elif factor > 1:
			return factor
	return None

n = 49000
p = get_factor(n)
if not p:
	print("It is prime number")
else:
	q = n/p
	print("factors of", n, "are", p, "and", q)
