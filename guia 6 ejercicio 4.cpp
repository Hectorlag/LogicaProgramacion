#include <iostream>
using namespace std;

/* Una compania de turismo aventura registro los paquetes vendidos durante la ultima temporada
   vacacional, para cada venta se ingreso: NRO DE PAQUETE, CANTIDAD DE PERSONAS INCLUIDAS, PRECIO
   POR PERSONA, HS TOTALES DE ACTIVIDADES, TIPO DE AVENTURA(m=montaña, t=traekking, r=rafting
   b=bicicleta). El lote se encuentra agrupado por tipo de aventura y corta con nro de paquete cero
   a) La cantidad de paquetes vendidos de cada tipo de aventura.
   b) La cantidad total de persona que disfrutaron las aventuras durante la temporada.
   c) El total recaudado por cada venta.
   d) La venta con mayor importe de cada tipo de aventura
   e) El paquete con menos horas incurridas y en que tipo de aventura fue.
   */

int main(int argc, char** argv) {
	
	int n,numpaq,cantpers,preunita,hs,tipoav,tipoactual,conta,acut,pv,mayor,nact,min;
	n=numpaq=cantpers=preunita=hs=tipoav=tipoactual=acut=min=0;
	bool ban;
	ban=0;
	
	cout<<"\n Ingrese el numero de paquete: ";
	cin>>numpaq;
	
	cout<<"\n Cantidad de personas incluidas: ";
	cin>>cantpers;
	
	cout<<"\n Precio por persona: ";
	cin>>preunita;
	
	cout<<"\n Horas totales de actividades: ";
	cin>>hs;
	
	cout<<"\n Ingrese el tipo de aventura: ";
	cin>>tipoav;
	
	while(numpaq !=0){
		
		tipoactual=tipoav;
		
		conta=pv=mayor=0;
		
		
		while(tipoav==tipoactual){
			conta++;                 //cantidad de paquetes por tipo de aventura
			acut= acut + cantpers;   //cantidad de personas totales
			
		    //calculo el precio de venta 
		    pv = cantpers *preunita;  //precio por cada venta
		    
		    cout<<"\n El precio para cada venta es: "<<pv;   //muestro el punto C
		         
		         if(pv >mayor){
		         	mayor=pv;
				 }
				 //busco el minimo
				 if(ban==0){
				 	min=hs;
				 	nact=numpaq;
				 	ban=1;
				 }
				 else{
				 	if(hs<min){
				 		min=hs;
				 		nact=numpaq;
					 }
				 }
		
			cout<<"\n Ingrese el numero de paquete: ";
	        cin>>numpaq;
	
	        cout<<"\n Cantidad de personas incluidas: ";
	         cin>>cantpers;
	
	        cout<<"\n Precio por persona: ";
	        cin>>preunita;
	
	        cout<<"\n Horas totales de actividades: ";
	        cin>>hs;
	
	        cout<<"\n Ingrese el tipo de aventura: ";
	        cin>>tipoav;	
		}
		//muestro el punto A
		cout<<"\n La cantidad de paquetes vendidos para la "<<tipoactual<< "\t es: "<<conta;
		
		//muestro el punto D
		cout<<"\n El precio mayor para esta aventura es: "<<mayor;
	}
	//muestro el punto B
	cout<<"\n La cantidad de personas totales es: "<<acut;
	
	//muestro el punto E
    cout<<"\n Las menos horas incurridas fue: "<<min<<"\t y el paqute fue: "<<nact;


return 0;
}
