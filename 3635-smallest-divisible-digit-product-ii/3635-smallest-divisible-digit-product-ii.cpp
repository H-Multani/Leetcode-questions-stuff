class Solution {
public:
    typedef long long ll;

    // funcn jo required number ke hisab se best possible ans bana kar dega
    // basically we input ki ye num chahiye, and itne length ka chahiye bana kar
    // dega

    // like if we want four 5's and three 7's, toh num=5*5*5*5*7*7*7,and we want
    // this best ans in 5 free slots toh len=5
    string func(ll num, int len) {
        // yaha apan ko best string banana len size ka(or more doesnt matter
        // here)

        // toh string lelo
        string ans = "";

        // yaha 9 se digits se divide karna start karo ab , since 9=3*3*3, toh 3
        // places par 3 daalne se accha ek par hi 9 daal denge, isse we get
        // better ans since 119 is smaller than 333, lekin both have same
        // product of digits

        // toh pehle 9,then 8,7,6,5,4,3,2 karenge in that order, so that jitne
        // bade digits nikal paaye sab nikal le

        for (int digit = 9; digit >= 2; digit--) {
            // agar current digit divide karra hai toh kar lo and ans me daal do
            while (num % digit == 0) {
                num /= digit;
                ans += (digit + '0');
            }
        }

        // ab maan lo len pahuchi nai pehle digits bhar kar num ko khatam kar
        // diye apan

        // toh bache kuchi space me padding 1 se kardo, since 1 is smallest digit and kisi se divisible nai
        while(ans.size()<len) ans.push_back('1');


        // now suppose we have 2 ans
        // ans=997711111, and 
        // ans=111117799

        // in dono me digits ka product same hai, lekin upar wala is bigger than neeche wala as a number, 

        // and since we need smallest ans we can find, hence apan ans ko reverse kar denge fir bhejenge

        reverse(ans.begin(),ans.end());

        // bhej do ans
        return ans; 


    }

    string smallestNumber(string num, long long t) {
        int n = num.size();

        // sabse pehle t ke prime factors nikalo, agar 2,3,5,7 ke alaga kuch bhi
        // hua, means ans cant be made, return -1

        ll temp = t;
        for (auto it : {2, 3, 5, 7}) {
            // agar it se divide hora toh karte raho
            while (temp % it == 0)
                temp /= it;
        }

        // ab agar 1 ke alava kuch bhi bacha means other prime factors bhi hai,
        // jiske chalte kabhi ans nai banega since num ke digits diviisble karne
        // hai t se, and agar t me lets say 13 hai, toh num ke koi digits ka
        // multiplication karne se 13 nai tootega, toh aise cases ke liye return
        // -1
        if (temp != 1)
            return "-1";

        // we here means number banana is possible

        // toh factors nikal lo t ke, ye factors hi apan ko sett karne padenge
        // ans me, so if t has four 7's, then apan ko ans me four times 7 fix
        // karna hi padega mandatory hai, uske baad jo digit lagana laga do,

        // similarly if t has six 2's and three 5's, toh ye accomodate karna
        // padega ans me apne

        // toh ye factors kaam ke hai, nikal kar rakhna pdega

        // to make ans, we need smallest number bigger than or = to num

        // for that we make remainingfactors array

        // remfact[i]=> agar apan apne ans me num se first i digits lele seedhe
        // seedhe, toh baaki factors kitne lagane padenge alag se so that
        // overall divisible by t

        // suppose t has six 2's and three 5's originally, and remfact[3]=400,
        // 400-> two 5's and two 2's,
        // means ans me agar nums se first 3 digits seedhe seedhe utha le, toh
        // bacha kucha ans banane ke liye apan ko sirf two 5's and two 2's
        // chahiye rahega

        // iss way me apan num se just bada valid ans bana payenge

        // precompute that
        vector<ll> remfact(n + 1, t);
        for (int i = 0; i < n; i++) {
            // current digit nikalo
            ll dgt = num[i] - '0';

            // here, suppose t me five 2's hai and seven 3's hai
            // and current character 6 hai
            // 6-> 2*3
            // toh iss 6 ko ans me include karne se apan ko one 2 kam banana
            // padega and one 3 kam banana padega

            // toh overall iss char ko lene se ab apan ko sirf four 2's banane
            // padenge and six 3's banane padenge

            // ye karne ke liye apan GCD lete hai since t me already both 2's
            // and 3's hai and yaha 6 hai apne paas, toh GCD aayega 6, iss 6 se
            // divide kar denge original ko toh itll be like

            // 2*2*2*2*2*3*3*3*3*3*3*3/2*3
            // 2*2*2*2*3*3*3*3*3*3

            // toh ab aage ans me sirf
            // 2*2*2*2*3*3*3*3*3*3
            // itna hi banane padenge for valid ans
            // yehi karre yaha

            // edge case, agar digit 0 nikal aaya toh aage precompute ka need hi nai hai, break frm here only
            if(dgt==0) break;
            remfact[i + 1] = remfact[i] / __gcd(remfact[i], dgt);
        }

        // edge case, agar num ke saare bande lene ke baad remaining me 1 bacha as factor, toh num hi return kardo, since num me already vo saare factors hai which can divide t, best ans yehi hai

        // ie is case me input itself is sufficient, toh yehi se bhejdo
        if(remfact[n]==1) return num;

        // ab num me 0's bhi ho sakte hai, toh we cant just replace 0's with 1's
        // and normal ans banao, since 0's ko 1's se switch karne par boht bda
        // number ban sakta hai way bigger than num, and possible hai ki apna
        // ans iss new num se chhota ho and original num se bada ho

        // toh uske liye, apan left se first 0 ka index nikalenge and waha se
        // ans banana start karenge

        // if num=12340345
        // toh start se ans nai banana apan ko
        // we start searching from idx 4, yaha 0 hai,
        // toh num me first 4 digits ko original se uthayenge(1234) and next 4
        // indexes wale positions ke liye ans dhundenge

        // like 0 ke jagah 1 rakhenge toh ans banega kya?,nai?
        // like 0 ke jagah 2 rakhenge toh ans banega kya?,nai?
        // ....
        // agar beech me ban gaya, then this is the best ans>=num we can get and
        // bhej denge

        // agar nai bana,
        // then jo apan ne original num se pehle 4 digits liye the(jisse ans nai
        // bana), ab 3 digits lenge, and try again like 123 is constant, and
        // aage 5 places ke liye dekho ki 5 places par apne se value rakhne se
        // ans ban raha ki nai

        // like idx 3 par 4 tha toh ans nai bana, 5 rakho(aage hi dekhenge since
        // we need >=num, toh yaha 4 se chhota toh nai rakh sakte),6 rakho....

        // yehi strategy hai apni

        // toh for that sabse pehle 0 ka posn nikal lo frm left, since whi se
        // dekhenge for ans

        int zeropos = num.find('0');
        // incase 0 nai mile toh right most idx se change karna start karenge
        int zeroidx = n - 1;
        if (zeropos != -1) {
            // we here means 0 mil gaya num me, yehi se chalu karenge
            zeroidx = zeropos;
        }

        for (int i = zeroidx; i >= 0; i--) {
            // ans me start se i digits le liye, toh kitne lene aur to get valid
            // ans ye precompute kiya tha use karlo
            ll reqd = remfact[i];

            // free slots nikalo ab, since start se i original ans se le rahe,
            // baaki slots free hai matlab, nikalo kitne hai, since in slots me
            // hisab se digits bharne hai

            int freeslot = n - i - 1;

            // ab ans me we have=> (first i digits from num)+current i digit jo
            // rakhna hai + remaining slots jo optimal way me bharna hai

            // toh current place par konse digit laga sakte uspar iterate karo,
            // if originally yaha 4 tha matlab 4 ko ans me pehle lene se kaam
            // nai chala, toh yaha ab 5,6,7,8,9 rakh kar dekho and so on, ban
            // jaaye toh yehi se bana kar bhej dena, otherwise aage badho

            for (int dgt = (num[i] - '0')+1; dgt <= 9; dgt++) {
                // ab ye number liya hai current place ke liye
                // toh remaining kitna chahiye
                // if original we needed four 5's and three 7's and current
                // digit is 5
                // toh we now need
                //  5*5*5*5*7*7*7/5
                // 5*5*5*7*7*7, itna value, from freeslots
                // ye reqd nikalne ke liye we do same thing jo precompute ke
                // time kiya

                ll furthereqd = reqd / gcd(reqd, 1LL * dgt);

                // so now we need furthereqd from freeslots, func se mang lo
                string reqdno = func(furthereqd, freeslot);

                // ab ho sakta hai ye reqd no freeslots se zyada le liye ho, in
                // which case ans nai ban sakta since we needed smallest, toh
                // freeslot ke range me hi chahiye tha

                if (reqdno.size() == freeslot) {
                    // we here means we found result jo exactly num ke size ka
                    // hai, yehi se bana kar bhej do

                    // remember ans kya tha

                    // first i digits original se liye+ current dgt + baaki free
                    // slots ke liye func se mangaya
                    return num.substr(0, i) + (char)(dgt + '0') + reqdno;
                }
            }
        }

        // we here matlab num ke size ka valid ans nai ban sakta chahe kitne bhi
        // original digits lelo

        // toh next best option is seedhe func se n+1(or more) size ka best
        // possible ans nikalva kar bhej do

        // func me pura t jitne chahiye ab, and n+1 size chahiye, bhej do
        return func(t, n + 1);
    }
};