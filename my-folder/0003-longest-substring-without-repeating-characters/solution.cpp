class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int n= s.size();
        int maxi=0;
        vector<int> freq (256,-1);
        for(int r=0;r<n;r++)
        {
            if(freq[s[r]]>=l)l=freq[s[r]]+1;
            freq[s[r]]=r;
            maxi=max(maxi,r-l+1);
        }
        return maxi;

    }
};
