#include <iostream>
#include "Persona.cpp"
#include "Cliente.cpp"
#include "Empleado.cpp"
#include "Gerente.cpp"
#include "Administrador.cpp"
#include "PersonalServicio.cpp"

using namespace std;

int main(){

    Cliente cliente1;
    cliente1.setNombre("Maria");
    cliente1.setDireccion("Zapopan");
    cliente1.setTelefono("3312345678");
    cliente1.setRFC("MALO010101");
    cliente1.setCorreo("maria@gmail.com");
    cliente1.setCodigoHuesped("H001");

    Gerente gerente1;
    gerente1.setNombre("Juan Perez");
    gerente1.setDireccion("Guadalajara");
    gerente1.setTelefono("3333333333");
    gerente1.setRFC("JUAP010101");
    gerente1.setCodigoEmpleado("E001");
    gerente1.setPuesto("Gerente");
    gerente1.calcularSalario();

    Administrador admin1;
    admin1.setNombre("Ana");
    admin1.setDireccion("Tlaquepaque");
    admin1.setTelefono("3344444444");
    admin1.setRFC("ANTA010101");
    admin1.setCodigoEmpleado("E002");
    admin1.setPuesto("Administrador");
    admin1.setHuespedesAtendidos(20);
    admin1.calcularSalario();

    PersonalServicio servicio1;
    servicio1.setNombre("Luis");
    servicio1.setDireccion("Zapopan");
    servicio1.setTelefono("3355555555");
    servicio1.setRFC("LUGA010101");
    servicio1.setCodigoEmpleado("E003");
    servicio1.setPuesto("Personal de Servicio");
    servicio1.calcularSalario();
    Persona *ptrPersona;

    ptrPersona = &cliente1;
    ptrPersona->mostrarDatos();

    cout << endl;

    ptrPersona = &gerente1;
    ptrPersona->mostrarDatos();

    cout << endl;

    ptrPersona = &admin1;
    ptrPersona->mostrarDatos();

    cout << endl;

    ptrPersona = &servicio1;
    ptrPersona->mostrarDatos();

    return 0;
}