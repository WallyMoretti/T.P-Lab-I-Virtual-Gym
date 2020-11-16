#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Estructuras.
typedef struct // Estructura Usuario.
{
    int idUsuario;
    char nombreYapellido[30];
    int password;
    int estado; // 0 = Baja, 1 = Alta.
} usuario;

typedef struct // Estructura Deportes.
{
    int idDeporte;
    char nombreDeporte[30];
} deporte;

typedef struct // Estructura Parte a Entrenar.
{
    int idParteEntrenar;
    char nombreParte[10];
} partes;

typedef struct // Estructura Ejercicios.
{
    int idEjercicio;
    char NombreEjercicio[50];
    int idParteEntrenar; // 1 - Brazos, 2 - Piernas, 3 - Cardio, 4 - Pecho, 5 - Espalda.
    int idDeporte; // 1 - Basquetball, 2 - Football, 3 - Natacion.
} ejercicios;

typedef struct // Estructura Historial Usuario.
{
    int ordenActividad;
    int idUsuario;
    char nombreEjercicio[50];
    int idParteEntrenar;
    int idDeporte;
} historial;

/// Funciones.
void consoleStopAndClean(); // Pausa y Limpia la consola.
int idMenu(); // Ingresa una ID del Menu.

void menuPrincipal(); // Menu Principal.

void menuRegistrarse(); // Menu Opcion 1(Registrarse) Menu Principal.
void mostrarIdUsuarios(); // Muestra la ID de los usuarios.
int determinarIdOcupada(int idUser); // Determina si una ID ya esta usada.
void registroUsuarios(); // Registro de usuarios.

void ingresoUsuario(); // Ingresa el usuario con ID y Password.
int busquedaIdUsuario(); // Busca ID Determinada.
void busquedaPasswordUsuario(); // Busca Password Determinada.
void menuIngresar(int userElegido); // Menu Opcion 2(Ingresar) Menu Principal.
void menuBasquetball(int userElegido, int depElegido); // Menu Basquetball.
void menuFootball(int userElegido, int depElegido); // Menu Football.
void menuNatacion(int userElegido, int depElegido); // Menu Natacion.
void mostrarDeterDeporteDeterParte(int depElegido, int parEntrenar); // Muestra Determinado Deporte y Determinada Parte.
void mostrarEjerciciosDeterminados(); // Muestra Ejercicios Determinados.
void mostrarHistorialUsuario(int userElegido); // Muestra el Historial de un Usuario.

void ingresoPasswordAdministrador(); // Permite el acceso al Menu Administrador a travez de una Password.
void menuAdministrador(); // Menu Opcion 3(Administrador) Menu Principal.
void mostrarArchivoUsuarios(); // Muestra los usuarios.
void mostrarUsuariosDadosAlta(); // Muestra Usuarios dados de Alta.
void mostrarUsuariosDadosBaja(); // Muestra Usuarios dados de Baja.
void mostrarPromedioUsuarios(); // Mueastra el Promedio de usuarios dados de Alta y dados de Baja.
void mostrarUnUsuario(usuario a); // Muestra un usuario.
int idBuscada(); // Busca una ID especifica.
int posicionIdBuscada(); // Retorna la posicion de la ID Buscada.
void mostrarIdDeterminada(); // Muestra ID Determinada.

int controlarIdCargada(int idPos);///Corroborar id cargada en usuario.

void cambiarEstadoUsuario(); // El Administrador cambia el estado del Usuario.
void cargarArchivoDeportes(); // Carga los Deportes.
void cargarParteEntrenar(); // Carga las Partes a Entrenar.
void mostrarArchivoDeportes(); // Muestra los Deportes.
void mostrarIdEjercicios(); // Muestra la ID Ejercicios.
int cantidadRegistrosEjercicios(); // Cantidad de Registros de Ejercicios.
void cargarArchivoEjercicios(); // Carga Archivo Ejercicios.
void mostrarArchivoEjercicios(); // Muestra el Archivo Ejercicios.
int cantidadRegistrosHistorial(); // Cantidad de Registros del Historial.
void historialUsuario(int userElegido, int depElegido, int parEntrenar); // Carga el Archivo Historial.
void mostrarArchivoHistorial(); // Muestra el Archivo Historial.

