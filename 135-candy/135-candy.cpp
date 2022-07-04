class Solution {
public:

    int candy(vector<int>& ratings) {
        int candies = 0;
        int candyCount = ratings.size();
        vector<int> left(candyCount), right(candyCount);
        left[0] = 0;
        right[candyCount - 1] = candyCount-1;
        for(int i = 1; i < candyCount; i++){
            if(ratings[i] > ratings[i - 1])
                left[i] = left[i - 1];
            else 
                left[i] = i;
        }
        for(int i = candyCount - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1])
                right[i] = right[i + 1];
            else 
                right[i] = i;
        }
        for(int i = 0; i < candyCount; i++){
            candies += max(right[i]-i, i-left[i])+1;
        }
        return candies;
    }
};