class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int zero = find(nums.begin(), nums.end(), 0) - nums.begin();

        bool inc = 1, dec = 1;

        for (int i = 0; i < n; i++) {
            if (nums[(zero + i) % n] != i)
                inc = 0;
            if (nums[(zero - i + n) % n] != i)
                dec = 0;
        }

        if (zero == 0 && inc)
            return 0;
        if (zero == n - 1 && dec)
            return 1; // rev

        if (!inc && !dec)
            return -1;
        int ans = INT_MAX;

        if (inc) {
            int p1 = zero;         // reverse
            int p2 = n - zero + 2; // reverse & shift
            return ans = min(p1, p2);
        }
        if (dec) {
            int p1 = n - zero;
            int p2 = zero + 2;
            return ans = min(p1, p2);
        }

        return -1;
    }
};