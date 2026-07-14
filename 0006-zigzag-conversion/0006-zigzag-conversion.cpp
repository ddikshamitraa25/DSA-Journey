class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        vector<string>rows(numRows);
        int currentRow=0;
        bool goingDown=true;
        for(char ch:s){
            rows[currentRow]+=ch;
            if(currentRow==numRows-1)goingDown=false;
            else if(currentRow==0)goingDown=true;
            if(goingDown)currentRow++;
            else currentRow--;
        }
        string ans="";
        for(int i=0; i<numRows; i++)ans+=rows[i];
        return ans;
    }
};