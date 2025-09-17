class FoodRatings {
public:
    struct Comp {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if (a.first != b.first) return a.first > b.first; 
            return a.second < b.second;
        }
    };

    unordered_map<string,set<pair<int,string>,Comp>>cuisineToSet;
    unordered_map<string,string>foodToCuisine;
    unordered_map<string,int>foodToRating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n= foods.size();
        for(int i= 0;  i< n; i++) {
            string fd = foods[i];
            string cui = cuisines[i];
            int rate  = ratings[i];
            cuisineToSet[cui].insert({rate,fd});
            foodToCuisine[fd] = cui;
            foodToRating[fd] = rate;
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisineOfFood = foodToCuisine[food];
        int oldRating = foodToRating[food];
        cuisineToSet[cuisineOfFood].erase({oldRating, food});
        cuisineToSet[cuisineOfFood].insert({newRating, food});
        foodToRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisineToSet[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
