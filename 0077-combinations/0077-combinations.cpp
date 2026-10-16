class Solution {
public:
    vector<vector<int>> res;

    void solve(int i, vector<int>& nums, vector<int>& tmp, int k, int len) {

        if (len == k) {
            res.push_back(tmp);
            return;
        }

        if (i == nums.size())
            return;

        for (int j = i; j < nums.size(); j++) {

            len++;
            tmp.push_back(nums[j]);

            solve(j + 1, nums, tmp, k, len);
            tmp.pop_back();
            len--;

        }
    }

    vector<vector<int>> combine(int n, int k) {

        vector<int> nums, tmp;

        for (int i = 0; i < n; i++) {
            nums.push_back(i + 1);
        }

        solve(0, nums, tmp, k, 0);
        return res;
    }
};