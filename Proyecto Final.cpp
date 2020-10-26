#include<stdlib.h>     
#include <iostream>
#include <fstream> 

using namespace std;
	int main()
{
    	int numero,opcion;
    	int operacion,op;
    			char palabra[15],significado[15];
    		ofstream Base;
    		ifstream Leer;
    		fstream Temp; 
    			Base.open("Traductor.txt",ios::app);
    			while(true)
    {
    	
    cout<<" ------------------------------------------------------------ "<<endl;
    cout<<"|                                                            |"<<endl;
    cout<<"|              Examen Final de c++  		                    |"<<endl;
    cout<<"|                                                            |"<<endl;
    cout<<" ------------------------------------------------------------- "<<endl;
      						
       								 cout <<"1 Crear" 	<< endl;
      								 cout <<"2 Leer"  	<< endl;
     								 cout <<"3 Buscar"	<< endl;
       								 cout <<"4 Actualizar"<< endl;
       								 cout <<"5 Eliminar"<<  endl;
       								 cout <<"6 Salida"  << endl;
        
       								 cout <<endl;
       							 cout<<"Elija una opcion:"<<endl;
      								  cin>>opcion;

        switch(opcion)
        {
            case 1:
                {
                    		system("cls");
            cout<<"Ingrese la palabra: ";
                    cin>>palabra;
            cout<<"Ingrese la traduccion: ";
                    cin>>significado;                  
            cout<<"Ingrese un numero para registrarlo";
                    cin>>operacion;
            Base<<palabra<<" "<<significado<<" "<<operacion<<endl;
                    break;
                }
            case 2:
                {
                   			 system("cls");  
                Leer.open("Traductor.txt");
            	Leer>>palabra>>significado;
                    while(!Leer.eof())
                    {
                        Leer>>operacion;
        
            cout<<"Palabra:      "<< palabra<<endl;
            cout<<"significado:  "<< significado<<endl;
            cout<<"operacion:    "<< operacion<<endl;
        
            cout<<endl;
                Leer>>palabra>>significado;
                    }
                Leer.close();
                    break;
                }
            case 3:
                {
                   			 system("cls");  
                Leer.open("Traductor.txt");
                Leer>>palabra>>significado;
                	bool encontrado=false;
            cout<<"Ingrese de registro"<<endl;
                    cin>>op;
                	while(!Leer.eof())
                    {
                Leer>>operacion;
                        if(operacion==op)
                        {
                            encontrado=true;
                    
            cout <<"palabra:      "<< palabra<<endl;
            cout <<"significado:  "<< significado<<endl;
            cout <<"operacion:    "<< operacion<<endl;
            
                        cout<<endl;
                        }
                Leer>>significado>>significado;
                    }
                    	if(encontrado==false)
                    {
            cout <<"numero de registro no encontrado"<< endl;
                    }
                Leer.close();
                    break;
                }

            case 4:
                {
                    		system("cls");  
                Leer.open("Traductor.txt");
                Temp.open("Temp.txt");
                Leer>>palabra>>significado;
                    bool encontrado=false;
            cout <<"Ingrese su numero de registro"<<endl;
                        cin>>operacion;
                    while(!Leer.eof())
                    {
                Leer>>operacion;
                        if(operacion==op)
                        {
                            encontrado=true;
            cout <<"Palabra:    	"<< palabra <<endl;
            cout <<"significado: 	"<< significado <<endl;
            cout <<"operacion:      "<< op << endl;
            cout <<endl;
                        
                Temp<<palabra<<" "<<significado<<" "<<operacion<<endl;
            cout << endl;
            cout <<"Modificado"<<endl;
                        }
                        else
                        {
                Temp<<palabra<<" "<<significado<<" "<<operacion<<endl;
                        }
                Leer>>palabra>>significado;
                    }
                    if(encontrado==false)
                    {
            cout <<"Numero de registro no encontrado"<<endl;
                    }
                Leer.close();
                Temp.close();
                    remove("Traductor.txt");
                    rename("Temp.txt","Traductor.txt");
                    break;
                }

            case 5:
                {
                    		system("cls");
                Leer.open("Traductor.txt");
                Temp.open("Temp.txt");
                Leer>>palabra>>significado;
                    bool encontrado=false;
            cout <<"Ingrese el numero de registro"<<endl;
                     cin>>op;
                    while(!Leer.eof())
                    {
                Leer>>operacion;
                    if(operacion==op)
                        {
                         encontrado=true;
            cout <<"palbra"         <<palabra<<endl;
            cout <<"significado"	<<significado<<endl;
            cout <<"operacion:    " <<operacion<<endl;
            cout << endl;
            cout <<"Eliminado"		<<endl;
                        }
                        else
                        {
                Temp<<palabra<<""<<significado<<" "<<operacion<<endl;
                        }
                Leer>>palabra>>significado;
                    }
                    if(encontrado==false)
                    {
            cout <<"Numero de registro no encontrado"<<endl;
                    }
                    
                    Leer.close();
					Temp.close();
                    remove("Traductor.txt");
                    rename("Temp.txt","Traductor.txt");

                    break;
                }

            case 6:
                {
                    system("cls");

                    break;
                }   
        }   
    }
    return 0;
}
