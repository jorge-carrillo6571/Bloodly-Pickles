#ifndef Habitacion_h_
#define Habitacion_h_

#include "Item.h"
#include "Enemigo.h"

class Habitacion{
    private:
        string nombre,
               descripcion;
        vector<Item*> items; //Vector donde se guardan los items que se encuentran en la habitación
        Habitacion* salidas[4]; 
        Enemigo* enemigo; //Apuntor al enemigo de la habitación, sino hay enemigo es un nullptr
    public:
        Habitacion();
        Habitacion(string, string, Enemigo*);
        string getNombre();
        string getDescripcion();
        Habitacion* getSalida(string); //Recibe una dirección (norte, sur, este u oeste) y regresa un apuntador a la habitación que esta en esa dirección, no habitación regresa un nullptr.
        int numSalida(string); //Convierte el string(dirección) que recibe a un número. norte = 0, sur = 1, este = 2, oeste = 3
        void setSalida(Habitacion*, Habitacion*, Habitacion*, Habitacion*); 
        Item* getItem(int); //Revisa que el número no sea menor a 0 o mayor al número de items en la habitación y regresa un apuntor al item en la posición del vector que se paso.
        void eliminarItem(int); //Saca el apuntor a item del vector en la posición que recibe.
        void agregarItem(Item*); //Recibe un apuntador a item y lo agrega al final dell vector.
        int buscaItem(string); //Recibe un string(nombre del item) y regresa la posición en la que esta ese item o -1 si el item no esta.
        Enemigo* getEnemigo(); 
        void descripcionHab(); //Imprime el nombre, la descripción y muestra los items que se encuentran en la habitación.
        bool enemigoDerrotado(); //Devuelve el valor booleano de derrotado (si e enemigo ha sido vencido).
};

Habitacion::Habitacion(){
    nombre = "NO NAME ROOM";
    descripcion = "NO SE DONDE ESTOY";
    for (int i = 0; i < 4; i++){
        salidas[i] = nullptr;
    }
    enemigo = nullptr;
}

Habitacion::Habitacion(string nombre_, string descripcion_, Enemigo* enemigo_){
    nombre = nombre_;
    descripcion = descripcion_;
    enemigo = enemigo_;
    for (int i = 0; i < 4; i++){
        salidas[i] = nullptr;
    }
}

string Habitacion::getNombre(){
    return nombre;
}

string Habitacion::getDescripcion(){
    return descripcion;
}

//Recibe una dirección (norte, sur, este u oeste) y regresa un apuntador a la habitación que esta en esa dirección, no habitación regresa un nullptr.
Habitacion* Habitacion::getSalida(string direccion){
    int num = numSalida(direccion); 
    if (num >= 0){
        return salidas[num];
    }
    else{
        return nullptr;
    }
} 

//Convierte el string(dirección) que recibe a un número. norte = 0, sur = 1, este = 2, oeste = 3
int Habitacion::numSalida(string direccion){
    if (direccion == "norte"){
        return 0;
    }
    else if (direccion == "sur"){
        return 1;
    }
    else if (direccion == "este"){
        return 2;
    }
    else if (direccion == "oeste"){
        return 3;
    }
    else{
        return -1;
    }
}

void Habitacion::setSalida(Habitacion* hNorte, Habitacion* hSur, Habitacion* hEste, Habitacion* hOeste){
    salidas[0] = hNorte;
    salidas[1] = hSur;
    salidas[2] = hEste;
    salidas[3] = hOeste;
}

//Revisa que el número no sea menor a 0 o mayor al número de items en la habitación y regresa un apuntor al item en la posición del vector que se paso.
Item* Habitacion::getItem(int posicion){
    if (posicion >= 0 && posicion < items.size()){
        return items[posicion];
    }
    else{
        return nullptr;
    }
}

// Saca el apuntor a item del vector en la posición que recibe.
void Habitacion::eliminarItem(int posicion){
    items.erase(items.begin() + posicion);
}

//Recibe un apuntador a item y lo agrega al final dell vector.
void Habitacion::agregarItem(Item* item){
    items.push_back(item);
}

//Recibe un string(nombre del item) y regresa la posición en la que esta ese item o -1 si el item no esta.
int Habitacion::buscaItem(string nombreItem){
    for (int i = 0; i < items.size(); i++){
        if (nombreItem == items[i] -> getNombre()){
            return i;
        }
    }
    return -1;
}

Enemigo* Habitacion::getEnemigo(){
    return enemigo;
}

//Imprime el nombre, la descripción y muestra los items que se encuentran en la habitación.
void Habitacion::descripcionHab(){
    cout << endl << "______________________________" << endl << endl;
    cout << nombre << endl;
    cout << descripcion << endl;
    cout << "Items: " << endl; 
    for (int i = 0; i < items.size(); i++){
        cout << items[i] -> getNombre() << endl;
    }
    cout << "______________________________" << endl << endl;
}

//Devuelve el valor booleano de derrotado (si e enemigo ha sido vencido).
bool Habitacion::enemigoDerrotado(){
    if (enemigo != nullptr){
        return enemigo -> getDerrotado();
    }
    else{
        return true;
    }
}

#endif 