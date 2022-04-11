class Solution {
public:
    int myAtoi(string s) {
        long long INF = 2147483647;
        int n = s.size();
        int sign = 0;
        string num = "0";

        for(int i = 0; i < n; i++) {
            if ('0' <= s[i] && s[i] <= '9') num += s[i];
            else if ('-' == s[i] && sign == 0 && num.size() == 1) sign = -1;
            else if ('+' == s[i] && sign == 0 && num.size() == 1) sign = 1;
            else if (' ' == s[i] && sign == 0 && num.size() == 1) continue;
            else break;
        }
        if (sign == 0) sign = 1;
        long long ans = 0;
        for(int i = 0; i < num.size(); i++) {
            ans = ans * 10 + (num[i] - '0');
            if (ans > INF) {
                if (sign == 1) ans = INF;
                else if (sign == -1) ans = INF + 1;
                break;
            }
        }
        
        return sign * ans;
    }
};
