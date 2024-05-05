vector<int> getLIS(vector<int> v){
    //run in O(nlogn)
    vector<int> lis;
    for(auto i : v){
        if(lis.empty() || lis.back() < i)
            lis.push_back(i);
        else
            *lower_bound(lis.begin(), lis.end(), i) = i;
    }
    return lis;
}