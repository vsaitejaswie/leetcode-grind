class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> nstore;

        for(int i=0; i<n;i++){
            // nstore.push_back(nums[i]); - not a set method
            nstore.insert(nums[i]);
        }

        int max_num = 0; // can't be INT_MIN
        int point = 0;
        for(auto i=nstore.begin(); i != nstore.end(); i++){
            cout<<*i<<endl;
            cout<<*i-1<<endl;
            if(nstore.find(*i-1) == nstore.end()){
                point = 1;
                int check = *i;
                while(nstore.find(check+1) != nstore.end()){
                    point++;
                    check++;
                }
            }
        
            if(point>max_num){
                max_num = point;
            }
            cout<<"point"<<point<<endl;
        }

        // // debug through print
        // for(auto i=nstore.begin(); i!=nstore.end(); i++){
        //     // cout<<nstore[i]<<endl; - does not work for set
        //     cout<<*i<<endl;
        // }

        return max_num;
    }
};