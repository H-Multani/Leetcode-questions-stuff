class Solution {
public:
string DecimalToBinary(int num)
{
    string str;
      while(num){
      if(num & 1) // 1
        str+='1';
      else // 0
        str+='0';
      num>>=1; // Right Shift by 1  
    }  
    // reverse(str.begin(),str.end());  
      return str;
}
    int largestCombination(vector<int>& candidates) {
        vector<int> bitcnt(32,0);

        for(auto it:candidates){
            // current bande ko convert to binary
            string curr=DecimalToBinary(it);

            for(int i=0;i<curr.size();i++){
                if(curr[i]=='1'){
                    bitcnt[i]++;
                }
            }
        }

        return *max_element(bitcnt.begin(),bitcnt.end());
    }
};