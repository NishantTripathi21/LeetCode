class Solution {
    class Car{
        public:
        int pos;
        int speed;
        Car(int po,int sp):pos(po),speed(sp){};
    };
    static bool myComp(Car&a,Car&b){
        return a.pos<b.pos;
    }
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car>cars;
        for(int i=0;i<position.size();i++){
            Car car(position[i],speed[i]);
            cars.push_back(car);
        }
        sort(cars.begin(),cars.end(),myComp);
        stack<float>st;
        for(auto car:cars){
            float time=(target-car.pos)/(float)car.speed;
            while(!st.empty() && st.top()<=time){
                st.pop();
            }
            st.push(time);
        }
        return st.size();
    }
};
