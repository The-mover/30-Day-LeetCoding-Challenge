class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > mp;
        vector<vector<string>> ans;
        int n = strs.size();
        if( n == 0 ) return ans;

        for(int i=0; i<n; i++) {
            string str = strs[i];
            string temp = str;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(str);
        }

        for(auto it: mp) {
            vector<string> tempVector;
            for(auto ii: it.second) {
                    tempVector.push_back(ii);
            }
            ans.push_back(tempVector);
        }
        
        return ans;
    }
};