#include <iostream>
#include <vector>
using namespace std;

int main(void){
    vector <int> v = {1,4,5,6,7,8,12,13,11,10,9,9,2,3};
    int n = (int)v.size();
    for(int i =0; i < n; ++i){
        int a = v[i];
        int que = i;
        for(int j = i + 1; j < n; ++j){
            if(a > v[j]){
                a = v[j];
                que = j;
            }
        }
        v[que] = v[i];
        v[i] = a;
    }
    for(int i =0 ; i < n; ++i){
        printf("%d ", v[i]);
    }
}
