class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>&a, vector<int>&b){
           return a[0]>b[0] || (a[0]==b[0] && a[1] < b[1]); 
        });
        vector<vector<int>> resultList;
        for(auto vec : people){
            resultList.insert(resultList.begin() + vec[1], vec);
        }
        return resultList;
    }
};