class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> count;
        for(int i : hand) count[i]++;
        
        for(auto elem : count){
            if(elem.second == 0) continue;
            for(int j = elem.first; j < elem.first + groupSize; j++){
                if(count[j] < elem.second) {
                    return 0;
                }
                count[j]-=elem.second;
            }
        }
        return 1;
    }
};