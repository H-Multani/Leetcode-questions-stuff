class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        // not really hard, 10^9 tak jaa raha hai, means ek ek karke check karna
        // loop laga kar isnt feasible, need better 

        // i notice that
        // 2 digits-> {12,23,34,45,56,67,78,89}
        // 3 digits-> {123,234,345,456,567,678,789}
        // 4 digits-> {1234,2345,3456,4567,5678,6789}
        // 5 digits-> {12345,23456,34567,45678,56789}
        // 6 digits-> {123456,234567,345678,456789}
        // 7 digits-> {1234567,2345678,3456789}
        // 8 digits-> {12345678,23456789}
        // 9 digits-> {123456789}, this is around 10^8, toh its valid,
        // bas itne hi hai total total, vector bana do, jo valid hai ans me daal
        // do return kardo

        vector<vector<int>> vec;
        vec.push_back({12,23,34,45,56,67,78,89});
        vec.push_back({123,234,345,456,567,678,789});
        vec.push_back({1234,2345,3456,4567,5678,6789});
        vec.push_back({12345,23456,34567,45678,56789});
        vec.push_back({123456,234567,345678,456789});
        vec.push_back({1234567,2345678,3456789});
        vec.push_back({12345678,23456789});
        vec.push_back({123456789});

        // iterate and make ans

        vector<int> ans;

        for(auto it:vec){
            for(auto it2:it){
                if(it2>=low && it2<=high){
                    ans.push_back(it2);
                }
            }
        }

        return ans;
    }
};