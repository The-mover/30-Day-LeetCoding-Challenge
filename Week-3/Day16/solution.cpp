class Solution {
public:
    bool checkValidString(string s) {
        stack<char> myStack;
        for(char ch: s) {
            if( ch == '(' || ch ==  '*' ) {
                myStack.push(ch);
            }
            else if( ch == ')' ) {
                int specialChar = 0;
                bool openingFound = false;
                while(!myStack.empty()) {
                    if( myStack.top() == '(' ) {
                        openingFound = true;
                        if( !myStack.empty() ) myStack.pop();
                        break;
                    }
                    else if( myStack.top() == '*' ) {
                        specialChar += 1;
                        if( !myStack.empty() ) myStack.pop();
                    }
                }
                if( openingFound ) {
                    for(int i=1; i<=specialChar; i++) {
                        myStack.push('*');
                    }
                } else if( !openingFound && specialChar ) {
                    if( !myStack.empty() ) myStack.pop();
                } else if( !openingFound && !specialChar ) {
                    return false;
                }
            }
        }
        //cout << "hello "<< myStack.size() << endl;
        int specialCount = 0;
        if( myStack.empty() ) return true;
        while( !myStack.empty() ) {
            //cout << myStack.top() << endl;
            if( myStack.top() == '*' ) {
                specialCount += 1;
            } else if( myStack.top() == '(' ) {
                if( specialCount ) specialCount -= 1;
                else return false;
            }
            myStack.pop();
        }
        return true;
    }
};