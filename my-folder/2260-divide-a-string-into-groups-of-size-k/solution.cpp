class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> v;
        int l=s.length();
        int ch=0;
        for(int i=0;i<l;i++)
        {
            string s1;
            s1 = "";
            for(int j=0;j<k;j++)
            {
                if(ch<l)
                s1+=s[ch];
                ch++;
            }
            if(s1.length()<k&&s1.length()>0)
            while(s1.length()!=k)
            {
                s1+=fill;
            }
            if(s1!="")
            v.push_back(s1);
        }
        return v;
    }
};
