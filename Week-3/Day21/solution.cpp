/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int n = dim[0];
        int m = dim[1];
        int hi = m-1;
        int lo = 0;
        while( lo < hi ) {
            int mid = (lo + hi) / 2;
            bool flag = 0;
            for(int i=0; i<n; i++) {
                if( binaryMatrix.get(i, mid) == 1 ) {
                    flag = true;
                    break;
                }
            }
            if( flag ) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        //cout << lo << endl;
        
        for(int i=0; i<n; i++) {
            if( binaryMatrix.get(i, lo) == 1 ) {
                return lo;
            }
        }
        
        return -1;
    }
};