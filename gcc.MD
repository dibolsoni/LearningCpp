# HEADERs, LIBRARIEs
Order your #includes as follows: your own user-defined headers first, then 3rd party library headers, then standard library headers, with the headers in each section sorted alphabetically.
Adding directories of header files
use the -I option to specify an alternate include directory.

<code> g++ -o main -I/source/includes main.cpp </code>

# FLAGS

Remove compiler extensions
<code>-pedantic-errors</code>

Warning and error levels
<code>-Wall -Weffc++ -Wextra -Wsign-conversion</code>

Setting a language standart
<code>-std=c++11, -std=c++14, -std=c++17, or -std=c++2a to enable C++11/14/17/2a support respectively.</code>

C++ standart library explicit linking (must be after target "main.cpp")
<code>-lstdc++</code>

Valgrind
--leak-check=full: "each individual leak will be shown in detail"
--show-leak-kinds=all: Show all of "definite, indirect, possible, reachable" leak kinds in the "full" report.
--track-origins=yes: Favor useful output over speed. This tracks the origins of uninitialized values, which could be very useful for memory errors. Consider turning off if Valgrind is unacceptably slow.
--verbose: Can tell you about unusual behavior of your program. Repeat for more verbosity.
--log-file: Write to a file. Useful when output exceeds
<code>valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./executable exampleParam1</code>
         


# All Flags & Valgrind

<code> g++ -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -std=c++2a main.cpp -lstdc++ -o main \
  && \
  valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./main exampleParam1 </code>
         
# Short version      
<code>g++ -std=c++2a main.cpp -lstdc++ -o main && valgrind --leak-check=full ./main</code>



