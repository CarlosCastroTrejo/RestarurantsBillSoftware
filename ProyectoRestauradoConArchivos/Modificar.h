#include <iostream>
#include <string>
using namespace std;



int modificar(int NumeroDeOrden,int pedido[100][100][2],int CuentaDeNumerosDeArticulosPorOrden[100],string alimentos[],int precios[],int numero){
    int NumeroDeOrdenAModificar,EleccionSubMenu,NumeroDeProductoAModificar,NuevaCantidad,NuevoProducto;
    string RespuestaSubMenuModificar;
    if(NumeroDeOrden==0){
        cout<<"\nNo se ha hecho ningun pedido\n";
    }
    else{
    do{
        cout<<"Que numero de orden deseas modificar?\n";
        cin>>NumeroDeOrdenAModificar;
        if(NumeroDeOrdenAModificar>NumeroDeOrden){
            cout<<"Este numero de orden no existe.\n";
        }
    }while(NumeroDeOrdenAModificar>NumeroDeOrden);
    //Despliegue de los productos de la orden previamente solicitada
    do{
        cout<<endl<<"Tu orden es:\n"<<endl;
        cout<<"Numero"<<setw(12)<<"Producto"<<setw(19)<<"Cantidad"<<endl;
        for(int x=0;x<CuentaDeNumerosDeArticulosPorOrden[NumeroDeOrdenAModificar-1];x++){
            
            cout<<x+1<<"        "<<alimentos[pedido[NumeroDeOrdenAModificar-1][x][0]-1]<<"        "<<pedido[NumeroDeOrdenAModificar-1][x][1]<<endl;
        }
        cout<<endl;
        //Despliegue del menu de modificacion
        do{
            cout<<"Que deseas modificar?\n 1)El producto\n 2)La cantidad\n 3)Quitar un producto\n";
            cin>>EleccionSubMenu;
            switch (EleccionSubMenu) {
                    //Modificacion del producto y Cantidad
                case 1:{
                    do{
                        cout<<"Que numero de producto deseas modificar?\n";
                        cin>>NumeroDeProductoAModificar;
                        if(NumeroDeProductoAModificar>CuentaDeNumerosDeArticulosPorOrden[NumeroDeOrdenAModificar-1]){
                            cout<<"Este numero de producto no existe en la orden\n";//revision de que el producto a modificar si exista en la orden
                        }
                    }while(NumeroDeProductoAModificar>CuentaDeNumerosDeArticulosPorOrden[NumeroDeOrdenAModificar-1]);
                    do{
                        cout<<"Que producto quieres ahora?\n";
                        cin>>NuevoProducto;
                        if(NuevoProducto>16){
                            cout<<"Este numero de producto no esta en el menu\n";//revision que el nuevo producto si se encuentre en el menu general de alimentos
                        }
                    }while(NuevoProducto>16);
                    cout<<"Cuantas quieres?\n";
                    cin>>NuevaCantidad;
                    pedido[NumeroDeOrdenAModificar-1][NumeroDeProductoAModificar-1][0]=NuevoProducto;//actualizacion de pedido
                    pedido[NumeroDeProductoAModificar-1][NumeroDeProductoAModificar-1][1]=NuevaCantidad;
                }break;
                    //Modificacion de la Cantidad de un producto
                case 2:{
                    do{
                        cout<<"Que numero de producto deseas modificar?\n";
                        cin>>NumeroDeProductoAModificar;
                        if(NumeroDeProductoAModificar>CuentaDeNumerosDeArticulosPorOrden[NumeroDeOrdenAModificar-1]){
                            cout<<"Este numero de producto no existe en la orden\n";//revision de que el producto a modificar si exista en la orden
                        }
                    }while(NumeroDeProductoAModificar>CuentaDeNumerosDeArticulosPorOrden[NumeroDeOrdenAModificar-1]);
                    cout<<"Cuantas quieres?\n";
                    cin>>NuevaCantidad;
                    pedido[NumeroDeProductoAModificar-1][NumeroDeProductoAModificar-1][1]=NuevaCantidad;
                }break;
                case 3:{
                    do{
                        cout<<"Que numero de producto deseas quitar?\n";
                        cin>>NumeroDeProductoAModificar;
                        if(NumeroDeProductoAModificar>CuentaDeNumerosDeArticulosPorOrden[NumeroDeOrdenAModificar-1]){
                            cout<<"Este numero de producto no existe en la orden\n";//revision de que el producto a modificar si exista en la orden
                        }
                    }while(NumeroDeProductoAModificar>CuentaDeNumerosDeArticulosPorOrden[NumeroDeOrdenAModificar-1]);
                    pedido[NumeroDeOrdenAModificar-1][NumeroDeProductoAModificar-1][0]=17;//actualizacion de pedido
                    pedido[NumeroDeOrdenAModificar-1][NumeroDeProductoAModificar-1][1]=0;
                }break;
                default:{
                    cout<<"Solo puedes elegir numeros entre el 1 y el 3\n";
                }break;
            }
        }while(EleccionSubMenu>3);
        cout<<"Quieres hacer otra modificacion a esta orden?(si/no)\n";
        cin>>RespuestaSubMenuModificar;//variable respuesta al menu de modificacion
    }while(RespuestaSubMenuModificar=="si");
    }
    return 0;
}





