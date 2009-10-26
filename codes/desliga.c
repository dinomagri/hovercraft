#include <stdio.h>
#include <unistd.h>
#include <sys/io.h>
#include <math.h>

#define PORTA 0x378  /* Acesso a Porta Paralela */

int main(){
	if( ioperm (PORTA, 3, 1)) {
			perror("ioperm"); 
			return(1);
	} /* Permite acesso aos endereços 0x378, 0x379, 0x37a */
	
	outb(0, PORTA); /* Desliga o Motor de Passo */ 
	if (ioperm(PORTA, 3, 0)) {perror("ioperm"); return(1);}
}
