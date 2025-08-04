class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.length() <= numRows) return s;
        vector<string> rows(numRows);
        int currentRow = 0;
        bool upToDown = false;
        for(char character : s){
            rows[currentRow] += character;
            if(currentRow == 0 || currentRow == numRows - 1)
            upToDown = !upToDown;
            currentRow += upToDown ? 1:-1;
        }
        string result;
        for(string row : rows){
            result += row;
        }
        return result;

    }
};