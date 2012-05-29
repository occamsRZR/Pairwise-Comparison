/*
    
    Here are all of our function declarations.
    The implementations are at the bottom of the file.

*/
typedef char *string;

int read_alignment(string file_name, int num_seq, string *all_seqs);
int num_pairwise_comp(int num_seq);
int get_align_size(char *file_name);
void calculate_hamming_dists(float *comparisons, int num_comparisons, string *all_seqs, int aln_len, int num_seqs);
float get_max_dist();
float get_avg_dist();
float get_min_dist();

