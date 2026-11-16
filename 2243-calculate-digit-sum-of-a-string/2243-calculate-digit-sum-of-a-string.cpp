class Solution {
public:
    int getSum(string s){
      //  int num = stoi(s);

        int sum = 0;
        for(char c : s){
        sum += c - '0';
        }

        return sum;
    }

    string digitSum(string s, int k) {
        
        while(s.size() > k){
            string temp = "";

            for(int i = 0; i < s.size(); i += k){
                string chunk = s.substr(i, k);
                int sum = getSum(chunk);
                temp += to_string(sum);
            }

            s = temp;
        }

        return s;
    }
};