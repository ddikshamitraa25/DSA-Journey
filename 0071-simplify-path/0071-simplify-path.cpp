class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string name;
        stringstream ss(path);
        while(getline(ss, name, '/')){
            if(name=="" || name=="."){
                continue;
            }
            if(name==".."){
                if(!st.empty()){
                    st.pop();
                }
            }else{
                st.push(name);
            }
        }
        if(st.empty()){
            return "/";
        }
        vector<string>folders;
        while(!st.empty()){
            folders.push_back(st.top());
            st.pop();
        }
        reverse(folders.begin(), folders.end());
        string ans="";
        for(string folder:folders){
            ans+="/"+folder;
        }
        return ans;
    }
};