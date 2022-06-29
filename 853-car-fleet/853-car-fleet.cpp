class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pos_speed;
        for(int i = 0; i < position.size(); i++){
            pos_speed.push_back({position[i], speed[i]});
        }
        sort(pos_speed.begin(), pos_speed.end());
        double currentMaxTime = 0;
        int fleet = 0;
        for(int i = position.size() - 1; i >= 0; i--){
            double timeToReachTarget = (double)(target - pos_speed[i].first) / pos_speed[i].second;
            if(currentMaxTime < timeToReachTarget){
                currentMaxTime = timeToReachTarget;
                fleet++;
            }
        }
        return fleet;
    }
};