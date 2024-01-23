class Solution {
public:
    bool isPalindrome(string s) {
        int front = 0;
        int rear = s.size()-1;
        while(front<rear){
            while(!isAlphaNumeric(s[front]) && front<rear){
                front++;
            }
            while(!isAlphaNumeric(s[rear]) && front<rear){
                rear--;
            }
            if(tolower(s[front]) != tolower(s[rear])) {
                return false;
            }
            front++;
            rear--;
        }
        return true;
    }
private:
    bool isAlphaNumeric(char c) {
        //return (('A' <= ch <= 'Z') || ('a' <= ch <= 'z') || ('0' <= ch <= '9'));
        // Above is wrong syntax for implementing code in cpp, written below is the right syntax
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
};