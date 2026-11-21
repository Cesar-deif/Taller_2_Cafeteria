#include <stdio.h>
#include <string.h>
#include <math.h>
#include "funciones.h"

float validarFloatRango(float a, float b){
    float num;
    int val;
    do
    {
        val = scanf("%f",&num);
        while ((getchar())!='\n');
        if (num < a || num > b || val != 1)
        {
            printf("Error: el valor ingresado es incorrecto\n");
        }
    } while (num < a || num > b || val != 1);
    return num;
}

void leerCadena(char *cadena, int n){
    fgets(cadena,n,stdin);
    int len = strlen(cadena) - 1;
    cadena[len] = '\0';
}

void registrarIngrediente(ingrediente *ingredientes, int *contador, float *gastos) {
    if (*contador < 25) {
        float costo;

        ingredientes[*contador].numingre = *contador + 1;

        printf("\nIngrese el nombre del ingrediente: ");
        leerCadena(ingredientes[*contador].nomingre, 100);

        printf("\nIngrese la cantidad: ");
        ingredientes[*contador].cantidad = validarFloatRango(0, 100000);

        printf("\nCuanto costo este ingrediente: ");
        costo = validarFloatRango(0, 100000);

        *gastos += costo;
        (*contador)++;
        printf("\nIngrediente registrado correctamente.\n");
    } else {
        printf("Error: Maximo de ingredientes alcanzados\n");
    }
}

void mostrarIngredientes(ingrediente *ingredientes, int contador) {
    printf("\nNumero de Ingrediente\t\tNombre\t\t\tCantidad\n");
    for (int i = 0; i < contador; i++) {
        printf("%d\t\t\t\t%s\t\t%.2f\n",
               ingredientes[i].numingre,
               ingredientes[i].nomingre,
               ingredientes[i].cantidad);
    }
}

void aumentarDisminuirIngrediente(ingrediente *ingredientes, int contador) {
    int buscarId;
    int encontrado = -1;
    int confirmar;
    float cambio;

    printf("Ingrese el numero del ingrediente a modificar (1 a 25): ");
    buscarId = (int)validarFloatRango(0, 25);

    for (int i = 0; i < contador; i++) {
        if (ingredientes[i].numingre == buscarId) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("\nError ingrediente no encontrado\n");
        return;
    }

    printf("\nIngrediente encontrado:\n");
    printf("\nNumero: %d | Nombre: %s | Cantidad actual: %.2f\n",
           ingredientes[encontrado].numingre,
           ingredientes[encontrado].nomingre,
           ingredientes[encontrado].cantidad);

    printf("Es el ingrediente que desea alterar? (0) No / (1) Si: ");
    confirmar = (int)validarFloatRango(0, 1);

    if (confirmar == 0) {
        printf("Operacion cancelada. Volviendo al menu...\n");
        return;
    }

    printf("Ingrese la cantidad que desea agregar o disminuir: ");
    cambio = validarFloatRango(-ingredientes[encontrado].cantidad, 10000);
    ingredientes[encontrado].cantidad += cambio;
    printf("Nueva cantidad de %s: %.2f\n",
           ingredientes[encontrado].nomingre,
           ingredientes[encontrado].cantidad);
}

void ingresarSopa(sopa *sopas, int *contsopa, ingrediente *ingredientes, int contIngredientes) {
    if (*contsopa >= 3) {
        printf("Error: Maximo de sopas alcanzado (3).\n");
        return;
    }

    mostrarIngredientes(ingredientes, contIngredientes);

    int indicesUsados[25];
    float cantidadesUsadas[25];
    int numSelecciones = 0;
    int estadoIngredientes;

    do {
        printf("\nIngrese el numero del ingrediente (1 a 25): ");
        int idBuscado = (int)validarFloatRango(1, 25);
        int idxEncontrado = -1;

        for (int i = 0; i < contIngredientes; i++) {
            if (ingredientes[i].numingre == idBuscado) {
                idxEncontrado = i;
                break;
            }
        }

        if (idxEncontrado == -1) {
            printf("Error: ingrediente no encontrado.\n");
            estadoIngredientes = 1;
        } else {
            printf("Ingrediente seleccionado: %s (Disponible: %.2f)\n",
                   ingredientes[idxEncontrado].nomingre,
                   ingredientes[idxEncontrado].cantidad);

            printf("Ingrese la cantidad necesaria para la sopa: ");
            float cantNecesaria = validarFloatRango(0, 100000);

            if (cantNecesaria > ingredientes[idxEncontrado].cantidad) {
                printf("Error: la cantidad necesaria supera la cantidad disponible del ingrediente.\n");
                for (int j = 0; j < numSelecciones; j++) {
                    ingredientes[indicesUsados[j]].cantidad += cantidadesUsadas[j];
                }
                return;
            }

            ingredientes[idxEncontrado].cantidad -= cantNecesaria;
            indicesUsados[numSelecciones] = idxEncontrado;
            cantidadesUsadas[numSelecciones] = cantNecesaria;
            numSelecciones++;

            printf("Se descontaron %.2f de %s (Restante: %.2f).\n",
                   cantNecesaria,
                   ingredientes[idxEncontrado].nomingre,
                   ingredientes[idxEncontrado].cantidad);

            printf("1) falta ingredientes | 2) son suficientes: ");
            estadoIngredientes = (int)validarFloatRango(1, 2);
        }
    } while (estadoIngredientes == 1);

    sopas[*contsopa].numsopa = *contsopa + 1;

    printf("Ingrese el nombre de la sopa: ");
    leerCadena(sopas[*contsopa].nomsopa, 100);

    printf("cuantos platos de sopa rinde: ");
    sopas[*contsopa].cantidad = (int)validarFloatRango(0, 10000);

    (*contsopa)++;
    printf("Sopa registrada correctamente.\n");
}

