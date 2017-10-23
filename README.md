# Practice

Program implements various sorting algorithms for the case of string sorting.

Below are the results of profiling:

Gprof and VALGRIND

|)(input1.txt strings 4818331 400-600 symbols)

QUICKSORT

 title| time
 ------|-----
real|	11m4.465s
user	|1m36.184s
sys	|0m30.292s

Index by function name

  time | cumulative seconds | self seconds | calls | self ns/call | total ns/call | name 
------ | ------             | ------       | ------| ------       | ------ | ------ 
 54.85 |  10.83             |  10.83       |  163134654 |  66.41 |  66.41 |  comparer 
 25.50 |  15.87 |  5.04 |  |  |  |  set_strings 
 16.15 |  19.06 |  3.19 |  |  |  |  set_quantity_of_numbers_strings 
 2.69 |  19.59 |  0.53 |  |  |  |  quicksort 
 0.66 |  19.72 |  0.13 |  |  |  |  printstrings 
 0.30 |  19.78 |  0.06 |  |  |  |  bubblesort 
 0.15 |  19.81 |  0.03 |  26101832 |  1.15 |  1.15 |  swap 
 
 [6] bubblesort              [1] quicksort               [7] swap
   [2] comparer                [4] set_quantity_of_numbers_strings
   [5] printstrings            [3] set_strings

Call graph


granularity: each sample hit covers 2 byte(s) for 0.05% of 19.81 seconds


 index | % time | self | children | called | name  
------ | ------ | ------ | ------ | ------ | ------ 
       |        |        |        |     1767794    |  quicksort  [1]
 [1]   |  57.5 |  0.53 |  10.86 |  0+1767794 |  quicksort  [1]
       |     |  10.83 |  0.00 |  163134654/163134654 |  comparer  [2]
 |  |  0.03 |  0.00 |  26101832/26101832 |  swap  [7]
 |  |  |  |  1767794 |  quicksort  [1]
 |  |  10.83 |  0.00 |  163134654/163134654 |  quicksort  [1]
 [2] |  54.7 |  10.83 |  0.00 |  163134654 |  comparer  [2]
 [3] |  |  |  |  |  |  <spontaneous>  
 |    25.4 |  5.04 |  0.00 | | set_strings  [3]
 [4]|  |  |  |  |  <spontaneous>  
 |    16.1 |  3.19 |  0.00 ||  set_quantity_of_numbers_strings  [4]
 [5]|  |  |  |  |  <spontaneous>  
   |  0.7 |  0.13 |  0.00 ||  printstrings  [5]
 [6]|  |  |  |  |  <spontaneous>  
 |    0.3 |  0.06 |  0.00 |  |bubblesort  [6]
 |   | 0.03 |  0.00 |  26101832/26101832 |  quicksort  [1]
 [7] |  0.2 |  0.03 |  0.00 |  26101832 |  swap  [7]
 

MERGESORT
 
 title| time
 ----|-----
 real	|10m43.772s
user	|1m27.540s
sys	|0m31.060s


Index by function name

time   | cumulative seconds | self seconds | calls | self ns/call | total ns/call | name 
------ | ------           | ------       | ------| ------         | ------        | ------ 
 25.66 |  12.02 |  3.31 |  |  |  |  set_quantity_of_numbers_strings 
 5.29 |  12.70 |  0.68 |  4818330 |  0.00 |  0.00 |  merge 
 1.09 |  12.84 |  0.14 |  |  |  |  printstrings 
 0.54 |  12.91 |  0.07 |  1 |  0.07 |  4.62 |  mergesortRecursively 
 0.16 |  12.93 |  0.02 |  |  |  |  bubblesort 
 0.08 |  12.94 |  0.01 |  |  |  |  insertsort 
 0.00 |  12.94 |  0.00 |  1049279 |  0.00 |  0.00 |  swap 
 0.00 |  12.94 |  0.00 |  624027 |  0.00 |  0.00 |  copyarray 

  [8] bubblesort              [4] merge                   [1] set_strings
   [5] comparer                [2] mergesortRecursively   [10] swap
  [11] copyarray               [7] printstrings
   [9] insertsort              [6] set_quantity_of_numbers_strings
Call graph


granularity: each sample hit covers 2 byte(s) for 0.08% of 12.94 seconds


 index | % time | self | children | called | name <spontaneous> 
------ | ------ | ------ | ------ | ------ | ------ 
       |        |        |        |        | <spontaneous> 
[1] |  |  37.4 |  4.84 |  0.00 |  set_strings  [1]
 |  |  |  |  9636660 |  mergesortRecursively  [2]
 |  |  0.07 |  4.55 |  1/1 |  mergesort  [3]
 [2] |  35.7 |  0.07 |  4.55 |  1+9636660 |  mergesortRecursively  [2]
 |  |  0.68 |  3.79 |  4818330/4818330 |  merge  [4]
 |  |  0.08 |  0.00 |  2097152/103063007 |  comparer  [5]
 |  |  0.00 |  0.00 |  1049279/1049279 |  swap  [10]
 |  |  0.00 |  0.00 |  624027/624027 |  copyarray  [11]
 |  |  |  |  9636660 |  mergesortRecursively  [2]
 |  |  |  |  |  <spontaneous>  
 [3]|    35.7 |  0.00 |  4.62 | | mergesort  [3]
 |  |  0.07 |  4.55 |  1/1 |  mergesortRecursively  [2]
 |  |  0.68 |  3.79 |  4818330/4818330 |  mergesortRecursively  [2]
 [4] |  34.6 |  0.68 |  3.79 |  4818330 |  merge  [4]
 |  |  3.79 |  0.00 |  100965855/103063007 |  comparer  [5]
 |  |  0.08 |  0.00 |  2097152/103063007 |  mergesortRecursively  [2]
 |  |  3.79 |  0.00 |  100965855/103063007 |  merge  [4]
 [5] |  29.9 |  3.87 |  0.00 |  103063007 |  comparer  [5]
 |  |  |  |  |  |  <spontaneous>  
 [6] |    25.6 |  3.31 |  0.00 | | set_quantity_of_numbers_strings  [6]
|  |  |  |  |  <spontaneous>  
[7]   |  1.1 |  0.14 |  0.00 | | printstrings  [7]
 |  |  |  |  |  <spontaneous>  
 [8]|    0.2 |  0.02 |  0.00 ||  bubblesort  [8]
 |  |  |  |  |  <spontaneous> 
 [9]   |  0.1 |  0.01 |  0.00 ||  insertsort  [9]
 |  |  0.00 |  0.00 |  1049279/1049279 |  mergesortRecursively  [2]
 [10] |  0.0 |  0.00 |  0.00 |  1049279 |  swap  [10]
 |  |  0.00 |  0.00 |  624027/624027 |  mergesortRecursively  [2]
 [11] |  0.0 |  0.00 |  0.00 |  624027 |  copyarray  [11]
 
 
    VALGRIND (400000 strings merge ) 
 ==4284== HEAP SUMMARY:
==4284==     in use at exit: 0 bytes in 0 blocks
==4284==   total heap usage: 400,006 allocs, 400,006 frees, 220,261,706 bytes allocated
==4284== 
==4284== All heap blocks were freed -- no leaks are possible
==4284== 
==4284== For counts of detected and suppressed errors, rerun with: -v
==4284== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0) 



Conclusion:Both (quick and merge work fine but merge faster). There could be some improvements in functions printstring and set_strings. Usage of memory very large- is minus. Could used mmap for decrease memory usage 

