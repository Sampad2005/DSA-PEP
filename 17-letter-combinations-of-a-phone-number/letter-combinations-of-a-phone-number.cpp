class Solution {
public:
    vector<string> ans;
    vector<string> mp = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return ans;

        solve(digits, 0, "");
        return ans;
    }

    void solve(string& digits, int idx, string s) {
        if (idx == digits.size()) {
            ans.push_back(s);
            return;
        }

        for (char c : mp[digits[idx] - '0']) {
            solve(digits, idx + 1, s + c);
        }
    }
};