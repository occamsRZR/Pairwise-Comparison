/*
    This file implements the pairwise compairsons functions.
    The header file has the prototypes.

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>    
#include "pairwise.h"

/*

    num_pairwise_comp:
    
        This method will take the number of sequences and
        find out how many comparisons we will be making.
        This is the formula:
            n(n-1)/2
    
*/
int num_pairwise_comp(int num_seq)
{
    int num_comparisons = num_seq*(num_seq - 1)/2;
    return num_comparisons;
}


/*

    get_align_size:
        This method takes in the file name of the alignment.
        It then runs through the first sequence and counts 
        how large it is.
    
*/
int get_align_size(char *file_name)
{
    FILE *fp;
    fp = fopen(file_name , "r");
    if(fp == NULL){
        printf("Unable to open the input file.\n");
        exit(-1);
    }

    // Our buffer and our alignment_length
    char buffer[1000];
    int aln_len = 0;
    // We'll start at -1 so we get to 0 during the first seq header
    int i = -1;
    // Assume that the first sequence is the same as the last sequence.
    while( (fgets(buffer, 1000, fp) != NULL) && (i < 1)){
        if(strchr(buffer, '>')){
            i++;
        }
        else{
            int str_len = strlen(buffer) - 1;
            aln_len += str_len;
        }
    }
    fclose(fp);
    return aln_len;
}


/*
    
    read_alignment:
        Here we're going to read our file in.
        We then will need to return all the sequences
        as an array of strings.    

*/
int read_alignment(string file_name, int num_seq, string *all_seqs)
{
    
    // First, we need to find the alignment size
    int aln_len = get_align_size(file_name);
    
    FILE *fp;
    fp = fopen(file_name , "r");
    if(fp == NULL){
        printf("Unable to open the input file.\n");
        exit(-1);
    }
    else{
        printf("Opened the alignment: %s!\n", file_name);
    }
    printf("The length of the alignment: %i\n", aln_len);
    char temp_seq[aln_len];
    char buffer[1000];
    
    // We'll start at -1 so we get to 0 during the first seq header
    int i = -1;
    while( fgets(buffer, 1000, fp) != NULL){
        // This will have to be after the first sequence
        if (strchr(buffer, '>') && i > -1){
            all_seqs[i] = malloc(strlen(temp_seq) + 1);
            strcpy(all_seqs[i], temp_seq);
            temp_seq[0] = '\0';
            i++;
        }
        // This will be the first sequence
        else if(strchr(buffer, '>')){
            temp_seq[0] = '\0';
            i++;
        }
        else{
            int str_len = strlen(buffer);
            buffer[str_len-1] = '\0';
            //temp_seq = &buffer[0];
            strcat(temp_seq, buffer);        
        }

        
    }
    all_seqs[i] = malloc(strlen(temp_seq) + 1);
    strcpy(all_seqs[i], temp_seq);
    fclose(fp);
    return aln_len;
}


/*
    
    calculate_hamming_dists:
      this method allows you to calculate the hamming distance using
      inputs:
        comparisons
	num_comparisons
	all_seqs
	aln_len
	num_seqs
        

*/
void calculate_hamming_dists(float *pairwise_comparisons, int num_comparisons, string *all_seqs, int aln_len, int num_seqs)
{
    int i, j, k, offset;
    int num_comp_temp = 0;
    
    // Our i variable is going to track the first sequence number
    for(i = 0; i < num_seqs; i++){
        offset = 1;
        // Our j variable is going to track the second sequence number
        for(j = i + 1; (j < num_seqs) && (i != (num_seqs - 1)); j++){
            num_comp_temp++;
            float matches = 0.00;
            float total = 0.00;
            // Our k variable is going to track the position in the alignment
            for(k = 0; k < aln_len; k++){

                char position1, position2;
                position1 = all_seqs[i][k];
                position2 = all_seqs[j][k];
              
                /*
                
                    There will be three different cases we will be looking for:
                    
                        1:  Either position has an indel "-"
                                - do nothing
                        2:  The two positions are the same (a match)
                                - increment the matches
                                - increment the total
                        3:  The two positions are different (a mismatch)
                                - increment the total
                                
                */
                    // 1: Either position has an indel
                    if((ispunct(position1)) || (ispunct(position2))){
                        ;
                    }
                    // 2: Else if the positions are the same, increment matches and total
                    else if(position1 == position2){
                        matches++;
                        total++;
                    }
                    // 3: Else if the positions are different, increment total
                    else if(position1 != position2){
                        total++;
                    }
                    // If none of these are true, print a warning and exit.
                    else{
                        printf("None of the three conditions were made!\n");
                        exit;
                    }
 
            }
            ratio_temp = matches / total;
            printf("Ratio %i: %f\n", num_comp_temp, ratio_temp);
            
        }
    }
    printf("number of comparisons temp: %i \t num total: %i\n", num_comp_temp, num_comparisons);
    
}


/*
    
    get_max_dist:
        

*/
float get_max_dist()
{

}

/*
    
    get_avg_dist:

*/
float get_avg_dist()
{

}
/*

    get_min_dist:


*/
float get_min_dist()
{

}






