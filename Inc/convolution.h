#ifndef CONVOLUTION_H
#define CONVOLUTION_H

#include "main.h"

#define KERNEL_SIZE 3
#define IMAGE_SIZE 120 

void initiate_matrix(uint8_t image_mat[IMAGE_SIZE][IMAGE_SIZE]);
void print_matrix(uint8_t image_mat[IMAGE_SIZE][IMAGE_SIZE], int rows, int cols);

void Sobel_operator_ver(uint8_t output_mat[IMAGE_SIZE][IMAGE_SIZE], uint8_t input_mat[IMAGE_SIZE][IMAGE_SIZE],int rows, int cols);
void Sobel_operator_hor(uint8_t output_mat[IMAGE_SIZE][IMAGE_SIZE], uint8_t input_mat[IMAGE_SIZE][IMAGE_SIZE],int rows, int cols);

#endif
