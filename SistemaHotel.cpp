#include "Persona.cpp"
#include "Cliente.cpp"
#include "Empleado.cpp"
#include "Administrador.cpp"
#include "Gerente.cpp"
#include "PersonalServicio.cpp"
#include "HabDobles.cpp"
#include "HabCuadruples.cpp"
#include "HabLujo.cpp"
#include "Renta.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SistemaHotel
{
private:
    vector<Cliente*> clientes;
    vector<Empleado*> empleados;
    vector<Habitacion*> habitaciones;
    vector<Renta*> rentas;
public:

    void menuPrincipal() {
    int opcion;

    do{
        cout << "\n---- SISTEMA HOTEL ----\n";
        cout << "1. Empleados\n";
        cout << "2. Clientes\n";
        cout << "3. Habitaciones\n";
        cout << "4. Rentas\n";
        cout << "5. Room Service\n";
        cout << "6. Reportes\n";
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
            case 5: menuRoomService();
                break;
            case 6:
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
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1: {
                int tipo;
                cout << "Que tipo de empleado desea registrar?\n";
                cout << "1. Gerente\n2. Administrador\n3. Personal de Servicio\nOpcion: ";
                cin >> tipo;

                if(tipo >= 1 && tipo <= 3) {
                    cin.ignore(); 

                    string nom, dir, tel, rfc, cod;
                    cout << "Nombre completo: "; 
                    getline(cin, nom);
                    cout << "Direccion: "; 
                    getline(cin, dir);
                    cout << "Telefono: "; 
                    getline(cin, tel);
                    cout << "RFC: "; 
                    getline(cin, rfc);
                    cout << "Codigo de empleado: "; 
                    getline(cin, cod);

                    Empleado* nuevoEmpleado = NULL;

                    if(tipo == 1) {
                        nuevoEmpleado = new Gerente();
                        nuevoEmpleado->setPuesto("Gerente");
                    } else if(tipo == 2) {
                        nuevoEmpleado = new Administrador();
                        nuevoEmpleado->setPuesto("Administrador");
                    } else if(tipo == 3) {
                        nuevoEmpleado = new PersonalServicio();
                        nuevoEmpleado->setPuesto("Servicio");
                    }

                    nuevoEmpleado->setNombre(nom);
                    nuevoEmpleado->setDireccion(dir);
                    nuevoEmpleado->setTelefono(tel);
                    nuevoEmpleado->setRFC(rfc);
                    nuevoEmpleado->setCodigoEmpleado(cod);

                    empleados.push_back(nuevoEmpleado);
                    cout << "Empleado agregado exitosamente.\n";
                } else {
                    cout << "Tipo de empleado invalido.\n";
                }
                break;
            }
            case 2: {
                if(empleados.size() == 0) {
                    cout << "No hay empleados registrados.\n";
                } else {
                    for(int i = 0; i < empleados.size(); i++) {
                        empleados[i]->mostrarDatos(); 
                        cout << "---------------------------\n";
                    }
                }
                break;
            }
            case 3: {
                string codBusqueda;
                cout << "Ingrese el codigo de empleado a eliminar: "; 
                cin >> codBusqueda;
                bool encontrado = false;

                for(int i = 0; i < empleados.size(); i++) {
                    if(empleados[i]->getCodigoEmpleado() == codBusqueda) {
                        delete empleados[i]; // Liberamos memoria de la RAM
                        empleados.erase(empleados.begin() + i); // Lo sacamos de la lista
                        cout << "Empleado eliminado.\n";
                        encontrado = true;
                        break;
                    }
                }
                
                if(encontrado == false) {
                    cout << "Empleado no encontrado.\n";
                }
                break;
            }
            case 4: {
                string codBusqueda;
                cout << "Ingrese el codigo de empleado a actualizar: "; 
                cin >> codBusqueda; // Esto deja un Enter en el buffer
                bool encontrado = false;

                for(int i = 0; i < empleados.size(); i++) {
                    if(empleados[i]->getCodigoEmpleado() == codBusqueda) {
                        // Limpiamos el buffer ANTES de pedir los nuevos datos con getline
                        cin.ignore(); 
                        
                        string nom, dir, tel, rfc;
                        cout << "Nuevo Nombre completo: "; 
                        getline(cin, nom);
                        cout << "Nueva Direccion: "; 
                        getline(cin, dir);
                        cout << "Nuevo Telefono: "; 
                        getline(cin, tel);
                        cout << "Nuevo RFC: "; 
                        getline(cin, rfc);
                        
                        empleados[i]->setNombre(nom);
                        empleados[i]->setDireccion(dir);
                        empleados[i]->setTelefono(tel);
                        empleados[i]->setRFC(rfc);
                        cout << "Empleado actualizado.\n";
                        encontrado = true;
                        break;
                    }
                }
                
                if(encontrado == false) {
                    cout << "Empleado no encontrado.\n";
                }
                break;
            }
            case 0:
                break;
            default:
                cout << "Opcion invalida\n";
        }

    }while(opcion != 0);
}

    void agregarCliente()
    {
         Cliente* nuevo = new Cliente();

    string nombre, direccion, telefono;
    string rfc, correo, codigo;

    cin.ignore();

    cout << "Nombre: ";
    getline(cin, nombre);

    cout << "Direccion: ";
    getline(cin, direccion);

    cout << "Telefono: ";
    getline(cin, telefono);

    cout << "RFC: ";
    getline(cin, rfc);

    cout << "Correo: ";
    getline(cin, correo);

    cout << "Codigo de huesped: ";
    getline(cin, codigo);

    // VALIDAR CODIGO REPETIDO
    for(Cliente* c : clientes)
    {
        if(c->getCodigoHuesped() == codigo)
        {
            cout << "Ese codigo ya existe.\n";
            delete nuevo;
            return;
        }
    }

    nuevo->setNombre(nombre);
    nuevo->setDireccion(direccion);
    nuevo->setTelefono(telefono);
    nuevo->setRFC(rfc);
    nuevo->setCorreo(correo);
    nuevo->setCodigoHuesped(codigo);

    clientes.push_back(nuevo);

    cout << "Cliente registrado correctamente.\n";
    }

    void consultarClientes()
    {
           if(clientes.empty())
    {
        cout << "\nNo hay clientes registrados.\n";
        return;
    }

    for(Cliente* c : clientes)
    {
        c->mostrarDatos();
        cout << endl;
    }
    }

    void eliminarCliente()
    {
        string codigo;

    cin.ignore();
    cout << "Codigo de huesped a eliminar: ";
    getline(cin, codigo);

    for(auto it = clientes.begin(); it != clientes.end(); it++)
    {
        if((*it)->getCodigoHuesped() == codigo)
        {
            delete *it;
            clientes.erase(it);

            cout << "Cliente eliminado.\n";
            return;
        }
    }

    cout << "Cliente no encontrado.\n";
    }

    void actualizarCliente()
    {
            string codigo;

    cin.ignore();
    cout << "Codigo de huesped: ";
    getline(cin, codigo);

    for(Cliente* c : clientes)
    {
        if(c->getCodigoHuesped() == codigo)
        {
            string nombre, direccion, telefono, rfc, correo;

            cout << "Nuevo nombre: ";
            getline(cin, nombre);

            cout << "Nueva direccion: ";
            getline(cin, direccion);

            cout << "Nuevo telefono: ";
            getline(cin, telefono);

            cout << "Nuevo RFC: ";
            getline(cin, rfc);

            cout << "Nuevo correo: ";
            getline(cin, correo);

            c->setNombre(nombre);
            c->setDireccion(direccion);
            c->setTelefono(telefono);
            c->setRFC(rfc);
            c->setCorreo(correo);

            cout << "Cliente actualizado.\n";
            return;
        }
    }

    cout << "Cliente no encontrado.\n";
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
                agregarCliente();
                break;

            case 2:
                // consultar
                consultarClientes();
                break;

            case 3:
                // eliminar
                eliminarCliente();
                break;

            case 4:
                // actualizar
                actualizarCliente();
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
        int i, dias;
        string codCli, codEmp, codHab;
        bool clienteExiste, yaTieneRenta, empleadoExiste, cuartoExiste, hayDisponibles;

        Cliente* elCliente;
        Empleado* elEmpleado;
        Habitacion* elCuarto;
        Administrador* admin;
        Renta* nuevaRenta;

        do {
            cout << "\n--- RENTAS ---\n";
            cout << "1. Agregar (Nueva Renta)\n";
            cout << "2. Consultar Rentas Activas\n";
            cout << "3. Eliminar\n";
            cout << "4. Actualizar\n";
            cout << "0. Regresar\n";
            cout << "Opcion: ";
            cin >> opcion;

            switch(opcion) {
                case 1:
                    // Reiniciamos nuestras variables bandera cada vez que se entra a la opcion
                    clienteExiste = false;
                    yaTieneRenta = false;
                    empleadoExiste = false;
                    cuartoExiste = false;
                    hayDisponibles = false;
                    elCliente = NULL;
                    elEmpleado = NULL;
                    elCuarto = NULL;

                    // Validacion 1: Verificar que tengamos datos
                    if(clientes.size() == 0 || empleados.size() == 0 || habitaciones.size() == 0) {
                        cout << "Error: Faltan datos. Registre clientes, empleados y habitaciones primero.\n";
                    } 
                    else {
                        cout << "Codigo del cliente que va a rentar: ";
                        cin >> codCli;

                        // Buscamos al cliente con un for normal
                        for(i = 0; i < clientes.size(); i++) {
                            if(clientes[i]->getCodigoHuesped() == codCli) {
                                clienteExiste = true;
                                elCliente = clientes[i];
                            }
                        }

                        if(clienteExiste == false) {
                            cout << "Error: Cliente no registrado.\n";
                        } 
                        else {
                            // Validar que no tenga doble renta
                            for(i = 0; i < rentas.size(); i++) {
                                if(rentas[i]->getCodigoCliente() == codCli) {
                                    yaTieneRenta = true;
                                }
                            }

                            if(yaTieneRenta == true) {
                                cout << "Error: El cliente ya tiene una renta activa.\n";
                            } 
                            else {
                                cout << "Codigo del empleado que atiende: ";
                                cin >> codEmp;

                                for(i = 0; i < empleados.size(); i++) {
                                    if(empleados[i]->getCodigoEmpleado() == codEmp) {
                                        empleadoExiste = true;
                                        elEmpleado = empleados[i];
                                    }
                                }

                                if(empleadoExiste == false) {
                                    cout << "Error: Empleado no encontrado.\n";
                                } 
                                else if(elEmpleado->getPuesto() == "Servicio") {
                                    cout << "Error: Los trabajadores de servicio no pueden realizar rentas.\n";
                                } 
                                else {
                                    cout << "\n--- HABITACIONES DISPONIBLES ---\n";
                                    for(i = 0; i < habitaciones.size(); i++) {
                                        if(habitaciones[i]->getEstatus() == "Disponible") {
                                            habitaciones[i]->mostrarDetalles();
                                            hayDisponibles = true;
                                        }
                                    }

                                    if(hayDisponibles == false) {
                                        cout << "Lo sentimos: No hay habitaciones disponibles por el momento.\n";
                                    } 
                                    else {
                                        cout << "\nIngrese el Codigo de la Habitacion que desea: ";
                                        cin >> codHab;

                                        for(i = 0; i < habitaciones.size(); i++) {
                                            if(habitaciones[i]->getCodigoHabitacion() == codHab) {
                                                if(habitaciones[i]->getEstatus() == "Disponible") {
                                                    cuartoExiste = true;
                                                    elCuarto = habitaciones[i];
                                                }
                                            }
                                        }

                                        if(cuartoExiste == false) {
                                            cout << "Error: Habitacion invalida o ya rentada.\n";
                                        } 
                                        else {
                                            cout << "Cantidad de dias a rentar: ";
                                            cin >> dias;

                                            // --- MODULO 1: PROGRAMA DE LEALTAD REALISTA ---
                                            float precioDiaFinal = elCuarto->getPrecioRenta();
                                            int historialVisitas = elCliente->getVisitas();

                                            // Evaluamos el nivel de lealtad (Tiers)
                                            if(historialVisitas >= 10) {
                                                cout << "\n*** HUESPED NIVEL ORO DETECTADO ***\n";
                                                cout << "Gracias por elegirnos nuevamente (Visitas: " << historialVisitas << ").\n";
                                                cout << "Se le aplicara nuestra tarifa preferencial con 20% de descuento.\n";
                                                precioDiaFinal = precioDiaFinal - (precioDiaFinal * 0.20);
                                            }
                                            else if(historialVisitas >= 5) {
                                                cout << "\n*** HUESPED NIVEL PLATA DETECTADO ***\n";
                                                cout << "Bienvenido de nuevo (Visitas: " << historialVisitas << ").\n";
                                                cout << "Se le aplicara un 10% de descuento en su estancia.\n";
                                                precioDiaFinal = precioDiaFinal - (precioDiaFinal * 0.10);
                                            }
                                            else {
                                                cout << "\n(Huesped Nivel Clasico - Tarifa Estandar aplicada)\n";
                                            }
                                            // ----------------------------------------------

                                            // Se crea la renta pasando el precio final (con o sin descuento)
                                            nuevaRenta = new Renta(elCuarto->getCodigoHabitacion(), codCli, dias, precioDiaFinal, elEmpleado->getCodigoEmpleado());
                                            rentas.push_back(nuevaRenta);

                                            // Registramos esta nueva visita en el historial del cliente
                                            elCliente->registrarVisita();

                                            elCuarto->setEstatus("Rentada");

                                            // Calcular comision si es administrador
                                            if(elEmpleado->getPuesto() == "Administrador") {
                                                // Casteo manual
                                                admin = (Administrador*)elEmpleado;
                                                admin->setHuespedesAtendidos(admin->getHuespedesAtendidos() + 1);
                                                admin->agregarComision(nuevaRenta->getCostoTotal() * 0.05); 
                                            }

                                            cout << "\nRENTA EXITOSA. Costo total de la renta: $" << nuevaRenta->getCostoTotal() << "\n";
                                        }
                                    }
                                }
                            }
                        }
                    }
                    break;

                case 2:
                    if(rentas.size() == 0) {
                        cout << "No hay rentas activas.\n";
                    } 
                    else {
                        for(i = 0; i < rentas.size(); i++) {
                            rentas[i]->mostrarDetalles();
                            cout << "\n";
                        }
                    }
                    break;

                case 3:
                case 4:
                    cout << "ACCESO DENEGADO. Por politicas del hotel, las rentas NO se pueden eliminar ni actualizar.\n";
                    break;

                case 0:
                    break;

                default:
                    cout << "Opcion invalida\n";
            }

        } while(opcion != 0);
    }

    void menuRoomService() {
    string codHab;
    bool encontrada = false;
    int opcion;

    if (rentas.size() == 0) {
        cout << "No hay rentas activas para ofrecer Room Service.\n";
        return;
    }

    cout << "\n--- ROOM SERVICE ---\n";
    cout << "Ingrese el codigo de la habitacion: ";
    cin >> codHab;

    for (int i = 0; i < rentas.size(); i++) {
        if (rentas[i]->getCodigoHabitacion() == codHab) {
            encontrada = true;
            
            do {
                cout << "\nHabitacion " << codHab << " - Menu de Alimentos\n";
                cout << "1. Desayuno Continental ($150)\n";
                cout << "2. Botanas y Cerveza ($200)\n";
                cout << "3. Cena Ejecutiva ($350)\n";
                cout << "0. Regresar\n";
                cout << "Opcion: ";
                cin >> opcion;
                
                switch(opcion) {
                    case 1:
                        rentas[i]->agregarCargosRoomService(150.0);
                        cout << "Desayuno agregado a la cuenta del huesped.\n";
                        break;
                    case 2:
                        rentas[i]->agregarCargosRoomService(200.0);
                        cout << "Botanas agregadas a la cuenta del huesped.\n";
                        break;
                    case 3:
                        rentas[i]->agregarCargosRoomService(350.0);
                        cout << "Cena agregada a la cuenta del huesped.\n";
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Opcion invalida.\n";
                }
            } while(opcion != 0);
            break; // Rompemos el ciclo for porque ya encontramos la habitacion
        }
    }
    
    if (encontrada == false) {
        cout << "Error: Esa habitacion no esta rentada actualmente.\n";
    }
}

    void menuHabitaciones() {
        int opcion, tipo, i;
        string cod, codEmp, codHab;
        float nuevoPrecio;
        bool esGerente, laEncontre;
        Habitacion* nuevaHab;

        do {
            cout << "\n--- HABITACIONES ---\n";
            cout << "1. Agregar\n";
            cout << "2. Consultar\n";
            cout << "3. Eliminar\n";
            cout << "4. Actualizar\n";
            cout << "0. Regresar\n";
            cout << "Elige una opcion: ";
            cin >> opcion;

            switch(opcion) {
                case 1:
                    nuevaHab = NULL;

                    cout << "Que tipo de habitacion es?\n";
                    cout << "1. Doble ($800)\n2. Cuadruple ($1200)\n3. Lujo ($1500)\nOpcion: ";
                    cin >> tipo;

                    if(tipo >= 1 && tipo <= 3) {
                        cout << "Escribe el codigo de la habitacion: ";
                        cin >> cod; 

                        if(tipo == 1) {
                            nuevaHab = new HabDobles(cod);
                        } 
                        else if(tipo == 2) {
                            nuevaHab = new HabCuadruples(cod);
                        } 
                        else if(tipo == 3) {
                            nuevaHab = new HabLujo(cod);
                        }
                        
                        habitaciones.push_back(nuevaHab);
                        cout << "Habitacion lista y guardada en el sistema.\n";
                    } 
                    else {
                        cout << "Ese tipo de habitacion no existe.\n";
                    }
                    break;

                case 2:
                    if(habitaciones.size() == 0) {
                        cout << "Todavia no tenemos habitaciones registradas.\n";
                    } 
                    else {
                        for(i = 0; i < habitaciones.size(); i++) {
                            habitaciones[i]->mostrarDetalles();
                            cout << "-----------------------\n";
                        }
                    }
                    break;

                case 3:
                    // Reiniciamos banderas
                    esGerente = false;
                    laEncontre = false;

                    cout << "Para borrar, ocupas ser Gerente. Ingresa tu codigo de empleado: ";
                    cin >> codEmp;

                    // Buscamos si existe y si es gerente
                    for(i = 0; i < empleados.size(); i++) {
                        if(empleados[i]->getCodigoEmpleado() == codEmp) {
                            if(empleados[i]->getPuesto() == "Gerente") {
                                esGerente = true;
                            }
                        }
                    }

                    if(esGerente == false) {
                        cout << "Error: No eres gerente, no tienes permiso para borrar.\n";
                    } 
                    else {
                        cout << "Codigo de la habitacion que quieres borrar: ";
                        cin >> codHab;

                        for(i = 0; i < habitaciones.size(); i++) {
                            if(habitaciones[i]->getCodigoHabitacion() == codHab) {
                                laEncontre = true;
                                
                                if(habitaciones[i]->getEstatus() == "Rentada") {
                                    cout << "Alerta: No se puede borrar porque hay gente adentro (Rentada).\n";
                                } 
                                else {
                                    delete habitaciones[i]; 
                                    habitaciones.erase(habitaciones.begin() + i); 
                                    cout << "Habitacion borrada con exito.\n";
                                }
                                break;
                            }
                        }
                        
                        if(laEncontre == false) {
                            cout << "Esa habitacion no existe.\n";
                        }
                    }
                    break;

                case 4:
                    // Reiniciamos banderas
                    esGerente = false;
                    laEncontre = false;

                    cout << "Para modificar precios ocupas ser Gerente. Ingresa tu codigo: ";
                    cin >> codEmp;

                    for(i = 0; i < empleados.size(); i++) {
                        if(empleados[i]->getCodigoEmpleado() == codEmp) {
                            if(empleados[i]->getPuesto() == "Gerente") {
                                esGerente = true;
                            }
                        }
                    }

                    if(esGerente == false) {
                        cout << "Error: Solo los gerentes pueden hacer esto.\n";
                    } 
                    else {
                        cout << "Codigo de la habitacion a modificar: ";
                        cin >> codHab;

                        for(i = 0; i < habitaciones.size(); i++) {
                            if(habitaciones[i]->getCodigoHabitacion() == codHab) {
                                laEncontre = true;
                                
                                cout << "Cual sera el nuevo precio? $";
                                cin >> nuevoPrecio;
                                habitaciones[i]->setPrecioRenta(nuevoPrecio);
                                cout << "Precio actualizado.\n";
                                break;
                            }
                        }
                        
                        if(laEncontre == false) {
                            cout << "Esa habitacion no se encontro.\n";
                        }
                    }
                    break;

                case 0:
                    break;

                default:
                    cout << "Esa opcion no es valida\n";
            }

        } while(opcion != 0);
    }

    void reporteClientes(){
        if(clientes.empty())
    {
        cout << "\nNo hay clientes registrados.\n";
        return;
    }

    cout << "\n===== LISTA DE CLIENTES =====\n";

    for(Cliente* c : clientes)
    {
        c->mostrarDatos();
        cout << endl;
    }
    }
    void reporteHabitaciones(){
         if(habitaciones.empty())
    {
        cout << "\nNo hay habitaciones registradas.\n";
        return;
    }

    cout << "\n===== TODAS LAS HABITACIONES =====\n";

    for(Habitacion* h : habitaciones)
    {
        h->mostrarDetalles();
    }
    }
    void reporteHabitacionesDisponibles(){
        bool encontrada = false;

    cout << "\n===== HABITACIONES DISPONIBLES =====\n";

    for(Habitacion* h : habitaciones)
    {
        if(h->getEstatus() == "Disponible")
        {
            h->mostrarDetalles();
            encontrada = true;
        }
    }

    if(!encontrada)
    {
        cout << "No hay habitaciones disponibles.\n";
    }
    }
    void reporteHabitacionesNoDisponibles(){
         bool encontrada = false;

    cout << "\n===== HABITACIONES RENTADAS =====\n";

    for(Habitacion* h : habitaciones)
    {
        if(h->getEstatus() == "Rentada")
        {
            h->mostrarDetalles();
            encontrada = true;
        }
    }

    if(!encontrada)
    {
        cout << "No hay habitaciones rentadas.\n";
    }
    }
    void reporteEmpleados(){
        if(empleados.empty())
    {
        cout << "\nNo hay empleados registrados.\n";
        return;
    }

    cout << "\n===== LISTA DE EMPLEADOS =====\n";

    for(Empleado* e : empleados)
    {
        e->mostrarDatos();
        cout << endl;
    }
    }
    void reporteEmpleadosPorTipo(){
        string tipo;
    bool encontrado = false;

    cin.ignore();

    cout << "\nIngrese el tipo de empleado:\n";
    cout << "Gerente\n";
    cout << "Administrador\n";
    cout << "Servicio\n";
    cout << "Tipo: ";

    getline(cin, tipo);

    cout << "\n===== EMPLEADOS ENCONTRADOS =====\n";

    for(Empleado* e : empleados)
    {
        if(e->getPuesto() == tipo)
        {
            e->mostrarDatos();
            cout << endl;
            encontrado = true;
        }
    }

    if(!encontrado)
    {
        cout << "No se encontraron empleados de ese tipo.\n";
    }
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
                reporteClientes();
                break;

            case 2:
                reporteHabitaciones();
                break;

            case 3:
                reporteHabitacionesDisponibles();
                break;

            case 4:
                reporteHabitacionesNoDisponibles();
                break;

            case 5:
                reporteEmpleados();
                break;

            case 6:
                reporteEmpleadosPorTipo();
                break;

            case 0:
                break;

            default:
                cout << "Opcion invalida\n";
        }

    }while(opcion != 0);
}

    ~SistemaHotel()
    {
        for(Cliente* c : clientes)
            delete c;

        for(Empleado* e : empleados)
            delete e;

        for(Habitacion* h : habitaciones)
            delete h;

        for(Renta* r : rentas)
            delete r;
    }
};

int main(){

    SistemaHotel hotel;

    hotel.menuPrincipal();

    return 0;
}