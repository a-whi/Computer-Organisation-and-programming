// Functions for computing statistics on arrays of data
// Created By : Alexander Whitfield 
// ID : 32541767

// 
/**
 * compute_mean function is used to compute the mean
 *
 * @param int *data, int data_length
 *  *data = pointer to an array with (height * width) elements
 *  data_length = the length of the data being given
 * @return - mu (the mean value)
 */
float compute_mean(int *data, int data_length){

    //Initalise a variable to hold the combine total of all values in the array
    float sum = 0;  // Set to 0 so it is reset everytime the function is called

    for (int i = 0; i < data_length; i++){
        sum += data[i];
    }

    float mu = sum / data_length;
    return mu;
};


// 
/**
 * compute_variance function is used to compute the variance
 *
 * @param int *data, int data_length
 *  *data = pointer to an array with (height * width) elements
 *  data_length = the length of the data being given
 * @return - variance
 */
float compute_variance(int *data, int data_length){
    
    // Call the mean function to find the mean
    float mu = compute_mean(data, data_length);

    // A sum of all values squared
    float sumSquareDiffs = 0; // (xi,xj - mu)^2

    for (int i =0; i < data_length; i++){
        float diff = data[i] - mu; //This is calculating (xi,xj - mu)
        sumSquareDiffs += diff * diff; // This is squaring the result and holding the combine total of all values in the array
    }

    float variance = sumSquareDiffs / data_length;
    return variance;
};