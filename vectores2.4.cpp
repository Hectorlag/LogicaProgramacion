#include <iostream>
using namespace std;
/*4. En un comercio se registran los importes de n ventas y sus formas de pago (1-contado 2-tarjeta). Realizar un
programa que permita acceder a:
a) datos de la mayor venta realizada de contado
b) datos de la menor venta realizada con tarjeta
c) total de ventas realizadas con forma de pago “contado”
d) total de ventas realizadas con forma de pago “tarjeta”
e) Listado de ventas realizadas de contado ordenado en forma decreciente por el importe
f) Listado de ventas realizadas con tarjeta, ordenado en forma decreciente por el importe*/
int main(){
	int n,i,j,op,aux,mayventac,menorventar,posmvc,posmenvt,cc,ct;
	n=i=j=op=aux=posmvc=cc=ct=posmenvt=0;
	mayventac=-9999;
	menorventar=9999;
	cout<<"\n ingresar la cantidad de ventas: ";
	cin>>n;
	
	//Declaro el vector
	int imp[n];    
	int fpago[n];
	
	//Inicializo el vector
	for(i=0;i<n;i++) 
	  {imp[i]=0;
	   fpago[i]=0;
	  }
	  
	  //carga de datos
	  for(i=0;i<n;i++)   
	    { cout<<"\n venta numero: "<<i+1;
	      cout<<"\n importe: ";
	      cin>>imp[i];
	      cout<<"\n Forma de pago: ";
	      cout<<"\n contado: (Ingrese 1) ";
	      cout<<"\n tarjeta: (Ingrese 2) ";
	      
	      do{
	    	cout<<"\n Ingrese una opcion de pago: ";
	    	cin>>fpago[i];
	    
		  }while(fpago[1]<0 || fpago[i]>2);
	   }
	   
	//Menu de opciones
	do{	
	    cout<<"\n 1.Mayor venta realizada de contado es: "<<endl;
	    cout<<"\n 2.Menor venta realizada con tarjeta es: "<<endl;
	    cout<<"\n 3.Total de ventas de contado es: "<<endl;
	    cout<<"\n 4.Total de ventas con tarjeta es: "<<endl;
	    cout<<"\n 5.Listado de ventas de contado en forma decreciente : "<<endl;
	    cout<<"\n 6.Listado de ventas con tarjeta en forma decreciente  : "<<endl;
	    cout<<"\n 8.Salir : "<<endl;
	    cout<<"\n Ingrese una opcion : "<<endl;
	    cin>>op;
	    switch(op)
	            {   case 1:   for(i=0;i<n;i++)
				               {  if((imp[i]> mayventac) && (fpago[i]==1))
				                  {mayventac=imp[i];
				                  posmvc=i;
							      }
							   }
							  cout<<"\n la mayor venta de contado es: "<<mayventac;
							  break; 
					case 2:   for(i=0;i<n;i++)
				               {  if((imp[i] < menorventar) && (fpago[i]==2))
				                  {menorventar=imp[i];
							      posmenvt=i+1;
							      }
							   }
							  cout<<"\n la menor venta con tarjeta es: "<<menorventar;
							  break; 
					case 3: cc=0;
					         for(i=0;i<n;i++)
					             {if(fpago[i]==1)
	                             {cc++;
							     }
							}
							  cout<<"\n la cantidad de ventas de contado es: "<<cc;
							  break; 
					case 4:  ct=0;
					         for(i=0;i<n;i++)
					        {if(fpago[i]==2)
	                           ct++;
							}
							  cout<<"\n la cantidad de ventas con tarjeta es: "<<ct;
							  break; 
					case 5:   //ordeno en forma decreciente los gastos de contado
					         for(i=0;i<n-1;i++)  
							   {for(j=i+1;j<n;j++)
							      {if(imp[i]<imp[j])
							        {aux=imp[i];
							         imp[i]=imp[j];
							         imp[j]=aux;
							         
							         aux=fpago[i];  //ordeno el indice que acompaña al gasto(forma de pago)
		                             fpago[i]=fpago[j];
		                             fpago[j]=aux;
							        }
							      }		  		  		  		  
		                       } 
		                
		                       for(i=0;i<n;i++)
    	                        { if(fpago[i]==1)
								    
								  cout<<"\n importe: "<<imp[i]<<"\t forma de pago: "<<fpago[i];
	                            }
		                       break;
		            case 6:
					        for(i=0;i<n-1;i++)   //ordeno en forma decreciente los gastos con tarjeta
							  {for(j=i+1;j<n;j++)
							      { if(imp[i] < imp[j])
							        { aux=imp[i];
								     imp[i]=imp[j];
									 imp[j]=aux;
									 
									 aux=fpago[i];       //ordeno el indice que acompaña al gasto(forma de pago)
				                      fpago[i]=fpago[j];
				                      fpago[j]=aux;			
							        }     
							      }  
				              }
				    
				                for(i=0;i<n;i++)
								   {if(fpago[i]==2)
								      cout<<"\n importe: "<<imp[i]<< "\t forma de pago: "<<fpago[i];
								   }
								break;         
					}               
	    }while(op!= 6);
	
	return 0;
}
