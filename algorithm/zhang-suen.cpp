#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector <vector <int> > mat(1000, vector <int> (1000));
vector <vector <int> > root(1000, vector <int> (1000));
int row = 450;
int col = 800;

namespace thinning{
    bool find_pixel_delete(string dir, vector <vector <int> > &pic, vector <vector <int> > &root){
        int row = (int)pic.size();
        int col = (int)pic[0].size();
        int neighbor_pixel[9];
        int connectivity;
        bool need_more_delete_pixel = 0;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                int count = 0;
                if(pic[i][j] == 255){
                    for(int k = -1; k <= 1; ++k){
                        for(int z = -1; z <= 1; ++z){
                            if(pic[i + k][j + z] == 255)++count;
                        }
                    }
                }
                if(count > 2 && count < 8){
                    neighbor_pixel[0] = pic[i - 1][j - 1];
                    neighbor_pixel[1] = pic[i][j - 1];
                    neighbor_pixel[2] = pic[i + 1][j - 1];
                    neighbor_pixel[3] = pic[i + 1][j];
                    neighbor_pixel[4] = pic[i + 1][j + 1];
                    neighbor_pixel[5] = pic[i][j + 1];
                    neighbor_pixel[6] = pic[i - 1][j + 1];
                    neighbor_pixel[7] = pic[i - 1][j];
                    neighbor_pixel[8] = pic[i - 1][j - 1];
                }
                //주변 3*3 반경 픽셀에서 캐릭터 픽셀과 배경 픽셀 변환 지점 갯수 확인(connectivity)
                connectivity = 0;
                
                for(int l = 0; l < 8; ++l){
                    if(neighbor_pixel[l] == 255 && neighbor_pixel[l + 1] == 0) ++connectivity;
                }

                if(connectivity == 1){
                    if(dir == "left_down"){
                        if(neighbor_pixel[1] == 0 || neighbor_pixel[3] == 0 || neighbor_pixel[7] == 0){
                            if(neighbor_pixel[1] == 0|| neighbor_pixel[3] == 0 || neighbor_pixel[5] == 0){
                                root[i][j] = 1;
                                need_more_delete_pixel = 1;
                                
                            }
                        }
                    }
                    else if(dir == "right_top"){
                        if(neighbor_pixel[3] == 0 || neighbor_pixel[5] == 0|| neighbor_pixel[7] == 0){
                            if(neighbor_pixel[1] == 0|| neighbor_pixel[5] == 0|| neighbor_pixel[7] == 0){
                                root[i][j] = 1;
                                need_more_delete_pixel = 1;
                                
                            }
                        }
                    }
                }
            }
        }
        
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(root[i][j] == 1){
                    pic[i][j] = 0;
                }
            }
        }
        
        return need_more_delete_pixel;
    }
    
    void zhang_suen(vector <vector <int> > &pic, vector <vector <int> > &root){
        bool need_thinning = true;
        
        while(need_thinning){
            need_thinning = find_pixel_delete("left_down", pic, root);
            if(need_thinning) break;
            need_thinning = find_pixel_delete("right_top", pic, root);
        }
        
    }
    
};

int main(void){
    int color;
    FILE *fp;
    
    if((fp = fopen("address", "r")) == NULL){
        printf("sorry");
    }
    
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            fscanf(fp, "%d", &color);
            mat[i][j] = color;
        }
    }
    fclose(fp);
    
    thinning::zhang_suen(mat, root);
    
    if((fp = fopen("address", "w")) == NULL){
        printf("sorry");
    }
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            fprintf(fp, "%d\n", mat[i][j]);
        }
    }
    fclose(fp);
    
}

