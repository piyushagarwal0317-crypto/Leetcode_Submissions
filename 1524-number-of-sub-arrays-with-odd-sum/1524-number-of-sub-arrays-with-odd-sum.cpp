class Solution {
public:
    const int M = 1e9+7;

    int numOfSubarrays(vector<int>& nums) {
        int n = nums.size();

        //vector<int>pref(n, 0);

        //pref[0] = nums[0];
        int sum = 0;
        // for(int i = 1; i < n; i++){
        //     pref[i] = pref[i-1] + nums[i];
        // }

        int odd = 0, cnt = 0, even = 1;

        for(int i = 0; i < n; i++){
            sum += nums[i];

            if(sum % 2 == 0){
                cnt = (cnt + odd) % M;
                even++;
            }
            else{
                cnt = (cnt + even) % M;
                odd++;
            }
        }

        return cnt;
    }
};