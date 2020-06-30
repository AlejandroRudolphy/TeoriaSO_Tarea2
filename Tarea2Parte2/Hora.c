#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>



int main() {
	int pid,estado;
	time_t tiempo = time(0); //Se obtiene la hora local.
	struct tm *tlocal = localtime(&tiempo); //Utiliza el valor apuntado por el temporizador para completar una estructura
						// con los valores que representan el tiempo correspondiente, expresado para la zona horaria local.
	char hora[128]; //Cantidad maxima de caracteres en donde estaran alamcenados la fecha y la hora.

 	pid=fork();
 
	switch(pid){
		case -1: // Si pid es -1 quiere decir que ha habido un error
			perror("No se ha podido crear el proceso hijo\n");
			break;
		case 0: // Cuando pid es cero quiere decir que es el proceso hijo
			// for(i=0; i<=5; i++)
				printf("programa hora ejecutandose. PID= [%d] \n",getpid());
				printf("Listo para recibir señal SIGUSR1\n");
				for(;;);
			break;
		default: // Cuando es distinto de cero es el padre
			//for(i=0; i<=5; i++)
			//	printf("tengo que decir la hora %d \n",getpid());
			// La función wait detiene el proceso padre y se queda esperando hasta
			// que termine el hijo
			
			waitpid(pid,&estado,0); //Se suspende la ejecucion del proceso actual hasta que el hijo, especificado por el agumento pid cambie su estado.
						//Por defecto, se espera solo por la muerte de los hijos pero ese comportamiento es modificable por el parametro options
			
			strftime(hora, 128, "%d/%m/%y %H:%M:%S", tlocal); //Este es el puntero a la matriz de destino donde se copia la cadena resultante
									  //El numero maximo de caracterers que se copiaran en el cadena.
									  //Tiempo correspondiente de la zona horaria local
   			printf("Señal SIGUSR1 recibida: %s\n",hora);
			break;
	}
 
}

