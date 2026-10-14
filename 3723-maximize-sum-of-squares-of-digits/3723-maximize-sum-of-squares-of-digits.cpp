class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s = "";

        if (num * 9 < sum)
            return "";

        for (int i = 1; i <= num; i++) {

            if (sum >= 9) {
                s += '9';
                sum -= 9;
            } else {
                s += char(sum + '0');
                sum = 0;
            }
        }
        
        return s;
    }
};