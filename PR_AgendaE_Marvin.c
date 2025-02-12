//proyecto repaso Marvin Antonio Martinez Martinez
// Agenda Electrónica

#include <stdio.h>
//#include <string.h>

#define max_contactos 100
#define max_citas 100
#define max_tareas 100

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
void mostrarContactos(struct Contacto contactos[], int posicion, int total);
int comparar_cadenas(char *cad1, char *cad2);
int buscarContacto(struct Contacto contactos[], int posicion, int total, char nombre[]);
void actualizarContacto(struct Contacto contactos[], int total);

void agregarCita(struct Cita citas[], int *num_citas);
void mostrarCitas(struct Cita citas[], int posicion, int total);
int buscarCita(struct Cita citas[], int posicion, int total, char cita[]);

int main(int argc, char const *argv[])
{
	struct Contacto contactos[max_contactos];
	struct Cita citas[max_citas];
	struct Tarea tareas[max_tareas];


	int num_contactos=0, num_citas =0;
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
	                		puts("Ingresa el nombre a buscar: ");
	                		fgets(nombre_buscado, 50, stdin);
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
		                		mostrarContactos(contactos, 0, num_contactos);
		                	}
		                	break;
		                case 4:
		                	actualizarContacto(contactos, num_contactos);
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
	                printf("1. Insertar Cita\n");
	                printf("2. Buscar Cita\n");
	                printf("3. Mostrar Citas\n");
	                printf("4. Volver al Menú Principal\n");
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
	                			puts("Cita no encintrada.");
	                		}
	                		break;

	                	case 3:
		                	if(num_citas== 0)
		                	{
		                		printf("No hay citas.\n");
		                	}else
		                	{
		                		puts("");
		                		mostrarCitas(citas, 0, num_citas);
		                	}
		                	break;
		                case 4: 
		                	printf("Regresando al menú prinipal...\n");
		                	break;
		                default: 
		                	printf("Opción inválida, intenta de nueezzz.\n");
	                }

	            }while(subopcion != 4 );
			
			break;

			case 3: 
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

void mostrarContactos(struct Contacto contactos[], int posicion, int total)
{
	if(posicion >= total)
	{
		return;
	}

	printf("\nNombre: %s", contactos[posicion].nombre);
	printf("Apellido: %s", contactos[posicion].a_paterno);
	printf("Teléfono: %s", contactos[posicion].telefono);
	printf("Email: %s", contactos[posicion].email);
	printf("----------\n");

	mostrarContactos(contactos, posicion +1, total);
}

int comparar_cadenas(char *cad1, char *cad2)
{
	while(*cad1 && *cad2)
	{
		char c1 = (*cad1>= 'A' && *cad1 <= 'Z') ? *cad1 + 32: *cad1;

		char c2 = (*cad2 >= 'A' && *cad2 <= 'Z') ? *cad2 +32: *cad2;

		if(c1 != c2)
		{
			return 0; //no iguales
		}

		cad1++;
		cad2++;
	}
	return (*cad1 == *cad2);
}

int buscarContacto(struct Contacto contactos[], int posicion, int total, char nombre[])
{
	if(posicion >= total)
	{
		return -1;
	}
	if(comparar_cadenas(contactos[posicion].nombre, nombre))
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
	fgets(nombre_buscado, 50, stdin);

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
		fgets(contactos[posicion].nombre, 50, stdin);
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

void mostrarCitas(struct Cita citas[], int posicion, int total)
{
	if(posicion >= total)
	{
		return;
	}

	printf("Descripción: %s", citas[posicion].descripcion);
	printf("Fecha de la cita: %s", citas[posicion].fecha);
	printf("Hora de la cita: %s", citas[posicion].hora);
	printf("-----------\n");

	mostrarCitas(citas, posicion +1, total);
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

void agregarTarea(struct Tarea tareas[], int *num_tareas)
{
	if(*num_tareas >= max_tareas)
	{
		puts("No se pueden agregar mas tareas.");
		return;
	}

	puts("");
}
