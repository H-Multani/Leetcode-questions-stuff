class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // conditions dekho , ya exact same banega, ya fir +ve value

        // toh similar logic lagaenge part 1 type, ya saare elements even
        // karenge ya odd karenge

        // count nikal lo
        int even = 0, odd = 0;

        for (auto it : nums1) {
            if (it % 2 == 0)
                even++;
            else
                odd++;
        }

        if (odd == 0 || even == 0) {
            // means already order me hai
            return true;
        }

        // we here means kuch odd hai kuch even hai

        // now we know
        // odd-even-> odd
        // even-even-> even
        // odd-odd-> even

        // smallest element nikal lo, since usko change nai kar payenge

        // toh if smallest element is odd, then baaki saare odd bana sakte GG
        int smol = INT_MAX;
        for (auto it : nums1) {
            smol = min(smol, it);
        }

        if (smol % 2 == 1) {
            // means saare elements odd bana sakte apan'

            // since even elements-odd element-> odd element

            // jo already odd hai unke liye nums[j]=nums[i] chal denge

            // hence ans can be made
            return true;
        }

        // we here means smollest element is even,

        // lekin

        // even-even-> even
        // odd-even-> odd

        // toh iss element ko kisi odd ke sath pair nai kar sakte

        // hell if theres like 5 odd elements, like {1,3,5,7,9}

        // then inko ek dusre ke sath pair karke bhi saare even nai ban payenge,
        // ghum fir kar 1 element last me odd bachega hi

        // toh sabko even toh bana nai sakte

        // bacha option ki sabko odd bana do

        // ab yaha ye scene ki nums[i] is even ke liye we need smaller odd value

        // smallest odd value nikal lo

        smol = INT_MAX;

        for (auto it : nums1) {
            if (it % 2 == 1)
                smol = min(smol, it);
        }

        // ab iterate over the array, if odd hai element toh chhor do

        // if even hai element then check if we can do nums[i]-nums[j] here
        // where nums[j]==smol

        // if this it-smol>=1, its valid, do it, else meaning we have even value smaller than the smallest odd value, toh iss ko odd nai bana oayenge in such case return false

        for(auto it:nums1){
            if(it%2==0 && it-smol<1) return false;
        }

        // we here means sabko odd bana sakte
        return true;
    }
};