class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int, int> mp;
        int totalCount = 0;
        for(int i: arr) {
            mp[i] = 1;
        }
        
        for(int i: arr) {
            totalCount += mp[i+1];
        }
        
        return totalCount;
    }
};