class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long long ans = 0;
        int n = s.size();

        // 1. Skip leading whitespace
        while (i < n && isspace(s[i])) {
            i++;
        }

        // 2. Handle sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Convert digits
        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            // 4. Check for overflow
            if (ans * sign > INT_MAX) {
                return INT_MAX;
            } else if (ans * sign < INT_MIN) {
                return INT_MIN;
            }
            i++;
        }

        return (int)(ans * sign);
    }
};
