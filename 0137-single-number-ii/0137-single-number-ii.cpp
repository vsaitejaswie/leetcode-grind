class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> store;

        for(int i=0;i<nums.size();i++){
            if(store[nums[i]]==2){
                store.erase(store.find(nums[i]));
                cout<<"if"<<endl;
            } else {
                store[nums[i]]++;
                cout<<nums[i]<<": "<<store[nums[i]]<<endl;
            }
        }

        return store.begin()->first;
    }
};