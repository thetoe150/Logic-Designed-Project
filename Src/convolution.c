#include "convolution.h"

static int8_t ker_mat_ver[KERNEL_SIZE][KERNEL_SIZE] =
{
    {1, 0, -1},
    {2, 0, -2},
    {1, 0, -1}
};

static int8_t ker_mat_hor[KERNEL_SIZE][KERNEL_SIZE] =
{
    {1, 2, 1},
    {0, 0, 0},
    {-1, -2, -1}
};

void initiate_matrix(uint8_t image_mat[IMAGE_SIZE][IMAGE_SIZE]){
    for(int i = 0; i < IMAGE_SIZE; i++){
        for(int j = 0; j < IMAGE_SIZE; j++){
            image_mat[i][j] = (i +j) % 250;
        }
    }
}

void print_matrix(uint8_t image_mat[IMAGE_SIZE][IMAGE_SIZE], int rows, int cols){
    for(unsigned int image_i = 0; image_i< rows; image_i++){
        for(unsigned int image_j = 0; image_j < cols; image_j++){
            printf("%d, ",image_mat[image_i][image_j]);
        }
        printf("\n");
    }
}

void Sobel_operator_ver(uint8_t output_mat[IMAGE_SIZE][IMAGE_SIZE], uint8_t input_mat[IMAGE_SIZE][IMAGE_SIZE],int rows, int cols){
    const int dx = KERNEL_SIZE/2;
    const int dy = KERNEL_SIZE/2;
    for(unsigned int image_i = 0; image_i< rows; image_i++){ 
        for(unsigned int image_j = 0; image_j < cols; image_j++){
            int accum = 0;
            for(unsigned int ker_i = 0; ker_i < KERNEL_SIZE; ker_i++){ 
                for(unsigned int ker_j = 0; ker_j < KERNEL_SIZE; ker_j++){
                    int x = image_i - dx + ker_i;
                    int y = image_j - dy + ker_j;
                    if(x >= 0 && x < rows && y >= 0 && y < cols)
                        accum += ker_mat_ver[ker_i][ker_j] * input_mat[x][y];             
                }
            }
            if(accum < 0)
                accum = 0;
            if(accum > 253)
                accum = 253;
            output_mat[image_i][image_j] = accum;
        }
    }
}

void Sobel_operator_hor(uint8_t output_mat[IMAGE_SIZE][IMAGE_SIZE], uint8_t input_mat[IMAGE_SIZE][IMAGE_SIZE],int rows, int cols){
    const int dx = KERNEL_SIZE/2;
    const int dy = KERNEL_SIZE/2;
    for(unsigned int image_i = 0; image_i< rows; image_i++){ 
        for(unsigned int image_j = 0; image_j < cols; image_j++){
            int accum = 0;
            for(unsigned int ker_i = 0; ker_i < KERNEL_SIZE; ker_i++){ 
                for(unsigned int ker_j = 0; ker_j < KERNEL_SIZE; ker_j++){
                    int x = image_i - dx + ker_i;
                    int y = image_j - dy + ker_j;
                    if(x >= 0 && x < rows && y >= 0 && y < cols)
                        accum += ker_mat_hor[ker_i][ker_j] * input_mat[x][y];             
                }
            }
            if(accum < 0)
                accum = 0;
            if(accum > 253)
                accum = 253;
            output_mat[image_i][image_j] = accum;
        }
    }
}