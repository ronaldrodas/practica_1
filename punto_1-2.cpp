
#include <iostream>

using namespace std;

struct ListadeObjetos
{
    string nombreObjeto;
    int serial;
};

int numeroObjeto=0;
int i;
int opc;

string textoTemporal;
int numeroTemporal;

int main()
{
    ListadeObjetos *listaClaseA = new ListadeObjetos[20];
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
        case 1:cout << endl;
                if (numeroObjeto < 20)
                {
                    cout << "Por favor ingrese el nombre del objeto: ";
                    cin >> listaClaseA[numeroObjeto].nombreObjeto;
                    cout << "Por favor ingrese el serial del objeto: ";
                    cin >> listaClaseA[numeroObjeto].serial;
                    numeroObjeto++;
                }
                else
                    cout << "El arreglo esta lleno "  << endl;
                break;
        case 2:cout << endl;
                   if(numeroObjeto==0){
                   cout << "No hay ningun objeto  en el arreglo " <<endl;
                   }else {
                         cout << "Por favor ingresa el nombre del objeto que quieres ver: ";
                         cin >> textoTemporal;
                         for (i=0; i<numeroObjeto; i++)
                                 if (listaClaseA[i].nombreObjeto == textoTemporal){
                                 cout << "Nombre: " << listaClaseA[i].nombreObjeto <<" serial: " << listaClaseA[i].serial<< endl;
                                 }else cout << "No hay ningun objeto con ese nombre en el arreglo " <<endl;
                        }
                  break;
        case 3: cout << endl;
                for (i=0; i<numeroObjeto; i++)
                    cout << "Nombre: " << listaClaseA[i].nombreObjeto<< " Serial: " << listaClaseA[i].serial<< endl;
                if(numeroObjeto==0){
                      cout << "No hay ningun objeto para mostar " <<endl;
                }
                break;
        case 4: cout << endl;
            if(numeroObjeto==0){
                  cout << "No hay ningun objeto para eliminar en el arreglo " <<endl;
            }else {
            cout << "Por favor ingresa el nombre del objeto que quieres borrar: ";
             cin >> textoTemporal;
            for (i=0; i<numeroObjeto; i++){
                if (listaClaseA[i].nombreObjeto == textoTemporal)
                    listaClaseA[i]=listaClaseA[i+1];
                numeroObjeto--;
                  }
                 }
                break;
        case 5:cout << endl;
                cout << "Fin del programa, GRACIAS " << endl;
                break;

            default:cout << endl;
                cout << "Opcion desconocida!" << endl;
                break;
        }
    } while (opc != 5);

    return 0;
}
