typedef struct
{
    int numingre;
    char nomingre[100];
    float cantidad;
}ingrediente;
typedef struct
{
    int numsopa;
    char nomsopa[100];
    int cantidad;
}sopa;
typedef struct
{
    int numsegundo;
    char nomsegundo[100];
    int cantidad;
}segundo;

float validarFloatRango(float a, float b);
void leerCadena(char *cadena, int n);
void registrarIngrediente(ingrediente *ingredientes, int *contador, float *gastos);
void mostrarIngredientes(ingrediente *ingredientes, int contador);
void aumentarDisminuirIngrediente(ingrediente *ingredientes, int contador);
void ingresarSopa(sopa *sopas, int *contsopa, ingrediente *ingredientes, int contIngredientes);
void ingresarSegundo(segundo *segundos, int *contsegundo, ingrediente *ingredientes, int contIngredientes);
void mostrarMenu(sopa *sopas, int contsopa, segundo *segundos, int contsegundo);void mostrarMenu(sopa *sopas, int contsopa, segundo *segundos, int contsegundo);
void modificarPlatillo(sopa *sopas, int contsopa, segundo *segundos, int contsegundo);
void ingresarPedido(sopa *sopas, int contsopa, segundo *segundos, int contsegundo, float *ganancias);
void ingresarGastos(float *gastos, float *ganancias);
void mostrarGananciaPerdida(float ganancias, float gastos, float *total);