void ingresarSegundo(segundo *segundos, int *contsegundo, ingrediente *ingredientes, int contIngredientes) {
    if (*contsegundo >= 4) {
        printf("Error: Maximo de segundos alcanzado (4).\n");
        return;
    }

    mostrarIngredientes(ingredientes, contIngredientes);

    int indicesUsados[25];
    float cantidadesUsadas[25];
    int numSelecciones = 0;
    int estadoIngredientes;

    do {
        printf("\nIngrese el numero del ingrediente (1 a 25): ");
        int idBuscado = (int)validarFloatRango(1, 25);
        int idxEncontrado = -1;

        for (int i = 0; i < contIngredientes; i++) {
            if (ingredientes[i].numingre == idBuscado) {
                idxEncontrado = i;
                break;
            }
        }

        if (idxEncontrado == -1) {
            printf("Error: ingrediente no encontrado.\n");
            estadoIngredientes = 1;
        } else {
            printf("Ingrediente seleccionado: %s (Disponible: %.2f)\n",
                   ingredientes[idxEncontrado].nomingre,
                   ingredientes[idxEncontrado].cantidad);

            printf("Ingrese la cantidad necesaria para el segundo: ");
            float cantNecesaria = validarFloatRango(0, 100000);

            if (cantNecesaria > ingredientes[idxEncontrado].cantidad) {
                printf("Error: la cantidad necesaria supera la cantidad disponible del ingrediente.\n");
                for (int j = 0; j < numSelecciones; j++) {
                    ingredientes[indicesUsados[j]].cantidad += cantidadesUsadas[j];
                }
                return;
            }

            ingredientes[idxEncontrado].cantidad -= cantNecesaria;
            indicesUsados[numSelecciones] = idxEncontrado;
            cantidadesUsadas[numSelecciones] = cantNecesaria;
            numSelecciones++;

            printf("Se descontaron %.2f de %s (Restante: %.2f).\n",
                   cantNecesaria,
                   ingredientes[idxEncontrado].nomingre,
                   ingredientes[idxEncontrado].cantidad);

            printf("1) falta ingredientes | 2) son suficientes: ");
            estadoIngredientes = (int)validarFloatRango(1, 2);
        }
    } while (estadoIngredientes == 1);

    segundos[*contsegundo].numsegundo = *contsegundo + 1;

    printf("Ingrese el nombre del segundo: ");
    leerCadena(segundos[*contsegundo].nomsegundo, 100);

    printf("cuantos platos de segundo rinde: ");
    segundos[*contsegundo].cantidad = (int)validarFloatRango(0, 10000);

    (*contsegundo)++;
    printf("Segundo registrado correctamente.\n");
}

void mostrarMenu(sopa *sopas, int contsopa, segundo *segundos, int contsegundo) {
    printf("\nSOPAS\n");
    printf("\nNumero\t\tNombre\t\tCantidad\n");
    for (int i = 0; i < contsopa; i++) {
        printf("%d\t\t%s\t\t%d\n",
               sopas[i].numsopa,
               sopas[i].nomsopa,
               sopas[i].cantidad);
    }

    printf("\nSegundos\n");
    printf("\nNumero\t\tNombre\t\tCantidad\n");
    for (int i = 0; i < contsegundo; i++) {
        printf("%d\t\t%s\t\t%d\n",
               segundos[i].numsegundo,
               segundos[i].nomsegundo,
               segundos[i].cantidad);
    }
}

