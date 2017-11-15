#include <signal.h>
#include <stdlib.h>
#include <iostream>
#include "bittypes.h"
//#include "Bank.h"

using namespace std;

static void signalHandler(int signo){
  if(signo == SIGSEGV){
    cout << "Nothing to see here. Everything's fine.\n";
    exit(1);
  }
}

static void printOptions(){
  cout << "1. enter another transaction\n";
  cout << "2. list all of a customer's accounts\n";
  cout << "3. print a monthly statement for a given account\n";
  cout << "4. print the total value of all of the savings accounts\n";
  cout << "5. print the total value of all of the checking accounts\n";
  cout << "6. print the total value of all of the CD accounts\n";
  cout << "7. print a list of customers with the total value of all of their accounts\n";
  cout << "8. save the current collection of customers, accounts and transactions to the appropriate files\n";

  cout << "\nEnter option: ";
}

int main(int argc, char **argv){
  signal(SIGSEGV, signalHandler);
  
  //Bank bank;

  if(argc > 3){
    cout << "Reading in files...\n";
    // TODO: read files
  }else{
    cout << "Enter X file: ";
    string fp;
    cin >> fp;
    // TODO: read files and ask for input
  }
  
  
  uf16 cmd;
  while(true){
    printOptions();
    cin >> cmd;
    switch(cmd){
      // TODO: 
    default:
      break;
    }
  }
  
  return 0;
}
