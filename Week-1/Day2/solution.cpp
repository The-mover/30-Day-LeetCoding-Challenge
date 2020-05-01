class Solution {
private:
    int sumOfDig(int n) {
        int sum = 0;
        while( n ) {
            int rem = n % 10;
            sum += rem * rem;
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        for(int i=1; i<=100; i++) {
            if( n == 1 ) return true;
            n = sumOfDig(n);
        }
        return false;
    }
};