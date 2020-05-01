class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int prev = nums[0];
        for(int i=1; i<nums.size(); i++) {
            int curr_max = max(nums[i], nums[i] + prev);
            prev = curr_max;
            ans = max(ans, curr_max);
        }
        return ans;
    }
};