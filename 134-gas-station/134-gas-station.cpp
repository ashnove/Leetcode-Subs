class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int hasFuel = 0, excess = 0;
        int idx = 0;
        for(int i = 0; i < gas.size(); i++){
            hasFuel += gas[i];
            hasFuel -= cost[i];
            if(hasFuel < 0){             //deadends
                excess -= hasFuel;       //keep track of the excess fuel required to travel till ith station without reaching deadends.
                hasFuel = 0;
                idx = (i + 1) % gas.size();
            }
        }
        return (excess <= hasFuel ? idx : -1);
    }
};