class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n && k > 0; i++) {
            char c = s[i];
            int backCost = c - 'a';          // steps going down to 'a'
            int forwardCost = 'z' - c + 1;   // steps going up (wrap) to 'a'
            
            int cost = min(backCost, forwardCost);
            
            if (cost <= k) {
                k -= cost;
                s[i] = 'a';
            } else {
                // We cannot reach 'a'; use remaining k to make it as small as possible
                if (backCost <= forwardCost) {
                    // move backward by k steps
                    s[i] = char(c - k);
                } else {
                    char backwardChar = char(c - k);
                    char forwardChar = char('a' + ((c - 'a' + k) % 26));

                    s[i] = min(backwardChar, forwardChar);;
                }
                k = 0; 
            }
        }
        return s;
    }
};
