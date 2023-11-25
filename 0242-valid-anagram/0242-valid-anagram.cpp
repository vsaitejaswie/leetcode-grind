// O(NlogN) and O(1) solution

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.size() != t.size()) return false;
//         if(s.sort() != t.sort()) return false;
//         return true;
//     }
// };

//O(N) and O(N) solution

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        map<char, int> sstore;
        map<char, int> tstore;
        for(int i=0; i<s.size(); i++){
            sstore[s[i]] += 1;
            tstore[t[i]] += 1;
        }
        if(sstore != tstore) return false; // Hashmaps can be compared directly in CPP
        return true;
    }
};