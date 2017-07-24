Thomas      Ngo     tngo0508@csu.fullerton.edu
Danh        Pham    danhpham312@gmail.com
Paul        Smith   dehobo84@gmail.com
Susmitha    chittem susmitha.chittem@csu.fullerton.edu

The programming language: C++

How to execute the program:

For shellskel.cpp:
    $ g++ -o shell shellskel.cpp
    $ ./shell

For serial.cpp:
    $ g++ -o serial serial.cpp
    $ time ./serial

    urls.txt file is named url.txt

For parallel.cpp:
    $ g++ -o parallel parallel.cpp
    $ time ./parallel 
    
    urls.txt file is named url.txt

The execution time for serial:
   real 0m13.440s
   user 0m0.034s
   sys 0m0.558s

   real 0m10.746s
   user 0m0.034s
   sys 0m0.544s

   real 0m10.647s
   user 0m0.037s
   sys 0m0.511
The execution time for parallel:
real 0m4.186s
user 0m0.034s
sys 0m0.545s

real 0m4.906s
user 0m0.042s
sys 0m0.548s

real 0m4.192s
user 0m0.035s
sys 0m0.510s

The answers for questions:
1.  The real time is the turnaround time of process. 
    The user time is the time running in user mode.
    The system time is the time spending in kernel mode to execute system's
    processes.

2.  The system time is longer than user time because it takes more time than to
process the system call than it does to invoke them.

3.  parallel is faster than serial since parallel starts and runs multiple
processes simultaneously while serial is only using the resources to finish one
job at a time.

4.  Parallel remains faster than serial for the same reason above. However,
serial would be faster if the ten files used enough of the system's memory for
them to run efficiently all at the same time.


real 0m57.946s
user 0m0.600s
sys 0m3.612s
