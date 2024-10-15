====================================================================
A Program for reading and displaying contents of a file using pthreads
==================================================================

Write a simple program to allow the reading of a file asynchronously in C or C++ using

pthreads and blocking IO system calls (read(2), open(2) and close(2)).

Application should:

1. create a reader (producer) single thread which reads file data into buffers

2. create a display (consumer) single thread which displays the file contents to stdout

The process should never have more than three 1k buffers allocated at any time and

should be able to display any sized file.

The program should take the file name as an argument.
