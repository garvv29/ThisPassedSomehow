class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> indexS(128, 0); // Stores index of characters in string s
        vector<int> indexT(128, 0); // Stores index of characters in string t
        
        int len = s.length();
        if(s.length()!=t.length())return false;

        if(len != t.length()) { // If the lengths of the two strings are different, they can't be isomorphic
            return false;
        }
        
        for(int i = 0; i < len; i++) { // Iterate through each character of the strings
            if(indexS[s[i]] != indexT[t[i]]) { 
                return false; // If different, strings are not isomorphic
            }
            
            indexS[s[i]] = i + 1; // updating position of current character
            indexT[t[i]] = i + 1;
        }
        
        return true;
    }
};
