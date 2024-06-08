#include <iostream>
#include <conio.h>
#include <cctype>
#include <string>
using namespace std;

struct cliente {
    string docIdentidad;
    string mensaje;
};

struct personalMedico{
    string nombre;
    string docIdentidadMed;
    string especializacion;
    string estadoTrabajo;
};

struct interfazAdmin {
    string nombre;
    string constraseña;
};

struct incidenteMed {
    string direccion;
    string descripcion;
    float tiempoLlegada;
};
struct Nodo {
    personalMedico a;
    Nodo * siguiente;
};

//Funciones: Verificación de Datos y Usuario:
void restringirEntradaOpcion(int & n );
void restringirEntradaNumero(int & n);
void restringirEntradaString(string & s);
void agregarAdministrador(interfazAdmin & Admin);
void identificacionUsuario(interfazAdmin & Admin);
void imprimirMenu(int &  opcion);
void insertarPersonalMedico(Nodo * lst, personalMedico a);

//Funciones: Actividades del negocio
void desplegarAmbulancia(incidenteMed Caso);


//Funciones: Reiteración del proceso
void reiniciarProceso(string & respuestaIterativa);


int main()
{
    //Inicialización de Variables
    string respuestaIterativa;
    interfazAdmin Administrador;
    int opcion;
    incidenteMed caso;
    //Proceso
    cout << "Diesel Aponte - Final Project Subject Algorithms and Data Structure" << endl;
    agregarAdministrador(Administrador);
    identificacionUsuario(Administrador);
    imprimirMenu(opcion);
    do {
        switch (opcion) {
            case 1: //Desplegar Ambulancia
                desplegarAmbulancia(caso);
                break;
            case 2: //Imprimir Lista pacientes

                break;
            case 3: //Atender al paciente siguiente

                break;
            case 4: //Agregar nuevo paciente
                break;
            case 5: //Agendar cita con un doctor especializado

                break;

            default:

                break;
        }
        reiniciarProceso(respuestaIterativa);
    }while(respuestaIterativa == "si" || respuestaIterativa == "s"); //Reiteración del proceso
    //Finalizando el proceso
    getch();
    return 0;
}


//Funciones: Verificación de Usuario y Datos
void restringirEntradaOpcion(int & n) {
    cin >> n;
    while(cin.fail() || n > 6) {
        cout << "Dato ingresado no valido ... " << endl;
        cout << "Ingrese un numero: " << endl;
        cin.clear();
        cin.ignore(10000,'\n');
        cin >> n;
    }
}
void restringirEntradaNumero(int & n) {
    cin >> n;
    while(cin.fail()) {
        cout << "Dato ingresado no valido ... " << endl;
        cout << "Ingrese un numero: " << endl;
        cin.clear();
        cin.ignore(10000,'\n');
        cin >> n;
    }
}

void restringirEntradaString(string & s) {
    cin >> s;
    while(cin.fail()) {
        cout << "Dato ingresado no valido ... " << endl;
        cout << "Ingrese una palabra: " << endl;
        cin.clear();
        cin.ignore(10000,'\n');
        cin >> s;
    }
}

void agregarAdministrador(interfazAdmin & Admin) {
    cout << "-----------------------------------------" << endl;
    cout << "Creando interfaz administrador ..." << endl;
    cout << "Ingrese el nombre de usuario: " << endl;
    restringirEntradaString(Admin.nombre);
    cout << "Ingrese una nueva contrasena para su cuenta: " << endl;
    restringirEntradaString(Admin.constraseña);
    cout << "Administrador agregado satisfactoriamente ..." << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;
}

