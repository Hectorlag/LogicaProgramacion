#include <iostream>
using namespace std;

/* Hacer un programa que permita ingresar una lista de numeros que corta cuando se ingresa un cero.
   A partir de dichos datos informar el mayor de los numeros pares, la cantidad de numeros impares,
   el menor de los numeros primos. Hacer uso de las funciones anteriormente desarrolladas.
   */
   
//declaro las funciones
 bool pares(int n);
 int primo(int n);
 
int main(int argc, char** argv) {
  int n1,mayor,p,conimp,minp;
  n1=mayor=conimp=minp=0;
  bool num,h,bmp,bminp;
  num=h=p=bmp=bminp=0;
  
  cout<<"\n Ingrese un numero: ";
  cin>>n1;
  
  while(n1!=0){
  	
  	num=pares(n1);
  	if(num==1){
  		if(bmp==0){
  			mayor=n1;
  			bmp=1;
		  }
		  else{
		  	if(n1>mayor){
		  		mayor=n1;
			  }
		  }
	  }
	  //cuento los impares
	  else{
	  	conimp++;
	  }
	  
	  //recibo a la funcion primo
	  p=primo(n1);
	  if(p==1){
	  	if(bminp==0){
	  		minp=n1;
	  		bminp=1;
		  }
		  else{
		    if(n1<minp){
		    	minp=n1;
			}
		  }
	  }
	  
	  cout<<"\n Ingrese un numero: ";
      cin>>n1;
  }
  cout<<"\n El mayor de los numeros pares es: "<<mayor;
  cout<<"\n La cantidad de numeros impares es: "<<conimp;
  cout<<"\n El menor de los numeros primos es: "<<minp;



return 0;
}

bool pares(int n){
	if(n%2==0){
		return 1;
	}
	else{
		return 0;
	}
}

int primo(int n){
	int con=0;
	
	for(int i=1;i<=n;i++){
		if(n%i==0){
			con++;
		}
	}
	if(con==2){
		return 1;
	}
	else{
		return 0;
	}
}
