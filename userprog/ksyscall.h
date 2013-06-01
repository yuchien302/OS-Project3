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




void SysHalt()
{
  kernel->interrupt->Halt();
}


int SysAdd(int op1, int op2)
{
  return op1 + op2;
}

int SysPrint(string input, int length){

  int data[1];

  for(int i=0;i<=input.length();i++){
    kernel->machine->ReadMem((int)&input+i, 1, data);
    kernel->synchConsoleOut->PutChar(data[0]);
  }
}




#endif /* ! __USERPROG_KSYSCALL_H__ */
