class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if( n == 0 ) return 0;
        
        priority_queue<int> pq;
        
        for(int stone: stones) {
            pq.push(stone);
        }
        
        //cout << pq.size() << endl;
        while( !pq.empty() ) {
            int a = pq.top();
            pq.pop();
            if( pq.empty() ) {
                pq.push(a);
                break;
            }
            int b = pq.top();
            pq.pop();
            //cout << a << " " << b << endl;
            
            int dif = abs(a - b);
            if( dif > 0 ) pq.push(dif);
            
        }
        
        if( pq.empty() ) {
            return 0;
        }
        return pq.top();
    }
};