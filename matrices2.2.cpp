/*Realizar un programa que permita ingresar una matriz de n filas y 4 columnas, cada fila representa 
un cliente y cada columna:
• código del cliente (valor entre 0 y 99)
• importe de la compra
• tipo de pago (0: efectivo 1: tarjeta)
• tipo de compra (0: mayorista 1:minorista)
 Determinar
a) El código del cliente que realizó la compra con mayor importe
b) Listado con los clientes que pagaron en efectivo
c) Listado con los clientes que pagaron con tarjeta
d) Ingresar un determinado código de cliente y determinar si el mismo se encuentra o no en la 
matriz. Si se encuentra mostrar todos sus datos.
e) Emitir un informe, que incluya el importe total de compras por tipo de compra
Mayorista: 99999
Minorista: 99999
f) Emitir dos listados por tipo de compra. Cada listado deberá estar ordenado en forma creciente 
por el importe de la venta:
Tipo de Compra: XXXXX
CódigoCliente Tipo Pago Importe
g) Ingresar un tipo de compra y una forma de pago, e informar la cantidad de clientes que 
realizaron compras según los datos ingresados
h) Generar otra matriz en la que cada fila represente un tipo de compra y cada columna una forma 
de pago. Cada componente de la matriz debe indicar la cantidad de clientes que realizaron un 
tipo de compra y pagaron en efectivo o tarjeta.
i) Buscar un cliente por su código, si se encuentra permitir modificar todos sus datos (importe, 
tipo pago, tipo compra)*/
#include <iostream>
using namespace std;


