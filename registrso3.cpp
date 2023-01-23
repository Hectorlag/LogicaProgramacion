#include <iostream>
using namespace std;
struct cuentas{
	int num_cuenta;
	int estado;
	float saldo;
};
int estado_deudor();
void promedio_cuenta();
void cant_cuentas_por_estado();
void mayor_y_menor_saldo();
int buscar_cuenta_modificar_datos();
void eliminar_cuenta();
void ordenamiento_por_saldo();
void agregar_cliente();

//Declaro las variables globales
int n;
cuentas v[50]; 
int main(int argc, char** argv) {
	int i,op,posi,pos;
	  i=op=0;
	do{
		cout<<"\n Ingrese la cantidad de clientes: ";
	cin>>n;
	}while(n>50);
	
	//Inicializo los campos
	for(i=0;i<n;i++)    
	  { v[i].num_cuenta=0;
	    v[i].estado=0;
	    v[i].saldo=0;
	  }
	//Carga de los datos
	for(i=0;i<n;i++)
	 {
	 	do{
	 		cout<<"\n Ingrese el numero de cuenta (mayor a cero): ";
	 		cin>>v[i].num_cuenta;
		 }while(v[i].num_cuenta <0);
		 
		 do{
	 		cout<<"\n Ingrese el estado de la cuenta (1: acreedor  2: deudor   3: nulo): ";
	 		cin>>v[i].estado;
		 }while(v[i].estado <1 || v[i].estado>3);
		 
	 		cout<<"\n Ingrese el saldo de la cuenta: ";
	 		cin>>v[i].saldo;
	 }
	 //Impresion de los datos
	 for(i=0;i<n;i++)
	   { cout<<"\n Cuenta numero:"<<v[i].num_cuenta;
	     cout<<"\n Estado:"<<v[i].estado;
	     cout<<"\n Saldo:"<<v[i].saldo;
	   }
	//Menu de opciones
	 do{
	
	 cout<<"\n 1.Emitir un msj si existe un estado deudor: ";
	 cout<<"\n 2. Promedio de saldo de cada estado: ";
	 cout<<"\n 3. Cantidad de cuentas por cada tipo: ";
	 cout<<"\n 4. Datos de la cuenta de MAYOR y MENOR saldo: ";
	 cout<<"\n 5. Buscar una cuenta por su num y permitir modificar sus datos: ";
	 cout<<"\n 6. Eliminar cuenta: ";
	 cout<<"\n 7. listado de cuenta ord en forma decreciente por el saldo: ";
	 cout<"\n  8. Agregar cliente";
	 cout<<"\n 9. Salir";
	 cout<<"\n  Opcion: ";
	 cin>>op;
	 
	 switch(op)
	 {     case 1: posi=estado_deudor();
	               if(posi!=-1)
	                {  cout<<" \t CUENTA EN ESTADO DEUDOR";
	                   cout<<"\n Numero de cuenta: "<<v[posi].num_cuenta;
	                   cout<<"\n Estado: "<<v[posi].estado;
	                   cout<<"\n Sueldo: "<<v[posi].saldo;
					}
	 	          break;
	 	          
	 	   case 2: promedio_cuenta(); 
			       break;
				   
		   case 3: cant_cuentas_por_estado();       
	 	           break;
	 	   
			case 4: mayor_y_menor_saldo(); 
			        break;
			 
			case 5: pos=buscar_cuenta_modificar_datos();
			         if(pos==-1)
					 {  cout<<"\n Ese numero de cuenta no se encuentra"; 
					 }      
			        else
			        { cout<<"\n CAMBIAR LOS DATOS: ";
			          do{
	 		          cout<<"\n Ingrese el numero de cuenta (mayor a cero): ";
	 		          cin>>v[pos].num_cuenta;
		              }while(v[pos].num_cuenta <0);
		 
		              do{
	 		          cout<<"\n Ingrese el estado de la cuenta (1: acreedor  2: deudor   3: nulo): ";
	 		          cin>>v[pos].estado;
		              }while(v[pos].estado <1 || v[pos].estado>3);
		 
	 		          cout<<"\n Ingrese el saldo de la cuenta: ";
	 		          cin>>v[pos].saldo;
	                }
	                break;
	                
	          case 6: eliminar_cuenta();
			          break;
					  
		     case 7: ordenamiento_por_saldo();	
			 		 break;
			 		 
			 case 8: void agregar_cliente();
			         break;		 
					  
			case 9: cout<<"\n Salir";
			default: cout<<"\n Opcion no valida";		        
		}
		
	 
   }while(op!=9);
	return 0;
} 
int estado_deudor()
{  int pos=-1;
     for(int i=0;i<n;i++)
     {if(v[i].num_cuenta!=0)
      { if(v[i].estado==2)
        {  pos=i;
		}
	}
  }
	return pos;
}
void promedio_cuenta()
{   int cont1,cont2,cont3,acu1,acu2,acu3;
        cont1=cont2=cont3=acu1=acu2=acu3=0;
	float prom1,prom2,prom3;
	      prom1=prom2=prom3=0;
	   for(int i=0;i<n;i++)
	   { if(v[i].num_cuenta!=0)
	       { if(v[i].estado==1)
	         { acu1= acu1+v[i].saldo;
	           cont1++;
	         }
		   if(v[i].estado==2)
	       { acu2= acu2+v[i].saldo;
	          cont2++;
		   }
		   if(v[i].estado==3)
	       { acu3= acu3+v[i].saldo;
	          cont3++;
		   }
		 }
	   }
		 if(cont1!=0)
		  {prom1=acu1/cont1;
	      }
	      if(cont2!=0)
	      {
		  prom2=acu2/cont2;
	      }
	      if(cont3!=0)
		  {
		  prom3=acu3/cont3;
	      }
	     	
		 cout<<"\n El promedio de saldo de la cuenta acreedor es: "<<prom1<<endl;
		 cout<<"\nEl promedio de saldo de la cuenta deudor es: "<<prom2<<endl;
		 cout<<"\n El promedio de saldo de la cuenta nulo es: "<<prom3<<endl;
    
}

