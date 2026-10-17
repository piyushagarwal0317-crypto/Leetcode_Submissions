class Solution {
public:
    int get_sum(int a){
        int sum = 0;

        while(a > 0){
            sum += a % 10;
            a /= 10;
        }

        return sum;
    }
    

    int minSwaps(vector<int>& nums) {
        
        vector<pair<int, int>> v;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end(), [this](pair<int,int>& a, pair<int,int>& b) {
            int s1 = get_sum(a.first);
            int s2 = get_sum(b.first);
            
            if(s1 != s2){
                return s1 < s2;
            }
            else return a.first < b.first;
        });

        vector<bool> vis(n, false);
        int swaps = 0;

        for(int i = 0; i < n; i++){

             if(vis[i] || v[i].second == i)
                 continue;

            int cycle_len = 0;
            int j = i;

            while(!vis[j]){

                vis[j] = true;
                j = v[j].second;
                cycle_len++;
            }

             swaps += cycle_len - 1;
        }

        return swaps;
    }
};