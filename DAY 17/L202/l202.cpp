class Solution {
private:
    int getnext(int n)
    {
        int totalSum = 0;
        while (n > 0) {
            int d = n % 10;
            n = n / 10;
            totalSum += d * d;
        }
        return totalSum;
    }
public:
    bool isHappy(int n) {
        set<int> has;
        while(n!=1 && has.find(n)==has.end())
        {
            has.insert(n);
            n=getnext(n);
        }
        
        return (n == 1);
    }
};
