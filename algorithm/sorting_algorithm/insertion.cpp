#include <iostream>
#include <vector>
using namespace std;

int main(void){
    vector <int> v = {1,4,5,6,7,8,12,13,11,10,9,9,2,3};
    int n = (int)v.size();
    for(int i = 0; i < n; ++i){
        int temp = v[i];
        for(int j = i - 1; j >= 0; --j){
            if(v[j] > temp){
                v[j + 1] = v[j];
            }
            else{
                v[j + 1] = temp;
                break;
            }
        }
        
    }
    for(int i =0 ; i < n; ++i){
        printf("%d ", v[i]);
    }
}
