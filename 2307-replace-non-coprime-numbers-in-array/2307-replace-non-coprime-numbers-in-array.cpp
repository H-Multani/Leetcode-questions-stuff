class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        // i think stack lene se ho jana chahiye, since we neeed to get GCD of 2
        // values at a time and bola gaya hai ki kuch bhi karlo tum, overall ans
        // same hi aayega hamesha toh greedy khel sakte hai jo pehle milte jaaye
        // banate jao uska kaam, and nai mile toh pada rahega stack me, stack
        // here since stack me apna just to the left wala element rahega
        // hamesha, toh current bande ko left wale bande ke sath mix maar kar
        // laga sakte hai checking

        // stack bana do which will store elements to the left of current
        // element
        stack<long long> st;

        // isme ek element hona chahiye atlesast, toh 1st wala bhej do
        st.push(nums[0]);

        long long n = nums.size();

        for (long long i = 1; i < n; i++) {
            // current element ko push kardo stack me
            st.push(nums[i]);

            // ab stack se 2 adjacent bande nikalo and tab tak merge karte jao
            // jab tak hora hai
            while (st.size() >= 2) {
                // 2 bande nikalo
                long long val1 = st.top();
                st.pop();
                long long val2 = st.top();
                st.pop();

                // cout << "chk " << val1 << " " << val2 << endl;

                // val2 pehle dalegi if reqd

                // kya inn dono values se ban sakta hai kuch
                if (gcd(val1, val2) > 1) {
                    // means ye 2 element coprimes hai, iska LCM daal do andar
                    // stack me we know gcd(a,b)*lcm(a,b)=a*b, by this we can
                    // get LCM ka formula, put it directly
                    long long lcm = (val1 * val2) / gcd(val1, val2);
                    st.push(lcm);
                } else {
                    // we here means neighbouring elements are not coprimes, in
                    // such case dono elements ko puran order me vapas daal do
                    st.push(val2);
                    st.push(val1);

                    // ab since iske aage kuch hona nai hai(since adjacent toh
                    // non coprime nikle) toh iss loop me chalte rehne se ko
                    // faayeda nai hai, get outta here
                    break;
                }
            }
            // we here means jitne baari process hona tha ho gaya, ab nai hora
            // aagr badho
        }

        cout << st.size() << endl;

        // ab saare processes hone ke baad jitne elements bache hai vo sab stack
        // me hai

        // stack se elements nikal kar vector me daal do
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        // ofc since apan stack se nikal rhe hai toh order ulta aayega, reverse the array
        reverse(ans.begin(),ans.end());

        return ans;
    }
};