void identificacionUsuario(interfazAdmin & Admin) {
    string respuestaName;
    string respuestaPassword;
    cout << "-----------------------------------------" << endl;
    cout << "Ingrese su usuario de administrador: " << endl;
    restringirEntradaString(respuestaName);
    while(respuestaName != Admin.nombre) {
        cout << "El nombre ingresado no pertenece a ningun usuario ..." << endl;
        cout << "Ingrese otra vez el nombre de usuario: " << endl;
        restringirEntradaString(respuestaName);
    }
    cout << "Ingrese la contrasena: " << endl;
    restringirEntradaString(respuestaPassword);
    while(respuestaPassword != Admin.constraseña) {
        cout << "La contraseña ingresada no es correcta ... " << endl;
        cout << "Ingrese la contrasena: " << endl;
        restringirEntradaString(respuestaPassword);
    }
    cout << "-----------------------------------------" << endl;
    cout << "ACCEDIENDO PERFIL ..." << endl;
    cout << endl;
}

void imprimirMenu(int & opcion) {
    cout << "-----------------Asignacion de Personal medico-----------------" << endl;
    cout << "1.- Desplegar ambulancia. " << endl;
    cout << "2.- Imprimir Lista Pacientes." << endl;
    cout << "3.- Imprimir Lista de Doctores. " << endl;
    cout << "3.- Atender al siguiente paciente." << endl;
    cout << "4.- Agregar paciente" << endl;
    cout << "5.- Agendar cita." << endl;
    cout << "6.- Cancelar cita. " << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Ingrese una opcion: " << endl;
    restringirEntradaNumero(opcion);
}


//Funciones: Actividades del Proceso:
void desplegarAmbulancia(incidenteMed Caso) {
    string confirmacionAdmin;
    string descripcionFar;
    string direccionFar;
    int opcionCaso;
    cout << "Desplegando ambulancia ..." << endl;
    cout << "Confirme la siguiente información: " << endl;
    cout << "* Descripcion: " << Caso.descripcion << endl;
    cout << "* Direccion: " << Caso.direccion << endl;
    cout << "Desplegar personal medico? (Si / No) " << endl;
    restringirEntradaString(confirmacionAdmin);
    while(confirmacionAdmin != "si" ||confirmacionAdmin != "no" ||confirmacionAdmin != "s" ||confirmacionAdmin != "n" ) {
        cout << "Ingrese una de las dos opciones (Si/No)" << endl;
        restringirEntradaString(confirmacionAdmin);
    }
    if(confirmacionAdmin == "si" || confirmacionAdmin == "s") {
        cout << "Desplegando personal medico ..." << endl;
        //Se inicializaria un contador ....
    } else {

        cout << "Que cual es la información que es incorrecta? " << endl;
        cout << "* Descripcion: " << Caso.descripcion << endl;
        cout << "* Direccion: " << Caso.direccion << endl;
        cout << "Ingrese 1 o 2: " << endl;
        restringirEntradaNumero(opcionCaso);
        while(opcionCaso > 2) {
            cout << "Ingrese un numero dentro del rango de opciones ... " << endl;
            restringirEntradaNumero(opcionCaso);
        }
        if(opcionCaso == 1) {
            cout << "Ingrese la descripción del caso: " << endl;
            restringirEntradaString(descripcionFar);
            Caso.descripcion = descripcionFar;
        } else {
            cout << "Ingrese la direccion del accidente: " << endl;
            restringirEntradaString(direccionFar);
            Caso.direccion = direccionFar;
        }
        cout << "Datos actualizados: " << endl;
        cout << "Desplegando ambulancia ..." << endl;
        cout << "Confirme la siguiente información: " << endl;
        cout << "* Descripcion: " << Caso.descripcion << endl;
        cout << "* Direccion: " << Caso.direccion << endl;
        cout << "Desplegando personal medico ... " << endl;
    }
}



//Algoritmos


//Funciones: Iteración del proceso
void reiniciarProceso(string & respuestaIterativa){
    cout << "Quiere realizar alguna otra diligencia? (Si/No)" << endl;
    restringirEntradaString(respuestaIterativa);
    for (int i = 0; i < respuestaIterativa.length(); i++) {
        respuestaIterativa += tolower(respuestaIterativa[i]);
    }
    while(respuestaIterativa != "si" || respuestaIterativa != "s" || respuestaIterativa != "no" || respuestaIterativa != "n") {
        cout << "Respuesta no valida " << endl;
        cout << "Ingrese una de las dos opciones(Si/No): " << endl;
    }
}
