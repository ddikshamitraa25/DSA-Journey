class Solution {
public:
    bool check(string s, string pattern){
        if(s.size()%pattern.size()!=0)return false;
        string temp="";
        int times=s.size()/pattern.size();
        for(int i=0; i<times; i++)temp+=pattern;
        return temp==s;
    }
    string gcdOfStrings(string str1, string str2) {
        int n=min(str1.size(), str2.size());
        for(int len=n; len>=1; len--){
            if(str1.size()%len!=0||str2.size()%len!=0)continue;
            string prefix=str1.substr(0, len);
            if(check(str1, prefix)&& check(str2, prefix))return prefix;
        }
        return "";
    }
};