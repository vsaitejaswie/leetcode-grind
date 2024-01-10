class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> anastore;
        for(int i=0; i<strs.size(); i++){
            string keyString = getKey(strs[i]);
            anastore[keyString].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for(auto m=anastore.begin(); m != anastore.end(); m++){
            //cout << m->second <<endl;
            result.push_back(m->second);
        }

        return result;
    }

private:
    string getKey(string keyWord) {
        vector<int> count(26);
        for(int j=0; j<keyWord.size(); j++) {
            count[keyWord[j] - 'a']++;
        }

        string keySent;

        for(int k=0; k<26; k++){
            keySent.append(to_string(count[k]));
            keySent.append("#");
        }

        return keySent;
    }
};