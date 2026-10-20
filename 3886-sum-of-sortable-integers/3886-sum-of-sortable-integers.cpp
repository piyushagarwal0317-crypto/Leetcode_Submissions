
class Solution {
public:
    void computeLPS(vector<int>& pattern, vector<int>& lps) {
        int M = pattern.size();
        int len = 0;

        lps[0] = 0;

        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    bool search(vector<int>& pat, vector<int>& txt) {
        int N = txt.size();
        int M = pat.size();

        vector<int> lps(M, 0);
        computeLPS(pat, lps);

        int i = 0;
        int j = 0;

        while (i < N) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }

            if (j == M) {
                return true;
            } else if (i < N && pat[j] != txt[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return false;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> fac;

        for (int x = 1; x * x <= n; ++x) {
            if (n % x == 0) {
                fac.push_back(x);

                if (n / x != x) {
                    fac.push_back(n / x);
                }
            }
        }

        vector<int> target = nums;
        sort(begin(target), end(target));

        auto check = [&](const vector<int>& nums1, const vector<int>& nums2) {
            vector<int> doubled = nums1;
            doubled.insert(doubled.end(), nums1.begin(), nums1.end());

            vector<int> pat = nums2;
            return search(pat, doubled);
        };

        int ans = 0;

        for (int d : fac) {
            bool allGood = true;

            for (int left = 0; left < n; left += d) {
                int right = left + d - 1;

                vector<int> sub1(nums.begin() + left,
                                 nums.begin() + right + 1);

                vector<int> sub2(target.begin() + left,
                                 target.begin() + right + 1);

                if (!check(sub1, sub2)) {
                    allGood = false;
                    break;
                }
            }

            if (allGood) {
                ans += d;
            }
        }

        return ans;
    }
};
