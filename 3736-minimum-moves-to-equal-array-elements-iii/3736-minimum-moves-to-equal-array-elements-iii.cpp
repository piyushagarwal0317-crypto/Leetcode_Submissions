class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt = cnt + maxi - nums[i];
        }
        return cnt;
    }
};