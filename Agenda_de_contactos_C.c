#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTOS 100
#define MAX_NOMBRE 50
#define MAX_TELEFONO 20

// Definición de la estructura de un contacto
struct Contacto {
    char nombre[MAX_NOMBRE];
    char telefono[MAX_TELEFONO];
};

// Función para agregar un contacto
void agregarContacto(struct Contacto agenda[], int *numContactos) {
    if (*numContactos >= MAX_CONTACTOS) {
        printf("La agenda esta llena. No se pueden agregar mas contactos.\n");
        return;
    }

    printf("Ingrese el nombre del contacto: ");
    scanf("%s", agenda[*numContactos].nombre);
    printf("Ingrese el número de telefono: ");
    scanf("%s", agenda[*numContactos].telefono);

    (*numContactos)++;
    printf("Contacto agregado correctamente.\n");
}

// Función para buscar un contacto por nombre
void buscarContacto(struct Contacto agenda[], int numContactos, char nombre[]) {
    int encontrado = 0;
    for (int i = 0; i < numContactos; i++) {
        if (strcmp(agenda[i].nombre, nombre) == 0) {
            printf("Nombre: %s, Telefono: %s\n", agenda[i].nombre, agenda[i].telefono);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("El contacto no se encuentra en la agenda.\n");
    }
}

// Función para eliminar un contacto por nombre
void eliminarContacto(struct Contacto agenda[], int *numContactos, char nombre[]) {
    int encontrado = 0;
    for (int i = 0; i < *numContactos; i++) {
        if (strcmp(agenda[i].nombre, nombre) == 0) {
            for (int j = i; j < *numContactos - 1; j++) {
                strcpy(agenda[j].nombre, agenda[j + 1].nombre);
                strcpy(agenda[j].telefono, agenda[j + 1].telefono);
            }
            (*numContactos)--;
            encontrado = 1;
            printf("Contacto eliminado correctamente.\n");
        }
    }
    if (!encontrado) {
        printf("El contacto no se encuentra en la agenda.\n");
    }
}

// Función para editar un contacto por nombre
void editarContacto(struct Contacto agenda[], int numContactos, char nombre[]) {
    int encontrado = 0;
    for (int i = 0; i < numContactos; i++) {
        if (strcmp(agenda[i].nombre, nombre) == 0) {
            printf("Ingrese el nuevo nombre del contacto: ");
            scanf("%s", agenda[i].nombre);
            printf("Ingrese el nuevo número de telefono: ");
            scanf("%s", agenda[i].telefono);
            printf("Contacto editado correctamente.\n");
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("El contacto no se encuentra en la agenda.\n");
    }
}

// Función principal
int main() {
    struct Contacto agenda[MAX_CONTACTOS];
    int numContactos = 0;
    int opcion;
    char nombre[MAX_NOMBRE];

    while (1) {
        printf("\nAgenda de Contactos\n");
        printf("1. Agregar contacto\n");
        printf("2. Buscar contacto\n");
        printf("3. Eliminar contacto\n");
        printf("4. Editar contacto\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarContacto(agenda, &numContactos);
                break;
            case 2:
                printf("Ingrese el nombre del contacto a buscar: ");
                scanf("%s", nombre);
                buscarContacto(agenda, numContactos, nombre);
                break;
            case 3:
                printf("Ingrese el nombre del contacto a eliminar: ");
                scanf("%s", nombre);
                eliminarContacto(agenda, &numContactos, nombre);
                break;
            case 4:
                printf("Ingrese el nombre del contacto a editar: ");
                scanf("%s", nombre);
                editarContacto(agenda, numContactos, nombre);
                break;
            case 5:
                printf("Saliendo del programa...\n");
                exit(0);
            default:
                printf("Opción no valida. Por favor, seleccione una opción valida.\n");
        }
    }

    return 0;
}