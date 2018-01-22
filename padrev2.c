#include<stdio.h>
#include<stdlib.h>

int main() {
	int pid, pid2,x;
	printf("PADRE: Soy el proceso padre y mi pid es: %d\n", getpid());
	printf("PADRE: Soy el proceso padre y el pid de mi padre es: %d\n", getppid());
	x = 5;
	pid = fork();
	// En cuanto llamamos a fork se crea un nuevo proceso. En el proceso
	// padre 'pid' contendrá el pid del proceso hijo. En el proceso hijo
	// 'pid' valdrá 0. Eso es lo que usamos para distinguir si el código
	// que se está ejecutando pertenece al padre o al hijo.
	if (pid) // Este es el proceso padre
	{
		x = 6;
		printf("PADRE: Soy el proceso padre y mi pid sigue siendo: %d\n", getpid());
		printf("PADRE: Mi hijo tiene el pid: %d\n", pid);
		sleep(1);
		
		pid2=fork();
		if(pid2){//codigo del padre
		 
		printf("PADRE: Soy el proceso padre y mi pid es: %d\n", getpid());
                printf("PADRE: mi hijo tiene el pid: %d\n", pid2);
               int pid3;
		pid3 = fork();
			if(pid3){//codigo padre
			printf("PADRE: Soy el proceso padre y mi pid es: %d\n", getpid());
                	printf("PADRE: mi hijo tiene el pid: %d\n", pid3);	
			sleep(2);
			}
			else{//codigo del hijo
			printf("Hijoc: Soy el proceso hijo y mi pid es: %d\n",getpid());
                	printf("Hijoc: Mi padre tiene el pid: %d\n", getppid());
			}
		}
		else{//codigo del hijo
			printf("Hijoa: Soy el proceso hijo y mi pid es: %d\n",getpid());
                	printf("Hijoa: Mi padre tiene el pid: %d\n", getppid());
			int pnieto;
			pnieto = fork();
			if(pnieto){//codigo padre  proceso hijoa
				printf("Padrea: Soy el proceso hipa y mi pid es: %d\n",getpid());
                        	printf("Padrea: Mi hijo tiene el pid: %d\n", pnieto);
				sleep(1);
			}
			else{//nieto
				printf("Nietoa: Soy el proceso hinieto y mi pid es: %d\n",getpid());
                        	printf("Nietoa: Mi padre tiene el pid: %d\n", getppid());

			}
		}
	
	}
	else // Proceso hijo
	{
		printf("HIJOb: Soy el proceso hijo y mi pid es: %d\n", getpid());
		printf("HIJOb: mi padre tiene el pid: %d\n", getppid());
		printf("La var x es: %d\n",x);
	}
}
