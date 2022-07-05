class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> present;
        for(auto &num:nums)
            present[num]=1;
        
        int prev=INT_MIN;
        int currentStreak=1;
        int maxStreak=0;
        
        for(auto &element:present){
            int num = element.first;
            if(num == prev+1){
                currentStreak++;
            }
            else
                currentStreak=1;
            prev=num;
            maxStreak = max(maxStreak, currentStreak);
        }
        
        
        return maxStreak;
        
        
        
        
    }
};