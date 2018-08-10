#include <iostream>
using namespace std;
fstream archivo;
string Ordenar;

int orden(int NumeroDeOrden,int pedido[100][100][2],int CuentaDeNumerosDeArticulosPorOrden[100],string NombreDeLaOrden,string alimentos[],int numero){
    int ContadorDeArticulos=0;//variable que da valor al numero de productos ordenados por orden.
    string RespuestaSubMenuOrden;//variable de respuesta al menu de orden.
    int band=0;
    
    cout<<"Hola "<<NombreDeLaOrden<<" tu orden # "<<NumeroDeOrden+1<<endl;
    do{
        cout<<"Porfavor el nombre del producto, y enseguida cuantos vas a ordenar:\n";
        for(int y=0;y<=1;y++){
            
                if(y==0){
                    do{
                        band=0;
                   getchar();
                    getline(cin,Ordenar);
                        for(int x=0;x<Ordenar.length();x++){ //Cambiamos lo ingresado a ordenar a mayusculas para que no exista error con lo del arreglo de alimentos
                            Ordenar[x]=toupper(Ordenar[x]);
                        }
                for(int x=0;x<16;x++){
                    if(Ordenar==alimentos[x]){
                        pedido[NumeroDeOrden][ContadorDeArticulos][y]=x+1; //Checamos si lo ingresado realmente si se encuentra en alimentos[]
                        band=1;
                    }
                }
                        if(band==0){
                            cout<<"Este producto no existe. Porfavor teclea enter, y posteriormente haz tu orden de nuevo.\n"; //Si no existe desplegamos este mensaje
                        }
                        
                }while(band!=1);
                    
                }
                else{
                cin>>pedido[NumeroDeOrden][ContadorDeArticulos][y];//ingresa el pedido[numero de orden][numero de producto por orden][cantidad de producto]
                }
        }
        cout<<"Algo mas? (si/no): \n";
        cin>>RespuestaSubMenuOrden;
        ContadorDeArticulos++;//aumenta el numero de productos por orden
    }while(RespuestaSubMenuOrden=="si");
   
    CuentaDeNumerosDeArticulosPorOrden[NumeroDeOrden]=ContadorDeArticulos;//guarda el numero de productos que se realizo en esta orden
    return 0;
}





