#include <iostream>
#include <cctype> //Funciones como tolower
#include <string> //Para manejo de cadenas de caracteres
using namespace std;

//Estructuras:

struct cliente {
    string docIdentidad;
    string mensaje;
};

struct Med {
    string nombre;
    string docIden;
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
};

struct NodoMed {
    Med indv;
    NodoMed *siguiente;
};

struct paciente {
    string nombre;
    string docIden;
    string numTelf;
    int edad;
    string razonConsulta;
    string antecedentesMed;
};

struct NodoPac {
    paciente indv;
    NodoPac *siguiente;
};

struct QueuePac {
    NodoPac *front;
    NodoPac *rear;
    int size;

    QueuePac() : front(nullptr), rear(nullptr), size(0) {}
};

// Funciones: Verificación de Datos y Usuario

void restringirEntradaOpcion(int &n);

void restringirEntradaNumero(int &n);

void restringirEntradaString(string &s);

void agregarAdministrador(interfazAdmin &Admin);

void identificacionUsuario(interfazAdmin &Admin);

void imprimirMenu(int &opcion);

// Funciones: Actividades del negocio

void iniciarPrograma();

void desplegarAmbulancia(incidenteMed Caso);

void ingresarMed(Med &indv);

void insertarListaMed(NodoMed *&lstMed, Med indv);

void eliminarMedico(NodoMed *&lstMed, string nombre);

void imprimirListaMed(NodoMed *&lstMed);

void imprimirColaPacientes(QueuePac &queue);

void atenderColaPacientes(QueuePac &queue);

void IngresarColaPacientes(QueuePac &queue);

// Funciones: Reiteración del proceso
void reiniciarProceso(string &respuestaIterativa);

int main() {
    cout << "Diesel Aponte - Trabajo Final" << endl;
    iniciarPrograma();
    // Finalizando el proceso:
    system("pause");
    return 0;
}

// Implementaciones de las funciones

void iniciarPrograma() {

    // Inicialización de Variables

    string respuestaIterativa;
    interfazAdmin Administrador;
    int opcion;
    incidenteMed caso;
    caso.descripcion = "Choque";
    caso.direccion = "Calle Sucre";
    NodoMed *lstMed = nullptr;
    Med indv;
    string name;
    QueuePac queuePacientes;

    // Proceso:

    agregarAdministrador(Administrador);
    identificacionUsuario(Administrador);

    do {
        imprimirMenu(opcion);

        switch (opcion) {

            case 1: // Desplegar Ambulancia
                desplegarAmbulancia(caso);
                break;

            case 2://Imprimir la Lista Enlazada de Doctores
                imprimirListaMed(lstMed);
                break;

            case 3:
                insertarListaMed(lstMed, indv);
                break;

            case 4:
                eliminarMedico(lstMed, name);
                break;

            case 5: // Imprimir Lista pacientes
                imprimirColaPacientes(queuePacientes);
                break;

            case 6: // Atender al paciente siguiente
                atenderColaPacientes(queuePacientes);
                break;

            case 7: // Agregar nuevo paciente
                IngresarColaPacientes(queuePacientes);
                break;

            default:

                cout << "Opción no válida." << endl;
                break;
        }

        reiniciarProceso(respuestaIterativa);

    } while (respuestaIterativa == "si" || respuestaIterativa == "s"); // Reiteración del proceso
}

void restringirEntradaOpcion(int &n) {
    cin >> n;
    while (cin.fail() || n > 6) {
        cout << "Dato ingresado no valido ... " << endl;
        cout << "Ingrese un numero: " << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> n;
    }
}

void restringirEntradaNumero(int &n) {
    cin >> n;
    while (cin.fail()) {
        cout << "Dato ingresado no valido ... " << endl;
        cout << "Ingrese un numero: " << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> n;
    }
}

void restringirEntradaString(string &s) {
    cin >> s;
    while (cin.fail()) {
        cout << "Dato ingresado no valido ... " << endl;
        cout << "Ingrese una palabra: " << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> s;
    }
}

