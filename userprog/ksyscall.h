/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls 
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__ 
#define __USERPROG_KSYSCALL_H__ 

#include "kernel.h"
#include "synchconsole.h"
#include "string"


void SysHalt()
{
  kernel->interrupt->Halt();
}


int SysAdd(int op1, int op2)
{
  return op1 + op2;
}

int SysPrint(char* input, int num){

  int data[100];
  // int i=0;
  cerr << "In SysPrint()" << endl;
  for(int i=0; i<5; i++) {
    kernel->machine->ReadMem((int)input+i, 1, data+i); 
    cerr << (char) data[i] << endl; 
    //i++;
  } //while(data[i]!='\0');
  data[10] = '0';
  std::string str = (char*) data;
  cerr << str << endl;
  cerr << (char*) data << endl;
  str = "lalala\n";
	kernel->synchConsoleOut->PutString(str);
  return 5;
}




#endif /* ! __USERPROG_KSYSCALL_H__ */
