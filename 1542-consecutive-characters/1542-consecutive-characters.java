class Solution {
    public int maxPower(String s) {
        char[] snew=s.toCharArray();
        int ans=1;
        int curr=1;
        int len=s.length();
        for(int i=0;i<len-1;i++){
            if(snew[i]==snew[i+1]){
                curr++;
            }
            else{
                if(ans<curr){
                    ans=curr;
                }

                curr=1;
            }
        }
        if(ans<curr){
            ans=curr;
        }

        return ans;

    }
}