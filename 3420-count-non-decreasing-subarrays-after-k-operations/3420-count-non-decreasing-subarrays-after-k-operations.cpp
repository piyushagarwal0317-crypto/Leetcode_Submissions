class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int, int>> q; 

        long long ans = 0, ops = 0;
        int R = n - 1; 

        for (int L = n - 1; L >= 0; --L) {
            int val = nums[L];
            int count = 1;

            while (!q.empty() && q.back().first <= val) {
                auto [prev_val, prev_count] = q.back();
                q.pop_back();
                ops += 1LL * (val - prev_val) * prev_count;
                count += prev_count;                
            }
            
            q.push_back({val, count});

            while (ops > k) {
                int max_val = q.front().first;
                ops -= (max_val - nums[R]);
                
                q.front().second--;
                if (q.front().second == 0) {
                    q.pop_front();
                }
                R--; 
            }
            
            ans += (R - L + 1);
        }
        
        return ans;
        

    }
};