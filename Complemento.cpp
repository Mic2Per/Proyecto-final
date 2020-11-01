#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
		char palabra[25];
		char significado[30];
}   	Traductor;

     void Listar(void);
     void Agregar(void);
     void Borrar(void);
     void Encontrar(void);

			char palabra_fichero[] = "Traductor2.txt";

			FILE *abrir_fichero_b(char cadena[], int metodo);

		int main(){
			FILE *fp;
		int opc;
		char cad[3];
	
			fp = abrir_fichero_b(palabra_fichero,0);
		if( fp ){
			fclose(fp);
		}
		else
		{
       		 fp = abrir_fichero_b(palabra_fichero,1);
        if(fp){
           fclose(fp);    
        }
        else
        {
    		printf( "Error (NO ABIERTO)\n" );
    		puts("Presiona cualquier tecla para continuar.... ");
    		fp = abrir_fichero_b(palabra_fichero,1);
    		fclose(fp);
    		getch();
        }
        
		}
	
		do{
		puts("1. Agregar\n2. Mostrar Todos\n3. Buscar\n4. Salir");
		puts("Selecciona tu opcion");
		opc = atoi(gets(cad));
		while(opc<0 || opc>4) 
			opc = atoi(gets(cad));
		switch(opc)
		{
		case 1:	
				Agregar();
				break;
		case 2:
				Listar();
				break;
		case 3:
				Encontrar();
				break;
			
		}
		
		
		if(opc<4){
			puts("\n\nPresiona Cualquier Tecla para Regresar al Menu");
			getch();
		}
	
	
		}while(opc!=4);
	
}

		void Listar(void){
  			 FILE *fp;
  		 int i=1;
  			 Traductor aux;
			fp = abrir_fichero_b(palabra_fichero,0);
   		if(!(fp))
   			printf("\n Error de apuertura del archivo\n");
   		else{
      		printf("\Palabras \n");
     		 printf("---------------------------------------------------------------\n");
        while ((fread(&aux, sizeof(aux), 1, fp))!=0){
			printf("Datos %d\n",i);
			printf("Palabra: %s | Significado: %s\n",aux.palabra,aux.significado);
			printf("\n");
			i++;
      }
    		  printf("---------------------------------------------------------------\n");
      		fclose(fp);
   }
}


		void Agregar(void){
  			 FILE *fp;
   			Traductor aux;
  		 char cad[3];

  		 printf("\n Agregar nuevo registro al archivo\n");
  		 fp=abrir_fichero_b(palabra_fichero,2);
   		if(!(fp))
   		
		printf("\n Error de apuertura del archivo\n");
   		else{
		
		printf("palabra: ");
		gets(aux.palabra);
		printf("Significado: ");
		gets(aux.significado);

		fwrite(&aux, sizeof(aux), 1, fp);
		fclose(fp);
   }
}

		void Encontrar(void){
		FILE *fp;
		Traductor	aux;
		int n;
		char cadena[25];

		printf("Introduce la palabra: ");
		gets(cadena);

		printf("\n Buscando palabra \n");
			fp=abrir_fichero_b(palabra_fichero,0);
		if(!(fp))
			printf("\n Error de apuertura del archivo\n");
		else{
			while ((n=fread(&aux, sizeof(aux), 1, fp))!=0 && stricmp(aux.palabra,cadena)!=0);
      	if (n==0)
         	printf("No existe: %s ",cadena);
      	else{
        	 printf("\n Encontrado\n");
			 printf("Palabra: %s | Significado : %s\n",aux.palabra,aux.significado);
		
		}
	}


}

		FILE *abrir_fichero_b(char cadena[], int metodo){
		FILE *x;
		switch(metodo){
		case 0:
			x = fopen(cadena,"rb");
			break;
		case 1:
			x = fopen(cadena,"wb");
			break;
		case 2:
			x = fopen(cadena,"ab");
			break;
		case 3:
			x = fopen(cadena,"r+b");
			break;
	}
	return x;
}
