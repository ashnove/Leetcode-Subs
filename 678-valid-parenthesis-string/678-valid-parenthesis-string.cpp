class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for(char bracks : s){
            if(bracks == '(') low++;
            else low--;
            
            if(bracks != ')') high++;
            else high--;
            
            if(high < 0) break;
            low = max(low, 0);
        }
        return low == 0;
    }
};