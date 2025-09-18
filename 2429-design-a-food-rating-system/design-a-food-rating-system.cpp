class FoodRatings {
public:
    unordered_map<string,string>map;
    unordered_map<string,set<pair<int,string>>>cuisine_ratings_food;
    unordered_map<string,int>food_rating;
    FoodRatings(vector<string>& food, vector<string>& cuisine, vector<int>& ratings) {
        int n=food.size();
        for(int i=0;i<n;i++){
            map[food[i]]=cuisine[i];
            cuisine_ratings_food[cuisine[i]].insert({-ratings[i],food[i]});

            food_rating[food[i]]=ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        int oldrating=food_rating[food];

        string cuisine=map[food];

        food_rating[food]=newRating;

        cuisine_ratings_food[cuisine].erase({-oldrating,food});
        cuisine_ratings_food[cuisine].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        return begin(cuisine_ratings_food[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */