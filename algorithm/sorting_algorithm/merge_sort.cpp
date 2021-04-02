#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

void merge(vector <int> &v, int start, int mid, int end){
    vector <int> v1(end - start + 1, 0);
    int que = 0;
    int que1 = start;
    int que2 = mid + 1;
    while(que1 <= mid && que2 <= end){
        if(v[que1] < v[que2]){
            v1[que] = v[que1];
            ++que1;
        }
        else{
            v1[que] = v[que2];
            ++que2;
        }
        ++que;
    }
    if(que1 <= mid){
        for(int i = que1; i <= mid; ++i){
            v1[que] = v[i];
            ++que;
        }
    }
    else{
        for(int i = que2; i <= end; ++i){
            v1[que] = v[i];
            ++que;
        }
    }
    for(int i = start; i <= end; ++i){
        v[i] = v1[i - start];
    }
}

void merge_sort(vector <int> &v, int start, int end){
    if(start < end){
        int mid = (start + end) / 2;
        merge_sort(v, start, mid);
        merge_sort(v, mid + 1, end);
        merge(v, start, mid, end);
    }
}

int main(void){
    vector <int> v = {1,4,5,6,7,8,12,13,11,10,9,9,2,3};
    int n = (int)v.size();
    
    merge_sort(v, 0, n - 1);
    for(int i =0; i < n; ++i){
        printf("%d ", v[i]);
    }
}
