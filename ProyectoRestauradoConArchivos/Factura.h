#include <iostream>
#include <fstream>

using namespace std;

void factura(int CuentaDeNumerosDeArticulosPorOrden[100],int pedido[100][100][2],string alimentos[],int precios[],int numero,int VentaTotal[1],int NumeroDeOrden,string NombreDeLaOrden){
    int ArticulosTotales=0;
        if(NumeroDeOrden==0){
        cout<<"\nNo se ha hecho ningun pedido\n";
    }
    else{
    int FacturaADesplegar=0;//variable contador de las ordenes
        VentaTotal[0]=0;
        
        for(int x=0;x<NumeroDeOrden;x++){
            ArticulosTotales+=CuentaDeNumerosDeArticulosPorOrden[x];
        }
        ofstream archivo;
        archivo.open(NombreDeLaOrden+".csv");
    cout<<endl<<"***** Factura completa de Borges&Charlies *****\n";
        archivo<<"La cuenta de la orden es:\n";
        archivo<<"Numero total de articulos comprados:"<<","<<ArticulosTotales<<endl;
        cout<<"Producto"<<setw(25)<<"Cantidad"<<setw(13)<<"Total\n";
        archivo<<"Producto"<<","<<"Cantidad"<<","<<"Total\n";
    do{
         cout<<"*******La cuenta de la orden "<<FacturaADesplegar+1<<" es:\n";
        for(int x=0;x<CuentaDeNumerosDeArticulosPorOrden[FacturaADesplegar];x++){
            cout<<alimentos[pedido[FacturaADesplegar][x][0]-1]<<setw(11)<<pedido[FacturaADesplegar][x][1]<<setw(14)<<"$"<<precios[pedido[FacturaADesplegar][x][0]-1]*pedido[FacturaADesplegar][x][1]<<endl;
            VentaTotal[0]=VentaTotal[0]+(precios[pedido[FacturaADesplegar][x][0]-1]*pedido[FacturaADesplegar][x][1]);
            archivo<<alimentos[pedido[FacturaADesplegar][x][0]-1]<<","<<setw(11)<<pedido[FacturaADesplegar][x][1]<<setw(14)<<","<<"$"<<precios[pedido[FacturaADesplegar][x][0]-1]*pedido[FacturaADesplegar][x][1]<<endl;
        }
        FacturaADesplegar++;//suma para si es que hay mas de 1 orden
        cout<<endl;
    }while(FacturaADesplegar<NumeroDeOrden);//realiza el ciclo hasta que el contador sea igual al contador(general) de ordendes
    cout<<endl<<setw(47)<<"__________"<<endl;
    cout<<setw(38)<<"Total de Ventas: "<<setw(5)<<"$"<<VentaTotal[0]<<endl;
        archivo<<setw(38)<<","<<"Total de Ventas: "<<setw(5)<<","<<"$"<<VentaTotal[0]<<endl;
        archivo.close();
        
        
        archivo.open("Nombres.csv",ios::app);
        archivo<<NombreDeLaOrden<<",";
        archivo.close();
        
        
    }
}
