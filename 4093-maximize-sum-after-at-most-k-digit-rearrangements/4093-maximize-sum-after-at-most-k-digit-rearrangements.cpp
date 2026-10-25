class Solution {
public:

    int rev(int n){

        string s = to_string(n);
        sort(s.rbegin(), s.rend());

        int num = stoi(s);
        return num - n;
    }

    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0LL;

        priority_queue<int> pq;

        for(int i = 0; i < n; i++){
            sum += 1LL * nums[i];
            pq.push(rev(nums[i]));
        }

        while(!pq.empty() && k != 0){
            //cout<<pq.top()<<endl;
            sum += 1LL * pq.top();
            pq.pop();
            k--;
        }

        return sum;

    }
};