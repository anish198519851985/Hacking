public int getLongestArithmeticSeq(int[] array) {
	int difference = array[1] - array[0];		// common difference of arithmetic sequence
	int longestLength = Integer.MIN_VALUE;	// stores the longest length sequence found till now
	int currentLength = 1;		// stores length of current arithmetic sequence
	for(int iii = 1; iii < array.length - 1; iii++) {
		int currentDifference = array[iii + 1] - array[iii];
		if (currentDifference == difference) {		// check if these elements are part of the sequence
			currentLength++;		// if they are, increase currentLenght
		} else {			// otherwise set currentLength to 1, and common difference to new difference
			currentLength = 1;
			difference = currentDifference;
		}
		longestLength = Math.max(longestLength, currentLength);		// store the maximum length
	}
	return longestLength;
