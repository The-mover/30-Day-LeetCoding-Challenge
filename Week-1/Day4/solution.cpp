class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZero = -1;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(!nums[i]) {
                nonZero = nonZero <= i ?  i + 1 : nonZero;
                for(int j=nonZero; j<n; j++) {
                    if( nums[j] ) {
                        swap(nums[i], nums[j]);
                        nonZero = j;
                        break;
                    }
                }
            }
        }
        
    }
};