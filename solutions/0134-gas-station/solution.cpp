class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalCost =0 , totalGas = 0,i;

        for(int val : gas){
            totalGas+= val;
        }

        for(int val : cost){
            totalCost += val;
        }
        
        if(totalGas < totalCost) return -1;

        // solution exits

        int start =0 , currGas =0;

        for(int i =0;i< gas.size();i++){
           currGas += gas[i] - cost[i];

           if(currGas< 0){
            start = i +1 ;
            currGas = 0;
           }
        }

        return start ;
    }
};
