class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0);
        return ans;
    }

    void solve(vector<int>& a, int target, int idx) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (target < 0)
            return;

        for (int i = idx; i < a.size(); i++) {
            if (i > idx && a[i] == a[i - 1])
                continue;

            temp.push_back(a[i]);
            solve(a, target - a[i], i + 1);
            temp.pop_back();
        }
    }
};