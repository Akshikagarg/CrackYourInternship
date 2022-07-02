#define ll long long int
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<ll> curr(amount+1,0),prev(amount+1,0);

        for(ll i=0;i<=amount;i++)
        {
            prev[i]=INT_MAX;
        }
        for(ll i=1;i<=n;i++)
        {
            prev[0]=0;
            for(ll j=1;j<=amount;j++)
            {
                ll ans=INT_MAX;
                if(coins[i-1]<=j)
                {
                    ans=min(ans,1+curr[j-coins[i-1]]);
                }
                ans=min(ans,prev[j]);
                curr[j]=ans;
            }
            prev=curr;
        }
        return (int)prev[amount]==INT_MAX?-1:prev[amount];
    }
};
