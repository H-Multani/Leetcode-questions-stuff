class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();

        int i=n-1;

        int carry=0;
        // last wale bande ko +1 karo

        while(i>=0){
            //agar last wala band hai
            if(i==n-1){
                digits[i]++;
            }

            // current digit me carry add kardo
            digits[i]+=carry;

            // agar ye >=10 hua toh 1 carry me laga kar agle digit par chalo
            if(digits[i]>=10){
                // if this value is like 15 then 1 carry me jayega and 5 yehi rahega
                digits[i]=digits[i]%10;

                carry=1;
            }
            else{
                // we here means carry and all add karne ke baad bhi digit is less than 10 toh aage wale bande ke liye carry becomes 0
                carry=0;
            }

            i--;
        }

        // agar last me carry=1 reh gaya toh number ke start me lagega like if 9999 diya tha original +1 karenge toh 10000 banega, toh 0000 toh array me honge hi, ye extra carry add karna padega
        if(carry==1){
            vector<int> ans={1};

            for(auto it:digits){
                ans.push_back(it);
            }

            return ans;

        }

        return digits;

    }
};