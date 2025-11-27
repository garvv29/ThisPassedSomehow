class Solution {
public:
    string mostCommonWord(string p, vector<string>& banned) {
        // lowercase everything
        transform(p.begin(), p.end(), p.begin(), ::tolower);

        // replace punctuation with space
        for(char &c : p) {
            if(!isalpha(c)) c = ' ';
        }

        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string,int> freq;

        string word;
        stringstream ss(p);

        while (ss >> word) {
            if (!ban.count(word))
                freq[word]++;
        }

        // find highest frequency word
        string ans = "";
        int best = 0;
        for (auto &x : freq) {
            if (x.second > best) {
                best = x.second;
                ans = x.first;
            }
        }

        return ans;
    }
};

