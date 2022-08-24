class Solution {
public:
    
    int getSum(vector<int> a){
        int sum = 0;
        for(auto item:a){
            sum += item;
        }
        return sum;
    }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(getSum(gas)<getSum(cost)){
            return -1;
        }
        int position = 0;
        int total_gas = 0;
        for(int i=0;i<gas.size();i++){
            total_gas += gas[i] - cost[i];
            if(total_gas<0){
                total_gas = 0;
                position = i+1;
            }
        }
        
        return position;
    }
};
