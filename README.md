Pairwise-Comparison
===================

This pairwise comparison program written in C will calculate the uncorrected protein distances for an alignment.

How to compile
------------------------------------------------

The easiest way to compile before I work on the Makefile is to run.

    $ gcc main.c pairwise.c -o pairwise
    
This will put the binary file in the present directory.


How to run
------------------------------------------------

In order to run, you will need to know two things:

1. The number of proteins in the alignment.
2. The name of the alignment file.

For example, the supplied alignment (alignment.fa) has 62 proteins.  You would run the program with the following parameters:

    $ ./pairwise 62 alignment.fa
    
From here, it will read in the file and calculate the uncorrected protein distance between all the sequences.  After it is done, it will print out the minimum, maximum and average distances.