class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        // sabse pehle create another array jisme +1 if element is target, -1 if
        // its not target

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == target)
                nums[i] = 1;
            else
                nums[i] = -1;
        }

        // not problem becomes how m,any +ve sum subarrays, toh subarrays sums
        // nikalne ke liye prefix sum nikal lo

        // vector<int> pre(n+1, 0);
        // first element me 0 rehne do

        // for (int i = 1; i <= n; i++) {
        //     pre[i] = pre[i - 1] + nums[i - 1];
        // }

        // toh isse hoga ye ki subarraySum[l,r] ke liye we only need
        // pre[r-1]-pre[l]

        // we need this to be +Ve, toh essentially we need pre[r-1]>pre[l],
        // which can come down to pre[r]>pre[l] since l==r wala bhi valid
        // chalega(1 size subarray)

        // toh for every pre[r] we need count of how many pre[l] present SMALLER
        // than pre[r]
        long long ans=0;


        // now we will find count of all pre[l], iske liye mai prefix sum wala array nai lera hu and continous prefix sum calculate karta jaunga and update karta jaunga(can be done with prefix array as well lekin fir usme pre[r-1]>pre[r] wala case alag and pre[r-1]<pre[r] wala case alag banega, usko mai bana dunga lekin baad me samajh nai paunga kya kiya tha)

        // ek map le lenge which will store count of pre[l] jo abhi tak mile hai this will be useful in counting valid points for current r

        map<long long ,long long> mpp;

        // mpp[0]=1 hoga since jab kuch pre[0]=0 hai, which makes sense since iss point par kuch processing nai kiya hai apan ne toh essentially empty subarray ka cumulative sum hai ye

        mpp[0]=1;

        // ek valid points ke liye leke chalenge variable
        long long valid=0;

        // ek prefix sum bhi le lenge jo change hota jayega
        long long presum=0;

        for(int r=0;r<n;r++){
            // current pre[r] ke liye banaenge solution

            // sabe pehle if current banda same as target
            if(nums[r]==1){
                // means current banda target hai

                // iss case me presum badhega aage by 1, lekin before we do that, aage wale presum(pre[r]) ke liye current wala(pre[r-1]) valid me count hoga, toh uss valid ko count karlo
                
                // ab iss same older presum ke boht instances ho sakte hai toh jitne hai saare add kardo valid me since all are valid

                // ye freq map se nikal lo, each instance will be 1 valid presum to be used with aane wala pre[r] wala 

                valid+=mpp[presum];

                // inn valid points ko aage ans me include kiya jayega for pre[r] wala element, ki pre[r] ke liye kitne pre[l] mile ye valid values hai

                // ab apan presum ko aage badha denge
                presum++;
            }
            else{
                // we here means current banda target nai hai

                // iss case me presum peeche aayega by 1,means jo older wala presum hai uske hisab ke valid points yaha nai chalenge, like if older presum =4 tha then uss 4 ke liye valid pre[l] values were [...-1,0,1,2,3], jo ki abhi valid me counted hai already

                // ie currently valid=...mpp[-1]+mpp[0]+mpp[1]+mpp[2]+mpp[3]

                // lekin jab abhi apan presum ko nikalenge new presum=3 banega jiske liye valid pre[l] will be [....-1,0,1,2], dono ko dhyan se dekha jaaye toh jo elements presum 4 ke liye extra add kiye the mpp[3] karke, vahi include nai karna hai bas
                // ie new  valid=...mpp[-1]+mpp[0]+mpp[1]+mpp[2]

                // toh sirf mpp[3] wale remove kar denge valid se

                // toh sabse pehle cumsum update karo so that 4 se 3 aaye new prefix sum

                presum--;

                // ab iss new wale presum se jitne values add kiye the purane wale ke liye vo remove kardo, like jo pre[4] ke liye extra mpp[3] add kiya tha vo remove kardo sufficient hai since baaki peeche wale already add hone hi the

                // now presum=3 already, lekin iss presum wale boht instances pehle ho sakte hai, saare invalid honge current pre[r] ke liye toh ye count remove kar dena valid se

                // for that count map se nikal lo
                valid-=mpp[presum];
            }

            // ab ghum fir kar jitne valid bande hai current r wale ke liye(ie pre[r]), saare valid bande se pre[r] ka subarray bana kar include karna hai in ans

            // ie if valid=7 means pre[r] ke liye r se peeche 7 bande hai jiske sath valid subarray bana sakte, count karlo

            ans+=valid;

            // current wala pre[r] aage count me kaam aayega addition ya removal ke liye toh update the map too
            mpp[presum]++;
        }



        return ans;
    }
};