void modificarPlatillo(sopa *sopas, int contsopa, segundo *segundos, int contsegundo) {
    printf("Que platillo desea modificar?\n");
    printf("1) Sopa\n");
    printf("2) Segundo\n");
    printf(">> ");
    int tipo = (int)validarFloatRango(1, 2);

    mostrarMenu(sopas, contsopa, segundos, contsegundo);

    if (tipo == 1) {
        if (contsopa == 0) {
            printf("No hay sopas registradas.\n");
            return;
        }

        printf("\nIngrese el numero de la sopa que desea modificar (1 a 3): ");
        int idBuscado = (int)validarFloatRango(1, 3);
        int encontrado = -1;

        for (int i = 0; i < contsopa; i++) {
            if (sopas[i].numsopa == idBuscado) {
                encontrado = i;
                break;
            }
        }

        if (encontrado == -1) {
            printf("Error: Sopa no encontrada.\n");
            return;
        }

        printf("Sopa seleccionada: %s (Cantidad actual: %d)\n",
               sopas[encontrado].nomsopa,
               sopas[encontrado].cantidad);
        printf("Ingrese la cantidad que desea agregar o disminuir (%d a 10000): ",
               -sopas[encontrado].cantidad);
        int cambio = (int)validarFloatRango((float)(-sopas[encontrado].cantidad), 10000);
        sopas[encontrado].cantidad += cambio;

        printf("Nueva cantidad de %s: %d\n",
               sopas[encontrado].nomsopa,
               sopas[encontrado].cantidad);

    } else {
        if (contsegundo == 0) {
            printf("No hay segundos registrados.\n");
            return;
        }

        printf("\nIngrese el numero del segundo que desea modificar (1 a 4): ");
        int idBuscado = (int)validarFloatRango(1, 4);
        int encontrado = -1;

        for (int i = 0; i < contsegundo; i++) {
            if (segundos[i].numsegundo == idBuscado) {
                encontrado = i;
                break;
            }
        }

        if (encontrado == -1) {
            printf("Error: Segundo no encontrado.\n");
            return;
        }

        printf("Segundo seleccionado: %s (Cantidad actual: %d)\n",
               segundos[encontrado].nomsegundo,
               segundos[encontrado].cantidad);
        printf("Ingrese la cantidad que desea agregar o disminuir (%d a 10000): ",
               -segundos[encontrado].cantidad);
        int cambio = (int)validarFloatRango((float)(-segundos[encontrado].cantidad), 10000);
        segundos[encontrado].cantidad += cambio;

        printf("Nueva cantidad de %s: %d\n",
               segundos[encontrado].nomsegundo,
               segundos[encontrado].cantidad);
    }
}

