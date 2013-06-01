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



void SysHalt()
{
  kernel->interrupt->Halt();
}


int SysAdd(int op1, int op2)
{
  return op1 + op2;
}

int SysPrint(char* input, int num){

  int data[1];
  int i=0;
  kernel->synchConsoleOut->PutChar('l');
  kernel->synchConsoleOut->PutChar('a');
  kernel->synchConsoleOut->PutChar('\n');

  do {
    kernel->machine->ReadMem((int)input+i, 1, data);
    kernel->synchConsoleOut->PutChar(data[0]);
    i++;
  } while(data[0]!='\0');

  return i;
}




#endif /* ! __USERPROG_KSYSCALL_H__ */
