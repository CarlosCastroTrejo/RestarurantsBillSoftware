#include <iostream>
using namespace std;

void menu(string alimentos[],int precios[],int numero){
    
    cout<<"***** Bienvenidos al restaurante Borges&Charlies *****\n";
    cout<<endl;
    cout<<"           ****** Menú ******\n";
    cout<<"Numero"<<setw(20)<<"Producto"<<setw(22)<<"Precios"<<endl;
    for(int x=0;x<numero-1;x++){
        if(x>=9){
            cout<<x+1<<setw (29)<< alimentos [x]<<setw (13)<<"$"<< precios[x]<<endl;
        }else{
            cout<<x+1<<setw (30)<< alimentos [x]<<setw (13)<<"$"<< precios[x]<<endl;
        }
    }
}
