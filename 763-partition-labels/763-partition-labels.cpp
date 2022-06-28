class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastOccurrence(26, -1);
        for(int i = 0; i < s.size(); i++){
            lastOccurrence[s[i] - 'a'] = i;
        }
        vector<int> partitions;
        int len = 0;
        int intervalEnd = -1;
        for(int i = 0; i < s.size(); i++){
            intervalEnd = max(intervalEnd, lastOccurrence[s[i] - 'a']);
            len++;
            if(i == intervalEnd){
                partitions.push_back(len);
                len = 0;
            }
        }
        return partitions;
    }
};