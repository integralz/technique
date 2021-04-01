#include <iostream>
#include <vector>
using namespace std;

int main(void){
    vector <int> v = {1,4,5,6,7,8,12,13,11,10,9,9,2,3};
    int n = (int)v.size();
    for(int i =0; i < n - 1; ++i){
        for(int j =0; j < n - 1 - i; ++j){
            if(v[j] > v[j + 1]){
                int a = v[j];
                v[j] = v[j + 1];
                v[j + 1] = a;
            }
        }
    }
    for(int i =0 ; i < n; ++i){
        printf("%d ", v[i]);
    }
}
