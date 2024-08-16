class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0,rt=numbers.size()-1;
        vector<int> ans;

        while(left<rt){
            int sum=numbers[left]+numbers[rt];
            if(sum==target){
                ans.push_back(left+1);
                ans.push_back(rt+1);
                break;
            }
            else if (sum<target){
                left++;
            }
            else rt--;
        }
        return ans;
    }
};