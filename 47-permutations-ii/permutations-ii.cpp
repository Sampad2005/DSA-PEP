class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(nums, 0);
        return ans;
    }

    void solve(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> st;

        for (int i = idx; i < nums.size(); i++) {
            if (st.count(nums[i]))
                continue;

            st.insert(nums[i]);
            swap(nums[idx], nums[i]);
            solve(nums, idx + 1);
            swap(nums[idx], nums[i]);
        }
    }
};