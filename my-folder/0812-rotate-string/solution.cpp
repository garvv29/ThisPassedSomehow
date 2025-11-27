class Solution {
public:
    bool rotateString(string s, string goal) {
        // Strings must be the same length to be rotations of each other
        if (s.length() != goal.length()) return false;
        
        // Concatenate s with itself and check if goal exists in it
        string doubledS = s + s;
        return doubledS.find(goal) != string::npos;
    }
};
