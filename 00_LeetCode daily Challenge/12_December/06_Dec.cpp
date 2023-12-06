//1716. Calculate Money in Leetcode Bank

class Solution {
public:
    int totalMoney(int n) {
        int noWeek=n/7;//no of weeks
        int totalMoney=0;
        for(int i=0;i<noWeek;i++){
            int num=7+i;
            totalMoney+=num*(num+1)/2 - i*(i+1)/2;
        }
        
        //remaining days.
        int rem=n%7;
        int i=noWeek+1;
        while(rem--){
            totalMoney+=i;
            i++;
        }

        return totalMoney;
    }
};