class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        // iterate over the array

        int n = bits.size();

        for (int i = 0; i < n; i++) {
            // now agar apan n-1 idx par aa gaye kahi se means ki pattern ends
            // in a first character pattern, in such case return true
            if(i==n-1) return true;


            
            // agar current wala 1 hai
            if (bits[i] == 1) {
                // means ye pakka second char wala hai, ie current banda 1 and
                // next banda 0/1 ko leke ye second character ban jayega

                // toh since current(i) character and next(i+1) character are
                // already booked for second character(ie 10 or 11), toh aage
                // wala character ko check karne ka tak need nai hai since
                // already second character me aa gaya hai

                // skip to the next to next character and explore there, like i
                // se i+2 ab next check karo, toh yaha i++ kardo ek baari and ek
                // i++ for loop me already hora hai
                i++;
                // isse we got from i to i+2 in next iteration
            }

        }

        // we here means iterate karne ke baad bhi nai ho paya kuch 
        return false;
    }
};