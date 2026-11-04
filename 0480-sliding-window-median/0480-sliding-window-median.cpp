class Solution {
public:

    multiset<int> left, right;

    void balance() {

        if(left.size() > right.size() + 1) {

            int x = *left.rbegin();

            left.erase(left.find(x));
            right.insert(x);
        }

        else if(left.size() < right.size()) {

            int x = *right.begin();

            right.erase(right.find(x));
            left.insert(x);
        }
    }

    void add(int x) {

        if(left.empty() || x <= *left.rbegin()) {
            left.insert(x);
        }
        else {
            right.insert(x);
        }

        balance();
    }

    void remove(int x) {

        auto it = left.find(x);

        if(it != left.end()) {
            left.erase(it);
        }
        else {
            it = right.find(x);
            right.erase(it);
        }

        balance();
    }

    double getMedian(int k) {

        if(k % 2 == 1) {
            return *left.rbegin();
        }

        return ((double)*left.rbegin() + *right.begin()) / 2.0;
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        vector<double> ans;

        for(int i = 0; i < k; i++) {
            add(nums[i]);
        }

        ans.push_back(getMedian(k));

        for(int i = k; i < nums.size(); i++) {

            remove(nums[i-k]);

            add(nums[i]);

            ans.push_back(getMedian(k));
        }

        return ans;
    }
};