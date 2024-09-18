class Solution {
public:
    static bool comp(string &s1,string &s2){
        // int minm=min(s1.size(),s2.size());
        // int i=0,j=
        // for(int i=0;i<minm;i++){
        //     if(s1[i]>s2[i]) return true;
        //     else if(s2[i]<s2[i]) return false;
        // }
        
        if(s1+s2>s2+s1) return true;

        return false;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(auto it:nums){
            arr.push_back(to_string(it));
        }
        sort(arr.begin(),arr.end(),comp);
        string ans="";
        for(auto it:arr){
            
            cout<<it<<endl;
            ans+=it;
        }
        if(ans[0]=='0') ans="0";

        return  ans;
    }
};