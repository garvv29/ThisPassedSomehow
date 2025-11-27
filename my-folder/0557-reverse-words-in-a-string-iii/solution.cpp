class Solution {
public:
    string reverseWords(string s) {
    int i=0,j=0;
    s+=' ';
    while(i<s.length()&&j<s.length())
    {
        if(s[j]!=' ')
        {
            j++;
        }
        else{
        reverse(s.begin()+i,s.begin()+j);
        j++;
        i=j;
        }
    }
    s.pop_back();
    return s;
}
};
