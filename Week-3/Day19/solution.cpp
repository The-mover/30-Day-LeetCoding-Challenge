class Solution {
private:
    int binarySearch(int lo, int hi, int target, vector<int>& ara) {
        //cout << lo << " " << hi << endl;
        if( lo > hi ) return -1;
        //if( lo == hi && ara[lo] != target ) return -1;
        
        int mid = (lo + hi) / 2;
        
        if( ara[mid] == target ) return mid;
        
        else if( ara[lo] <= ara[mid] ) {
            if( ara[lo] <= target && target <= ara[mid] ) {
                return binarySearch(lo, mid-1, target, ara);
            } else{
                return binarySearch(mid+1, hi, target, ara);
            }
        } 
        
        else {
            if( ara[mid] <= target && target <= ara[hi] ) {
                return binarySearch(mid+1, hi, target, ara);
            } else {
                return binarySearch(lo, mid-1, target, ara);
            }
        }
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if( n == 0 ) return -1;
        return binarySearch(0, n-1, target, nums);
    }
};