int main()
{
    menuPrincipal();
    return 0;
}
void consoleStopAndClean() // Pausa y Limpia la consola.
{
    system("pause");
    system("cls");
}
int idMenu() // Ingresa una ID del Menu.
{
    int retorno = 0;

    printf("Ingrese un numero para seleccionar una opcion: ");
    scanf("%i", &retorno);

    return retorno;
}
void menuPrincipal() // Menu Principal.
{
    int z = 0, numeroMenu = 0;

    while(z == 0)
    {
        printf("\t\t\t\t---------------MENU PRINCIPAL---------------\n\n");
        printf("[1] - Registrarse\n[2] - Ingresar\n[3] - Administrador\n\n[27] - Salir\n");
        numeroMenu = idMenu();
        switch(numeroMenu)
        {
        case 1:
        {
            system("cls");
            menuRegistrarse();
            break;
        }
        case 2:
        {
            system("cls");
            ingresoUsuario();
            break;
        }
        case 3:
        {
            system("cls");
            ingresoPasswordAdministrador();
            break;
        }
        case 27:
        {
            z++;
            break;
        }
        }
    }
}
void menuRegistrarse() // Menu Opcion 1(Registrarse) Menu Principal.
{
    int z = 0, numeroMenu = 0;

    while(z == 0)
    {
        printf("\t\t\t\t---------------REGISTRACION---------------\n\n");
        printf("[1] - Registrarse\n[2] - IDs Ocupadas\n\n[27] - Menu Principal\n");
        numeroMenu = idMenu();
        switch(numeroMenu)
        {
        case 1:
        {
            system("cls");
            printf("\t\t\t\t---------------REGISTRARSE---------------\n\n");
            mostrarIdUsuarios();
            registroUsuarios();
            consoleStopAndClean();
            break;
        }
        case 2:
        {
            system("cls");
            printf("\t\t\t\t---------------IDs OCUPADAS---------------\n\n");
            mostrarIdUsuarios();
            consoleStopAndClean();
            break;
        }
        case 27:
        {
            system("cls");
            z++;
            break;
        }
        }
    }
}
void mostrarIdUsuarios() // Muestra la ID de los usuarios.
{
    usuario a;
    FILE *archiUser;

    archiUser = fopen("Usuarios.bin", "rb");
    if(archiUser != NULL)
    {
        printf("IDs ocupadas: ");
        while(fread(&a, sizeof(usuario), 1, archiUser) > 0)
        {
            printf("%i - ", a.idUsuario);
        }
        fclose(archiUser);
    }
    printf("\n\n");
}
int determinarIdOcupada(int idUser) // Determina si una ID ya esta usada.
{
    int retorno = 0, flag = 0;
    usuario a;
    FILE *archiUser;

    archiUser = fopen("Usuarios.bin", "rb");
    if(archiUser != NULL)
    {
        while(fread(&a, sizeof(usuario), 1, archiUser) > 0 && flag == 0)
        {
            if(a.idUsuario == idUser)
            {
                printf("\nLa ID ya se encuentra en uso\n\n");
                retorno = 1;
                flag = 1;
            }
            else
            {
                retorno = 0;
                flag = 0;
            }
        }
        fclose(archiUser);
    }

    return retorno;
}
void registroUsuarios() // Registro de usuarios.
{
    int idOcupada = 0, flag = 0;
    char control = 's';
    usuario a;
    FILE *archiUser;

    archiUser = fopen("Usuarios.bin", "ab");
    if(archiUser != NULL)
    {
        while(control == 's' && flag == 0)
        {
            printf("Ingrese ID Usuario: ");
            fflush(stdin);
            scanf("%i", &a.idUsuario);
            idOcupada = determinarIdOcupada(a.idUsuario);
            if(a.idUsuario == 9999)
            {
                printf("Usted a ingresado el codigo para salir del menu de registro\n\n\n");
                flag = 1;
            }
            if(idOcupada == 0 && flag == 0)
            {
                printf("Ingrese Nombre y Apellido: ");
                fflush(stdin);
                gets(a.nombreYapellido);
                printf("Ingrese Password numerica (NO puede empezar con cero): ");
                fflush(stdin);
                scanf("%i", &a.password);
                printf("Ingrese Estado - 0(BAJA) / 1(ALTA) - : ");
                fflush(stdin);
                scanf("%i", &a.estado);

                fwrite(&a, sizeof(usuario), 1, archiUser);

                printf("\n");
                printf("Desea continuar? S/N: ");
                fflush(stdin);
                scanf("%c", &control);
                printf("\n");
            }
        }
        fclose(archiUser);
    }
    else
    {
        printf("\n---------ERROR---------\n\n");
    }
}
void ingresoUsuario() // Ingresa el usuario con ID y Password.
{
    printf("\t\t\t\t---------------BIENVENIDO USUARIO---------------\n\n");
    busquedaPasswordUsuario();
}
int busquedaIdUsuario() // Busca ID Determinada.
{
    int id = 0, flag = 0;
    usuario a;
    FILE* archiUser;

    id = idBuscada();
    archiUser = fopen("Usuarios.bin", "rb");
    if(archiUser != NULL)
    {
        while(fread(&a, sizeof(usuario), 1, archiUser) > 0 && flag == 0)
        {
            if(a.idUsuario == id)
            {
                if(a.estado == 0)
                {
                    printf("\nEl usuario esta dado de baja\n\n");
                    id = 0;
                    consoleStopAndClean();
                }
                flag = 1;
            }
        }
        fclose(archiUser);
    }
    if(flag == 0)
    {
        printf("\nLa ID ingresada es incorrecta\n\n");
        consoleStopAndClean();
    }

    return id;
}
void busquedaPasswordUsuario() // Busca Password Determinada.
{
    int idBuscada = 0, passwordIngresada = 0, flag = 0, intentosRestantes = 3;
    char control = 's';
    usuario a;
    FILE *archiUser;

    idBuscada = busquedaIdUsuario();
    archiUser = fopen("Usuarios.bin", "rb");
    if(archiUser != NULL)
    {
        while(fread(&a, sizeof(usuario), 1, archiUser) > 0)
        {
            while(a.idUsuario == idBuscada && flag == 0)
            {
                printf("Ingrese Password correspondiente: ");
                scanf("%i", &passwordIngresada);
                if(a.password == passwordIngresada)
                {
                    printf("\n\nPassword correcta. Bienvenido %s\n\n\n\n", a.nombreYapellido);
                    flag = 1;
                    consoleStopAndClean();
                    menuIngresar(idBuscada);
                }
                else
                {
                    intentosRestantes--;
                    printf("Password incorrecta. %i intentos restantes\n\n", intentosRestantes);
                    if(intentosRestantes != 0)
                    {
                        printf("Desea intentar otra vez? S/N: ");
                        fflush(stdin);
                        scanf("%c", &control);
                        printf("\n");
                    }
                    if(control == 'n')
                    {
                        flag = 1;
                        consoleStopAndClean();
                    }
                    if(intentosRestantes == 0)
                    {
                        printf("\nUsted a ingresado la password incorrectamente 3 veces. Por favor, comuniquese con el administrador.\n\n");
                        flag = 1;
                        consoleStopAndClean();
                    }
                }
            }
        }
        fclose(archiUser);
    }
}
void menuIngresar(int userElegido) // Menu Opcion 2(Ingresar) Menu Principal.
{
    int z = 0, numeroMenu = 0;

    while(z == 0)
    {
        printf("\t\t\t\t---------------INGRESAR---------------\n\n");
        mostrarArchivoDeportes();
        printf("\n[4] - Determinados Ejercicios\n[5] - Todos los Ejercicios\n\n[6] - Historial de Actividades\n\n[27] - Atras\n");
        numeroMenu = idMenu();
        switch(numeroMenu)
        {
        case 1:
        {
            system("cls");
            menuBasquetball(userElegido, numeroMenu);
            break;
        }
        case 2:
        {
            system("cls");
            menuFootball(userElegido, numeroMenu);
            break;
        }
        case 3:
        {
            system("cls");
            menuNatacion(userElegido, numeroMenu);
            break;
        }
        case 4:
        {
            system("cls");
            printf("\t\t\t\t---------------DETERMINADOS EJERCICIOS---------------\n\n");
            mostrarEjerciciosDeterminados();
            consoleStopAndClean();
            break;
        }
        case 5:
        {
            system("cls");
            printf("\t\t\t\t---------------TODOS LOS EJERCICIOS---------------\n\n");
            mostrarArchivoEjercicios();
            consoleStopAndClean();
            break;
        }
        case 6:
        {
            system("cls");
            printf("\t\t\t\t---------------HISTORIAL DE ACTIVIDADES---------------\n\n");
            mostrarHistorialUsuario(userElegido);
            consoleStopAndClean();
            break;
        }
        case 27:
        {
            system("cls");
            z++;
            break;
        }
        }
    }

}
void menuBasquetball(int userElegido, int depElegido) // Menu Basquetball.
{
    int z = 0, numeroMenu = 0;

    while(z == 0)
    {
        printf("\t\t\t\t---------------BASQUETBALL---------------\n\n");
        printf("[1] - Brazos\n[2] - Piernas\n[3] - Cardio\n\n[27] - Atras\n");
        numeroMenu = idMenu();
        switch(numeroMenu)
        {
        case 1:
        {
            system("cls");
            printf("\t\t\t\t---------------BRAZOS---------------\n\n");
            mostrarDeterDeporteDeterParte(depElegido, numeroMenu);
            historialUsuario(userElegido, depElegido, numeroMenu);
            consoleStopAndClean();
            break;
        }
        case 2:
        {
            system("cls");
            printf("\t\t\t\t---------------PIERNAS---------------\n\n");
            mostrarDeterDeporteDeterParte(depElegido, numeroMenu);
            historialUsuario(userElegido, depElegido, numeroMenu);
            consoleStopAndClean();
            break;
        }
        case 3:
        {
            system("cls");
            printf("\t\t\t\t---------------CARDIO---------------\n\n");
            mostrarDeterDeporteDeterParte(depElegido, numeroMenu);
            historialUsuario(userElegido, depElegido, numeroMenu);
            consoleStopAndClean();
            break;
        }
        case 27:
        {
            system("cls");
            z++;
            break;
        }
        }
    }
}
void menuFootball(int userElegido, int depElegido) // Menu Football.
{
    int z = 0, numeroMenu = 0;

    while(z == 0)
    {
        printf("\t\t\t\t---------------FOOTBALL---------------\n\n");
        printf("[1] - Brazos\n[2] - Piernas\n[3] - Cardio\n\n[27] - Atras\n");
        numeroMenu = idMenu();
        switch(numeroMenu)
        {
        case 1:
        {
            system("cls");
            printf("\t\t\t\t---------------BRAZOS---------------\n\n");
            mostrarDeterDeporteDeterParte(depElegido, numeroMenu);
            historialUsuario(userElegido, depElegido, numeroMenu);
            consoleStopAndClean();
            break;
        }
        case 2:
        {
            system("cls");
            printf("\t\t\t\t---------------PIERNAS---------------\n\n");
            mostrarDeterDeporteDeterParte(depElegido, numeroMenu);
            historialUsuario(userElegido, depElegido, numeroMenu);
            consoleStopAndClean();
            break;
        }
        case 3:
        {
            system("cls");
            printf("\t\t\t\t---------------CARDIO---------------\n\n");
            mostrarDeterDeporteDeterParte(depElegido, numeroMenu);
            historialUsuario(userElegido, depElegido, numeroMenu);
            consoleStopAndClean();
            break;
        }
        case 27:
        {
            system("cls");
            z++;
            break;
        }
        }
    }
}
void menuNatacion(int userElegido, int depElegido) // Menu Natacion.
{
    int z = 0, numeroMenu = 0;

    while(z == 0)
    {
        printf("\t\t\t\t---------------NATACION---------------\n\n");
        printf("[1] - Brazos\n[2] - Piernas\n[3] - Cardio\n[4] - Pecho\n[5] - Espalda\n\n[27] - Atras\n");
        numeroMenu = idMenu();
        switch(numeroMenu)
        {
        case 1:
        {
            system("cls");
            printf("\t\t\t\t---------------BRAZOS---------------\n\n");
            mostrarDeterDeporteDeterParte(depElegido, numeroMenu);
            historialUsuario(userElegido, depElegido, numeroMenu);
            consoleStopAndClean();
            break;
        }
        case 2:
        {
            system("cls");
            printf("\t\t\t\t---------------PIERNAS---------------\n\n");
            mostrarDeterDeporteDeterParte(depElegido, numeroMenu);
            historialUsuario(userElegido, depElegido, numeroMenu);
            consoleStopAndClean();
            break;
        }
        case 3:
        {
            system("cls");
            printf("\t\t\t\t---------------CARDIO---------------\n\n");
            mostrarDeterDeporteDeterParte(depElegido, numeroMenu);
            historialUsuario(userElegido, depElegido, numeroMenu);
            consoleStopAndClean();
            break;
        }
        case 4:
        {
            system("cls");
            printf("\t\t\t\t---------------PECHO---------------\n\n");
            mostrarDeterDeporteDeterParte(depElegido, numeroMenu);
            historialUsuario(userElegido, depElegido, numeroMenu);
            consoleStopAndClean();
            break;
        }
        case 5:
        {
            system("cls");
            printf("\t\t\t\t---------------ESPALDA---------------\n\n");
            mostrarDeterDeporteDeterParte(depElegido, numeroMenu);
            historialUsuario(userElegido, depElegido, numeroMenu);
            consoleStopAndClean();
            break;
        }
        case 27:
        {
            system("cls");
            z++;
            break;
        }
        }
    }
}
void mostrarDeterDeporteDeterParte(int depElegido, int parEntrenar) // Muestra Determinado Deporte y Determinada Parte.
{
    ejercicios a;

    FILE *archiEjercicios;
    archiEjercicios = fopen("Ejercicios.bin", "rb");
    if(archiEjercicios != NULL)
    {
        while(fread(&a, sizeof(ejercicios), 1, archiEjercicios) > 0)
        {
            if(a.idDeporte == depElegido && a.idParteEntrenar == parEntrenar)
            {
                printf("ID Ejercicio: %i\n", a.idEjercicio);
                printf("Ejercicio: %s\n", a.NombreEjercicio);
                printf("\n---------------------------------\n\n");
            }
        }
        fclose(archiEjercicios);
    }
}
void mostrarEjerciciosDeterminados() // Muestra los Ejercicios de Basquetball.
{
    int id = 0;
    partes a;
    ejercicios b;
    FILE *archiPartes;
    FILE *archiEjercicios;

    printf("1 - Basquetball // 2 - Football // 3 - Natacion\n");
    id = idBuscada();
    printf("\n\n");
    archiPartes = fopen("PartesEntrenar.bin", "rb");
    archiEjercicios = fopen("Ejercicios.bin", "rb");
    if(archiPartes != NULL)
    {
        if(archiEjercicios != NULL)
        {
            while(fread(&b, sizeof(ejercicios), 1, archiEjercicios) > 0)
            {
                if(b.idDeporte == id)
                {
                    printf("ID Ejercicio: %i\n", b.idEjercicio);
                    printf("Ejercicio: %s\n", b.NombreEjercicio);
                    while(fread(&a, sizeof(partes), 1, archiPartes) > 0)
                    {
                        if(b.idParteEntrenar == a.idParteEntrenar)
                        {
                            printf("Parte a Entrenar: %s\n", a.nombreParte);
                        }
                    }
                    fseek(archiPartes, 0, SEEK_SET);
                    printf("\n---------------------------------\n\n");
                }
            }
            fclose(archiEjercicios);
        }
        fclose(archiPartes);
    }
}
void mostrarHistorialUsuario(int userElegido) // Muestra el Historial de un Usuario.
{
    deporte a;
    partes b;
    historial c;
    FILE* archiDeporte;
    FILE *archiPartes;
    FILE *archiHistorial;

    archiDeporte = fopen("Deportes.bin", "rb");
    archiPartes = fopen("PartesEntrenar.bin", "rb");
    archiHistorial = fopen("Historial.bin", "rb");
    if(archiDeporte != NULL)
    {
        if(archiPartes != NULL)
        {
            if(archiHistorial != NULL)
            {
                while(fread(&c, sizeof(historial), 1, archiHistorial) > 0)
                {
                    if(c.idUsuario == userElegido)
                    {
                        printf("Orden Actividad: %i\n", c.ordenActividad);
                        printf("ID Usuario: %i\n", c.idUsuario);
                        printf("Ejercicio: %s\n", c.nombreEjercicio);
                        while(fread(&b, sizeof(partes), 1, archiPartes) > 0)
                        {
                            if(c.idParteEntrenar == b.idParteEntrenar)
                            {
                                printf("Parte a Entrenar: %s\n", b.nombreParte);
                            }
                        }
                        fseek(archiPartes, 0, SEEK_SET);
                        while(fread(&a,sizeof(deporte), 1, archiDeporte) > 0)
                        {
                            if(c.idDeporte == a.idDeporte)
                            {
                                printf("Deporte: %s\n", a.nombreDeporte);
                            }
                        }
                        fseek(archiDeporte, 0, SEEK_SET);
                        printf("\n---------------------------------\n\n");
                    }
                }
                fclose(archiHistorial);
            }
            fclose(archiPartes);
        }
        fclose(archiDeporte);
    }
}
void ingresoPasswordAdministrador() // Permite el acceso al Menu Administrador a travez de una Password.
{
    int retorno = 0, flag = 0, contador = 3;
    char password[10] = {"The Game"};
    char passwordIngresada[10];

    printf("\t\t\t\t---------------BIENVENIDO ADMINISTRADOR---------------\n\n");
    while(flag == 0 && contador > 0)
    {
        printf("Password: ");
        fflush(stdin);
        gets(passwordIngresada);
        retorno = strcmp(passwordIngresada, password);
        if(retorno == 0)
        {
            flag = 1;
            printf("\nPassword correcta. Sea nuevamente bienvenido administrador\n\n\n");
            consoleStopAndClean();
            menuAdministrador();
        }
        else
        {
            contador--;
            printf("Password incorrecta. %i intentos restantes\n\n", contador);
        }
        if(contador == 0)
        {
            printf("\n\t\t\t\t\tAdios Vaquero\n\n\n");
            flag = 1;
            consoleStopAndClean();
        }
    }
}
void menuAdministrador() // Menu Opcion 3(Administrador) Menu Principal.
{
    int z = 0, numeroMenu = 0;

    while(z == 0)
    {
        printf("\t\t\t\t---------------ADMINISTRADOR---------------\n\n");
        printf("[1] - IDs Ocupadas.\n[2] - Usuarios Registrados\n[3] - Usuarios dados de Alta\n[4] - Usuarios dados de Baja\n[5] - Promedio Usuarios Activos\n[6] - Busqueda por ID\n[7] - Cambiar Estado del Usuario\n[8] - Cargar Ejercicios al Sistema\n[9] - Ejercicios Cargados\n[10] - Historial de los Usuarios\n\n[27] - Menu Principal\n");
        numeroMenu = idMenu();
        switch(numeroMenu)
        {
        case 1:
        {
            system("cls");
            printf("\t\t\t\t---------------IDs OCUPADAS---------------\n\n");
            mostrarIdUsuarios();
            consoleStopAndClean();
            break;
        }
        case 2:
        {
            system("cls");
            printf("\t\t\t\t---------------USUARIOS REGISTRADOS---------------\n\n");
            mostrarArchivoUsuarios();
            consoleStopAndClean();
            break;
        }
        case 3:
        {
            system("cls");
            printf("\t\t\t\t---------------USUARIOS DADOS DE ALTA---------------\n\n");
            mostrarUsuariosDadosAlta();
            consoleStopAndClean();
            break;
        }
        case 4:
        {
            system("cls");
            printf("\t\t\t\t---------------USUARIOS DADOS DE BAJA---------------\n\n");
            mostrarUsuariosDadosBaja();
            consoleStopAndClean();
            break;
        }
        case 5:
        {
            system("cls");
            printf("\t\t\t\t---------------PROMEDIO USUARIOS---------------\n\n");
            mostrarPromedioUsuarios();
            consoleStopAndClean();
            break;
        }
        case 6:
        {
            system("cls");
            printf("\t\t\t\t---------------BUSQUEDA POR ID---------------\n\n");
            mostrarIdDeterminada();
            consoleStopAndClean();
            break;
        }
        case 7:
        {
            system("cls");
            printf("\t\t\t\t---------------CAMBIAR ESTADO DEL USUARIO---------------\n\n");
            cambiarEstadoUsuario();
            consoleStopAndClean();
            break;
        }
        case 8:
        {
            system("cls");
            printf("\t\t\t\t---------------CARGAR EJERCICIOS AL SISTEMA---------------\n\n");
            mostrarIdEjercicios();
            cargarArchivoEjercicios();
            consoleStopAndClean();
            break;
        }
        case 9:
        {
            system("cls");
            printf("\t\t\t\t---------------EJERCICIOS CARGADOS---------------\n\n");
            mostrarArchivoEjercicios();
            consoleStopAndClean();
            break;
        }
        case 10:
        {
            system("cls");
            printf("\t\t\t\t---------------HISTORIAL DE LOS USUARIOS---------------\n\n");
            mostrarArchivoHistorial();
            consoleStopAndClean();
            break;
        }
        case 27:
        {
            system("cls");
            z++;
            break;
        }
        }
    }
}
void mostrarArchivoUsuarios() // Muestra los usuarios.
{
    usuario a;
    FILE *archiUser;

    archiUser = fopen("Usuarios.bin", "rb");
    if(archiUser != NULL)
    {
        while(fread(&a, sizeof(usuario), 1, archiUser) > 0)
        {
            mostrarUnUsuario(a);
        }
        fclose(archiUser);
    }
    else
    {
        printf("\n---------ERROR---------\n\n");
    }
}
void mostrarUsuariosDadosAlta() // Muestra Usuarios dados de Alta.
{
    usuario a;
    FILE *archiUser;

    archiUser = fopen("Usuarios.bin", "rb");
    if(archiUser != NULL)
    {
        while(fread(&a, sizeof(usuario), 1, archiUser) > 0)
        {
            if(a.estado == 1)
            {
                mostrarUnUsuario(a);
            }
        }
        fclose(archiUser);
    }
}
void mostrarUsuariosDadosBaja() // Muestra Usuarios dados de Baja.
{
    usuario a;
    FILE *archiUser;

    archiUser = fopen("Usuarios.bin", "rb");
    if(archiUser != NULL)
    {
        while(fread(&a, sizeof(usuario), 1, archiUser) > 0)
        {
            if(a.estado == 0)
            {
                mostrarUnUsuario(a);
            }
        }
        fclose(archiUser);
    }
}
void mostrarPromedioUsuarios() // Mueastra el Promedio de usuarios dados de Alta y dados de Baja.
{
    int cant = 0, total = 0;
    float prom = 0, promInvertido = 100;
    usuario a;
    FILE *archiUser;

    archiUser = fopen("Usuarios.bin", "rb");
    if(archiUser != NULL)
    {
        while(fread(&a, sizeof(usuario), 1, archiUser) > 0)
        {
            total++;
            if(a.estado == 1)
            {
                cant++;
            }
        }
        fclose(archiUser);
    }
    prom = (float) (cant * 100) / total;
    printf("\nEl promedio de Usuarios dados de Alta es de: %.2f\n", prom);
    promInvertido = (float) promInvertido - prom;
    printf("El promedio de Usuarios dados de Baja es de: %.2f", promInvertido);
    printf("\n\n\n");
}
void mostrarUnUsuario(usuario a) // Muestra un usuario.
{
    printf("ID Usuario: %i\n", a.idUsuario);
    printf("Nombre y Apellido: %s\n", a.nombreYapellido);
    printf("Password: %i\n", a.password);
    printf("Estado: %i\n", a.estado);
    printf("\n---------------------------------\n\n");
}
int idBuscada() // Busca una ID especifica.
{
    int id = 0;
    printf("Ingrese ID: ");
    scanf("%i", &id);

    return id;
}
int posicionIdBuscada() // Retorna la posicion de la ID Buscada.
{
    int id = 0, posId = 0, flag = 0;
    usuario a;
    FILE *archiUser;

    id = idBuscada();
    archiUser = fopen("Usuarios.bin", "rb");
    if(archiUser != NULL)
    {
        while(fread(&a, sizeof(usuario), 1, archiUser) > 0 && flag == 0)
        {
            posId++;
            if(a.idUsuario == id)
            {
                flag = 1;
            }
        }
        fclose(archiUser);
    }
    if(flag == 0)
    {
        posId = 0;
    }

    return posId;
}
void mostrarIdDeterminada() // Muestra ID Determinada.
{
    int id = 0, flag = 0;
    usuario a;
    FILE *archiUser;

    id = idBuscada();
    archiUser = fopen("Usuarios.bin", "rb");
    if(archiUser != NULL)
    {
        while(fread(&a, sizeof(usuario), 1, archiUser) > 0 && flag == 0)
        {
            if(a.idUsuario == id)
            {
                printf("\n");
                mostrarUnUsuario(a);
                flag = 1;
            }
        }
        fclose(archiUser);
    }
    if(flag == 0)
    {
        printf("No se encuentra la ID buscada\n\n");
    }
}
void cambiarEstadoUsuario() // El Administrador cambia el estado del Usuario.
{
    int contador = 0, posId = 0, flag = 0;
    char control = 's';
    usuario a;
    FILE *archiUser;

    mostrarIdUsuarios();
    printf("\n\nIngrese una ID visible -OCUPADA-\n");
    posId = posicionIdBuscada();
    archiUser = fopen("Usuarios.bin", "r+b");
    if(archiUser != NULL)
    {
        if(posId != 0)
        {
            while(contador != posId)
            {
                contador++;
            }
            fseek (archiUser,(posId -1) * sizeof(usuario), SEEK_SET);
            if(fread(&a, sizeof(usuario), 1, archiUser) > 0 && flag == 0)
            {
                fseek (archiUser,(posId -1) * sizeof(usuario), SEEK_SET);
                printf("Desea cambiar el estado del Usuario? S/N: ");
                fflush(stdin);
                scanf("%c", &control);
                if(control == 's')
                {
                    printf("Ingrese el nuevo estado del Usuario: ");
                    fflush(stdin);
                    scanf("%i", &a.estado);
                    if(a.estado == 0)
                    {
                        printf("\nEl usuario esta dado de baja\n\n");
                    }
                    else
                    {
                        printf("\nEl usuario esta dado de alta\n\n");
                    }
                }
                else
                {
                    printf("\nNo se realizo ningun cambio en el Estado del Usuario\n\n");
                }
                fwrite(&a, sizeof(usuario), 1, archiUser);
                flag = 1;
            }
            fclose(archiUser);
        }
        else
        {
            printf("La ID ingresada no ha sido encontrada.\n\n\n");
        }
    }
}
void cargarArchivoDeportes() // Carga los Deportes.
{
    int deportes = 3;
    deporte a;
    FILE *archiDeporte;

    archiDeporte = fopen("Deportes.bin", "ab");
    if(archiDeporte != NULL)
    {
        while(deportes > 0)
        {
            printf("Ingrese ID Deporte: ");
            fflush(stdin);
            scanf("%i", &a.idDeporte);
            printf("Nombre deporte: ");
            fflush(stdin);
            gets(a.nombreDeporte);
            printf("\n");

            fwrite(&a, sizeof(deporte), 1, archiDeporte);

            deportes--;
        }
        fclose(archiDeporte);
    }
}
void cargarParteEntrenar() // Carga las Partes a Entrenar.
{
    int part = 5;
    partes a;
    FILE *archiPartes;

    archiPartes = fopen("PartesEntrenar.bin", "ab");
    if(archiPartes != NULL)
    {
        while(part > 0)
        {
            printf("Ingrese ID Parte a Entrenar: ");
            fflush(stdin);
            scanf("%i", &a.idParteEntrenar);
            printf("Nombre Parte a Entrenar: ");
            fflush(stdin);
            gets(a.nombreParte);
            printf("\n");

            fwrite(&a, sizeof(partes), 1, archiPartes);

            part--;
        }
        fclose(archiPartes);
    }
}
void mostrarArchivoDeportes() // Muestra los Deportes.
{
    deporte a;
    FILE *archiDeportes;

    archiDeportes = fopen("Deportes.bin", "rb");
    if(archiDeportes != NULL)
    {
        while(fread(&a, sizeof(deporte), 1, archiDeportes) > 0)
        {
            printf("[%i] - %s\n", a.idDeporte, a.nombreDeporte);
        }
        fclose(archiDeportes);
    }
}
void mostrarIdEjercicios() // Muestra la ID Ejercicios.
{
    ejercicios a;
    FILE *archiEjercicios;

    archiEjercicios = fopen("Ejercicios.bin", "rb");
    if(archiEjercicios != NULL)
    {
        printf("IDs Ocupadas: ");
        while(fread(&a, sizeof(ejercicios), 1, archiEjercicios) > 0)
        {
            printf("%i - ", a.idEjercicio);
        }
        fclose(archiEjercicios);
    }
    printf("\n\n");
}
int cantidadRegistrosEjercicios() // Cantidad de Registros de Ejercicios.
{
    int retorno = 0;
    FILE *archiEjercicios;

    archiEjercicios = fopen("Ejercicios.bin", "rb");
    if(archiEjercicios != NULL)
    {
        fseek(archiEjercicios, 1, SEEK_END);
        retorno = ftell(archiEjercicios) / sizeof(ejercicios);
        fclose(archiEjercicios);
    }

    return retorno;
}
void cargarArchivoEjercicios() // Carga Archivo Ejercicios.
{
    int contadorIdEjercicio = 0, flag = 0;
    char control = 's';
    ejercicios a;
    FILE *archiEjercicios;

    printf("Si NO queria ingresar en esta seccion, ingrese 1 -UNO-. En caso contrario, ingrese 0 -CERO-: ");
    fflush(stdin);
    scanf("%i", &flag);
    printf("\n\n");
    if(flag == 0)
    {
        contadorIdEjercicio = cantidadRegistrosEjercicios();
        archiEjercicios = fopen("Ejercicios.bin", "ab");
        if(archiEjercicios != NULL)
        {
            while(control == 's')
            {
                contadorIdEjercicio++;
                a.idEjercicio = contadorIdEjercicio;
                printf("Ingrese Nombre del Ejercicio: ");
                fflush(stdin);
                gets(a.NombreEjercicio);
                printf("\n1 - Brazos // 2 - Piernas // 3 - Cardio // 4 - Pecho // 5 - Espalda\n");
                printf("Ingrese a que parte pertenece el ejercicio: ");
                fflush(stdin);
                scanf("%i", &a.idParteEntrenar);
                printf("\n1 - Basquetball // 2 - Football // 3 - Natacion\n");
                printf("Ingrese a que Deporte pertenece el ejercicio: ");
                fflush(stdin);
                scanf("%i", &a.idDeporte);

                fwrite(&a, sizeof(ejercicios), 1, archiEjercicios);

                printf("\n");
                printf("Desea continuar? S/N: ");
                fflush(stdin);
                scanf("%c", &control);
                printf("\n");
            }
            fclose(archiEjercicios);
        }
    }
}
void mostrarArchivoEjercicios() // Muestra el Archivo Ejercicios.
{
    deporte a;
    partes b;
    ejercicios c;
    FILE* archiDeporte;
    FILE *archiPartes;
    FILE *archiEjercicios;

    archiDeporte = fopen("Deportes.bin", "rb");
    archiPartes = fopen("PartesEntrenar.bin", "rb");
    archiEjercicios = fopen("Ejercicios.bin", "rb");
    if(archiDeporte != NULL)
    {
        if(archiPartes != NULL)
        {
            if(archiEjercicios != NULL)
            {
                while(fread(&c, sizeof(ejercicios), 1, archiEjercicios) > 0)
                {
                    printf("ID Ejercicio: %i\n", c.idEjercicio);
                    printf("Ejercicio: %s\n", c.NombreEjercicio);
                    while(fread(&b, sizeof(partes), 1, archiPartes) > 0)
                    {
                        if(c.idParteEntrenar == b.idParteEntrenar)
                        {
                            printf("Parte a Entrenar: %s\n", b.nombreParte);
                        }
                    }
                    fseek(archiPartes, 0, SEEK_SET);
                    while(fread(&a,sizeof(deporte), 1, archiDeporte) > 0)
                    {
                        if(c.idDeporte == a.idDeporte)
                        {
                            printf("Deporte: %s\n", a.nombreDeporte);
                        }
                    }
                    fseek(archiDeporte, 0, SEEK_SET);
                    printf("\n---------------------------------\n\n");
                }
                fclose(archiEjercicios);
            }
            fclose(archiPartes);
        }
        fclose(archiDeporte);
    }
}
int cantidadRegistrosHistorial() // Cantidad de Registros del Historial.
{
    int retorno = 0;
    FILE *archiHistorial;

    archiHistorial = fopen("Historial.bin", "rb");
    if(archiHistorial != NULL)
    {
        fseek(archiHistorial, 1, SEEK_END);
        retorno = ftell(archiHistorial) / sizeof(historial);
        fclose(archiHistorial);
    }

    return retorno;
}
void historialUsuario(int userElegido, int depElegido, int parEntrenar) // Carga el Archivo Historial.
{
    int id = 0, contadorActividad = 0, flag = 0;
    char control = 's';
    ejercicios a;
    historial b;
    FILE* archiEjercicios;
    FILE *archiHistorial;

    printf("Para no generar inconvenientes en el historial, por favor, ingrese una ID visible\n\n");
    id = idBuscada();
    contadorActividad = cantidadRegistrosHistorial();
    if(id == 9999)
    {
        printf("Usted a ingresado el codigo para salir del menu de actividades\n\n\n");
        flag = 1;
    }
    archiEjercicios = fopen("Ejercicios.bin", "rb");
    archiHistorial = fopen("Historial.bin", "ab");
    if(archiEjercicios != NULL)
    {
        if(archiHistorial != NULL)
        {
            while(fread(&a, sizeof(ejercicios), 1, archiEjercicios) > 0 && flag == 0)
            {
                if(a.idEjercicio == id)
                {
                    printf("Desea realizar la actividad Nro. %i? S/N: ", id);
                    fflush(stdin);
                    scanf("%c", &control);
                    printf("\n");
                    if(control == 's')
                    {
                        contadorActividad++;
                        b.ordenActividad = contadorActividad;
                        b.idUsuario = userElegido;
                        strcpy(b.nombreEjercicio, a.NombreEjercicio);
                        b.idParteEntrenar = parEntrenar;
                        b.idDeporte = depElegido;

                        fwrite(&b, sizeof(historial), 1, archiHistorial);

                        printf("\nLa actividad ha sido cargada con exito en el historial\n\n");
                    }
                    else
                    {
                        flag = 1;
                    }
                }
            }
            fclose(archiHistorial);
        }
        fclose(archiEjercicios);
    }
}
void mostrarArchivoHistorial() // Muestra el Archivo Historial.
{
    deporte a;
    partes b;
    historial c;
    FILE* archiDeporte;
    FILE *archiPartes;
    FILE *archiHistorial;

    archiDeporte = fopen("Deportes.bin", "rb");
    archiPartes = fopen("PartesEntrenar.bin", "rb");
    archiHistorial = fopen("Historial.bin", "rb");
    if(archiDeporte != NULL)
    {
        if(archiPartes != NULL)
        {
            if(archiHistorial != NULL)
            {
                while(fread(&c, sizeof(historial), 1, archiHistorial) > 0)
                {
                    printf("Orden Actividad: %i\n", c.ordenActividad);
                    printf("ID Usuario: %i\n", c.idUsuario);
                    printf("Ejercicio: %s\n", c.nombreEjercicio);
                    while(fread(&b, sizeof(partes), 1, archiPartes) > 0)
                    {
                        if(c.idParteEntrenar == b.idParteEntrenar)
                        {
                            printf("Parte a Entrenar: %s\n", b.nombreParte);
                        }
                    }
                    fseek(archiPartes, 0, SEEK_SET);
                    while(fread(&a,sizeof(deporte), 1, archiDeporte) > 0)
                    {
                        if(c.idDeporte == a.idDeporte)
                        {
                            printf("Deporte: %s\n", a.nombreDeporte);
                        }
                    }
                    fseek(archiDeporte, 0, SEEK_SET);
                    printf("\n---------------------------------\n\n");
                }
                fclose(archiHistorial);
            }
            fclose(archiPartes);
        }
        fclose(archiDeporte);
    }
}










