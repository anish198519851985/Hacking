m = 0

def increasing_one(array, current_index, k, k_org, result):
	global m
	if current_index >= len(array):
		return
	if array[current_index]:
		increasing_one(array, current_index+1, k, k_org, result + 1)
	elif not array[current_index] and k:
		increasing_one(array, current_index+1, k-1, k_org, result + 1)
	elif not array[current_index] and not k:
		increasing_one(array, current_index+1, k_org-1, k_org, 1)
		increasing_one(array, current_index+1, k_org, k_org, 0)
	m = max(m, result)
		
increasing_one([1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1], 0, 2, 2, 0)
print(m)
