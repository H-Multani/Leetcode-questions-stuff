class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        // mera simple wala code TLE dera tha, mik se dekhna pada

        // mik ne bhi mera TLE wale code me bass thoda change kiya tha, instead
        // of checking each k size ka window, ek window banate jao, badi karte
        // jao, agar window k size tk extend ho gai toh ans++ kardena, nai toh
        // agar kahi bhi invalid aaya ie r and r-1 th banda same nikal aaya toh
        // matlab windo invalid hogi, in such case l ko r par le aao and phir se
        // windo extend karte jao

        // boht simple hai fr fr logic wise, mik se samajh lo adha vdo khtm hone
        // se pehle samajh jaoge kya karna hai

        // code pura khud se bana liya maine

        int l = 0, r = 1;
        // start r frm 1 since r and r-1 ko check karenge apan

        int n = colors.size();
        // colors array me start se k elements aur append kardo, so that
        // circular wala bakchodi na ho

        // did upto k-1 since idx wahi tak sufficient hoga
        colors.insert(colors.end(), colors.begin(), colors.begin() + k - 1);

        // chalu karo window
        int ans = 0;

        // apan ko l se chalu karke k size ke windows lene hai, toh l<n tak
        // chalega, since agar l==n-1 se chalu hoke k size ka window valid ho
        // sakta hai, waha tak r jayega, l apna n tak hi jayega at max
        while (l < n) {
            // include karne ke liye kuch nai hai window me

            // shrink windo if needed

            // agar r and r-1 th banda same hai means invalid window ban rhi, l
            // to r par le aao, and restart with fresh window of size 0
            if (colors[r] == colors[r - 1]) {
                l = r;
            }

            // agar windo exact k size ki pahuch gai hai toh ans++ kardo, and
            // l++ bhi kardo, so that aage ki new window conside kare ab apan

            // basically agar current windo k size pahuh gai means 1 possible
            // window included, hence ans++, ab aage wali windows >k size ki
            // banengi, which is not needed, toh l++ kar rhe hai to show ki
            // current window count hone ke baad new windo l+1 se chalu hoyegi,
            // agar hogi toh, simple hai logic bohot, maathe me visualize karo,
            // nai toh dry run karo windo bana kar aa jayega samajh me
            if (r - l + 1 == k) {
                ans++;
                l++;
            }
            // window aage badhao
            r++;
        }

        return ans;
    }
};