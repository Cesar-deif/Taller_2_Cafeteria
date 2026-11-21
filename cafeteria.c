#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main (int argc, char *argv[]) {
    int menu;
    ingrediente ingrediente[25];
    int contIngredientes =0;
    sopa sopa[3];
    int contsopa =0;
    segundo segundo[4];
    int contsegundo =0;
    float gastos = 0;
    float ganancias = 0;
    float total = 0;
    do {
        printf("Seleccione una opcion:\n");
        printf("0.Finalizar Programa\n");
        printf("1.Registrar Ingrediente\n");
        printf("2.Mostrar Ingredientes\n");
        printf("3.Aumentar o Disminuir Ingredientes\n");
        printf("4.Ingresar Sopa\n");
        printf("5.Ingresar Segundo\n");
        printf("6.Mostrar Menu\n");
        printf("7.Modificar Platillo\n");
        printf("8.Ingresar Pedido\n");
        printf("9.Ingresar Gastos o Ganancias adicionales\n");
        printf("10.Mostrar Ganancia/Perdida\n");
        printf(">> ");
        menu = validarFloatRango(0,10);
        switch (menu)
        {
        case 1:
            registrarIngrediente(ingrediente, &contIngredientes, &gastos);
            break;
        
        case 2:
            mostrarIngredientes(ingrediente, contIngredientes);
            break;

        case 3:
            aumentarDisminuirIngrediente(ingrediente, contIngredientes);
            break;
        
        case 4:
            ingresarSopa(sopa, &contsopa, ingrediente, contIngredientes);
            break;
        case 5:
            ingresarSegundo(segundo, &contsegundo, ingrediente, contIngredientes);
            break;
        case 6:
            mostrarMenu(sopa, contsopa, segundo, contsegundo);
            break;
        case 7:
            modificarPlatillo(sopa, contsopa, segundo, contsegundo);
            break;
        case 8:
            ingresarPedido(sopa, contsopa, segundo, contsegundo, &ganancias);
            break;
        case 9:
            ingresarGastos(&gastos, &ganancias);
            break;
        case 10:
            mostrarGananciaPerdida(ganancias, gastos, &total);
            break;
        default:
            break;
        }
    } while(menu != 0);
    return 0;
}