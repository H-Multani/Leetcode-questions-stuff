class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {

        // ghum fir kar prefix par hi aa gaye apan, since jumps karne ke baad
        // bhi best ans will be in 1-2 jumps, toh prefix will work
        int n = nums.size();
        // maxm left store karlo
        vector<int> maxleft(n);
        // maxleft[i]=maxm element from idx 0 to i

        // minm rt store karlo
        vector<int> minrt(n);
        // minrt[i]=minm element from idx i+1 to n-1

        // base values daal denge
        maxleft[0] = nums[0];
        // since iske left me koi maxm nai hai
        minrt[n - 1] = nums[n - 1];
        // since iske rt me koi minm nai hai

        // maxleft bhardo
        for (int i = 1; i < n; i++) {
            maxleft[i] = max(maxleft[i - 1], nums[i]);
        }
        // minrt bhardo
        for (int i = n - 2; i >= 0; i--) {
            minrt[i] = min(minrt[i + 1], nums[i]);
        }

        vector<int> ans(n);

        // ab last element ke liye ans will be maxleft of n-1 th element, since
        // right toh jana not possible
        ans[n - 1] = maxleft[n - 1];

        // baaki ka ans bhardo
        for (int i = n - 2; i >= 0; i--) {

            // yaha 2 cases
            if (maxleft[i] <= minrt[i + 1]) {
                // we here meaning, apan original se left toh chale gaye, lekin
                // left ka maxm is smaller than right ka minm, toh iss case me
                // apan right side par kabhi jaa hi nahi payenge

                // toh in such case ans for current element will be the max we
                // have found on left side
                ans[i] = maxleft[i];
            } else {
                // we here meaning apan right side par minm element mil gaya
                // such that its smaller than the maxm element of left side

                // toh apan original se left toh chale gaye, and uske baad left
                // wale jagah se right bhi chale aaye

                // toh minm se to right side par chale jaenge, aur waha se best
                // ans will be, maxleft from that place, which will get is to
                // maxm best ans

                // aur vo same maxm will be ans[i+1] since

                // maan lo array was like [10,....i,...100,7,200], maxleft is
                // 10, minright=7

                // ab apan iss 10 se 7 jaa sakte hai since smaller hai, aur 7
                // par baith kar best ans will be 100, which is maxleft of 7

                // ab ye best ans couldve been 200 if 200 ke right me smaller
                // hota toh, but nai milega, since milna hota toh first time me
                // hi mil jata

                // ab this 100 will be ans for current i, lekin ye apan nikale
                // kaise, since we cant just keep maxright as well since usse
                // 200 milega which isnt right, lekin apan loop ulta chal rahe
                // hai, means ye 100 pehle aage wale kisi ka ans raha hoga pehle
                // se, simply due to the face that 100 ke right me 7 hai, and 7
                // se 100 hamesha aa jaenge

                // toh i+1 th bande se leke 7 ki posn tak sabka ans 100 hoga
                // since hamesha 100 par pahuch paenge

                // toh best ans is just 1 step aage which is i+1


                // iska detailed logic mik se samjha hai check there too
                ans[i]=ans[i+1];
            }
        }

        // ab return krdo ans ko
        return ans;
    }
};