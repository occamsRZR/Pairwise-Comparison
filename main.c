#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>      
#include "pairwise.h"





/*

    our main needs to take in the options
        -number of sequences
        -file name
        
*/
main(int argc, char *argv[])                                                                                                                                                                                                                                                     {
    /* 
    
        first we need to get the first variable, 
        our number of sequences and convert it 
        to an int.
    
    */
    string num_str = *(argv + 1);
    int num_seq = atoi(num_str);
    int num_comparisons = num_pairwise_comp(num_seq);
    
    /*
    
        We then need to find out the string to 
        the file we will be working with.
    
    */
    string file_name = *(argv + 2);
    // Normally, I would use string *all_seqs but it keeps giving me 
    // the following warning:
    // `warning: passing argument 3 of 'read_alignment' from incompatible pointer type`
    char *all_seqs[num_seq];
    int aln_length = read_alignment(file_name, num_seq, all_seqs);
    // Normally, I would define how many comparisons we will do
    float pairwise_comparisons[num_comparisons];
    calculate_hamming_dists(&pairwise_comparisons, num_comparisons, all_seqs, aln_length, num_seq);
    int i;
    // for each of the comparisons, print out the float
    for(i = 0; i < num_comparisons; i++){
        printf("Comp: %i Result: %f\n", i+1, pairwise_comparisons[i]);
    }
     
    return 0;
}






