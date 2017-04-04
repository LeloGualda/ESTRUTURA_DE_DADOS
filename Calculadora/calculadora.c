#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define QNT 11
#difine sqnt 4

 typedef enum sinal
 {	
	 mult 	= 0,	// 		*
	 divsor = 1,	// 		/
	 soma 	= 2,	//		+
	 subs 	= 3		//		-
 } sinal;
 
 
typedef struct operacao
{
	float 	num;
	sinal 	sin;
	struct operacao* op;		
}operacao;


// Global
	
char 	resolva			[QNT];

int main()
{
	strcpy(resolva,"2+2+2+2+2+2");
	for(int i=0; i<QNT;i++)
	{
		
	}		
}