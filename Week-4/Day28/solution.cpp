class FirstUnique {
public:
    unordered_map<int, int> mp;
    queue<int> q;
    FirstUnique(vector<int>& nums) {
        for(int num: nums) {
            mp[num]++;
        }
        for(int num: nums) {
            if( mp[num] == 1 ) {
                q.push(num);
            }
        }
    }
    
    int showFirstUnique() {
        if( q.empty() ) return -1;
        return q.front();
    }
    
    void add(int value) {
        mp[value]++;
        if( mp[value] == 1 ) q.push(value);
        while(!q.empty()) {
            int top = q.front();
            if( mp[top] > 1 ) {
                q.pop();
            }
            else break;
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */