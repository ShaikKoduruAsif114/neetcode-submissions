class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>>cars;
        int n = speed.size();
        for(int i =0;i<n;i++){
            cars.push_back({position[i],(double)(target - position[i])/speed[i]});
        }
        sort(cars.rbegin(),cars.rend());
        stack<double>st;
        for(auto car:cars){
            if(st.empty() || st.top()<car.second){
                st.push(car.second);
            }
        }
        return st.size();
    }
};
