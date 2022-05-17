/* Autor: Andriks Imanol Ruiz M�rtinez, Realizado: 07/04/2022
Escuela: Universidad del Valle de M�xico Campus Villahermosa
Materia: Programaci�n Estructurada
Ciclo: 01/2022

Este es un programa en Lenguaje C de la materia de Programaci�n Estructurada
Muestra el uso de:

    -Variables enteras, flotantes y en cadena
    -printf para mostrar mensajes y variables
    -fgets
    -scanf
    -El uso de include para las librer�as
    -Librer�as de la funci�n string.h
    -Uso de condicionales
    -archivos en cpp y tipo Header
    -#define MAX
    -Ciclos
    -fflush
    -Funciones
    -Comentarios para la documentaci�n interna del programa
*/
#include<stdio.h>
#include<stdlib.h>
#include"milibreria.h"
//Declaraciones globales
#define MAX 10
struct alumno { //Estructura, declaraciones globales
	char nombre[30];
	float promedio;
	int faltas;
};
int n=0; //Variable que dice cuantos alumnos hay en el arreglo
//Prototipos
int menu();
void agregar(struct alumno x[]);
void imprimir(struct alumno x[], int tipo);
void promedio(struct alumno x[]);
void Per(struct alumno x[]);
//main
int main(){
	//Declaraci�n de variab�es
	int op;
	struct alumno grupo[MAX];
	do{
		op=menu();
		switch(op){
			case 0: printf("Adios..\n");
				break;
			case 1: agregar(grupo);
				break;
			case 2: imprimir(grupo,0);
				break;
			case 3: imprimir(grupo,1);
				break;
			case 4: imprimir(grupo, 2);
				break;
			case 5: promedio(grupo);
				break;
			case 6: 
				break;
		}
	}while(op!=0);
	return 0;
}
//funciones
int menu(){
 	int opcion;
	printf("-------- MENU PRINCIPAL ---------\n");
	printf("0. Salir \n");
	printf("1. Agregar alumnos \n");
	printf("2. Imprimir \n");
	printf("3. Alumnos Aprobados \n");
	printf("4. Alumnos Reprobados \n");
	printf("5. Promedio del grupo \n");
	printf("6. Porcentaje de alumnos Aprobados \n");
	printf("--------------------------------------\n");
	opcion=leerd("Selecciona una opcion: ",0,6);
	return opcion;
}
void agregar(struct alumno x[]){
	int pregunta;
	while(n<MAX){
		leers("Nombre: ", x[n].nombre,30);
		x[n].promedio=leerf("Promedio: ",0,10);
		x[n].faltas=leerd("Faltas: ",0,32);
		n++; //hay que validar
		pregunta=leerd("Agregar otro alumno? (1-Si, 0-No)", 0, 1);
		if (pregunta==0) {
			break;
		}
	}
	if(n==MAX){
		printf("Arreglo lleno!!!\n");
		system("PAUSE");
	}
}
//La funcion imprimir el parametro tipo se le indica que va a imprimir
//0 a todos, 1 aprobados, 2 reprobados
void imprimir(struct alumno x[], int tipo){
	char mensaje[20];
	switch(tipo){
		case 0: strcpy(mensaje, "TOTALES	");
			break;
		case 1: strcpy(mensaje, "APROBADOS");
			break;
		case 2: strcpy(mensaje, "REPROBADOS");
			break;	
	}
	printf("----------------- ALUMNOS %s ----------------------------\n,", mensaje);
	printf("NO.ALUMNO\tNOMBRE\t\tFALTAS\tPROM\n");
	printf("----------------------------\n");
	for (int i=0;i<n;i++){ 
		switch(tipo){
			case 0: printf("%2d \t%-30s \t%2d \t%4.1f\n",i+1,x[i].nombre,x[i].faltas,x[i].promedio);
				break;
			case 1: if(x[i].promedio>=7){
					printf("%2d\t%-30s\t%2d\t%4.1f\n",i+1,x[i].nombre,x[i].faltas,x[i].promedio);
			}
				break;
			case 2: if(x[i].promedio<7){
					printf("%2d\t%-30s\t%2d\t%4.1f\n",i+1,x[i].nombre,x[i].faltas,x[i].promedio);
			}
			break;
		}
	}
	printf("----------------------------\n");
		system("PAUSE");
}
void promedio(struct alumno x[]){
	float suma=0, prom;
	for(int i =0;i<n;i++){
		suma=suma+x[i].promedio;	
	} 
	prom=suma/n;
		printf("PROMEDIO DEL GRUPO\n");
		printf("------------------------\n");
		printf("El promedio es %.1f\n: ", prom);
		printf("------------------------\n");
		printf("La calificaci�n es 5");
	}
void Per(struct alumno x[]){
	int porcentaje;
	printf("PORCENTAJE DE APROBADOS DEL GRUPO\n");
	printf("------------------------\n");
	for(int i =0;i<n;i++){
			porcentaje=100-(x[i].promedio*100/32);
			printf("%d%%:\n",porcentaje);
	}
	printf("------------------------\n");
	}
