#include <iostream>
#include<fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void corte(){
//    Variables
    string Nombres[100]{};// Variable que almacena los nombre de todas las facturas que se alamcenan en el libro de Nombres
    int icontador=0; //Contador del numero de nommbre que va a desplegar
    int TotalLocal=0; //Varible que almacena el total cada factura completas
    int TotalTotal=0; //Variable que almacena el total global de todas la facturas en conjunto
    string separador; // variable la cual almacenamos la linea del libro que nos interesa leer
    string productos[100]{}; //Varible string donde donde guardamos el segmento de string separador que equivale al de los prooductos
    int cantidad[100]{}; //Varible donde almacenas la cantidad de cada producto de la factura correspondiente
    int total[100]{}; //Varible donde almacenas el total de cada producto de la factura correspondiente
    string Basura; //Variable auxiliar donde almacenamos las lineas de los libros que no nos interesan
    string CantidadDeArticulos; // Variable string donde guardamos el segmento de string separador que equivale a la cantidad de articulos
    string Auxiliar; // varible auxiliar que nos ayuda a separar y convertir a entero
    int ArticulosDeOrden; //Variable donde guardamos que producto se pide en la factura correspiente
    int numeros=1;
    
    
//    Contador de Ordenes Totales
    ifstream archivo;
    archivo.open("Nombres.csv");
    while(!archivo.eof()){
        getline(archivo, Nombres[icontador], ',');
        icontador++;
    }
    archivo.close();
    TotalTotal=0;
    
//    Envio de Titulos al archivo de Cierre
    ofstream cierre;
    cierre.open("Cierre.csv");
    cierre << "Numero"<<","<<"Producto"<<","<<"Cantidad"<<","<<"Total"<<endl;
    cierre.close();
    
//    Paso de Datos del archivo a arreglos
    for(int i=0;i<icontador-1;i++){
        ifstream archivo;
        archivo.open(Nombres[i]+".csv");
        getline(archivo,Basura); //Envio de la primera linea de Datos a basura
        getline(archivo,CantidadDeArticulos);
        CantidadDeArticulos.erase(0,CantidadDeArticulos.find(',')+1);
        ArticulosDeOrden=stoi(CantidadDeArticulos); //Saber cuantos articulos se encuentran en esta orden
        getline(archivo,Basura); //Enviamos la tercera lines (titulos) a basura
        for(int j=0;j<ArticulosDeOrden;j++){
            getline(archivo,separador); //Mandamos a separador la linea que nos interesa (producto,cantida,total)
            productos[j]=separador.substr(0,separador.find(',')); //Mandamos a productos[], la primera parte de separador, ya que es el producto
            separador.erase(0,separador.find(',')+1); //Lo borramos una vez escaneado
            Auxiliar=separador.substr(0,separador.find(',')); //mandamos a auxiliar la cantidad
            cantidad[j]=stoi(Auxiliar); //Mandamos a cantidad[] la variable auxiliar en entero
            separador.erase(0,separador.find(',')+2); //Borramos la cantidad
            Auxiliar=separador.substr(0,separador.length()); //mandamos a auxiliar el total
            total[j]=stoi(Auxiliar); //Mandamos a total[], el auxiliar pero en entero
        }
        getline(archivo,Basura); // Enviamos la ultima linea a basura
        Basura.erase(0,Basura.find(','));//borramos la basura poco a poco hasta encontrar el numero total de la factura
        Basura.erase(0,Basura.find(',')+1);
        Basura.erase(0,Basura.find(',')+2);
        TotalLocal=stoi(Basura); // Mandamos a TotatLocal la variable basura pero en entero
        archivo.close();
     
//        Paso de Datos al archivo de Cierre
        ofstream cierre;
        cierre.open("Cierre.csv",ios::app); //Creamos un archivo de cierre
        for(int x=0;x<ArticulosDeOrden;x++){
            cierre<< numeros<< ','<<productos[x]<<','<<cantidad[x]<<','; //Mandamos al archivo de cierre todos nuestros arreglos
            TotalTotal+=total[x];
            cierre<<"$"<<total[x]<<endl;
            numeros++;
        }
        
    }
    cierre.close();
    cout<<"\nTu corte del dia se esta generando....\nCargando....\nCargando....\nSe genero satisfactoriamente\n";
    ofstream file;
    file.open("Cierre.csv",ios::app);
    file<<" "<<','<<" "<<','<<"Total del Dia:"<<','<<"$"<<TotalTotal<<endl; //Mandamos al archivo cierre nuestro TotalTotal
    file.close();
}

    
    

    
 