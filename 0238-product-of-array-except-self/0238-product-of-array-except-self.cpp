// This is how you do not write a solution (19/22 test cases passed)
// It is creating two extra arrays, just one result array is enough to solve this question
// postprod.insert(postprod.begin(), dummy) is a O(n) operation, therefore when you write it
// inside a for loop it leads to O(n^2) complexity giving rise to a Time Limit Exceeded error
// when the input size is large

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();

//         vector<int> preprod;
//         preprod.push_back(1);
//         for(int i=0; i<n; i++){
//             preprod.push_back(preprod[i]*nums[i]);
//         }

//         vector<int> postprod;
//         postprod.push_back(1);

//         for(int i=0; i<n; i++){
//             int dummy = nums[n-1-i]*postprod[0];
//            postprod.insert(postprod.begin(), dummy);
//         }

//         // for(int i=0; i<postprod.size(); i++){
//         //     //cout<<"pre: "<<preprod[i]<<endl;
//         //     cout<<"post: "<<postprod[i]<<endl;
//         // }
                
//         vector<int> result;
//         for(int i=0; i<n; i++){
//             result.push_back(preprod[i]*postprod[i+1]);
//         }
//         cout<<"----------"<<endl;
//         return result;
//     }
// };

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

        int prefix = 1;
        for(int i=0; i<n; i++){
            result[i] *= prefix;
            prefix = prefix*nums[i];
        }

        int postfix = 1;
        for(int i=n-1; i>=0; i--){
            result[i] *= postfix;
            postfix = postfix * nums[i];
        }

        // for(int i=0; i<n; i++){
        //     cout<<"pre: "<<result[i]<<endl;
        // }

        return result;
    }
};
