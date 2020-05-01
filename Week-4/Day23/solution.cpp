class Solution {
private:
    int msb(int n) {
        int pos = -1;
        while( n ) {
            n = n / 2;
            pos++;
        }
        return pos;
    }
    
    int rec(int lo, int hi) {
        int msbOfLo = msb(lo);
        int msbOfHi = msb(hi);
        if( msbOfLo != msbOfHi ) return 0;
        if( min(msbOfLo, msbOfHi) == -1 ) return 0;
        int msbPow = 1 << msbOfHi;
        int res = msbPow + rec(lo - msbPow, hi - msbPow);
        return res;
    }
        
        
public:
    int rangeBitwiseAnd(int m, int n) {
        return rec(m, n);
    }
};