void cant_cuentas_por_estado()
{ int cant1,cant2,cant3;
      cant1=cant2=cant3=0;
       for(int i=0;i<n;i++)
       {if(v[i].num_cuenta!=0)
          {  if(v[i].estado==1)
            { cant1++;
		    }
		  if(v[i].estado==2)
		     { cant2++;
			 }
		  if(v[i].estado==3)
		     { cant3++;
			 }	 
	   }
     }
	    {cout<<"\n La cantidad de cuentas en estado acreedor es: "<<cant1<<endl;
		cout<<"\n La cantidad de cuentas en estado deudor es: "<<cant2<<endl;
		cout<<"\n La cantidad de cuentas en estado nulo es: "<<cant3<<endl; 
        }
}
void mayor_y_menor_saldo()
{ cuentas mayorsaldo;
  cuentas menorsaldo;
  mayorsaldo.saldo=-9999;
  menorsaldo.saldo=9999;
      for(int i=0;i<n;i++)
      {if(v[i].num_cuenta!=0)
         { if(v[i].saldo > mayorsaldo.saldo)
           { mayorsaldo=v[i];
		   }
		}
	  }
		//impresion de datos
	   {  cout<<"\t CUENTA MAYOR SALDO";
	      cout<<"\n Cuenta numero: "<<mayorsaldo.num_cuenta;
	      cout<<"\n Estado: "<<mayorsaldo.estado;
	      cout<<"\n Saldo: "<<mayorsaldo.saldo;  
	   }
	   
	   for(int i=0;i<n;i++)
	     {if(v[i].num_cuenta!=0)
	        {if(v[i].saldo < menorsaldo.saldo)
	          { menorsaldo=v[i];
		      }
		    }
	     }
		 		//impresion de datos
	  
	   {  cout<<"\t CUENTA MENOR SALDO";
	      cout<<"\n Cuenta numero: "<<menorsaldo.num_cuenta;
	      cout<<"\n Estado: "<<menorsaldo.estado;
	      cout<<"\n Saldo: "<<menorsaldo.saldo;  
	   }		
}
int buscar_cuenta_modificar_datos()
{  int x,pos;
    x=0;
    pos=-1;
    cout<<"\n Ingrese el numero de cuenta que desea buscar: ";
    cin>>x;
      for(int i=0;i<n;i++)
        {if(v[i].num_cuenta!=0)
        { if(v[i].num_cuenta==x)
           {  pos=i;
		   }
		}
	}
	return pos;
}
void eliminar_cuenta()
{   int p=0;
    bool ban=false;
    cout<<"\n Ingrese el nro cuenta que desea eliminar: ";
    cin>>p;
      for(int i=0;i<n;i++)
        { if(v[i].num_cuenta==p)
          {  ban=true;
            v[i].num_cuenta=0;
            v[i].estado=0;
            v[i].saldo=0;
		  }
		}
		if(ban==false)
		{ cout<<"\n El numero de cuenta no fue encontrado";
		}
		if(ban==true)
		{  cout<<"\n Numero de cuenta eliminada";
		}
}
void ordenamiento_por_saldo()  //ordenamiento decrec por saldo
{  cuentas aux;
      for(int i=0;i<n-1;i++)
        { for(int j=i+1;j<n;j++)
        {if(v[i].num_cuenta!=0)
          { if(v[i].saldo < v[j].saldo)
              { aux=v[i];
               v[i]=v[j];
               v[j]=aux;
		      }
		  }
		}
	  }
		//impresion de datos
		for(int i=0;i<n;i++)
		 { cout<<"\n Cuenta numero:"<<v[i].num_cuenta;
	       cout<<"\n Estado:"<<v[i].estado;
	       cout<<"\n Saldo:"<<v[i].saldo;
	     }	
}
void agregar_cliente()
{        do{
	 		cout<<"\n Ingrese el numero de cuenta (mayor a cero): ";
	 		cin>>v[n].num_cuenta;
		 }while(v[n].num_cuenta <0);
		 
		 do{
	 		cout<<"\n Ingrese el estado de la cuenta (1: acreedor  2: deudor   3: nulo): ";
	 		cin>>v[n].estado;
		 }while(v[n].estado <1 || v[n].estado>3);
		 
	 		cout<<"\n Ingrese el saldo de la cuenta: ";
	 		cin>>v[n].saldo;
	      
	      n=n+1;  //agrego un cliente
	      
	      for(int i=0;i<n;i++)
	   { cout<<"\n Cuenta numero:"<<v[i].num_cuenta;
	     cout<<"\n Estado:"<<v[i].estado;
	     cout<<"\n Saldo:"<<v[i].saldo;
	   }
}


