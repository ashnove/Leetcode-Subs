class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> a, vector<int> b){
           return (a[1]>b[1]); 
        });
        
        int boxLoaded = 0;
        int unitsLoaded = 0;
        for(auto boxType : boxTypes){
            int toBeLoaded = min(boxType[0], truckSize);
            truckSize -= toBeLoaded;
            unitsLoaded += toBeLoaded*boxType[1];
        }
        return unitsLoaded;
    }
};