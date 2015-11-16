
def get_precedence(optr1, optr2):
	low = ["+", "-"]
	high = ["/", "*" , "^"]
	if optr1 in low and optr2 in low or optr1 in high and optr2 in high:
		return 0
	elif optr1 in low and optr2 in high:
		return -1
	elif optr1 in high and optr2 in low:
		return 1
	else:
		return -1
		
def infix_to_prefix(string):
	stack = []
	operators = ["+", "*", "-", "/"]
	string = string[::-1]
	index = len(string)-1
	output = [0]*(index+1)
		
	for i in string:
		if i == ")":
			stack.append(i)
		elif i == "(":
			while len(stack) and stack[-1] != ")":
				output[index ] = stack.pop()
				index -= 1
			if len(stack) and output[-1] == ")":
				stack.pop()
		elif i in operators:
			#before pushing to operator stack, check if its precedence is more or less
			#if less than pop all the previos operators
			while len(stack) >= 1 and get_precedence(stack[-1], i) >=0:
				output[index] = stack.pop()
				index -= 1
			stack.append(i)
		else:
			output[index] = i
			index -= 1
			
	stack_length = len(stack)
	for i in range(0, stack_length):
		if stack[-1] == "(" or stack[-1] == ")":
			stack.pop()
			continue
		output[index] = stack.pop()
		index -= 1
	
	#remove zeros	
	output = [i for i in output if i != 0]
	return ("").join(output)		
	
print infix_to_prefix("((A+B)*C-(D-E))*(F+G)")	
