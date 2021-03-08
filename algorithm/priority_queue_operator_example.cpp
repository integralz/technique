
struct gg{
bool operator()(pair <int, int> a, pair <int, int> b){
    if(a.second - a.first == b.second - b.first){
        return a.first > b.first;
    }
    else if(a.second - a.first < b.second - b.first){
        return true;
    }
    else{
        return false;
    }
}
};
priority_queue <pair <int, int>, vector <pair <int, int> >, gg> que;
  


