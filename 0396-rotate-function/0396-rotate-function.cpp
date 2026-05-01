class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        // samajh gaya loigcck

        // ttl=arr[0]+arr[1]+....arr[n-1];
        // for f(0) and f(1)
        // f(0)=             (0*ar[0]) +(1*ar[1]) +(2*ar[2]) ....+ (n-1*ar[n-1])
        // f(1)=(0*ar[n-1]) +(1*ar[0]) +(1*ar[1]) ....+ (n-2*ar[n-2])

        // meaning f(1)=f(0)+ttl- n*(last element currently)

        // ye logic samajh me kaise aaya, see the bifurcation above, f(0) ke
        // saare elements me elements add hue 1 time to get to f(1), ie
        // 0*ar[0] became 1*ar[0],
        // 1*ar[1] became 2*ar[1],
        // 2*ar[2] became 3*ar[2],...
        // this goes on until last second element, toh ye wale part ko we can
        // simulate by simply adding ttl one time to previous f(0) since
        // ttl=ar[0]+ar[1]+ar[2]+...ar[n-1]

        // for last element,originally it was (n-1)*ar[n-1], after we added
        // ttl(to simulate sum for baaki elements), it became n*ar[n-1], now
        // n*ar[n-1] became 0*ar[n-1]
        // we can simulate this by subtracting n*(last element currently) from
        // whatever ttl we made till here

        // hence overall
        // f[i]=f[i-1]+ttl-n*(last element)

        // ab jaise apan rotate karenge toh last elements change hote jaenge,
        // for getting these last elements in order, apan loop peeche se start
        // karenge, since first rotation me last element niklega, second
        // rotation me last 2nd element and so onn

        // f[0] nikal lo

        int sum = 0;
        int n = nums.size(), ttl = 0;
        for (int i = 0; i < n; i++) {
            sum += (i * nums[i]);
            ttl += nums[i];
        }

        // f[0] ko ans bana do and get better answers later
        int ans = sum;

        // iterate peeche se and apply formula
        for (int i = n - 1; i >= 0; i--) {
            // current element last me hai, rotation ke baad new sum ke liye
            // formula apply kardo

            int newsum=sum+ttl-(n*nums[i]);

            // update ans
            ans=max(ans,newsum);

            // ab sum ko bhi update kar dena for aage aane wale elements/rotations
            sum=newsum;
        }


        // end me jo max ans mila le leo
        return ans;
    }
};