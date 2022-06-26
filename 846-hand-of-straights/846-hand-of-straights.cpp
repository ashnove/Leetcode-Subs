class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> count;
        for(int i : hand) count[i]++;
        
        sort(hand.begin(), hand.end());
        
        for(int i = 0; i < hand.size(); i++){
            if(count[hand[i]] == 0) continue;
            vector<int> temp;
            int cnt = 0;
            for(int j = hand[i]; j < hand[i] + groupSize && count[j]; j++){
                cnt++;
                count[j]--;
            }
            if(cnt != groupSize){
                
                return 0;
            }
        }
        return 1;
    }
};