
//tree, mat, node, l, r
int min_seg(vector <int> &a, vector <int> &b, int node, int l, int r){
    if(l == r) return a[node] = b[l];
    int mid = (l + r) / 2;
    return a[node] = min(min_seg(a, b, 2*node, l, mid), min_seg(a, b, 2*node + 1, mid + 1, r));
}
//tree, start, end, node, findl, findr
int find_min_seg(vector <int> &v, int start, int end, int node, int l, int r){
    if(end < l || r < start){
        return 1987654321;
    }
    else if(l <= start && end <= r){
        return v[node];
    }
    int mid = (start + end) / 2;
    return min(find_min_seg(v, start, mid, 2*node, l, r), find_min_seg(v, mid + 1, end, 2*node + 1, l, r));
}

