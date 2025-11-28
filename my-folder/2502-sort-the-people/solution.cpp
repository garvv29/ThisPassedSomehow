class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> l(names.size());
        for(int i = 0;i<names.size();i++){
            l[i].first=heights[i];
            l[i].second=names[i];
        }
        sort(l.begin(),l.end());
        
        for(int i = 0;i<names.size();i++){
            names[names.size()-1-i]=l[i].second;
        }
        return names;
    }
};
