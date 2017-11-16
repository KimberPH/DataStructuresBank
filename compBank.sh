# compile bank part of program
g++ Bank.cpp -std=c++14 -c
g++ main.cpp Bank.o -std=c++14
