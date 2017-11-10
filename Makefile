PROGNAME=bank
CXX=g++
CC=$(CXX)
OPLVL=3
FILES=$(PROGNAME).cc
OBJS=$(FILES:.cc=.o)
STD=14
CFLAGS=-c -O$(OPLVL) -Werror -std=c++$(STD)
CXXFLAGS=$(CFLAGS)

all: $(OBJS)
	$(CXX) $(OBJS) -o $(PROGNAME)

%.o : %.cc
	$(CXX) $(CFLAGS) $<

clean:
	rm -f $(PROGNAME) *.o *~
