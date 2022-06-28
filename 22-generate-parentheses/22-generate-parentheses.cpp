class Solution {
    
public:
    vector<string> parentheses;
    void generate(int idx, int n, string combination, int balanced){
        if(idx == n){
            if(balanced == 0){
                parentheses.push_back(combination);
            }
            return;
        }
        generate(idx + 1, n, combination + '(', balanced + 1);
        if(balanced)        
            generate(idx + 1, n, combination + ')', balanced - 1);
    }
    vector<string> generateParenthesis(int n) {
        generate(1,  n*2, "(", 1);
        return parentheses;
    }
};