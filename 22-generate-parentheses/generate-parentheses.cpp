class Solution {
public:
    vector<string>result;
    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return result;
    }
    void backtrack(string current, int open, int close, int max){
        if(current.length()==max*2){
            result.push_back(current);
            return;
        }
        if(open < max){
            backtrack(current+"(", open+1, close, max);
        }
        if(close<open){
            backtrack(current+")", open, close+1, max);
        }
    }
};