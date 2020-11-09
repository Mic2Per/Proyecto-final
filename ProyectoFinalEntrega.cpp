#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
 
using namespace std;
int menu() {
    int x;
    system("cls");
    cout<<"<<------Fase uno------>>"<<endl<<endl;
    cout<<"1. Ingrese palabra"<<endl;
    cout<<"2. ver palabras guardadas"<<endl;
    cout<<"3. Modificar palabra"<<endl;
    cout<<"4. Eliminar palabra"<<endl;
    cout<<"5. salir"<<endl;
    cout<<"6. Ver traduccion de texto"<<endl;
	cout<<"opcion ";
    cin>>x;
    return x;
}

void agregar(ofstream &es) {
	system("cls");
	string pal;
	string tra;
	string fun;
	es.open("fase.txt", ios::out | ios::app);
	cout<<"palabra ";
	cin>>pal;
	cout<<"traduccion ";
	cin>>tra;
	cout<<"funcion ";
	cin>>fun;
	es<<pal<<"  "<<tra<<"  "<<fun<<"\n";
	es.close();
}


void verRegistros(ifstream &Lec) {
	system("cls");
	string pal;
	string fun;
	string tra;
	Lec.open("fase.txt", ios::in);
	if(Lec.is_open()){
	  cout<<"------Palabras guardadas------"<<endl<<endl;
	  
	  while(!Lec.eof()) {
	  	Lec>>pal;
	    Lec>>tra;
	    Lec>>fun;
	    cout<<"Palabra--------:"<<pal<<endl;
	    cout<<"Traduccion-----:"<<tra<<endl;
	    cout<<"Funcion--------:"<<fun<<endl;
	    cout<<"------------------"<<endl;
	    Lec>>pal;
	}
	Lec.close();
	}else 
	     cout<<"Error"<<endl;
	system("pause");
	
}

void eliminar(ifstream  &Lec){
    system("cls");
	string pal;
	string tra;
	string fun;
	Lec.open("fase.txt", ios::in);
	ofstream aux("auxiliar.txt", ios::out);
	if(Lec.is_open()){
		cout<<"palabra ";
		cin>>pal;
		Lec>>tra;
		while(!Lec.eof()){
			Lec>>tra;
			Lec>>pal;
			if(pal == pal){
				cout<<"Eliminado ok**";
				Sleep(1500);

			}else{
			    aux<<pal<<"  "<<fun<<" "<<tra<<"\n";
			}
		    Lec>>fun;

		}
		Lec.close();
		aux.close();
	}else
	     cout<<"Error"<<endl;
	remove("fase.txt");
	rename("auxiliar.txt", "fase.txt");
}

void eliminar2(ifstream  &Lec){
    system("cls");
	string pal;
	string tra;
	string fun;
	Lec.open("fase.txt", ios::in);
	ofstream aux("auxiliar.txt", ios::out);
	if(Lec.is_open()){
		cout<<"palabra ";
		cin>>pal;
		Lec>>tra;
		while(!Lec.eof()){
			Lec>>tra;
			Lec>>pal;
			if(pal == pal){
				Sleep(1500);

			}else{
			    aux<<pal<<"  "<<fun<<" "<<tra<<"\n";
			}
		    Lec>>fun;

		}
		Lec.close();
		aux.close();
	}else
	     cout<<"Error"<<endl;
	remove("fase.txt");
	rename("auxiliar.txt", "fase.txt");
}


void ver(ifstream  &Lec){
	string pal ;
	
	
    	cout << "\n INGRESE EL TEXTO DESEADO "<<endl;
    	cin>>pal;
		char* original = new char[50];
	
	getline(cin,pal);
	
  string::size_type pos = 0;
  cout<<"\n VARIABLE: "<<pal<<endl;
  string reserved[11] = {"int", "string","double","char","get line","main","for","return","if","exit","endl"};
  string toStr[11] = {"entero","cadena","doble","caracter","obtener linea","principal","para","retornar","si","salida","finalizar"};
  
  for (int i = 0; i < 11; ++i) 
  {
    while ((pos = pal.find(reserved[i], pos)) < string::npos)
    {
      pal.replace(pos, reserved[i].length(), toStr[i]);
      pos+=toStr[i].size();
    }
    pos = 0;
  }
  
 
  cout << "\n TRADUCIDO: "<<pal<<endl;
}

void traduccion(ifstream &Lec){
	system("cls");
	system("cls");
	string pal;
	string fun;
	string tra;
	Lec.open("fase.txt", ios::in);
	char contenido[100];
	char *token;
	printf("Introduce el texto: ");
	gets(contenido);
	token=strtok(contenido,",");

		while(token){
		Lec.open("fase.txt", ios::in);
		printf("Palabra: %s\n",token);
		token=strtok(NULL,",");
		}
		
	
}


int main () {
    ofstream Esc;
    ifstream Lec;
    int op;
    do{ 
       system("cls");
       op = menu();
	   switch(op){
	   	    case 1:
	   	    	    agregar(Esc);
	   	    break;	  
			case 2:
 			        verRegistros(Lec);
			break; 
			case 3:
			        eliminar2(Lec);
			        agregar(Esc);
			break;
			case 4:
					eliminar(Lec);
            
            break;
            case 5:
            	
            	break;
			case 6:
					ver(Lec);
			break;
			
	   }	
	}while(op != 5);
	return 0;
}
