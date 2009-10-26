#include <stdio.h>
#include <unistd.h>
#include <sys/io.h>
#include <math.h>

#define PORTA 0x378  /* Acesso a Porta Paralela */

int main(){
	int d,r;
	if( ioperm (PORTA, 3, 1)) {
			perror("ioperm"); 
			return(1);
	} /* Permite acesso aos endereços 0x378, 0x379, 0x37a */
	
	outb(80, PORTA); /* Liga Moteres M1 e M2 */ 
	
	for (d=0; d <=3; d++){
		r = exp2(d);
		outb(r, PORTA);
		usleep(100000);	
	}
	

	outb(80, PORTA); /* Liga Moteres M1 e M2 */ 
	if (ioperm(PORTA, 3, 0)) {perror("ioperm"); return(1);}
}
