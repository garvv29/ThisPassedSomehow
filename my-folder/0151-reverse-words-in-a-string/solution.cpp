class Solution {
public:
    string trim(string s) {
    int start = 0;
    int end = s.size() - 1;

    // Remove leading spaces
    while (start <= end && s[start] == ' ') 
        start++;

    // Remove trailing spaces
    while (end >= start && s[end] == ' ') 
        end--;

    return s.substr(start, end - start + 1);    
    }

    string reverseWords(string s) {
    
    //clean
    s=trim(s);

    for (int i = 1; i < s.length(); ) {
    if (s[i] == ' ' && s[i - 1] == ' ') {
        s.erase(s.begin() + i);   // erase current space
    } else {
        i++;                      // only move forward when no erase
    }
}


    int i=0,j=0;

    reverse(s.begin(),s.end());
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
