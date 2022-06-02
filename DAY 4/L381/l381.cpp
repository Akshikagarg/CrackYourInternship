class RandomizedCollection {
public:
        vector<int>v;
int n=0;
map<int,set<int>>mp; 
    RandomizedCollection() {
 
    }
    
    bool insert(int val) {
        bool x=false;
    if(mp.find(val)==mp.end()){
        x=true;
    }
    v.push_back(val);
    mp[val].insert(n);
    n++;
    return x;
    }
    
    bool remove(int val) {
        if(mp.find(val)== mp.end()){
        return false;
    }
    auto it = mp[val].begin();
    int idx = *it;
    mp[val].erase(idx);
    if(mp[val].size()==0){
        mp.erase(val);
    }
      if(idx==(n-1))
    {
        v.pop_back();
        n--;
    }
     else{   
    int temp = v[n-1];
    mp[temp].erase(n-1);
    mp[temp].insert(idx);
    v[idx]=temp;
    v.pop_back();
    n--;
     }
    return true;
    
        
    }
    
    int getRandom() {
          int idx=0;
    if(n>0){
        idx = rand()%n;
    }
    return v[idx];
    }
};
