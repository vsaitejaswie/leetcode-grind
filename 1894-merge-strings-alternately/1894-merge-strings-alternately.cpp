class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merge = "";
        int loop = word1.size()<word2.size()? word1.size() : word2.size();
        
        for(int i=0; i<loop; i++){
            merge.push_back(word1[i]);
            merge.push_back(word2[i]);
        }

        for(int i=loop; i<word1.size(); i++)
        {
            merge.push_back(word1[i]);
        }

        for(int i=loop; i<word2.size(); i++)
        {
            merge.push_back(word2[i]);
        }
        
        cout<<merge<<endl;
        return merge;
    }
};