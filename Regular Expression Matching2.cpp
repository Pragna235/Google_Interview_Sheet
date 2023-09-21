/*
    Time Complexity: O(N * M)
    Space Complexity: O(N * M)

    where N is the length of string and M is the length of pattern.
*/

bool isMatchHelper(int i, string& s, int j, string &p, vector<vector<int>> &dp) 
{

	int m = p.size(), n = s.size();

	// Base case.
	if (j == m) 
	{
		if (i == n) 
		{
			dp[i][j] = true;
		}
		else
		{
			dp[i][j] = false;
		}

		return dp[i][j];
	}

	// Memoised case.
	if (dp[i][j] != -1) 
	{
		return dp[i][j];
	}

	// Trying to replace '*' with previous character.
	if (p[j + 1] == '*') 
	{
		if (isMatchHelper(i, s, j + 2, p, dp) ||
		        i < n && (p[j] == '.' || s[i] == p[j]) && isMatchHelper(i + 1, s, j, p, dp))
			return dp[i][j] = 1;
	}
	// Checking the condition if both the characters are equal or pattern has a dot.
	else if (i < n && (p[j] == '.' || s[i] == p[j]) && isMatchHelper(i + 1, s, j + 1, p, dp)) 
	{
		return dp[i][j] = 1;
	}

	dp[i][j] = 0;
	return dp[i][j];
}

bool isMatch(string s, string p) 
{

	vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
	return isMatchHelper(0, s, 0, p, dp);
}

