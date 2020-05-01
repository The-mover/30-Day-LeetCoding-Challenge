class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int need = 0;
        for(int i=n-2; i>=0; i--) {
            if( nums[i] > need ) {
                need = 0;
            } else {
                need++;
            }
        }
        return need ? false : true;
    }
};