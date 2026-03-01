class Solution {
public:
    int minPartitions(string n) {
        // bhai seedha seedha soche toh 10101 types se bharna hai apan ko, aur
        // ek toh scene samajh aa raha ki deci binary numbers koi ajeeb si value
        // nai banayenge, ajeeb in the sense, 110 and 1101 are deci binary nos
        // hai add karenge toh we get 1211, toh ye number is made by adding the
        // 1's in ones place,tens place,100s place of all deci binary values

        // like we will never get ki deci binary nos ko add kiya toh aage wale
        // number me overflow hoga, unless we choose wrong, for eg
        // 10+10+10+10+10+10+10+10+10+10+10+10=120 bana sakte hai its valid ans,
        // but this is not the best way since this way uses 12 values , jabki we
        // can use 2 values to make 120 by doing 110+10, jisme all values(110
        // and 10) considered we have no 1's in units place,two 1's in tenths
        // place, one 1's in hundreds place,which is the best way we can get the
        // overall ans

        // all in all 10+10+... wale method me 12 baar 10+ lagane se number went
        // like 80->90->100(ie 90 ke badd add karne par the extra 1 overflowed
        // from 10s place to 100s place), aisa case wala kabhi best answer nai
        // dega(kyu?, idk, 2-4 examples me try kiya logic baith raha tha)

        // toh for 32, we need to have 3 nos jisme 10s place par 1 aaye and 2
        // nos jisme units place par 1 aaye, these are 10,11,11, hence best ans
        // is 3

        // toh for 94, we need to have 9 nos jisme 10s place par 1 aaye and 4
        // nos jisme units place par 1 aaye, these are
        // 10,10,10,10,10,10,10,11,11 hence best ans is 9, since isse kam values
        // me toh nai hona, since 11 ke baad we have next value as 100, which is
        // bigger than 94 so thats not an option clearly

        // for 82734, we need 8 nos with ten_thousand'ths place par 1 aaye, 2
        // nos with thousand'ths place par 1 aaye, 7 nos jisme 100s place par 1
        // aaye, 3 nos where 10's place par 1 aaye, 4 nos jisme units place par
        // 1 aaye, these can be 11111,11111,10111,10101,10100,10100,10100,10000,
        // since inn 8 nos me saare 1's posn me aa rahe ie 8 nos with
        // ten_thousand'ths place par 1, 2 nos with thousand'ths place par
        // 1, 7 nos jisme 100s place par 1, 3 nos where 10's place par
        // 1, 4 nos jisme units place par 1
        // isse best ans nai milne wala

        // toh overall n me se biggest jo bhi digit milega, apan ko utne values
        // chahiye rahenge atleast, no way around this since agar add karde
        // overflow se banane ka try karoge toh zyada values lagengi

        // hence we find overall biggest digit and return that as ans

        // hints me bhi yehi likha hai ig

        char ans='0';

        for(auto it:n){
            ans=max(ans,it);
        }

        // ab digit aa chuka hai maxm, lekin character hai... toh -'0' kar dena toh aa jayega int wala digit
        return ans-'0';
    }
};