def queen_solution(queen, table, col, memoize):
	if queen <= 0:
		return 	True
	if col > 7 or col < 0:
		return False
  #put the queen anywhere and check if that conflicts with any previously placed queen
	for i in range(0, 8):
		if feasible(i, col, memoize):
			table[i][col] = "x"
			memoize[str(col)] = (i, col)
			if queen_solution(queen-1, table, col-1, memoize):
				return True
			table[i][col] = "0"
			memoize.pop(str(col), None)
			
def feasible(row, col, memoize):
	for i in range(0, 8):
		i = str(i)
		if i in memoize.keys():
			rows = abs(row - memoize[i][0])
			cols = abs(col - memoize[i][1])
			if memoize[i] == (row, col):
				return False
			elif rows == cols:		
				return False
			elif memoize[i][0] == row:
				return False
			elif memoize[i][1] == col:		
				return False
	return True

table = [["0" for i in range(8)] for i in range(8)]
queen_solution(8, table, 7, {})
for i in range(0, 8):
	print(table[i])
