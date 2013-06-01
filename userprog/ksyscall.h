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

  for(int i=0; i<5; i++) {
    kernel->machine->ReadMem((int)input+i, 1, data+i);  
    //i++;
  } //while(data[i]!='\0');

  std::string str = (char*) data;
	kernel->synchConsoleOut->PutString(str);
  return i;
}




#endif /* ! __USERPROG_KSYSCALL_H__ */
