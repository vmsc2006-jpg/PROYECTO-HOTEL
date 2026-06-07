#include "Persona.cpp"
#include "Cliente.cpp"
#include "Empleado.cpp"
#include "Administrador.cpp"
#include "Gerente.cpp"
#include "PersonalServicio.cpp"
//#include "Habitacion.cpp"
//#include "Renta.cpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SistemaHotel
{
private:
    vector<Cliente*> clientes;
    vector<Empleado*> empleados;
    //vector<Habitacion*> habitaciones;
    //vector<Renta*> rentas;
public:
    void menuPrincipal() {
    int opcion;

    do{
        cout << "\n---- SISTEMA HOTEL ----\n";
        cout << "1. Empleados\n";
        cout << "2. Clientes\n";
        cout << "3. Habitaciones\n";
        cout << "4. Rentas\n";
        cout << "5. Reportes\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                menuEmpleados();
                break;
            case 2:
                menuClientes();
                break;
            case 3:
                menuHabitaciones();
                break;
            case 4:
                menuRentas();
                break;
            case 5:
                menuReportes();
                break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida\n";
        }

    }while(opcion != 0);
}

    void menuEmpleados() {
    int opcion;

    do{
        cout << "\n--- EMPLEADOS ---\n";
        cout << "1. Agregar\n";
        cout << "2. Consultar\n";
        cout << "3. Eliminar\n";
        cout << "4. Actualizar\n";
        cout << "0. Regresar\n";

        cin >> opcion;

        switch(opcion){
            case 1:
                // agregar empleado
                break;

            case 2:
                // consultar
                break;

            case 3:
                // eliminar
                break;

            case 4:
                // actualizar
                break;
            case 0:
                // regresar
                break;
            default:
                cout<<"Opcion invalida\n";
        }

    }while(opcion != 0);
}   
    void menuClientes() {
    int opcion;

    do{
        cout << "\n--- CLIENTES ---\n";
        cout << "1. Agregar\n";
        cout << "2. Consultar\n";
        cout << "3. Eliminar\n";
        cout << "4. Actualizar\n";
        cout << "0. Regresar\n";

        cin >> opcion;

        switch(opcion){
            case 1:
                // agregar cliente
                break;

            case 2:
                // consultar
                break;

            case 3:
                // eliminar
                break;

            case 4:
                // actualizar
                break;
            case 0:
                // regresar
                break;
            default:
                cout<<"Opcion invalida\n";
        }

    }while(opcion != 0);
}
    void menuHabitaciones() {
    int opcion;

    do{
        cout << "\n--- HABITACIONES ---\n";
        cout << "1. Agregar\n";
        cout << "2. Consultar\n";
        cout << "3. Eliminar\n";
        cout << "4. Actualizar\n";
        cout << "0. Regresar\n";

        cin >> opcion;

        switch(opcion){
            case 1:
                // agregar Habitacion
                break;

            case 2:
                // consultar
                break;

            case 3:
                // eliminar
                break;

            case 4:
                // actualizar
                break;
            case 0:
                // regresar
                break;
            default:
                cout<<"Opcion invalida\n";
        }

    }while(opcion != 0);
}
    void menuRentas() {
    int opcion;

    do{
        cout << "\n--- RENTAS ---\n";
        cout << "1. Agregar\n";
        cout << "2. Consultar\n";
        cout << "3. Eliminar\n";
        cout << "4. Actualizar\n";
        cout << "0. Regresar\n";

        cin >> opcion;

        switch(opcion){
            case 1:
                // agregar renta
                break;

            case 2:
                // consultar
                break;

            case 3:
                // eliminar
                break;

            case 4:
                // actualizar
                break;
            case 0:
                // regresar
                break;
            default:
                cout<<"Opcion invalida\n";
        }

    }while(opcion != 0);
}
    void menuReportes() {
    int opcion;

    do{
        cout << "\n--- REPORTES ---\n";
        cout << "1. Lista de Clientes\n";
        cout << "2. Lista de Habitaciones Totales\n";
        cout << "3. Habitaciones Disponibles\n";
        cout << "4. Habitaciones No Disponibles\n";
        cout << "5. Lista de Empleados\n";
        cout << "6. Empleados por Tipo\n";
        cout << "0. Regresar\n";

        cin >> opcion;

        switch(opcion){
            case 1:
                // Lista de Clientes
                break;

            case 2:
                // Lista de Habitaciones Totales
                break;

            case 3:
                // Habitaciones Disponibles
                break;

            case 4:
                // Habitaciones No Disponibles
                break;
            case 5:
                // Lista de Empleados
                break;
            case 6:
                // Empleados por Tipo
                break;
            case 0:
                // Regresar
                break;
            default:
                cout<<"Opcion invalida\n";
        }

    }while(opcion != 0);
}

    //Destructor
    ~SistemaHotel()
    {
    for(Cliente* c : clientes)
        delete c;

    for(Empleado* e : empleados)
        delete e;

    /*
    for(Habitacion* h : habitaciones)
        delete h;

    for(Renta* r : rentas)
        delete r;
        */
    }
};

int main(){

    SistemaHotel hotel;

    hotel.menuPrincipal();

    return 0;
}