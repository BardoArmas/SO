#include<stdio.h>
#include<stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
	int status;
	pid_t pid;
	printf("PADRE: Soy el proceso padre y mi pid es: %d\n", getpid());
	pid = fork();
	pid = fork();
	pid = fork();
	// En cuanto llamamos a fork se crea un nuevo proceso. En el proceso
	// padre 'pid' contendrá el pid del proceso hijo. En el proceso hijo
	// 'pid' valdrá 0. Eso es lo que usamos para distinguir si el código
	// que se está ejecutando pertenece al padre o al hijo.
	if (pid) // Este es el proceso padre
	{
		printf("PADRE: Soy el proceso padre y mi pid sigue siendo: %d\n", getpid());
		printf("PADRE: Mi hijo tiene el pid: %d\n", pid);
		pid_t pid2;
		waitpid(pid,&status,0);
		pid2=fork();
		if(pid2==0){//codigo hijo B
			printf("HIJOB: Soy el proceso hijo B con pid: %d\n",getpid());
			printf("HIJOB: mi padre tiene el pid: %d\n",getppid());
			sleep(5);
		}

		else{//codigo del padre
			waitpid(pid2,&status,0);
			printf("Soy el proceso padre con pid: %d\n",getpid());
			printf("Mi hijoB tiene el pid: %d\n ",pid2);
			sleep(5);
		}

	}
	else // Proceso hijo A
	{
		sleep(5);
		printf("HIJO: Soy el proceso hijo y mi pid es: %d\n", getpid());
		printf("HIJO: mi padre tiene el pid: %d\n", getppid());
	}
}