void ingresarPedido(sopa *sopas, int contsopa, segundo *segundos, int contsegundo, float *ganancias) {
    printf("Seleccione el tipo de pedido:\n");
    printf("1) Sopa\n");
    printf("2) Segundo\n");
    printf("3) Almuerzo\n");
    printf(">> ");
    int opcion = (int)validarFloatRango(1, 3);

    mostrarMenu(sopas, contsopa, segundos, contsegundo);

    if (opcion == 1) {
        if (contsopa == 0) {
            printf("error se acabaron las sopas\n");
            return;
        }

        printf("\nIngrese el numero de la sopa (1 a 3): ");
        int numSopa = (int)validarFloatRango(1, 3);
        int idxSopa = -1;

        for (int i = 0; i < contsopa; i++) {
            if (sopas[i].numsopa == numSopa) {
                idxSopa = i;
                break;
            }
        }

        if (idxSopa == -1) {
            printf("Error: sopa no encontrada.\n");
            return;
        }

        if (sopas[idxSopa].cantidad == 0) {
            printf("error se acabaron las sopas\n");
            return;
        }

        printf("Ingrese la cantidad de platos de sopa (0 a %d): ", sopas[idxSopa].cantidad);
        int cantPedida = (int)validarFloatRango(0, (float)sopas[idxSopa].cantidad);

        sopas[idxSopa].cantidad -= cantPedida;
        *ganancias += cantPedida * 1.75f;

        printf("Pedido registrado. Ganancias actuales: %.2f\n", *ganancias);

    } else if (opcion == 2) {
        if (contsegundo == 0) {
            printf("error se acabaron los segundos\n");
            return;
        }

        printf("\nIngrese el numero del segundo (1 a 4): ");
        int numSeg = (int)validarFloatRango(1, 4);
        int idxSeg = -1;

        for (int i = 0; i < contsegundo; i++) {
            if (segundos[i].numsegundo == numSeg) {
                idxSeg = i;
                break;
            }
        }

        if (idxSeg == -1) {
            printf("Error: segundo no encontrado.\n");
            return;
        }

        if (segundos[idxSeg].cantidad == 0) {
            printf("error se acabaron los segundos\n");
            return;
        }

        printf("Ingrese la cantidad de platos de segundo (0 a %d): ", segundos[idxSeg].cantidad);
        int cantPedida = (int)validarFloatRango(0, (float)segundos[idxSeg].cantidad);

        segundos[idxSeg].cantidad -= cantPedida;
        *ganancias += cantPedida * 2.25f;

        printf("Pedido registrado. Ganancias actuales: %.2f\n", *ganancias);

    } else {
        if (contsopa == 0 || contsegundo == 0) {
            printf("Error: no hay suficientes sopas o segundos registrados para un almuerzo.\n");
            return;
        }

        printf("\nIngrese el numero de la sopa para el almuerzo (1 a 3): ");
        int numSopa = (int)validarFloatRango(1, 3);
        int idxSopa = -1;

        for (int i = 0; i < contsopa; i++) {
            if (sopas[i].numsopa == numSopa) {
                idxSopa = i;
                break;
            }
        }

        if (idxSopa == -1 || sopas[idxSopa].cantidad == 0) {
            printf("Error: sopa no disponible o se acabaron las sopas.\n");
            return;
        }

        printf("Ingrese el numero del segundo para el almuerzo (1 a 4): ");
        int numSeg = (int)validarFloatRango(1, 4);
        int idxSeg = -1;

        for (int i = 0; i < contsegundo; i++) {
            if (segundos[i].numsegundo == numSeg) {
                idxSeg = i;
                break;
            }
        }

        if (idxSeg == -1 || segundos[idxSeg].cantidad == 0) {
            printf("Error: segundo no disponible o se acabaron los segundos.\n");
            return;
        }

        int sopaInicial = sopas[idxSopa].cantidad;
        int segundoInicial = segundos[idxSeg].cantidad;

        printf("Ingrese la cantidad de almuerzos: ");
        int cantAlmuerzos = (int)validarFloatRango(0, 10000);

        if (cantAlmuerzos > sopaInicial || cantAlmuerzos > segundoInicial) {
            printf("Error: la cantidad de almuerzos supera la disponibilidad de sopa o segundo.\n");
            sopas[idxSopa].cantidad = sopaInicial;
            segundos[idxSeg].cantidad = segundoInicial;
            return;
        }

        sopas[idxSopa].cantidad -= cantAlmuerzos;
        segundos[idxSeg].cantidad -= cantAlmuerzos;
        *ganancias += cantAlmuerzos * 2.75f;

        printf("Almuerzo registrado. Ganancias actuales: %.2f\n", *ganancias);
    }
}

void ingresarGastos(float *gastos, float *ganancias) {
    printf("Que desea registrar o ajustar?\n");
    printf("1) Gasto\n");
    printf("2) Ganancia\n");
    printf(">> ");
    int tipo = (int)validarFloatRango(1, 2);

    if (tipo == 1) {
        printf("Gastos actuales: %.2f\n", *gastos);
        printf("Ingrese el monto a sumar o disminuir (%.2f a 10000): ", -(*gastos));
        float monto = validarFloatRango(-(*gastos), 10000.0f);
        *gastos += monto;
        printf("Gastos actualizados: %.2f\n", *gastos);
    } else {
        printf("Ganancias actuales: %.2f\n", *ganancias);
        printf("Ingrese el monto a sumar o disminuir (%.2f a 10000): ", -(*ganancias));
        float monto = validarFloatRango(-(*ganancias), 10000.0f);
        *ganancias += monto;
        printf("Ganancias actualizadas: %.2f\n", *ganancias);
    }
}

void mostrarGananciaPerdida(float ganancias, float gastos, float *total) {
    if (fabsf(ganancias - gastos) < 0.0001f) {
        *total = 0.0f;
        printf("no hay ganancias y no hay perdidas\n");
    } else if (ganancias > gastos) {
        *total = ganancias - gastos;
        printf("su ganancia es igual %.2f\n", *total);
    } else {
        *total = gastos - ganancias;
        printf("su perdida es igual a %.2f\n", *total);
    }
}