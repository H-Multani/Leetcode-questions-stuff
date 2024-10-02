class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0) return {};
        vector<int> temp=arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int>mpp;
        mpp[temp[0]]=1;
        int curr=2;// iss rank ke liye banda chahiye
        for(int i=1;i<temp.size();i++){
            if(mpp.find(temp[i])!=mpp.end()){
                // common element found, same rank rehen do
            }
            else{
                // new element mila hai, curr rank de do
                mpp[temp[i]]=curr;
                // curr rank ko aage badha do new element ke liye
                curr++;
            }
        }


        for(int i=0;i<arr.size();i++){
            arr[i]=mpp[arr[i]];
        }

        return arr;
    }
};