# CPool_bistro-matic_2017
First year project in C in which the goal is to write a program that will display the result of an evaluated mathematical expression (kind of a big calculator). The expression will be composed of infinite integers that can be expressed in any base. The program handle following operators: +-*/%, parentheses, operation priorities and syntax errors, but not float numbers.

The program implements the "Shunting Yeard algorithm" along a doubly circular linked list for the computations + storage and a lexical parser to parse inputs received.

USAGE :
      
    Make
    
    ./calc base operators size_read

DESCRIPTION :

    - base: all the symbols of the base
    - operators: the symbols for the parentheses and the 5 operators
    - size_read: number of characters to be read

EXEMPLE :

    echo ‘3+6’ | ./calc 0123456789 ‘()+-*/%’ 3 ; echo
    > 9

    echo ‘----++-6*12’ | ./calc 0123456789 ‘()+-*/%’ 11 | cat -e ; echo
    > -72

    echo ‘-(12-(4*32))’ | ./calc 0123456789 ‘()+-*/%’ 12 | cat -e ; echo
    > 116
