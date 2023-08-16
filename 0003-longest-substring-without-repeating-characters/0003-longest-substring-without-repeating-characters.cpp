class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unsigned long maxi = 1;
        map<char, int> track;
        int point = 0;
        int slide = 0;

        while(slide < s.size()){
            if(track.count(s[slide]) == 0){
                track[s[slide]] = 1;
                slide++;
            }
            else{
                track.erase(s[point]);
                point++;
            }
            maxi = max(maxi, track.size());

            if(point == s.size()) break;
        }
        return maxi;
    }
};