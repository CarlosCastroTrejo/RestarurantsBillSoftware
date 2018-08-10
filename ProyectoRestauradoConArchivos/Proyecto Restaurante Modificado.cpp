//Carlos Emiliano Casro Trejo A01422062 Jorge Romero Romanis A01423263
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include "Orden.h"
#include "Modificar.h"
#include "Factura.h"
#include "Menu.h"
#include "Corte.h"
using namespace std;
/*
 *\param alimentos[] Vector alimentos[]
 *\param precios[] Vector precios[]
 *\param numero Tamaño del vector alimentos[].
 Esta funcion solo despliega el menu de los alimentos junto con sus precios.
*/

void menu(string alimentos[],int precios[],int numero);
/*
 *\param NumeroDeOrden lleva la cuenta de cuantas ordenes se han generado
 *\param pedido[][][] Matriz pedido[][][]. LLeva la cuenta de los pedidos
 *\param CuentaDeNumerosDeArticulosPorOrden[] Vector que lleva las cuentas de cuantos articulos se han pedido por orden.
 *\param NombreDeLaOrden lleva el nombre al cual esta hecha la orden.
 *\param alimentos[] Vector alimentos[]
 *\param numero Tamaño del vector alimentos[].
 *\return  actualiza el arrgelo de pedido[][][].
 Con esta funcion el usuario ingresa el numero del alimento desplegado en el menu, y elige que cantidad requiere. La orden se actualiza en el arreglo pedido[numero de orden][numero de producto][cantidad de producto].
 */
int orden(int NumeroDeOrden,int pedido[100][100][2],int CuentaDeNumerosDeArticulosPorOrden[100],string NombreDeLaOrden, string alimentos[],int numero);
/*
 *\param NumeroDeOrden lleva la cuenta de cuantas ordenes se han generado
 *\param pedido[][][] Matriz pedido[][][]. LLeva la cuenta de los pedidos
 *\param CuentaDeNumerosDeArticulosPorOrden[] Vector que lleva las cuentas de cuantos articulos se han pedido por orden.
 *\param alimentos[] Vector alimentos[]
 *\param precios[] Vector precios[]
 *\param numero Tamaño del vector alimentos[].
 *\return  actualiza el arrgelo de pedido[][][].
 Esta funcion se encarga de modificar la orden que el usuario desea, modifica el producto y/o la cantidad.
 */
int modificar(int NumeroDeOrden,int pedido[100][100][2],int CuentaDeNumerosDeArticulosPorOrden[100],string alimentos[],int precios[],int numero);
/*
 *\param CuentaDeNumerosDeArticulosPorOrden[] Vector que lleva las cuentas de cuantos articulos se han pedido por orden.
 *\param pedido[][][] Matriz pedido[][][]. LLeva la cuenta de los pedidos
 *\param alimentos[] Vector alimentos[]
 *\param precios[] Vector precios[]
 *\param numero Tamaño del vector alimentos[].
 *\param VentaTotal[] Vector VentaTotal[].
 *\param NumeroDeOrden lleva la cuenta de cuantas ordenes se han generado
 *\param NombreDeLaOrden lleva el nombre al cual esta hecha la orden.
 *\return  actualiza el arrgelo de ventatotal[].
 Esta funcion se encarga de desplegar la factura total de todas las ordenes, esta funcion separa la factura por ordenes mostrando los productos y cantidad de cada productopor ordenes. Finalmente hace la suma de cada orden y muestra la venta total de la factura.
 */
void factura(int CuentaDeNumerosDeArticulosPorOrden[100],int pedido[100][100][2],string alimentos[],int precios[],int numero,int VentaTotal[1],int NumeroDeOrden,string NombreDeLaOrden);

void corte();

int main(){
    // Variables utilizadas en el menu y submenu
    string NombreDeLaOrden;
    int menuorden;
    string resmenu;
    const int numero=17;
    int NumeroDeOrden=0;
    string alimentos[numero]{"HAMBURGUESA SENCILLA","HAMBURGUESA DOBLE","QUESADILLA DE POLLO","QUESADILLA DE QUESO","SINCRONIZADAS","CHILAQUILES","ENCHILADAS","FLAUTAS","TOSTADAS","TACOS DE PASTOR","TORTA DE MILANESA","ALAMBRE","LICUADOS","REFRESCO","JUGO DE BOING","JUGO NATURAL","       "};
    int precios[numero]{45,75,25,20,27,35,35,28,23,10,30,40,17,13,10,15};
    //Variables para las funciones
    int pedido[100][100][2]{};//Matriz tridimensional de los pedidos a realizar
    int CuentaDeNumerosDeArticulosPorOrden[100]{};
    int VentaTotal[1]{}; // Matriz que almacena el total de lo vendido
    string NombresDeOrdenes[100]{};
 //Despliegue del menu
    menu(alimentos, precios, numero);
    cout<<endl;
    
    
    cout<<"A nombre de quien esta la orden?\n";
    getline(cin, NombreDeLaOrden);
   cout<<"Ya que viste nuestro menu de alimentos, te redireccionaremos a otro menu para que puedas hacer tu orden.\n";
   do{
       cout<<endl<<"Porfavor elige que deseas hacer:\n 1)Solicitar una nueva orden.\n 2)Realizar algún cambio en una orden.\n 3)Desplegar la factura completa.\n 4)Corte del dia(NOTA: solo se hace una vez al dia, los archivos se borraran si lo haces).\n 5)Salir.\n";
        cin>>menuorden;
        switch (menuorden) { //Condicional Switch para generar el menu general
            case 1:{
               orden(NumeroDeOrden, pedido, CuentaDeNumerosDeArticulosPorOrden,NombreDeLaOrden,alimentos,numero);
                NumeroDeOrden++; //Aumentamos en numero de orden
            }break;
            case 2:{
                modificar(NumeroDeOrden, pedido, CuentaDeNumerosDeArticulosPorOrden, alimentos, precios, numero);
            }break;
            case 3:{
                factura(CuentaDeNumerosDeArticulosPorOrden, pedido, alimentos, precios, numero, VentaTotal, NumeroDeOrden,NombreDeLaOrden);
            }break;
            case 4:{
                corte();
            }break;
            case 5:{
                cout<<"Adios!\nGracias por su visita!\n";
            }break;
            default:{
                cout<<"Este numero no esta en el menu, elige otro porfavor\n";\
            }break;
        }
    }while(menuorden!=5);
    system ("pause");
}






