/*
    Time Complexity: O((M + N) * (2 ^ (N + M/2)))
    Space Complexity: O((M + N) * (2 ^ (N + M/2))),

    where N is the length of string and M is the length of pattern.
*/

bool isMatch(string s, string p) {

	// Base Case.
	if (p.size() == 0) {
		if (s.size() == 0) {
			return true;
		}

		else {
			return false;
		}
	}

	// Checking the condition if both the characters are equal or pattern has a dot.
	bool first = (s.size() > 0 and (p[0] == s[0] || p[0] == '.'));

	// Trying to replace '*' with previous character.
	if (p.size() > 1 and p[1] == '*') {
		return isMatch(s, p.substr(2)) || (first && isMatch(s.substr(1), p));
	}

	else {
		return first && isMatch(s.substr(1), p.substr(1));
	}
}
