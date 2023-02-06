/*Copyright 2022 Lili Wang*/
#include <hw3/inc/find_sum.h>
#include <iostream>
#include <cstddef> 
using std::cout;
const size_t** FindSum(const int** matrix,
                       const size_t* matrix_size,
                       int search_sum,
                       size_t* sums_found){
    const size_t kMatrix_size_rows_idx = 0;  // row index in matrix_size
    const size_t kIndices_size = 4;  // size of indices array
    *sums_found = 0; // init sums found to 0
    const size_t row = matrix_size[kMatrix_size_rows_idx]; // row number of tested matrix
    const size_t col = matrix_size[kMatrix_size_cols_idx]; // col number of tested matrix
  // create Matrix

    // define memory
    // start assuming no more than 2 summations
    // build structre to hold all found summations
  size_t** ret = new size_t*[row*col*4]; // create new array with results
   for (size_t i = 0; i < row*col*4; i++) {
    ret[i] = new size_t[kIndices_size];
   }
  
  // row summation
  int curr_sum;
  int counter = 0 ; 
  for(size_t i = 0; i < row; i++)
  {
 
    // Pick a starting point
    for (size_t j = 0; j < col; j++) {
          curr_sum = 0 ;
    
        // try all subarrays starting with 'i'
        for (size_t k = j ; k < col; k++) {
             curr_sum = curr_sum + matrix[i][k];
             
            if (curr_sum == search_sum) {
            
              size_t increase[] = {i, j, i, k};
             
              // put data one by one into the arr
                while(counter < kIndices_size)
                {
                 
                ret[*sums_found][counter] = increase[counter];
                counter++;
                }
                *sums_found = *sums_found + 1 ;
               counter=0;           
            }  
        }        
    }
}  

  for(size_t i = 0; i < col; i++)
  {
    
    for (size_t j = 0; j < row; j++) 
    {
          curr_sum = matrix[j][i] ;
        
        // try all subarrays starting with 'i
        for (size_t k = j+1 ; k < row; k++) 
        {
          curr_sum = curr_sum + matrix[k][i];

            if (curr_sum == search_sum) 
            {
              size_t increase[] = {j,i,k,i};
                while(counter < kIndices_size)
                {
                ret[*sums_found][counter] = increase[counter];
                counter++;}
                *sums_found = *sums_found + 1 ;
               counter=0;          
            }  
        }        
    }
}
  
// asc dialogal

 for(size_t i = 0; i < row; i++)
  {
    // Pick a starting point
    for (size_t j = 0; j < col; j++)
     {
          curr_sum = matrix[i][j] ;   
        // try all subarrays starting with 'i'
        for (size_t k = 1 ; k < row; k++)
         {
            if (i-k<row && i-k >=0 && j+k < col)
            {          
              curr_sum = curr_sum + matrix[i-k][j+k];
            
            if (curr_sum == search_sum) {
              size_t increase[] = {i,j,i-k,j+k};
                while(counter < kIndices_size){
                ret[*sums_found][counter] = increase[counter];
                counter++;}
                *sums_found = *sums_found + 1 ;
                counter=0;                      
            } 
            } 
        }  
    }
}
    // dsc 
    for(size_t i = 0 ; i < col; i++)
      {

    for (size_t j = 0 ; j < row; j++)
     {
          curr_sum = matrix[j][i] ; 
     
        for (size_t k = 1 ; k < col; k++)
         {
            if( i+k < col && i+k >= 0 && j+k < row)
            {    
            curr_sum = curr_sum + matrix[j+k][i+k];      
           
            if (curr_sum == search_sum) 
            {
              size_t increase[] = {j,i,j+k,i+k};
                while(counter < kIndices_size)
                {
                ret[*sums_found][counter] = increase[counter];
                counter++; 
            }
                *sums_found = *sums_found + 1 ;
                counter=0;             
            } 
            } 
        }  
    }
}

 if (*sums_found != 0)
    return const_cast<const size_t**>(ret); 
    
return nullptr;

}


