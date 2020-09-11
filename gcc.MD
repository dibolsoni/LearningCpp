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

All Flags

<code> g++ -pedantic-errors -Wall -Weffc++ -Wextra -Wsign-conversion -std=c++2a main.cpp -lstdc++ -o main </code>




