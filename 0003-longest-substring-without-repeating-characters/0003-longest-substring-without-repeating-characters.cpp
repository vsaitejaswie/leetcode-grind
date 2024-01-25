// Solved it a few months ago

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         if(s.size() == 0) return 0;
//         unsigned long maxi = 1;
//         map<char, int> track;
//         int point = 0;
//         int slide = 0;

//         while(slide < s.size()){
//             if(track.count(s[slide]) == 0){
//                 track[s[slide]] = 1;
//                 slide++;
//             }
//             else{
//                 track.erase(s[point]);
//                 point++;
//             }
//             maxi = max(maxi, track.size());

//             if(point == s.size()) break;
//         }
//         return maxi;
//     }
// };

// // while loop has been used because it doesn't make sense to use for loop
// // for sliding window implementation for this problem (window size is variable)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0 || n==1) return n;

        int result = 0;
        unordered_map<char, int> track;
        int f=0, r=1;

        track[s[f]] = f;

        while(r<n) {
            if(track.find(s[r]) != track.end()) {
                for(int i=f; i<=track[s[r]]; i++){
                    cout<<s[i]<<endl;
                    track.erase(s[i]);
                    f++;
                }
            }
            track[s[r]] = r;
            result = max(result, int(track.size()));
            r++;
        }
        return result;
    }
};
