class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();

        // vector lelo usme finish time store karo ki current potion ka
        // finishing time kya kya hai according to differnet wizards
        vector<long long> finishtime(n, 0);

        // iterate over each potion
        for (int j = 0; j < m; j++) {
            // firstly time update karo in accordance to previous potion,
            // basically jaha previous potion end hota hai wahi se current
            // potion ka start kardo

            // first value update kardo
            finishtime[0] += mana[j] * skill[0];
            // skills[0] since sabse pehle toh wizard 0 kaam karega na

            // ab bhar do baaki values ko

            // basically i th wale wizard ke liye finishtime= max(finishtime of
            // i-1 wala wizard,finishtime of i th wizard from previous potion),
            // basically the first value is ki current wizard ko pichle wale
            // wizard se kab mila potion free, second value is current wizard
            // pichle wale potion se free kab hua

            // dono ka max lenge since agar potion free hua lekin wizrd is
            // occupied, nothing happens, similarly when current wizard free
            // lekin abhi pichle wale wizard ka kaam nai finish hua hai toh idle
            // baithega, tabhi max lere so that exact time par chalu kare
            for (int i = 1; i < n; i++) {
                // finishtime[i]-> i th wizard ne previous potion ko kab finish
                // kiya finishtime[i-1]-> i-1 th wizard ne current potion ko kab
                // finish kiya
                finishtime[i] = max(finishtime[i], finishtime[i - 1]) +
                                (1LL * mana[j] * skill[i]);

                // ab konse time se start hoga count kar liye, ab count karenge
                // ki current potion ke liye kitna time lagega which is
                // mana[j]*skills[i], add kardo
            }

            // ab pichle potion ke hisab se time nikal liya, ab synchronize karo
            // time ko so that do wizards potion same time par potion exchange
            // kare, like jab wiz3 finish kare tabhi wiz4 utha le potion ko

            // for this apan peeche se chalenge last wale wizard se chalu karke
            // synchrnize karenge
            for (int i = n - 1; i > 0; i--) {
                // for {i-1} th banda, we need ki i th banda kab free hua, so
                // that i th bande ke free hone ke time se nikal paaye ki i-1 th
                // banda kab free hoga

                // since time taken to brew=skill[i]*mana[j], itna time i th
                // bande ke time se nikalenge toh pata chalega ki i-1 th wale
                // bande ko kab free hona chahiye
                finishtime[i - 1] = finishtime[i] - (1LL * mana[j] * skill[i]);
            }

            // ab current potion ke liye times have been successfully
            // synchronized , agle potion par badho
        }

        // we here means saare potions ke hisab se time has been optimized, toh
        // ab total time to finish all potions is when last wizard finish last
        // potion, and finishtime currently stores ki last wale potion ka brew
        // time kitna tha har wizard ka

        // toh final wizard finished with last potion by finishtime[n-1] time, yehi bhej do
        return finishtime[n-1];
    }
};