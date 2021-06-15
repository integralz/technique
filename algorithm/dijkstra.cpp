
vector <int> dy(vector <vector <pair <int, int> > > &v, int st, int n){
    vector <int> ans(n, 987654321);
    ans[st] = 0;
    priority_queue <pair <int, int> > pq;
    pq.push({st, 0});

    while(!pq.empty()){
        int a = pq.top().first;
        int dist = -1*pq.top().second;
        pq.pop();
        if(ans[a] < dist) continue;
        for(int i =0; i < v[a].size(); ++i){
            if(ans[v[a][i].first] > dist + v[a][i].second){
                ans[v[a][i].first] = dist + v[a][i].second;
                pq.push({v[a][i].first, -1 * ans[v[a][i].first]});
            }
        }
    }

    return ans;
}
