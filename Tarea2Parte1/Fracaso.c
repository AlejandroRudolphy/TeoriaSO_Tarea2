
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

 
#define N 3  // Definir los 3 hijos

void ciclo_hijo(int id,int random)
{
   for (int i=0; i<random; ++i){  //Se recorre la cantidad de procesos hijos randomicante pero con un rango establecido desde [1,10[.
      printf("Soy %d° HIJO PID=[%d] MI PADRE: PID=[%d]",id,getpid(),getppid()); //Se imprime de forma randomica la id del padre y del hijo;
      for (int j=random-1; j > i; --j){ //Se recorre la cantidad de procesos que se van realizando por cada hijo.
         printf(" *"); //Se imprime un "*", el cual corresponde a las veces que se ha iterado un proceso hijo.
      }
      sleep(2);  //dormir por 2 segundos
    printf("\n");  
   }
   
   exit(0);
}


int main() {
   int hijos[N];//Se declara el arreglo hijos
   int pidproc,estado;  //Se declara el pid del proceso y el estado en el que se encontrara los procesos hijos.
   unsigned int  random;


   for(int i =0 ; i<N;++i){
        switch(pidproc=hijos[i]=fork())
        {
            case -1:
                printf("ERROR EN FORK\n");
                return -1; //Se sale
                break;
            case 0:
                random=rand()%10+1*clock()/100; /* Se establece que la variable random tendra un rango entre [1,10[, lo que significa que cada proceso hijo 
						 tendra 3 iteraciones randomicamente cada uno. */ 
                ciclo_hijo(i+1,random); /*Se llama a la funcion ciclo_hijo para ir recorriendo cada proceso de los hijos randomicamente e incrementando su 
               				 id correspondiente  */
		 break;
            default:
                printf("SOY PADRE PID=[%d] CREANDO [%d]° HIJO \n",getpid(),i+1); //El padre va a ir creando a sus hijos por cada iteracion que se realice.
                sleep(2);
        }
    }

if (pidproc>0){ //Si el pid del procesos es mayor que cero se procede a esperar a los hijos.
   printf("---SOY PADRE[%d] ESPERANDO HIJOS---\n",getpid()); //Se imprime por consola el pid del padre con su respectivo mensaje.
   for (int i = 0; i < N; ++i){ //Se recorre los procesos hijos que estan por ejecutarse.
      waitpid(hijos[i], &estado, 0); //Mientras el proceso padre estara esperando a que terminen los procesos de los hijos para culminar con su proceso. 
   }
   printf("---SOY PADRE[%d] HIJOS TERMINADOS---\n",getpid()); //Se muestra en consola la culminacion de los procesos hijos y del proceso padre.
}

   
return 0;
}

