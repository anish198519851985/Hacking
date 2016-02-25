def count_permute(s, t, s_index, t_index):
	dp = [[0 for i in range(0, len(t)+1)] for i in range(0, len(s)+1)]
	for s_index in range(0, len(s)):
		dp[s_index][0] = 1
	for s_index in range(1, len(s)+1):
		for t_index in range(1, len(t)+1):
			if s[s_index-1] == t[t_index-1]:
				dp[s_index][t_index] = dp[s_index-1][t_index] + dp[s_index-1][t_index-1]
			else:
				dp[s_index][t_index] = dp[s_index-1][t_index]
	return dp[len(s)][len(t)]
			
print(count_permute("rabbbit", "rabbit", 0, 0))
