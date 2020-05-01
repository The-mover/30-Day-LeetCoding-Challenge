class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> leftToRight(n+1, 0), rightToLeft(n+1, 0);
        leftToRight[0] = nums[0];
        rightToLeft[n] = 1;
        
        // calculating left to right product sum of given nums
        for(int i=1; i<n; i++) {
            leftToRight[i] = leftToRight[i-1] * nums[i];
        }
        // calculating right to left product sum of given nums
        for(int i=n-1; i>=0; i--) {
            rightToLeft[i] = rightToLeft[i+1] * nums[i];
        }
        // now its simple. just multiple the i+1 th value of rightToLeft and 
        // i-1 th value of leftToRight value and push them to ans vector
        ans.push_back(rightToLeft[1]);
        for(int i=1; i<n; i++) {
            ans.push_back(leftToRight[i-1] * rightToLeft[i+1]);
        }
        return ans;
    }
};