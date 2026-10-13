class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        int sz = n/2;
        long long ans = 0LL;

        for(int i = 0; i < n; i++){
            nums[i] = abs(nums[i]);
        }

        sort(begin(nums), end(nums));

        for(int i = 0; i < sz; i++){
            ans -= nums[i] * nums[i];
        }

        for(int i = sz; i < n; i++){
            ans += nums[i] * nums[i];
        }

        return ans;
    }
};