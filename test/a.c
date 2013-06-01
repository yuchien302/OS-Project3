#include <syscall.h>

int main(){
	int i;
	for( i=1;i<5;i++){
		OSPrint("da000\n", i);
		OSPrint("da001\n", i);
		OSPrint("da002\n", i);
		
	}
}