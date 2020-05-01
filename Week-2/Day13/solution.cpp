class Solution {
    
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size(), sum = 0, maxLen = 0;
        if( n == 0 ) return 0;
        mp[0] = -1;
        for(int i=0; i<n; i++) {
            sum += nums[i] ? 1 : -1;
            if( mp.find(sum) != mp.end() ) {
                maxLen = max(maxLen, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};