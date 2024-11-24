class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        // hint 1 se padha
        // har row ke saare - signs ko ya toh resolve kardo, ya ek edge par
        // lado, if current row me 4 -ve signs hai, those can be resolved easily
        // 2-2 ka pair bana kar remove kardo signs
        // [-,+,-]=>[-,-,+]=>[+,+,+]

        // incase current row me odd nno of -ve signs hai, toh kuch bhi karlo
        // end me 1 -ve sign bacha rahega current row me, iss -ve sign ko la kar
        // rakh do left waale end par
        // [-,-,-]=>[+,+,-]=>[+,-,+]=>[-,+,+]

        // so now we will either have all rows with one -ve sign or no -ve signs
        // like this
        // [-,+,+,+]
        // [+,+,+,+]
        // [-,+,+,+]
        // [-,+,+,+]

        // ab saare -ve signs 1st column me hai like
        // [-,+,-,-]
        // ab inko resolve kardo like
        // [-,+,-,-]=>[-,+,+,+]

        // now we have only 1 -ve sign in the whole array like
        // [-,+,+,+]
        // [+,+,+,+]
        // [+,+,+,+]
        // [+,+,+,+]

        // ab ye ek 0 sign ko apan kisi bhi position par bhej sakte hai like
        // [-,+,+,+]->[+,-,+,+]->[+,+,-,+]

        // [+,+,-,+], - sign goes down like

        // [+,+,+,+]
        // [+,+,-,+], again - sign goes down like

        // [+,+,+,+]
        // [+,+,+,+]
        // [+,+,-,+]

        // so now we have
        // [+,+,+,+]
        // [+,+,+,+]
        // [+,+,-,+]
        // [+,+,+,+]

        // - sign ko kahi bhi le jaa sakte hai

        // ab apan ko sum of matrix elements ko maximize karna tha, and matrix
        // me 1 -ve value hai, hence common sense lagaenge thoda toh samajh me
        // aayega ki sum ko maximize karne ke liye, - wala sign sabse chhote
        // element ko bhejna padega, so that -ve wale value ka affect minimum ho
        // overall sum me

        // toh sabse pehle saare elements ka sum nikal lo
        long long ttlsum = 0;
        long long negative_sign_cnt = 0;
        for (auto it : matrix) {
            for (auto it2 : it) {
                // abs() value since original matrix me toh -ve element kaafi ho
                // sakte hai na
                ttlsum += abs(it2);
                if (it2 < 0)
                    negative_sign_cnt++;
            }
        }

        // ab sabse chhota element nikalo matrix ka, sabse chhota element
        // without the -ve sign, since -ve sign consider karenge toh -3 is
        // smaller than -1 lekin agar apan ne 3 pae -ve sign chhora toh ttlsum
        // me se -3 hoga, ie ttlsum chhota aayega , we dont want that since agar
        // -1 karte toh ttlsum biggest aata

        // basically numerically smallest value nikalo matrix me se, so that
        // apan -ve sign numerically smallest value ko de toh totalsum maximum
        // aayega
        int minm = INT_MAX;
        for (auto it : matrix) {
            for (auto it2 : it) {
                minm = min(minm, abs(it2));
            }
        }

        // ab apan ke paas numerically smallest value hai, iss par - sign lagana
        // hai

        // ab apan ke paas numerically smallest value mil chuka hai, usko ttlsum
        // se 2 baar remove karenge to get answer

        // since if matrix was like [1,-2,3],
        // iss case ke liye ans needed= 2+3-1= 4
        // currently, we have
        // ttlsum=1+2+3=6, and apan ne - sign
        // 1 ko diya hai, toh ttlsum calculation me se jo value -ve leni thi vo
        // +ve leli apan ne, hence remove minm value 1st time to get to the
        // ttlsum jo hota if -ve wali value +ve lete hi nai toh,
        // ttlsum=1+2+3-1=>2+3=>5

        // now agae uss -ve value ko ttlsum se remove karenge toh aayega
        // ttlsum=2+3-1=4, which is the answer when minm val is removed

        // hence return ttlsum-(2*(numerically smallest number))

        // ab yaha 2 cases hai actually,
        // case 1: in the end apan ke paas 1 extra - sign bacha hua hai , jo
        // apan minm waale bande ko de rahe hai to get maxm ttlsum

        // case 2: in the end apan ke paas koi extra - sign bacha nai hai
        // ie all -ve signs got resolved, like in eg1
        // ye case tab hoga is the total number of -ve signs in the matrix is
        // even, agar even no of - signs hai toh saare - sign ek dusre ke saath
        // pair bana lenge, and then +ve ho jaenge(like in eg1)
        // in such case apan ko ttlsum hi dena hai direct ans me

        // hence
        if (negative_sign_cnt % 2 == 0) {
            // means case 2 hua hai yaha
            // ie even no of - signs the, saare ek dusre ke saath aa kar cancel
            // ho gaye, hence end me koi -ve value nai rahegi, in such case
            // ttlsum bhj do directly
            return ttlsum;
        }

        // we here means end me resolve karte time 1 - sign reh gaya, which will
        // be given to smallest numerical vala element so that ttlsum maxm hoye

        // hence in this case return ttlsum-(2*(smallest numerical number)),
        // iska logic upar likha hai pehle se
        return ttlsum-=2*minm;
    }
};