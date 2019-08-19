#include <iostream>

using namespace std;

int i=0;
string textoTemporal;
int a, m, d, h, opc, numeroCitas;
string persona1;
string persona2;

class Fecha{
string ano;
string mes;
string dia;
string hora;
 public:

bool  comprobar_fecha()
{   string me[12] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
    string me2[12]= {"1", "2", "3", "4", "5", "6", "7", "8" ,"9" , "10", "11" ,"12"};
    int a, m, d, h;
 ano=a;
 mes=m;
 dia=d;
 hora=h;
    cout<<"Por favor ingrese el año: ";
    cin>>a;
    cout<<"Por favor ingrese mes: ";
    cin >> textoTemporal;
    for (i=0; i<12; i++)
        if (me[i] == textoTemporal){
            m=i+1;
    }else if (me2[i]==textoTemporal)
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


};

class Cita{
string persona1;
string persona2;
string lugarReunion;
Fecha objeto;
public:
friend class ClaseExterna;
void nombrep1(string p1){
   persona1=p1;
}
void nombrep2(string p2){
   persona2=p2;
}
};

class ClaseExterna{
Cita listacitas[10];
Cita persona1;
friend class Citas;

public:
friend class Cita;
   void cita(){
        Cita *listaCitas = new Cita[10];
        if (numeroCitas < 10)
        {
            cout << "Por favor ingrese el nombre de la primera persona: ";
            cin >> listaCitas[numeroCitas].persona1;
            cout << "Por favor ingrese el nombre de la segunda persona: ";
            cin >> listaCitas[numeroCitas].persona2;
            cout << "Por favor ingrese el lugar de la reunion: ";
            cin >> listaCitas[numeroCitas].lugarReunion;
            numeroCitas++;
        }
        else
            cout << "El arreglo esta lleno "  << endl;
    }

 void consultarCitas();
};

void ClaseExterna::consultarCitas()
{   Cita *listaCitas = new Cita[10];
    if(numeroCitas==0){
    cout << "No hay ninguna Cita creada " <<endl;
    }else {for (i=0; i<numeroCitas; i++)
cout << "Cita: la persona " << listaCitas[i].persona1<< " Se reunira con " << listaCitas[i].persona2
     <<" en: "<<listaCitas[i].lugarReunion<<" en la fecha: "<<a<<"/"<<m<<"/"<<d<<"/"<<h<<endl;
    }
}


int main()
{
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
    case 1: {Fecha p;
           bool correcta = p.comprobar_fecha();
           cout << "La fecha ingresada es CORRECTA "<<endl;
           if(correcta){
            ClaseExterna p;
            p.cita();          
              }
          }
          break;
     case 2:{ ClaseExterna p;
            p.consultarCitas();
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


