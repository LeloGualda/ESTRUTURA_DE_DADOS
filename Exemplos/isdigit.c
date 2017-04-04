/* isdigit example */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//defict atenção tdah
int contI(int);
int contS(char *);

int main ()
{
  char str[]= "123456789";
  int n1,n2,aux;
  
  if (isdigit(str[0]))
  {
    n1 = atoi (str);
	n2 =contI(n1);
   printf ( "\n Numero 01: \t %d \t %d  \n",n1,n2);
//	char t[] = n1 + ' ';
	//aux = cont(&t);
//	printf("%s \n",t); 
//	printf ("QNT CHAR N1 \t %d \n",aux);

  }
  return 0;
}

// Aurelio Gualda 28/03/17  Conta casas decimais do inteiro
int contI(int x){int k,i,j,aux;
	for(i=1,k=0;j>0;(i=(i*10)),k++)
	{		j = x/i;  /* Entenda!*/ //		printf("\n %d \t %d \t %d",k,x,i); 
	
	//	printf("\n %d \t %d \t %d",k,x,i);	
	}
	return(k-1);
		}
	
// Aurelio Gualda 28/03/17 Conta numero de char no array char[] 
int contS(char *c){int i,x;
	for(i=0; c[i]; i++){if(c[i] != ' ')x++;}
	return(x);
}
	