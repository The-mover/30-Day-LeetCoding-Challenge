class Solution {
private:
    string resultedString(string s, int firstPart, int stringLen) {
        string part1 = s.substr(0, firstPart);
        string part2 = s.substr(firstPart, stringLen - firstPart);
        return part2 + part1;
    }
    
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int shiftLen = shift.size();
        int sLen = s.size();
        int shiftSum = 0;
        
        for(int i=0; i<shiftLen; i++) {
            if( shift[i][0] == 0 ) {
                shiftSum += shift[i][1];
                shiftSum %= sLen;
            } else {
                shiftSum -= shift[i][1];
                shiftSum %= sLen;
            }
        }
        
        if( shiftSum == 0 ) return s;
        
        if( shiftSum > 0 ) {
            return resultedString(s, shiftSum, sLen);
        }
        else {
            return resultedString(s, sLen + shiftSum, sLen);
        }
    }
};