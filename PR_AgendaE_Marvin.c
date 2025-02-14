//proyecto repaso Marvin Antonio Martinez Martinez
// Agenda Electrónica

#include <stdio.h>
#include <string.h>

#define max_contactos 10
#define max_citas 10
#define max_tareas 10

//estructuras
struct Contacto
{
	char nombre[50];
	char a_paterno[50];
	char telefono[10];
	char email[50];
};

struct Cita
{
	char descripcion[100];
	char fecha[15];
	char hora[10];
};

struct Tarea
{
	char descripcion[100];
	char fechaLimite[15];
	int prioridad; 
};


//prototipos de función
void agregarContacto(struct Contacto contactos[], int *num_contactos);
void mostrarContactos(struct Contacto contactos[], int num_contactos);
int comparar_cadenas(char *cad1, char *cad2);
int buscarContacto(struct Contacto contactos[], int posicion, int total, char nombre[]);
void actualizarContacto(struct Contacto contactos[], int total);
void eliminarContacto(struct Contacto contactos[], int *num_contactos);
//void eliminarSaltoLinea(char *cadena);

void agregarCita(struct Cita citas[], int *num_citas);
void mostrarCitas(struct Cita citas[], int num_citas);
int buscarCita(struct Cita citas[], int posicion, int total, char cita[]);
void cancelarCita(struct Cita citas[], int *num_citas);

void agregarTarea(struct Tarea tareas[], int *num_tareas);
void mostrarTareas(struct Tarea tareas[], int num_tareas);
void eliminarTarea(struct Tarea tareas[], int *num_tareas);
int buscarTarea(struct Tarea tareas[], int posicion, int total, char fechaLimite[]);

