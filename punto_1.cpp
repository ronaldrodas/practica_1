#include <iostream>


using namespace std;

string textoTemporal;
int numeroTemporal;
int opc;
int i;
int n;
string objetoA;

class A{

string nombreobjeto;
int serial;
int numeroobjetos;
friend void nuevoObjetoLista(A num );
friend class ListadeObjetos;
public:
};

class ListadeObjetos{
A listaClaseA[2];
string nombreobjeto;
int serial;

public:



void guardarObjetoA()
{ ListadeObjetos *listaClaseA = new ListadeObjetos[2];
    if (n < 2)
    {
        cout << "Por favor ingrese el nombre del objeto: ";
        cin >> listaClaseA[n].nombreobjeto;
        cout << "Por favor ingrese el serial del objeto: ";
        cin >> listaClaseA[n].serial;
        n++;
    }    else
        cout << "El arreglo esta lleno "  << endl;
   }
void mostrarobjetos();
void todosmostrarobjetos();

};


void ListadeObjetos::mostrarobjetos()
{ListadeObjetos *listaClaseA = new ListadeObjetos[2];
        if(n==0){
        cout << "No hay ningun objeto  en el arreglo " <<endl;
        }else
              cout << "Por favor ingresa el nombre del objeto que quieres ver: ";
              cin >> textoTemporal;
              for (i=0; i<n; i++)
                  if (listaClaseA[i].nombreobjeto == textoTemporal)
                  cout << "Nombre: " << listaClaseA[i].nombreobjeto <<" serial: " << listaClaseA[i].serial<< endl;
                  else cout << "No hay ningun objeto con ese nombre en el arreglo " <<endl;
    }

void ListadeObjetos::todosmostrarobjetos()
{    ListadeObjetos *listaClaseA = new ListadeObjetos[2];
    for (i=0; i<n; i++)
        cout << "Nombre: " << listaClaseA[i].nombreobjeto<< " Serial: " << listaClaseA[i].serial<< endl;
    if(n==0)
          cout << "No hay ningun objeto para mostar " <<endl;
}

void nuevoObjetoLista(A num)
{
  num.nombreobjeto;
  num.serial;
}

int main()
{
    do
    {
    cout << endl;
    cout << "           MENU DE OPCIONES       " << endl;
    cout << endl;
    cout << "1.- Agregar objeto a la lista" << endl;
    cout << "2.- Ver datos de un objeto" << endl;
    cout << "3.- Mostrar los datos de todos los objetos "<< endl;
    cout << "4.- Eliminar objeto de la lista"<< endl;
    cout << "5.- Salir" << endl;
    cout << endl;
    cout << "Por favor ingrese una de las opciones, de 1 a 5: ";
    cin >> opc;
    switch(opc)
           {
    case 1:
         {
          ListadeObjetos P;
          P.guardarObjetoA();
          break;
          }
    case 2:{
          ListadeObjetos P;
          P.mostrarobjetos();
          break;
          }
    case 3: ListadeObjetos p;
           p.todosmostrarobjetos();
   }

} while (opc != 5);
    return 0;
}


