#include <iostream>
#include <string.h>


using namespace std;

struct Cita
{
    string persona1;
    string persona2;
    string lugarReunion;
};


int a,  i, d, h, opc, numeroCitas;
int m;
string textoTemporal;
string mes[12] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
string mes2[12]= {"1", "2", "3", "4", "5", "6", "7", "8" ,"9" , "10", "11" ,"12"};

bool  comprobar_fecha()
{
    cout<<"Por favor ingrese el año: ";
    cin>>a;
    cout<<"Por favor ingrese mes: ";
    cin >> textoTemporal;
    for (i=0; i<12; i++)
        if (mes[i] == textoTemporal){
            m=i+1;
    }else if (mes2[i]==textoTemporal)
            m=i+1;
    cout<<"Por favor ingrese dia: ";
    cin>>d;
    cout<<"Por favor ingrese la hora: ";
    cin>>h;

    if( h < 0 or h >= 24)
        return false;

    int dias_mes[] = {31, 28, 31, 30,31, 30, 31, 31, 30, 31, 30, 31};
    if((a%4 == 0 and a%100 != 0) or a%400 == 0)
        dias_mes[1]++;

    if(m < 1 or m > 12)
        return false;

        m = m-1;
        if(d <= 0 or d > dias_mes[m])
        return false;

      m=m+1;
    return true;
 }

int main()
{
    Cita *listaCitas = new Cita[10];
    do
    {
        cout << endl;
        cout << "           MENU DE OPCIONES       " << endl;
        cout << endl;
        cout << "1.- Crear una cita" << endl;
        cout << "2.- Mostrar todas las citas creadas" << endl;
        cout << "3.- Salir" << endl;
        cout << endl;
        cout << "Por favor ingrese una de las opciones, de 1 a 3: ";
        cin >> opc;
        switch(opc)
        {
        case 1:{cout << endl;

            bool correcta = comprobar_fecha();
            {
               if(correcta){
                       cout << "La fecha ingresada es CORRECTA "<<endl;
                       if (numeroCitas < 10)
                         {
                          cout << "Por favor ingrese el nombre de la primera persona: ";
                          cin >> listaCitas[numeroCitas].persona1;
                          cout << "Por favor ingrese el nombre de la segunda persona: ";
                          cin >> listaCitas[numeroCitas].persona2;
                          cout << "Por favor ingrese el lugar de la reunion: ";
                          cin >> listaCitas[numeroCitas].lugarReunion;
                          numeroCitas++;
                          } else
                          cout << "El arreglo esta lleno "  << endl;
                           }else
                           cout << "La fecha ingresada es INCORRECTA" << endl;
           };
        }
                break;
        case 2: cout << endl;
            if(numeroCitas==0){
            cout << "No hay ninguna Cita creada " <<endl;
            }else {           for (i=0; i<numeroCitas; i++)
                    cout << "Cita: la persona " << listaCitas[i].persona1<< " Se reunira con " << listaCitas[i].persona2
                         <<" en: "<<listaCitas[i].lugarReunion<<" en la fecha: "<<a<<"/"<<m<<"/"<<d<<"/"<<h<<endl;
            }
                break;
        case 3:cout << endl;
                cout << "Fin del programa, GRACIAS " << endl;
                break;

            default:cout << endl;
                cout << "Opcion desconocida!" << endl;
                break;
        }
    } while (opc != 3);

    return 0;
}