int main(int argc, char const *argv[])
{
	struct Contacto contactos[max_contactos];
	struct Cita citas[max_citas];
	struct Tarea tareas[max_tareas];


	int num_contactos=0, num_citas =0 ,num_tareas=0;
	int opcion, subopcion;
	char nombre_buscado[50];
	char cita_buscada[50];
	
	puts("\nBIENVENIDO USUARIO\n");
	
	do
	{
		puts("");
		
		printf("---- Agenda Electrónica ----\n");
		printf("1. Gestión de Contactos\n");
		printf("2. Gestión de Citas\n");
		printf("3. Gestión de Tareas\n");
		//printf("0. Salir\n");


		printf("\nSelecciona una opción: ");
		scanf("%d", &opcion);
		getchar();

		switch(opcion)
		{
			case 1: 
				do
				{
					printf("\n---> Gestión de Contactos\n");
	                printf("1. Insertar Contacto\n");
	                printf("2. Buscar Contacto\n");
	                printf("3. Mostrar Contactos\n");
	                printf("4. Actualizar Contacto\n");
	                printf("5. Eliminar Contacto\n");
	                printf("6. Volver al Menú Principal\n");
	                printf("Seleccione una opción: ");
	                scanf("%d", &subopcion);
	                getchar();
	                
	                switch(subopcion)
	                {
	                	case 1: 
	                		agregarContacto(contactos, &num_contactos);
	                		getchar();
	                		break;
	                	case 2: 
	                		if (num_contactos==0)
	                		{
	                			printf("No hay contactos registrados.\n");
	                			break;
	                		}



	                		puts("Ingresa el nombre a buscar: ");
	                		//scanf("%s", nombre_buscado);
	                		fgets(nombre_buscado, sizeof(nombre_buscado), stdin);
	                		nombre_buscado[strcspn(nombre_buscado, "\n")]='\0';

	                		//eliminarSaltoLinea(nombre_buscado); //elimina '\n'

	                		//nombre_buscado[strcspn(nombre_buscado, "\n")]=0;
	                		int posicion= buscarContacto(contactos,0,num_contactos,nombre_buscado);
	                		if(posicion != -1)
	                		{
	                			printf("Contacto encontrado: \n - %s - %s - %s - %s\n",contactos[posicion].nombre,
	                				contactos[posicion].a_paterno, contactos[posicion].telefono, contactos[posicion].email);
	                		}
	                		else
	                		{
	                			puts("Contacto no encontrado.");
	                		}
	                		break;

	                	case 3:
		                	if(num_contactos== 0)
		                	{
		                		printf("No hay contactos.\n");
		                	}else
		                	{
		                		mostrarContactos(contactos, num_contactos);
		                	}
		                	break;
		                case 4:
		                	actualizarContacto(contactos, num_contactos);
		                	break;
		                case 5:
		                	eliminarContacto(contactos, &num_contactos);
		                	break;

		                case 6: 
		                	printf("Regresando al menú prinipal...\n");
		                	break;
		                default: 
		                	printf("Opción inválida, intenta de nueezzz.\n");
	                }

				}while(subopcion != 6 );
				break;
				
				
			case 2: 
				do
				{
					printf("\n---> Gestión de Citas\n");
	                printf("1. Agregar Cita.\n");
	                printf("2. Buscar Cita.\n");
	                printf("3. Mostrar Citas.\n");
	                printf("4. Modificar Cita.\n");
	                printf("5. Cancelar/Eliminar Cita.\n");
	                printf("6. Volver al Menú Principal.\n");
	                printf("Seleccione una opción: ");
	                scanf("%d", &subopcion);
	                getchar();
	                
	                switch(subopcion)
	                {
	                	case 1:
	                		agregarCita(citas, &num_citas);

	                		break;
	                	case 2: 
	                		puts("Ingresa la cita a buscar: ");
	                		fgets(cita_buscada, 50, stdin);
	                		int posicion= buscarCita(citas ,0,num_citas,cita_buscada);
	                		if(posicion != -1)
	                		{
	                			printf("Cita encontrada: \n - %s - %s - %s\n",citas[posicion].descripcion,
	                				citas[posicion].fecha, citas[posicion].hora);
	                		}
	                		else
	                		{
	                			puts("Cita no encontrada.");
	                		}
	                		break;

	                	case 3:
		                	if(num_citas== 0)
		                	{
		                		printf("No hay citas.\n");
		                	}else
		                	{
		                		puts("");
		                		mostrarCitas(citas, num_citas);
		                	}
		                	break;
		                case 4:

		                case 5: 
		                	cancelarCita(citas, &num_citas);
		                	break;

		                case 6: 
		                	printf("Regresando al menú prinipal...\n");
		                	break;
		                default: 
		                	printf("Opción inválida, intenta de nueezzz.\n");
	                }

	            }while(subopcion != 6 );
			
			break;

			case 3: 
				do
				{
					printf("\n---> Gestión de Tareas\n");
					printf("1. Agregar Tarea\n");
					printf("2. Buscar Tarea\n");
					printf("3. Mostrar Tarea\n");
					printf("4. Actualizar Tarea\n");
					printf("5. Eliminar Tarea\n");
					printf("6. Volver al Menú Principal\n");
					printf("Seleccione una opción: ");
					scanf("%d", &subopcion);
					getchar();

					switch(subopcion)
					{
					case 1: 
						agregarTarea(tareas, &num_tareas);
						getchar();
						break;
					case 2: 
						printf("Ingresa la fecha de la tarea a buscar: (YYYY/MM/DD)");
						fgets(nombre_buscado, 50, stdin);
						int posicion= buscarTarea(tareas, 0, num_tareas, nombre_buscado);
						if(posicion != -1)
						{
							printf("Tarea encontrada: \n - Descripción: %s - Fecha Límite: %s - Prioridad: %d\n", tareas[posicion].descripcion, 
								tareas[posicion].fechaLimite, tareas[posicion].prioridad);
						}else
						{
							puts("Tarea no encontrada.");
						}
						break;
					case 3: 
						if(num_tareas==0)
						{
							printf("No hay Tareas.\n");
						}
						else
						{
							mostrarTareas(tareas, num_tareas);
						}
						break;

					case 4: 

					case 5: 
						eliminarTarea(tareas, &num_tareas);
						break;
					case 6:
						printf("Regresando al menú principal...\n");
						break;
					default: 
						printf("Opción invalida, intenta de nuevo.\n");
					}

				}while(subopcion != 6);
				break;

		}

	}while(1);

	return 0;
}

void agregarContacto(struct Contacto contactos[], int *num_contactos)
{
	if(*num_contactos >= max_contactos)
	{
		puts("No se pueden agregar más contactos.");
		return;
	};

	puts("Nombre: ");
	fgets(contactos[*num_contactos].nombre, 50, stdin);
	//scanf("%[^\n]", contactos[*num_contactos].nombre);
	puts("Apellido Paterno: ");
	fgets(contactos[*num_contactos].a_paterno, 50, stdin);
	//scanf("%[^\n]", contactos[*num_contactos].a_paterno);
	puts("Teléfono: ");
	fgets(contactos[*num_contactos].telefono, 15, stdin);
	//scanf("%[^\n]", contactos[*num_contactos].telefono);
	puts("Email: ");
	fgets(contactos[*num_contactos].email, 50, stdin);
	//scanf("%[^\n]", contactos[*num_contactos].email);

	printf("\nContacto agregado correctamente!!\n");

	(*num_contactos)++;
}

