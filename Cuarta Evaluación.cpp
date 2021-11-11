#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct //se define la estructura
 {
	char titulo[100]; //sus variables
	char genero[25];
	int anio;
	char comentario[100];
		
}libro;//para registrar un libro leido

void escribiregistro(FILE*archivo)//funcion para registrar
{
	libro k;
	char opcion, option;
	//int today;
	//int *aptrtoday;// *?
do{
system("cls");//*Limpiar pantalla

printf("****************************KBOOKS****************************\n\n");
printf("\n\n\nTitulo del libro: ");
fflush(stdin);
gets(k.titulo);//k= estructura y a diferencia de scanf, gets permite hacer espacios max de 99 caracteres
printf("\nGeneros");
fflush(stdin);
gets (k.genero);
printf ("\nA%co: ",164);//El % para el 164 que es la ñ
scanf("%i",&k.anio);
printf ("Comentario: ");
fflush(stdin);
gets(k.comentario);
		
	fwrite(&k, sizeof(libro), 1, archivo);//Escribir el registro en el archivo.De k, del tamaño libro(4=titulo, genero, año y comentario) al archivo.		
printf("\n\n ¿Quiere continuar?: ");//para salir 
opcion=getche();
	
}while(opcion!= 'n');
	
}
	
void leeregistro(FILE*archivo){
	
libro k;
int tam=sizeof(libro);

rewind(archivo);//?*
	
while (fread (&k,tam,1,archivo))
{ //para imprimir en pantalla
printf ("titulo:%s generos: %s año: %i comentarios: %s \n_____________________\n",k.titulo,k.genero,k.anio,k.comentario);
}
}

int main(){

	
FILE *archivo;
int opcion; //para el menu
 
archivo=fopen("libros.dat","a+");//abrir, nombre y a+b para leer, escribir en el y en caso de no existir crear
if(archivo !=NULL){
	
do{
	system("title= KBOOKS");
	//system,("cls");
	system("color 03");//Dar color a la imagen de caracteres:)
	
	printf("****************************KBOOKS****************************\n"); //imagen con caracteres, mucho trabajo para hacer la palabra books, pero valio la pena probar
	printf("HOLAHOLAH       HOLAHOLA        HOLAHOLA    HOLA    HOLA\n");
	printf("HOLAHOLAHOL    HOLAHOLAHO      HOLAHOLAHO   HOLA   HOLA\n");                                                                
	printf("HOLA    HOLA  HOLA    HOLA    HOLA    HOLA  HOLA  HOLA\n");                                                                 
	printf("HOLA    HOL  HOLA      HOLA  HOLA      HOLA HOLA HOLA\n" );                                                            
	printf("HOLAHOLAHO   HOL        OLA  HOL        OLA HOLAHOLA\n");
	printf("HOLA    HOL  HOL        HOL  HOL        HOL HOLA HOLA\n");
	printf("HOLA    HOLA HOLA      HOLA  HOLA      HOLA HOLA  HOLA\n");                                                                
	printf("HOLAHOLAHOL   HOLAHOLAHOLA    HOLAHOLAHOLA  HOLA   HOLA\n");                                                                   
	printf("HOLAHOLAH       HOLAHOLA        HOLAHOLA    HOLA    HOLA\n");
 printf("Presiona una tecla");
 getch();
 system("cls");
 system("color 06");//Dar color al menu
 printf("****************************KBOOKS****************************\n");
 printf(" \n BIENVENID@ \n");
 printf("1.Registrar un libro\n2.Ver libros almacenados\n3.Ver frase reflexiva\n0.Salir del systema\n");
 printf("Proximante quiero que puedas registrar tus series, peliculas, animes y mangas. Con su calificacion del 1 al 10\n");
 printf(" pero, por ahora, espero disfrutes de almacenar tus libros aqui y puedas ver despues lo que sacaste de ellos\n");
 scanf("%i",opcion);
 
 switch(opcion){//evaluar la opcion que se quiere elegir del menu y ejecutar las funciones correspondientes
 	case 1:
 	escribiregistro(archivo); //funcion para registrar en nuestra estrucuta Libro                                          
 	break;
 	case 2:
 	system("cls");
 	leeregistro(archivo); //Funcion para mostrar
 	break;
 	case 3:
 	system("cls"); //Lindo detalle
 	system("color 40");
 	printf("****************************KBOOKS****************************\n");
 	printf("Tu mismo debes divertirte, la sociedad no te debe divertir a ti, exepto,\n por esos maravillosos libros de fabulosos autores que forman parte de ella\n");
	printf("KBOOKS by Karfex Company\n\n");
 	getch();
 	break;
 	case 0:
 	fclose(archivo);//Cerrar el archivo
 	system("cls");
 	printf("Hasta la vista Baby (me gusto la frase, creditos al video tutorial)");
 	printf("No olvides vistar el canal de youtube");
 	break;
 }
 
 getch();
 
 }while(opcion);
}
else 
printf ("Error al abrir el archivo");
   
return 0;}