int main(int argc, char** argv) {
	int i,j,n,op,max,codmax,cod,totalcomprasmino,totalcomprasmay,aux,x,h,cantclientes,fila,col,z;
	i=j=n=op=cod=totalcomprasmino=totalcomprasmay=aux=x=h=cantclientes=fila=col=z=0;
	bool ban=false;
	int mc[2][2];
	
	do{
	cout<<"\n Ingrese la cantidad de clientes: ";
	cin>>n;
    }while(n<2);
    
     //Declaro la matriz
	int mat[n][4];
	 
    //Inicializo la matriz
	for(i=0;i<n;i++)
	  {for(j=0;j<4;j++)  
	       mat[i][j]=0;
		 } 
	  //Carga de datos
	  for(i=0;i<n;i++)
	  { 
	     do{
	    	cout<<"\n Ingrese el codigo del cliente: ";
	    	cin>>mat[i][0];
		 }while(mat[i][0]<0 || mat[i][0]>99);
	  
	     do{
	   	    cout<<"\n Ingrese el importe de la compra: ";
	   	    cin>>mat[i][1];
	     }while(mat[i][1] < 0);
	   
	     do{
	   	   cout<<"\n Ingrese el tipo de pago (0:Efectivo  1:Tarjeta): ";
	   	   cin>>mat[i][2];
	     }while(mat[i][2]<0 || mat[i][2]>1);
	   
	     do{
	   	   cout<<"\n Ingrese el tipo de compra (0:Mayorista  1:Minorista): ";
	   	   cin>>mat[i][3];
	     }while(mat[i][3] <0 || mat[i][3]> 1);
	  }
	  //Impresion de la matriz
	  for(i=0;i<n;i++)      
	     {  cout<<"\n Codigo del cliente: "<<mat[i][0];
	        cout<<"\n Importe de la compra: "<<mat[i][1];
	        cout<<"\n Tipo de pago: "<<mat[i][2];
	        cout<<"\n Tipo de compra: "<<mat[i][3];
		 }
	  //Menu de opciones
	  do{
	  	cout<<"\n 1.Codigo del cliente con la mayor compra: ";
	  	cout<<"\n 2.Listado de los clientes que pagaron en efectivo: ";
	  	cout<<"\n 3.Listado de los clientes que pagaron con tarjeta: ";
	  	cout<<"\n 4.Determinar si un cliente se encuentra y mostrar sus datos: ";
	  	cout<<"\n 5.Importe total por tipo de compras: ";
	  	cout<<"\n 6.Listados de compras ordenados en forma creciente por el importe de venta: ";
	  	cout<<"\n 7.Cantidad de clientes segun tipo de compras y forma de pago: ";
	  	cout<<"\n 8.Matriz nueva. Fila=tipo de compra. Columna=forma de pago: ";
	    cout<<"\n 9.Buscar cliente por su codigo, si esta permitir cambiar sus datos: ";
	    cout<<"\n 10. Salir: ";
	    cout<<"\n Opcion ";
	    cin>>op;
	    
	    switch(op)
	    
	       {       case 1: max= -9999;
		                     for(i=0;i<n;i++)
	                          { if(mat[i][1]>max) //pregunto si el importe es mayor al maximo
						        { max=mat[i][1];   //asigno el importe que tengo en la matriz al maximo
						          codmax=mat[i][0];  //tambien le asigno el codigo de cliente(indice asociado)
						       }
						    }
						    cout<<"\t CLIENTE MAYOR COMPRA";
						    cout<<"\n El codigo del cliente que realizo la mayor compra es: "<<codmax<<endl;
						    cout<<"\n El monto maximo es: "<<max<<endl;
						    break;
						    
				 case 2:   for(i=0;i<n;i++)
				            {   if(mat[i][2]==0) //pregunto si la forma de pago es en efectivo
				               { cout<<"\t CLIENTE QUE PAGO EN EFECTIVO";
							    cout<<"\n Codigo del cliente: "<<mat[i][0];
	                             cout<<"\n Importe de la compra: "<<mat[i][1];
	                             cout<<"\n Tipo de compra: "<<mat[i][3];
							   }
							   cout<<"\n ";
							 }
							 break; 
							 
				case 3:   for(i=0;i<n;i++)
				            {  if(mat[i][2]==1) //pregunto si la forma de pago es con tarjeta
				            
				               { cout<<"\t CLIENTE QUE PAGO CON TARJETA";
							     cout<<"\n Codigo del cliente: "<<mat[i][0];
	                             cout<<"\n Importe de la compra: "<<mat[i][1];
	                             cout<<"\n Tipo de compra: "<<mat[i][3];
							   }
						    }			 
				             break;  
				             
				case 4:		cout<<"\n Ingrese el codigo del cliente: ";
				            cin>>cod;
							ban=false; 
							for(i=0;i<n;i++)
							  {  if(mat[i][0]==cod) //pregunto si el codigo del cliente ingresa esta
							     { ban=true;
							       
							       cout<<"\n Importe de la compra: "<<mat[i][1];
	                               cout<<"\n Tipo de pago: "<<mat[i][2];
	                               cout<<"\n Tipo de compra: "<<mat[i][3];
							     
								 }
							  } 
							  if(ban==false)
							     cout<<"\n El codigo del cliente no se encontro"<<endl;
				 		       break;
				 		       
				case 5:      for(i=0;i<n;i++)
				              { if(mat[i][3]==0)  //calculo el total de compras mayoristas
				                 totalcomprasmay=totalcomprasmay + mat[i][1];
							  }	
							  for(i=0;i<n;i++)
							    { if(mat[i][3]==1)   //calculo el total de compras minoristas
							       totalcomprasmino=totalcomprasmino + mat[i][1];
							    }  
							 
							  cout<<"\n El total de compras minoristas es: "<<totalcomprasmay<<endl;	 
							  cout<<"\n El total de compras mayoristas es: "<<totalcomprasmino<<endl;
							  break; 
							  
					case 6:  for(i=0;i<n-1;i++)
					           { for(j=i+1;j<n;j++)
					             {if(mat[i][1] > mat[j][1]) //ordeno la matriz por el importe de compra
					             
					                {  aux=mat[i][0];
					                   mat[i][0]=mat[j][0];
					                   mat[j][0]=aux;
					                   
					                   aux=mat[i][1];
					                   mat[i][1]=mat[j][1];
					                   mat[j][1]=aux;
					                   
					                   aux=mat[i][2];
					                   mat[i][2]=mat[j][2];
					                   mat[j][2]=aux;
					                   
					                   aux=mat[i][3];
					                   mat[i][3]=mat[j][3];
					                   mat[j][3]=aux;
									}
							     }
						       }
						       cout<<"\t COMPRAS MAYORISTAS"<<endl;
						       for(i=0;i<n;i++)
						         {  if(mat[i][3] == 0)       //pregunto por fila si en la columna 3 se compro mayorista
						            { cout<<"\n Codigo: "<<mat[i][0];
						              cout<<"\n Importe: "<<mat[i][1];
						              cout<<"\n Forma de pago: "<<mat[i][2]<<endl;
						           }
						        }
						          cout<<"\t COMPRAS MINORISTAS"<<endl;
						         for(i=0;i<n;i++)
						         {  if(mat[i][3] == 1 )  //pregunto por fila si en la columna 3 se compro pro minorista
		                           {  cout<<"\n Codigo: "<<mat[i][0];
						              cout<<"\n Importe: "<<mat[i][1];
						              cout<<"\n Forma de pago: "<<mat[i][2];
								   }
							     }
								 break;
								 
					case 7:  do{
						         cout<<"\ Ingrese un tipo de compra: ";  
						         cin>>x;
					          }while( x<0 || x> 1);
					          
					          do{
					          	  cout<<"\n Ingrese una forma de pago: ";
					          	  cin>>h;
							  }while(h<0 || h> 1);
							  
							  for(i=0;i<n;i++)       //se calcula la cantidad de clientes que reunen las condiciones cargadas
							     { if(mat[i][3] ==x && mat[i][2]== h)
							       cantclientes++;
								 }
								 cout<<"\n La cantidad de clientes con esas condiciones son: "<<cantclientes<<endl;
								 break;
								 
					case 8:  for(i=0;i<2;i++)          //inicializamos la matriz de 2x2
					           { for(j=0;j<2;j++)
					              mc[i][j]=0;
				         	   }
								
								for(i=0;i<n;i++) //recorro la matriz original para extraer los datos solicitados
								  {
								  	 fila= mat[i][3]; //posicion fila para la matriz de conteo
								  	 col= mat[i][2];  //posicion columna para la matriz de conteo
								  	 
								  	 mc[fila][col]++; //sumo los datos solicitados en la variables
								  }	
								  for(i=0;i<2;i++)
								   { cout<<endl;
								   for(j=0;j<2;j++)
								     {
									 cout<<" | "<<mc[i] [j]<<" | ";
									 }
								   }
								   break;	 
					         			 
					case 9:   ban=false;
					          z=0;
					          do{
					          	cout<<"\n Ingrese el codigo del cliente: ";
					          	cin>>z;
					            }while(z<0 || z>99 );
					          	for(i=0;i<n;i++)
					          	  {  if(mat[i][0]==z) //preg si esta el cliente
					          	      ban=true;
					          	      //en el caso de estar permito modificar los datos requeridos
					          	     do{
	   	                               cout<<"\n Ingrese de nuevo importe de la compra: ";
	               	                   cin>>mat[i][1];
	                                 }while(mat[i][1] < 0);
	   
                            	     do{
	                            	   cout<<"\n Ingrese dd nuevo tipo de pago (0:Efectivo  1:Tarjeta): ";
    	   	                           cin>>mat[i][2];
	                                 }while(mat[i][2]<0 || mat[i][2]>1);
	   
	                                 do{
	   	                               cout<<"\n Ingrese de nuevo tipo de compra (0:Mayorista  1:Minorista): ";
	   	                               cin>>mat[i][3];
	                                 }while(mat[i][3] <0 || mat[i][3]> 1);
							     
								  }
					case 10:	cout<<"\n Salir "<<endl;  
								break;
				                default: cout<<"\n Opcion no valida"<<endl;
					            break;      	          				 
		   }
	    
	  }while(op!=11);
	
	return 0;
}
