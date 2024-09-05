class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum=0;
        for(auto it:rolls){
            sum+=it;
        }
        int prod=(n+(rolls.size()))*mean;
        int reqd=prod-sum;
        vector<int> ans;
        if(reqd>6*n || reqd<n) return ans;
        // if(reqd<7) return {reqd};
        
        // sum=4 
        // n=3,_ _ _,1 1 1, sum remaining extra after filling=4-n=4-3=1
        // jitna extra sum bacha hai, utna mai ek element me de dunga
        // 1,1,1. extra=1, sent to the first wala 1->  (currsum-n)+1
        // 2,1,1, extra=0
        // curr wale element ke liye options: 
        // 1-> (currsum-n)+1, ye bharenge tab jab iska value overall <=6
        // 2-> 6
        // overall if((currsum-n)+1>6) take 6, otherwise take (currsum-n)+1
        // can be written as min(6,(currsum-n)+1)

        // sum=13 
        // n=4,_ _ _ _,1 1 1 1,
        // for first iteration(/value) ,min(6,sum-n+1)=>min(6,13-4+1)->6
        // _ _ _ _ => 6 _ _ _, n=3, sum=13-6=7
        // sum=7
        // n=3,_ _ _,1 1 1
        // for second ,min(6,sum-n+1)=>min(6,7-3+1)->5
        // 6 _ _ _ => 6 5 _ _, n=2, sum=7-5=2
        // sum=2
        // n=2,_ _,1 1
        // for third ,min(6,sum-n+1)=>min(6,2-2+1)->1
        // 6 5 _ _ => 6 5 1 _, n=1, sum=2-1=1
        // sum=1
        // n=1,_,1
        // for fourth ,min(6,sum-n+1)=>min(6,1-1+1)->1
        // 6 5 1 _ => 6 5 1 1, n=0, sum=1-1=0
        // n==0, apna kaam khatam, rok denge yaha
        while(reqd!=0){
            int value_taken=min(6, reqd-n+1);
            ans.push_back(value_taken);
            n--;
            reqd=reqd-value_taken;
        }
        return ans;


    }
};