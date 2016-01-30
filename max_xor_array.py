import math

def get_bit_set(data):
	if not data:
		return 0
	return int(math.log(data, 2))
	
def get_max_xor(input):
	input = sorted(input, reverse=True)
	sum = 0
	index = 0
	set_bit = get_bit_set(input[0])
	choosen = [0]*len(input)
	while set_bit >= 0:
		#check if any other has set_bit to 1; if yes then xor with index element.
		check_and_xor(input, set_bit, index)
		choosen.append(index)
		set_bit -= 1
		#now find out if there is any one else whose set_bit is set
		index = check_set_bit(choosen, set_bit, input)
		if index < -1:
			break
	for i in input:
		sum ^= i
	return sum
	
def check_and_xor(input, set_bit, index):
	for i in range(0, len(input)):
		if i != index and (input[i]& (1 << set_bit)):
			input[i] ^= input[index]

def check_set_bit(choosen, set_bit, input):
	for i in range(0, len(input)):
		if i not in choosen:
			bit = get_bit_set(input[i])
			if bit == set_bit:
				return i
	return -1
	
print(get_max_xor([9, 8, 5]))
print(get_max_xor([8, 1, 2, 12, 7, 6]))
print(get_max_xor([4, 6]))
