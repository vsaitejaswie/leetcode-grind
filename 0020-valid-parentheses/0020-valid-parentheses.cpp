class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2!=0) return false;

        stack<char> store;
        int countPop = 0;

        for(int i=0; i<s.size(); i++){

            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                store.push(s[i]);
                continue;}

            if(store.empty()){
                return false;}

            if(s[i] == ')' && store.top()=='('){
                store.pop();}
            else if(s[i] == '}' && store.top()=='{'){
                store.pop();}
            else if(s[i] == ']' && store.top()=='['){
                store.pop();}
            else{
                return false;}  
            countPop++;
        }
        if(countPop!=s.size()/2) return false;
        return true;
    }
};