void mostrarContactos(struct Contacto contactos[], int num_contactos)
{
	if(num_contactos ==0)
	{
		printf("No hay contactos en la agenda\n");
		return;
	}

	printf("\n-> Lista de Contactos <-\n");
	for(int i =0; i<num_contactos; i++)
	{
		printf("\n[%d] Nombre: %s",i+1, contactos[i].nombre);
		printf("    Apellido: %s", contactos[i].a_paterno);
		printf("    Teléfono: %s", contactos[i].telefono);
		printf("    Email: %s", contactos[i].email);
		printf("----------\n");
	}
}

int comparar_cadenas(char *cad1, char *cad2)
{
	while(*cad1 && *cad2)
	{
		char c1 = (*cad1>= 'A' && *cad1 <= 'Z') ? *cad1 + 32: *cad1;

		char c2 = (*cad2 >= 'A' && *cad2 <= 'Z') ? *cad2 +32: *cad2;

		if(c1 != c2)
		{
			return c1 - c2;
		}

		cad1++;
		cad2++;
	}
	return *cad1 - *cad2;
}
/*
void eliminarSaltoLinea(char *cadena)
{
	size_t len = strlen(cadena);
	
	if(len > 0 && cadena[len -1]== '\n')
	{
		cadena[len-1]='\0';
	}
	
}*/
int buscarContacto(struct Contacto contactos[], int posicion, int total, char nombre[])
{
	if(posicion >= total)
	{
		return -1;
	}

	//nombre[strcspn(nombre, "\n")]=0;

	if(strcmp(contactos[posicion].nombre, nombre))
	{
		return posicion;
	}

	/*if(strcmp(contactos[posicion].nombre, nombre)== 0)
	{
		return posicion;
	}*/

	return buscarContacto(contactos, posicion +1, total, nombre );
}


void actualizarContacto(struct Contacto contactos[], int total)
{
	char nombre_buscado[50];
	int posicion, opcion;

	printf("Ingrese el nombre del contacto a actualizar: ");
	scanf("40%s",nombre_buscado);
	//fgets(nombre_buscado, 50, stdin);

	posicion = buscarContacto(contactos, 0, total, nombre_buscado);

	if (posicion== -1)
	{
		printf("Contacto no encontrado");
		return;
	}

	printf("Contacto emcontrado.\n");
	printf("1. Nombre: %s", contactos[posicion].nombre);
	printf("2. Apellido: %s", contactos[posicion].a_paterno);
	printf("3. Teléfono: %s", contactos[posicion].telefono);
	printf("4. Email: %s", contactos[posicion].email);
	printf("5. Cancelar Actualización.");

	printf("\nSelecciona el dato que desea actualizar: ");
	scanf("%d", &opcion);
	getchar();

	switch(opcion)
	{
	case 1: 
		printf("Ingresa el nuevo nombre: ");
		scanf("40%s", contactos[posicion].nombre);
		//fgets(contactos[posicion].nombre, 50, stdin);
		break;
	case 2: 
		printf("Ingresa el nuevo apellido: ");
		fgets(contactos[posicion].a_paterno, 50, stdin);
		break;
	case 3: 
		printf("Ingresa el nuevo teléfono: ");
		fgets(contactos[posicion].telefono, 50, stdin);
		break;
	case 4: 
		printf("Ingresa el nuevo email: ");
		fgets(contactos[posicion].email, 50, stdin);
		break;
	case 5:
		printf("Actualización cancelada...\n");
		return;
	default:
		printf("Opción no valida.\n");
		return;
	}
	printf("Contacto actualizado correctamente.\n");


}

void eliminarContacto(struct Contacto contactos[], int *num_contactos)
{
	//char nombre_buscado[50];
	int posicion;

	if(*num_contactos==0)
	{
		printf("No hay contactos para eliminar.\n");
		return;
	}

	mostrarContactos(contactos, *num_contactos);

	printf("Ingresa el número del contacto a elimainar.\n ");
	scanf("%d", &posicion);
	getchar();

	if(posicion < 1 || posicion > *num_contactos)
	{
		printf("Número invalido. Intenta de nuevo.\n");
		return;
	}


	posicion --;
	printf("Eliminando contacto: %s %s\n", contactos[posicion].nombre, contactos[posicion].a_paterno);

	for (int i = posicion; i < (*num_contactos)-1 ; i++)
	{
		contactos[i]= contactos[i+1];
	}
	//memset(&contactos[*num_contactos-1],0,sizeof(struct Contacto));

	(*num_contactos)--; 
	printf("Contacto eliminado correctamente.\n");
}

