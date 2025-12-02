class Solution {
public:
    string convert(string s, int n) {
    vector<string> v(n,"");
        if(n<=1)return s;
        int j=0,dir=-1;
        for(int i=0;i<s.length();i++)
        {
            if(j==n-1 || j==0)dir*=(-1);
            v[j]+=s[i];
            if(dir==1)j++;
            else j--;
        }
        string result="";
        for(auto c: v)
        {
            result+=c;
        }
    return result;
    }
};
