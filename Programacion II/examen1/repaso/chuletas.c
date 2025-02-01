#define MAX_TEXT_LENGTH 40

int main(int argc, char *argv[])
int num_caracteres = argc - 1;
char caracteres[MAX_TEXT_LENGTH];
int contador[MAX_TEXT_LENGTH] = {0};
char texto[MAX_TEXT_LENGTH];

for (i = 1; i < argc; i++){
    caracteres[i-1] = argv[i][0];
}

scanf(" %[^\n]", texto);

for (i = 0; i < strlen(texto); i++){
    for (j = 0; j < num_caracteres; j++) {
        if(texto[i] == caracteres[j]){
            contador[j]++;
        }
    }
}

for (i = 0; i < num_caracteres; i++){
    int count = contador[i] > 10 ? 10 : contador[i];
    printf("El caracter '%c' se repite %i veces.\n", caracteres[i], count);
}


typedef struct {
    int ancho;
    char material[MAX_TIPO_MATERIAL];
} Mesa;

int indices[5];
int num_mesas_pedido = 0;
float precio_total = 0;

void introducirMesa(Mesa *mesas, *num_mesas){
    scanf("%i", &mesas[*num_mesas].ancho);
    strcpy(mesas[*num_mesas].material, "Plastico");
}

char entrada[50];
fgets(entrada, 50, stdin);
char *token = strtok(entrada, ",");
while (token != NULL && num_mesas_pedido < 5) {
    indices[num_mesas_pedido++] = atoi(token);
    token = strtok(NULL, ",");
}

void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n');
}


srand(time(NULL));
rand() % 2 == 0

Gladiador jugador, cpu;

char *token;
token = strtok(argv[1], ",");
strcpy(jugador.nombre, token);
token = strtok(NULL, ",");
jugador.fuerza = atoi(token);
jugador.salud = 100;
token = strtok(NULL, ",");
strcpy(jugador.tipo_arma, token);

void atacar(Gladiador *atacante, Gladiador *defensor) {
    int danio;
    if (strcmp(atacante->tipo_arma, "espada") == 0) {
        danio = atacante->fuerza;
    } else if (strcmp(atacante->tipo_arma, "lanza") == 0) {
        danio = 2 * atacante->fuerza;
    }

    printf("%s ataca a %s con un danio de %d\n", atacante->nombre, defensor->nombre, danio);
    defensor->salud -= danio;
}

void defenderse(Gladiador *defensor) {
    printf("%s se defiende\n", defensor->nombre);
}