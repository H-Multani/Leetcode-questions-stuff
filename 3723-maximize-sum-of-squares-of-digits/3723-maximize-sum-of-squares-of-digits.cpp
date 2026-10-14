class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // jitne 9 bhar sakte ho bhar do, baaki me 0 bhar dena

        string ans="";

        while(num--){
            // current digit me 9 bhar sakte toh bhar do, and then sum se remove kar dena utna

            int rem=min(9,sum);
            // rmemove from sum
            sum-=rem;
            // rem jitna string me daal do
            ans+=(rem+'0');
        }

        // loop ke bahar aane ke baad agar sum bacha means 9's se bhi nai bhar sakte meaning ans nai aayega, in such case return ""

        if(sum>0) return "";

        return ans;
    }
};