void agregarCita(struct Cita citas[], int *num_citas)
{
	if(*num_citas >= max_citas)
	{
		puts("No se pueden agregar más citas.");
		return;
	}


	puts("Descripción: ");
	fgets(citas[*num_citas].descripcion, 100, stdin);
	puts("Fecha de la cita: (YYYY/MM/DD)");
	fgets(citas[*num_citas].fecha, 50, stdin);
	puts("Hora de la cita: ");
	fgets(citas[*num_citas].hora, 50, stdin);

	printf("\nCita guardada correctamente!!\n");

	(*num_citas)++;
}

void mostrarCitas(struct Cita citas[], int num_citas)
{
	if(num_citas==0)
	{
		printf("No hay citas en la agenda");
		return;
	}
	printf("\n-> Lista de Citas <-\n");
	for(int i=0; i<num_citas; i++)
	{
		printf("\n[%d] Descripción: %s",i+1, citas[i].descripcion);
		printf("    Fecha de la cita: %s", citas[i].fecha);
		printf("    Hora de la cita: %s", citas[i].hora);
		printf("-----------\n");
	}
}


int buscarCita(struct Cita citas[], int posicion, int total, char cita[])
{
	if(posicion>= total)
	{
		return -1;
	}

	if(comparar_cadenas(citas[posicion].descripcion, cita))
	{
		return posicion;
	}

	return buscarCita(citas, posicion +1, total, cita);
}

void cancelarCita(struct Cita citas[], int *num_citas)
{
	int posicion;
	if(*num_citas==0)
	{
		printf("No hay contactos para eliminar. \n");
		return;
	}

	mostrarCitas(citas, *num_citas);

	printf("Ingresa el número de la cita a eliminar: \n");
	scanf("%d", &posicion);
	getchar();

	if(posicion < 1 || posicion > *num_citas)
	{
		printf("Número invalido. Intenta de nuevo.\n");
		return;
	}	

	posicion--;
	printf("Cancelando cita: %s", citas[posicion].descripcion);

	for(int i = posicion; i <(*num_citas)-1; i++)
	{
		citas[i]= citas[i+1];
	}

	(*num_citas)--;
	printf("Cita cancelada correctamente.\n");
}

void agregarTarea(struct Tarea tareas[], int *num_tareas)
{
	if(*num_tareas >= max_tareas)
	{
		puts("No se pueden agregar mas tareas.");
		return;
	}

	printf("Descripción: ");
	fgets(tareas[*num_tareas].descripcion, 50, stdin);
	printf("Fecha límite de entrega (YYYY/MM/DD): ");
	fgets(tareas[*num_tareas].fechaLimite, 50, stdin);
	printf("Prioriadad \n1. Alto\n2. Medio\n3. Bajo\n -> ");
	scanf("%d", &tareas[*num_tareas].prioridad);

	printf("\nTarea agregada correctamente!!\n");
	(*num_tareas)++;
}

void mostrarTareas(struct Tarea tareas[], int num_tareas)
{
	if(num_tareas==0)
	{
		printf("No hay tareas en la agenda\n");
		return;
	}
	printf("\n-> Lista de tareas <-\n");
	for(int i=0; i<num_tareas; i++)
	{
		printf("\n[%d]Descripción: %s", i+1, tareas[i].descripcion);
		printf("    Fecha límite de entrega: %s", tareas[i].fechaLimite);
		printf("    Prioridad: %d\n", tareas[i].prioridad);
		printf("------------\n");
	}
}

int buscarTarea(struct Tarea tareas[], int posicion, int total, char fechaLimite[])
{
	if(posicion>= total)
	{
		return -1;
	}
	if(comparar_cadenas(tareas[posicion].fechaLimite, fechaLimite))
	{
		return posicion;
	}
	return buscarTarea(tareas, posicion+1,total, fechaLimite);
}
void eliminarTarea(struct Tarea tareas[], int *num_tareas)
{
	int posicion;
	if(*num_tareas==0)
	{
		printf("No hay tareas para eliminar");
		return;
	}

	mostrarTareas(tareas, *num_tareas);

	printf("Ingresa el número de la tarea a eliminar: ");
	scanf("%d", &posicion);
	getchar();

	if(posicion <1|| posicion > *num_tareas)
	{
		printf("Número invalido. Intenta de nuevo.\n");
		return;
	}

	posicion--;
	printf("Eliminando tarea: %s", tareas[posicion].descripcion);

	for (int i = posicion; i < (*num_tareas); i++)
	{
		tareas[i]= tareas[i+1];
	}
	printf("Tarea eliminada correctamente.\n");
}

