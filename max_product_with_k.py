def product(input, start, end, k):
  result = -1
  if start <= end:
    if memoize[start][end] != 0:
      return memoize[start][end]
    if not k:	
      return int(input[start:end+1])
    for i in range(start, end):
    	result = max(result, max((product(input, start, i, k-1) * int(input[i+1:end+1]), (int(input[start:i+1]) * product(input, i+1, end, k-1)))))
    	memoize[start][end] = result
  return result
	
data = str(4609110)
memoize = [[0 for x in range(len(data)+1)] for x in range(len(data)+1)] 
print(product(data, 0 , len(data)-1, 3))