void agregarAdministrador(interfazAdmin &Admin) {
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

void identificacionUsuario(interfazAdmin &Admin) {
    string respuestaName;
    string respuestaPassword;
    cout << "-----------------------------------------" << endl;
    cout << "Ingrese su usuario de administrador: " << endl;
    restringirEntradaString(respuestaName);

    while (respuestaName != Admin.nombre) {
        cout << "El nombre ingresado no pertenece a ningun usuario ..." << endl;
        cout << "Ingrese otra vez el nombre de usuario: " << endl;
        restringirEntradaString(respuestaName);
    }

    cout << "Ingrese la contrasena: " << endl;
    restringirEntradaString(respuestaPassword);

    while (respuestaPassword != Admin.constraseña) {
        cout << "La contraseña ingresada no es correcta ... " << endl;
        cout << "Ingrese la contrasena: " << endl;
        restringirEntradaString(respuestaPassword);
    }

    cout << "-----------------------------------------" << endl;
    cout << "ACCEDIENDO PERFIL ..." << endl;
    cout << endl;
}

void imprimirMenu(int &opcion) {
    cout << "-----------------Asignacion de Personal medico-----------------" << endl;
    cout << "1.- Desplegar ambulancia. " << endl;
    cout << "2.- Imprimir Lista de Doctores. " << endl;
    cout << "3.- Agregar un nuevo Doctor. " << endl;
    cout << "4.- Eliminar un Doctor de la lista. " << endl;
    cout << "5.- Imprimir Lista Pacientes." << endl;
    cout << "6.- Atender al siguiente paciente." << endl;
    cout << "7.- Agregar paciente" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Ingrese una opcion: " << endl;
    restringirEntradaNumero(opcion);
}

void desplegarAmbulancia(incidenteMed Caso) {
    string confirmacionAdmin;
    string descripcionFar;
    string direccionFar;
    int opcionCaso;
    cout << "Preparando ambulancia ..." << endl;
    cout << "Confirme la siguiente informacion: " << endl;
    cout << "* Descripcion: " << Caso.descripcion << endl;
    cout << "* Direccion: " << Caso.direccion << endl;
    cout << "Desplegar personal medico? (Si / No) " << endl;

    restringirEntradaString(confirmacionAdmin);

    while (confirmacionAdmin != "si" && confirmacionAdmin != "no" && confirmacionAdmin !=
                                                                     "s" && confirmacionAdmin != "n") {
        cout << "Ingrese una de las dos opciones (Si/No)" << endl;
        restringirEntradaString(confirmacionAdmin);
    }

    if (confirmacionAdmin == "si" || confirmacionAdmin == "s") {
        cout << "Desplegando personal medico ..." << endl;
    } else {
        cout << "Que cual es la informacion que es incorrecta? " << endl;
        cout << "* Descripcion: " << Caso.descripcion << endl;
        cout << "* Direccion: " << Caso.direccion << endl;
        cout << "Ingrese 1 o 2: " << endl;
        restringirEntradaNumero(opcionCaso);

        while (opcionCaso > 2) {
            cout << "Ingrese un numero dentro del rango de opciones ... " << endl;
            restringirEntradaNumero(opcionCaso);
        }

        if (opcionCaso == 1) {
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

void ingresarMed(Med &indv) {
    cout << "Ingrese el nombre: " << endl;
    cin >> indv.nombre;
    cout << "Ingrese el DNI: " << endl;
    cin >> indv.docIden;
    cout << "Ingrese el especializacion: " << endl;
    cin >> indv.especializacion;
    indv.estadoTrabajo = "libre";
}

void insertarListaMed(NodoMed *&lstMed, Med indv) {
    NodoMed *nuevoNodo = new NodoMed();
    ingresarMed(indv);
    nuevoNodo->indv = indv;
    NodoMed *aux1 = lstMed;
    NodoMed *aux2 = nullptr;

    while (aux1 != nullptr) {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    if (lstMed == aux1) {
        lstMed = nuevoNodo;
    } else {
        aux2->siguiente = nuevoNodo;
    }

    nuevoNodo->siguiente = aux1;
    cout << "El medico " << indv.nombre << " se agrego correctamente al equipo ..." << endl;
}

void eliminarMedico(NodoMed *&lstMed, string nombre) {
    cout << "Ingrese el nombre del medico que quiere despedir: " << endl;
    restringirEntradaString(nombre);
    if (lstMed == nullptr) {
        cout << "La lista esta vacia. No se puede eliminar." << endl;
        return;
    }

    NodoMed *aux1 = lstMed;
    NodoMed *aux2 = nullptr;

    while (aux1 != nullptr && aux1->indv.nombre != nombre) {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    if (aux1 == nullptr) {
        cout << "Medico no encontrado." << endl;
        return;
    }
    if (aux1 == lstMed) {
        lstMed = lstMed->siguiente;
    } else {
        aux2->siguiente = aux1->siguiente;
    }
    delete aux1;
    cout << "El medico " << nombre << " fue eliminado del equipo." << endl;
}

void imprimirListaMed(NodoMed *&lstMed) {
    NodoMed *actual = lstMed;
    if (actual == nullptr) {
        cout << "No hay medicos en la lista." << endl; // Mensaje corregido
        return;
    }
    cout << "----------------------------EQUIPO MEDICO----------------------------" << endl;
    while (actual != nullptr) {
        cout << "---------------------------------------------------------------------" << endl;
        cout << "Nombre: " << actual->indv.nombre << endl;
        cout << "DNI: " << actual->indv.docIden << endl;
        cout << "Especializacion: " << actual->indv.especializacion << endl;
        cout << "---------------------------------------------------------------------" << endl;
        actual = actual->siguiente;
    }
    cout << "----------------------------EQUIPO MEDICO----------------------------" << endl;
    cout << endl;
}

void reiniciarProceso(string &respuestaIterativa) {
    cout << "Quiere realizar alguna otra diligencia? (Si/No)" << endl;
    restringirEntradaString(respuestaIterativa);
    // Convertir a minúsculas para asegurar la comparación
    for (char &c: respuestaIterativa) {
        c = tolower(c);
    }
    // Validar la respuesta del usuario
    while (respuestaIterativa != "si" && respuestaIterativa != "s" && respuestaIterativa != "no"
           && respuestaIterativa != "n") {
        cout << "Respuesta no valida. Ingrese una de las opciones (Si/No): " << endl;
        restringirEntradaString(respuestaIterativa);
        // Convertir a minúsculas de nuevo después de obtener nueva entrada
        for (char &c: respuestaIterativa) {
            c = tolower(c);
        }
    }
}

void IngresarColaPacientes(QueuePac &queue) {
    if (queue.size >= 3) {
        cout << "La cola ya tiene el máximo de 5 pacientes." << endl;
        return;
    }
    for (int i = 0; i < 3; ++i) {
        if (queue.size >= 3) {
            cout << "Se ha alcanzado el máximo de 3 pacientes en la cola." << endl;
            break;
        }
        paciente newPaciente;
        cout << "Ingresando datos del paciente " << i + 1 << ":\n";
        cout << "Nombre: " << endl;
        restringirEntradaString(newPaciente.nombre);
        cout << "Documento de Identidad: " << endl;
        restringirEntradaString(newPaciente.docIden);
        cout << "Numero de Telefono: " << endl;
        restringirEntradaString(newPaciente.numTelf);
        cout << "Edad: " << endl;
        restringirEntradaNumero(newPaciente.edad);
        cout << "Razon de Consulta: " << endl;
        restringirEntradaString(newPaciente.razonConsulta);
        cout << "Antecedentes Medicos: " << endl;
        restringirEntradaString(newPaciente.antecedentesMed);
        NodoPac *nuevoNodo = new NodoPac;
        nuevoNodo->indv = newPaciente;
        nuevoNodo->siguiente = nullptr;
        if (queue.rear == nullptr) {
            queue.front = queue.rear = nuevoNodo;
        } else {
            queue.rear->siguiente = nuevoNodo;
            queue.rear = nuevoNodo;
        }
        queue.size++;
    }
    cout << "Pacientes ingresados satisfactoriamente en la cola." << endl;
}

void imprimirColaPacientes(QueuePac &queue) {
    if (queue.front == nullptr) {
        cout << "No hay pacientes en la cola." << endl;
        return;
    }
    NodoPac *temp = queue.front;
    int i = 1;
    while (temp != nullptr) {
        cout << "Paciente " << i << ":\n";
        cout << "Nombre: " << temp->indv.nombre << endl;
        cout << "Documento de Identidad: " << temp->indv.docIden << endl;
        cout << "Numero de Telefono: " << temp->indv.numTelf << endl;
        cout << "Edad: " << temp->indv.edad << endl;
        cout << "Razon de Consulta: " << temp->indv.razonConsulta << endl;
        cout << "Antecedentes Medicos: " << temp->indv.antecedentesMed << endl;
        cout << "-----------------------------" << endl;
        temp = temp->siguiente;
        i++;
    }
}

void atenderColaPacientes(QueuePac &queue) {
    if (queue.front == nullptr) {
        cout << "No hay pacientes en la cola para atender." << endl;
        return;
    }
    NodoPac *temp = queue.front;
    queue.front = queue.front->siguiente;
    if (queue.front == nullptr) {
        queue.rear = nullptr;
    }
    delete temp;
    queue.size--;
    cout << "Paciente atendido y eliminado de la cola." << endl;
    // Agregar un nuevo paciente si hay espacio
    if (queue.size < 3) {
        cout << "Ingresar un nuevo paciente para llenar el espacio dejado:\n";
        IngresarColaPacientes(queue);
    }
}