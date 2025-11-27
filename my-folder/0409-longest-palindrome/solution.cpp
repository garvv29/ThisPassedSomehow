class Solution {
public:
    int longestPalindrome(string s) {
        int freq [128] ={0};

        for(char c: s)
        {
            freq[(int)c]++;
        }

        int len=0;
        bool isodd=false;

        for(int i=0;i<128;i++)
        {
            len += (freq[i]/2)*2;

            if(freq[i]%2!=0)
            {
                isodd=true;
            }
        }
        if(isodd)return len+1;
        return len;
    }
};
