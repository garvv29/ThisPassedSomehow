class Solution{
    public:
int lengthOfLongestSubstring(string s) {
    vector<int> d(256,-1);
    int maxl=0,start=-1;
    for(int i=0;i<s.length();i++)
    {
        if(d[s[i]]>start)
            start=d[s[i]];
        d[s[i]]=i;
        maxl=max(maxl,i-start);
    }
    return maxl;
}
};
