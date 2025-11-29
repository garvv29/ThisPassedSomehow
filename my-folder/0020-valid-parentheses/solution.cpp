class Solution {
public:
    bool isValid(string s) {
        stack <int> st;
        for(char c: s)
        {
            if(!st.empty())
            {
                char last = st.top();
                if(ispair(last,c))
                {
                st.pop();
                continue;
                }
            }
            st.push(c);
        }
        return st.empty();
    }

    bool ispair(char a,char b)
    {
        return (a=='(' && b ==')' ||
                a=='[' && b == ']'||
                a=='{' && b == '}');
    }
};
