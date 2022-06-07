class Solution {
public: 
     
 unsigned long int binomialCoeff(unsigned int n, unsigned int k)
{
   unsigned long int res = 1;

    if (k > n - k)
        k = n - k;
 
    // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
 
    return res;
}
 
    int numTrees( int n) {
    unsigned long int c = binomialCoeff(2*n, n);
    return c/(n+1);
        
    }
};
