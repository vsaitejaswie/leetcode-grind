// // Not optimal solution
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         map<int, int> store;
//         vector<int> result;
//         for(int i=0; i<nums.size();i++){
//             store[nums[i]] += 1;
//         }

//         sort(store.rend(),store.rbegin());

//         int n=0;
//         auto point = store.rend();
//         while(n<=k){
//             result.push_back(point->first);
//             point++;
//             n++;
//         }
//         return result;
//     }
// };

// Optimal solution - Modified Bucket Sort

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> numstore;
        for(int i=0; i<nums.size(); i++){
            numstore[nums[i]]++;
        }

        vector<vector<int>> counts(nums.size() + 1);
        for(auto j=numstore.begin(); j!=numstore.end(); j++){
            counts.at(j->second).push_back(j->first);
            cout<<"index :"<<j->second<<endl;
        }

        cout<<"counts size is: "<<counts.size()<<endl;

        vector<int> result;
        for (int i=counts.size()-1; i>0; i--){
            if(result.size()>=k){
                break;
            }
            if(!counts[i].empty()){   // (1)
                cout<<"counts index: "<<i<<endl;
                for(auto r=counts[i].begin(); r != counts[i].end(); r++){
                    result.push_back(*r); //(2)
                }
            }
        }

        return result;
    }
};