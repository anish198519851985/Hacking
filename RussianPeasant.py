# exponentiation using Russian Peasant Multiplication
def RussianPeasant(a, b):
	result = 1
	while b != 0:
		if b & 1:
			result *= a
		b >>= 1
		a *= a 
	return result

print(RussianPeasant(2, 8))
