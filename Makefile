PROGNAME=main
CXX=g++
CC=$(CXX)
OPLVL=3
FILES=$(PROGNAME).cpp Account.cpp  Bank.cpp  Cd.cpp  Checking.cpp  Customer.cpp  Date.cpp  Deposit.cpp  Fee.cpp  main.cpp  Savings.cpp  Transaction.cpp  Withdrawl.cpp
OBJS=$(FILES:.cpp=.o)
STD=14
CFLAGS=-c -O$(OPLVL) -Werror -std=c++$(STD)
CXXFLAGS=$(CFLAGS)

all: $(OBJS)
	$(CXX) $(OBJS) -o $(PROGNAME)

%.o : %.cpp
	$(CXX) $(CFLAGS) $<

clean:
	rm -f $(PROGNAME) *.o *~
