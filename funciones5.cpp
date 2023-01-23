#include <iostream>
using namespace std;

/* Hacer una funcion llamada PAGOS que reciba un monto FLOAT y una cantidad de pagos
   de TIPO ENTERO y que devuelva el monto de cada pago. Luego hacer un programa para ingresar
   10 ventas, para cada venta se conoce el monto y la cantidad de pagos, el programa debera
   mostrar la cantidad de pagos y el monto del pago para cada una de las ventas. 
  */
   
//Declaro la funcion
 float pagos(float monto, int p);
 
int main(int argc, char** argv) {
 
    int cuotas,pagot;
    cuotas=pagot=0;
    float m=0;
    
    for(int i=0;i<10;i++){
	
    cout<<"\n Ingrese el monto: ";
    cin>>m;
    cout<<"\n Ingrese la cantidad de pagos que desea realizar: ";
    cin>>cuotas;
    
    pagot=pagos(m,cuotas);
    cout<<"\n La cantidad de cuotas para esta venta es de: "<<cuotas;
	cout<<"\n El monto a pagar en esta venta es de: "<<pagot;
	}


return 0;
}

float pagos(float monto, int p){
	int cp=0;
	
	cp= monto/p;
	
	return cp;
}
