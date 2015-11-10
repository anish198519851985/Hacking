# your code goes here

#is optr1 higher priority than optr2
def get_precedence(optr1, optr2):
	low = ["+", "-"]
	high = ["/", "*"]
	if optr1 == optr2:
		return 0
	if optr1 in low and optr2 in high:
		return -1
	if optr1 in high and optr2 in low:
		return 1
	
def infix_to_post(string):
	print string
	operator_stack = []
	output = []
	operators = ["+", "*", "-", "/"]
	for i in string:
		if i in operators:
			#before pushing check that the precedence of already pushed
			#operator is more or less;if less then keep popping until you get
			#lesser precedence or
			while len(operator_stack) >= 1 and get_precedence(operator_stack[-1], i) >= 0:
				output.append(operator_stack.pop())
			operator_stack.append(i)
		elif i == ")":
			while len(operator_stack) > 0:
				output.append(operator_stack.pop())
		elif i == "(":
			continue
		else:
			output.append(i)
	length = len(operator_stack)		
	for i in range(0, length):
		output.append(operator_stack.pop())
	return ("").join(output)

print infix_to_post("(A+B+C)*D+K")
