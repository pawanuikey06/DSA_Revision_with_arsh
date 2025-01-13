class Solution {
public:
     int mod=1e5;
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        if(mass<asteroids[0]) return false;
        long long masss=mass;
        for(int i=0;i<asteroids.size();i++){
            if(masss>=asteroids[i]){
                masss+=asteroids[i];
                ;
            }
            if(masss<asteroids[i] ) return false;
        }
        return true;

    }
};
