class Solution {
    public boolean isPalindrome(int x) {
        String s = ""+x;
        String r = "";
        for(int i=0;i<s.length();i++)
        {
            char ch=s.charAt(i);
            r=ch+r;
        }
        if(r.equals(s))
        {
            return true;
        }
        else 
        return false;
    }
}
