class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int sCount = 0, sBack = 0;
        int tCount = 0, tBack = 0;
        
        int sLen = S.size();
        int tLen = T.size();
        
        string s = "", t = "";
        
        for(int i=sLen-1; i>=0; i--) {
            if( !sCount && S[i] != '#' ) {
                s = S[i] + s;
            } else if( sCount && S[i] != '#' ) {
                sCount--;
            } 
            else if( S[i] == '#' ) {
                sCount++;
            }
        }
        
        for(int i=tLen-1; i>=0; i--) {
            if( !tCount && T[i] != '#' ) {
                t = T[i] + t;
            } if( tCount && T[i] != '#' ) {
                tCount--;
            }
            else if( T[i] == '#' ) {
                tCount++;
            } 
        }
        if( s == t ) return true;
        return false;
    }
};