#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct informacion
{
	int bytes_total;
	int operaciones_en_memoria;
	char tipo_operacion[30];
	
};

int main(){
	//Se abren los archivos de entrada y salida
	
	ifstream archivo_entrada;
	ofstream archivo_salida;
	
	//nombre_arch_e = nombre del archivo de entrada
	//nommbre_arch_s = nombre del archivo de salida
	
	char nombre_arch_e[30], nombre_arch_s[30];
	printf("Ingrese nombre del archivo\n");
	scanf("%s %s", nombre_arch_e, nombre_arch_s);

	nombre_arch_s.open(archivo_salida, ios::binary);
	archivo_entrada.open(nombre_arch_e, ios::binary);
	//Se comprueba si los archivos existen
	if (archivo_entrada.fail() || archivo_salida.fail()){
		cout <<"El archivo no se abrio correctamente" << endl;
		exit();
	}
	//i= en que linea esta
	int i=0;
	//se lee el archivo de entrada
	while(!archivo_entrada.eof()){
		//bytes = la cantidad de bytes en la memoria total
		//cant_operaciones = cantidad de operaciones que se deben hacer
		// tipo = el tipo de operacion que se debe hacer
		
		int bytes, cant_operacion;
		char tipo[30];
		if(i==0 || i==(cant_operacion+1)){
			//se guarda la informacion de la cantidad de bytes
			
			fread(&bytes, sizeof(int), 1, archivo_entrada); 
			informacion.bytes_total=bytes;
		}
		else if(i==1||(cant_operacion+2){
			//se guarda la informacion de la cantidad de operaciones
			
			fread(&cant_operacion, sizeof(int), 1, archivo_entrada);
			informacion.operaciones_en_memoria=cant_operacion;
		}
		else{
			//se guarda el tipo de operacion que se debe hacer
			
			fread(tipo, sizeof(char), 30, archivo_entrada);
			strcpy(informacion.tipo_operacion, tipo);
		}
	}


	



}