#include <syscall.h>

int main(){
	int i;
	for( i=1;i<5;i++){
		cerr << "!!!" << endl;
		OSPrint("%da001\n", i);
		cerr << "???" << endl;
		OSPrint("%da0-1\n", i);
		OSPrint("%da002\n", i);
		
	}
}