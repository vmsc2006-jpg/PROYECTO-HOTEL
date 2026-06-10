#include <iostream>
using namespace std;

class Cliente : public Persona{
    private:
    string correo;
    string codigoHuesped;
    int visitas;

    public:
    Cliente();

    void setCorreo(string);
    string getCorreo();

    void setCodigoHuesped(string);
    string getCodigoHuesped();

    void registrarVisita();
    int getVisitas();

    void mostrarDatos();
};

Cliente::Cliente(){
    correo = "";
    codigoHuesped = "";
    visitas = 0;
}

void Cliente::setCorreo(string correo){
    this -> correo = correo;
}
string Cliente::getCorreo(){
    return this -> correo;
}

void Cliente::setCodigoHuesped(string codigoHuesped){
    this -> codigoHuesped = codigoHuesped;
}
string Cliente::getCodigoHuesped(){
    return this -> codigoHuesped;
}

void Cliente::registrarVisita(){
    this -> visitas++;
}

int Cliente::getVisitas(){
    return this -> visitas;
}

void Cliente::mostrarDatos(){
    cout<<"---CLIENTE---"<<endl;
    cout<<"Nombre: "<<getNombre()<<endl;
    cout<<"Direccion: "<<getDireccion()<<endl;
    cout<<"Telefono: "<<getTelefono()<<endl;
    cout<<"RFC: "<<getRFC()<<endl;
    cout<<"Correo electronico: "<<correo<<endl;
    cout<<"Codigo de huesped: "<<codigoHuesped<<endl;
    cout<<"Visitas registradas: "<<visitas<<endl;

    cout<<"Nivel de Lealtad: ";
    if(visitas >= 10) {
        cout << "Oro (20% de descuento en rentas)" << endl;
    } 
    else if(visitas >= 5) {
        cout << "Plata (10% de descuento en rentas)" << endl;
    } 
    else {
        cout << "Clasico (Tarifa estandar)" << endl;
    }
}