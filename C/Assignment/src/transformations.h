// Functions for transforming images
// Created By : Alexander Whitfield 
// ID : 32541767


// 
/**
 * rotate_90_clockwise function is used to rotate an image 90 degrees clockwise
 *
 * @param Image *image
 *  *image = pointer to the Image struct, it is used to get information about the image like width & height
 * 
 * @return - None (thie image will just have been rotated)
 */
void rotate_90_clockwise(Image *image){
    // Get info about the image from the Image struct
    int width = image->width;
    int height = image->height;
    int *data = image->data;

    // Loop through a quarter of the image as each iteration will
    //rotate 4 pixels (one from each quadrant)
    for (int i = 0; i < height / 2; i++){
        for (int j = 0; j < width / 2; j++){
            // Create a temp to hold pixel value for top left quardant
            int temp = data[(i * width) + j];

            // Perform a clockwise rotation of the 4 corresponding pixels in each quadrant
            data[(i * width) + j] = data[((height - 1 - j) * width) + i];
            data[((height - 1 - j) * width) + i] = data[((height - 1 - i) * width) + (width - 1 - j)];
            data[((height - 1 - i) * width) + (width - 1 - j)] = data[(j * width) + (width - 1 - i)];
            data[(j * width) + (width - 1 - i)] = temp;
        }
    }
}


// 
/**
 * rotate_90_anticlockwise function is used to rotate an image 90 degrees anticlockwise
 *
 * @param Image *image
 *  *image = pointer to the Image struct, it is used to get information about the image like width & height
 * 
 * @return - None (thie image will just have been rotated)
 */
void rotate_90_anticlockwise(Image *image){
    // For this function I've just called my 90 degrees 
    //clockwise function 3 times as it is the same and roating it anticlockwise once
    rotate_90_clockwise(image);
    rotate_90_clockwise(image);
    rotate_90_clockwise(image);
}


// 
/**
 * rotate_180 function is used to rotate an image 180 degrees
 *
 * @param Image *image
 *  *image = pointer to the Image struct, it is used to get information about the image like width & height
 * 
 * @return - None (thie image will just have been rotated)
 */
void rotate_180(Image *image){
    // For this function I've just called my 90 degrees 
    //clockwise function twice as it will rotate the image 180 degress
    rotate_90_clockwise(image);
    rotate_90_clockwise(image);
}


// 
/**
 * flip function is used to flip an image upside down (vertically) 
 *
 * @param Image *image
 *  *image = pointer to the Image struct, it is used to get information about the image like width & height
 * 
 * @return - None (thie image will just have been flipped)
 */
void flip(Image *image){
    // Get info about the image from the Image struct
    int width = image->width;
    int height = image->height;
    int *data = image->data;

    // Loop through only half the height since we are swapping the pixel values
    //between the top and bottom halves of the image
    for (int i = 0; i < height/2; i++){
        // k is the index for the opposite pixel that we are swapping
        int k = width * (height - i - 1); 

        // Loop through each pixel in row
        for (int j = 0; j < width; j++){
            // Create a temp to hold pixel value
            int temp = data[k+j];
            // Swap the pixel values
            data[k+j] = data[j + (width * i)];
            data[j + (width * i)] = temp;
        }
    }
}


// 
/**
 * mirror function is used to reverse the image left to right (horizontally). 
 *
 * @param Image *image
 *  *image = pointer to the Image struct, it is used to get information about the image like width & height
 * 
 * @return - None (thie image will just have been mirrored)
 */
void mirror(Image *image){
    // Get info about the image from the Image struct
    int width = image->width;
    int height = image->height;
    int *data = image->data;

    // Loop through each row of the image
    for (int i = 0; i < height; i++){
        // k is the index for the opposite pixel that we are swapping
        int k = width * i; 

        // Loop through only half the width since we are swapping the pixel values
        //between the left side and the right side of the image
        for (int j = 0; j < width/2; j++){
            // Create a temp to hold pixel value
            int temp = data[k+j];
            // Swap the pixel values
            data[k+j] = data[k+width-1-j];
            data[k+width-1-j] = temp;
        }
    }
}
