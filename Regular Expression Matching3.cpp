/*
    Time Complexity: O(N * M)
    Space Complexity: O(N * M)

    where N is the length of string and M is the length of pattern.
*/

bool isMatch(string s, string p) 
{
	int n = s.size();
	int m = p.size();

	// Creating a 2D dp boolean array for storing the answer.
	vector<vector<bool>>dp(n + 1, vector<bool>(m + 1, false));
	dp[0][0] = true;

	// Base case initailisation.
	for (int i = 0; i < m; i++) 
    {
		if (p[i] == '*' && dp[0][i - 1]) 
        {
			dp[0][i + 1] = true;
		}
	}

	for (int i = 0; i < n; i++) 
    {
		for (int j = 0; j < m; j++) 
        {
			// Checking the condition if both the characters are equal or pattern has a dot.

			if (p[j] == '.' || s[i] == p[j]) 
            {
				dp[i + 1][j + 1] = dp[i][j];
			}

			// Trying to replace * with previous character.
			if (p[j] == '*') 
            {
				if (p[j - 1] != s[i] && p[j - 1] != '.') 
                {
					dp[i + 1][j + 1] = dp[i + 1][j - 1];
				}

				else 
                {
					dp[i + 1][j + 1] = (dp[i + 1][j] || dp[i][j + 1] || dp[i + 1][j - 1]);
				}
			}
		}
	}

	// Final answer will be stored at dp[n][m].
	return dp[n][m];
}
