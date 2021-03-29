#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int mat[1000][1000];
int root[1000][1000];
int row = 450;
int col = 800;
int main(void){
    int que = 1;
    int color;
    int count;
    int neighbor[9];
    int connectivity;
    FILE *fp;
    
    if((fp = fopen("/Users/kimjunseok/PycharmProjects/pythonProject/character.txt", "r")) == NULL){
        printf("sorry");
    }
    
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            fscanf(fp, "%d", &color);
            mat[i][j] = color;
        }
    }
    fclose(fp);
    printf("d");
    while(que){
        que = 0;
        for(int i = 1; i < row - 1; ++i){
            for(int j = 1; j < col - 1; ++j){
                count = 0;
                if(mat[i][j] == 255){
                    for(int k = -1; k <= 1; ++k){
                        for(int z = -1; z <= 1; ++z){
                            if(mat[i + k][j + z] == 255)++count;
                        }
                    }
                    if(count > 2 && count < 8){
                        neighbor[0]= mat[i - 1][j - 1];
                        neighbor[1] = mat[i][j - 1];
                        neighbor[2] = mat[i + 1][j - 1];
                        neighbor[3]= mat[i + 1][j];
                        neighbor[4] = mat[i + 1][j + 1];
                        neighbor[5] = mat[i][j + 1];
                        neighbor[6]= mat[i - 1][j + 1];
                        neighbor[7] = mat[i - 1][j];
                        neighbor[8] = mat[i - 1][j - 1];
                        
                        connectivity = 0;
                        for(int l = 0; l < 8; ++l){
                            if(neighbor[l] == 255 && neighbor[l + 1] == 0) ++connectivity;
                        }
                        if(connectivity == 1){
                            if(neighbor[1] == 0 || neighbor[3] == 0 || neighbor[7] == 0){
                                if(neighbor[1] == 0|| neighbor[3] == 0 || neighbor[5] == 0){
                                    root[i][j] = 1;
                                    que = 1;
                                    
                                }
                            }
                        }
                        
                    }
                }
            }
        }
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(root[i][j] == 1){
                    mat[i][j] = 0;
                }
            }
        }
        
        if(que == 0) break;
        que = 0;
        
        for(int i = 1; i < row - 1; ++i){
            for(int j = 1; j < col - 1; ++j){
                
                count = 0;
                if(mat[i][j] == 255){
                    for(int k = -1; k <= 1; ++k){
                        for(int z = -1; z <= 1; ++z){
                            if(mat[i + k][j + z] == 255)++count;
                        }
                    }
                    if(count > 2 && count < 8){
                        neighbor[0]= mat[i - 1][j - 1];
                        neighbor[1] = mat[i][j - 1];
                        neighbor[2] = mat[i + 1][j - 1];
                        neighbor[3]= mat[i + 1][j];
                        neighbor[4] = mat[i + 1][j + 1];
                        neighbor[5] = mat[i][j + 1];
                        neighbor[6]= mat[i - 1][j + 1];
                        neighbor[7] = mat[i - 1][j];
                        neighbor[8] = mat[i - 1][j - 1];
                        
                        connectivity = 0;
                        for(int l = 0; l < 8; ++l){
                            if(neighbor[l] == 255 && neighbor[l + 1] == 0) ++connectivity;
                        }
                        if(connectivity == 1){
                            if(neighbor[3] == 0 || neighbor[5] == 0|| neighbor[7] == 0){
                                if(neighbor[1] == 0|| neighbor[5] == 0|| neighbor[7] == 0){
                                    root[i][j] = 1;
                                    que = 1;
                                    
                                }
                            }
                        }
                        
                    }
                }
                
            }
        }
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(root[i][j] == 1){
                    mat[i][j] = 0;
                }
            }
        }
    }
    
    
    
    if((fp = fopen("/Users/kimjunseok/PycharmProjects/pythonProject/thinning.txt", "w")) == NULL){
        printf("sorry");
    }
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            fprintf(fp, "%d\n", mat[i][j]);
        }
    }
    fclose(fp);
    
}

