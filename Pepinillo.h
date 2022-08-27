#ifndef Pepinillo_h_
#define Pepinillo_h_

#include "Character.h"
#include "Habitacion.h"
#include "ItemCuracion.h"

class Pepinillo: public Character{
    private:
        //Lista de insultos que el jugador puede usar
        string insultos[10] = {"Chinga tu madre", "Puta madre", "Fucking stupid", "Me lleva la verga", "MALDITO!!!", "You FUCKING diaper-man", "La concha, PELOTUDO!!!", "FUUUUUUCCCCCCKKK!!!!", "MALDITA RATA PELUDA!!!", "You son of a BITCH"};
        int capacidadCarga,
            currentItems; //Número actual de items del inventario
        Item* inventario[10]; 
        Habitacion* habActual; //Habitación en la que se encuentra el jugador
    public:
        Pepinillo();
        Pepinillo(string, int, Habitacion*, int); 
        void insultar(); //Con un número random entre 0 a 9 elige uno de los insultos del arreglo y lo imprime
        void gritar(); //Polimorfismo. Sobreescribe el método gritar.
        int getCapacidadCarga(); 
        int getCurrentSize(); //Devuelve el número de items en el invetario
        Habitacion* getHabActual();
        void setHabActual(Habitacion*);
        void tomarItem(Item*); //Checa que el invetario no este lleno. Que la capacidad de carga no se exceda cuando agrego el nuevo item. Agrega el item y suma 1 a currentItems. Imprime mensajes si las condiciones no se cumplen
        void dejarItem(Item*); //Recorre todos los apuntadores, a partir de la posicion del item que se quiere dejar, hacia atras. item(i+1) = item(i). Resta 1 a currentItems y agrega el item a la habitación actual
        bool buscaItem(string); //Regresa true si el string(nombre del item) esta en el inventario
        int posicionItem(string); //Regresa la posición del string(nombre del item) en el inventario
        Item* getInventario(int);
        bool caminar(string); //Regresa true si la habitación en la dirección que recibe no es un nullptr y el enemigo de la habitación ya fue derrotado
        bool curar(string); //Recibe un string(nombre del item) y guarda la posición en la que esta. Si el item es de tipo ItemCuración - con downcasting - se obtiene la recuperación del item y se actualiza la health del jugador. Se imprime cuando aumento la salud. Se deja el item en la habitación
        void atacar(Character*); //Polimorfismo. Sobreecribir método atacar. Agrega insultar y gritar
        void estornudar(); //Revisa si el jugador tiene la "bocina" en el inventario y este en los ductos. Si se cumplen las condiciones vence automaticamente al enemigo de los ductos
        //string mostrar();
        friend ostream& operator<< (ostream&, const Pepinillo&); //Sobrecarga de operadores para imprimir el inventario y salud del jugador
};

Pepinillo::Pepinillo(){
    capacidadCarga = 0;
    currentItems = 0; 
}

Pepinillo::Pepinillo(string nombre_, int health_, Habitacion* habActual_, int capacidadCarga_): Character(nombre_, health_){
    capacidadCarga = capacidadCarga_; 
    currentItems = 0;
    habActual = habActual_;
}

//Con un número random entre 0 a 9 elige uno de los insultos del arreglo y lo imprime
void Pepinillo::insultar(){
    srand((unsigned) time(0));
    int randomNumber = rand()%10;
    cout << insultos[randomNumber] << endl;
}

//Polimorfismo. Sobreescribe el método gritar.
void Pepinillo::gritar(){
    Character::gritar();
    cout << "MALDITO ANIMAL!!!!!" << endl;
}

int Pepinillo::getCapacidadCarga(){
    return capacidadCarga; 
}

//Devuelve el número de items en el invetario
int Pepinillo::getCurrentSize(){
    return currentItems;
}

Habitacion* Pepinillo::getHabActual(){
    return habActual;
}

void Pepinillo::setHabActual(Habitacion* habActual_){
    habActual = habActual_;
}

//Checa que el invetario no este lleno. Que la capacidad de carga no se exceda cuando agrego el nuevo item. Agrega el item y suma 1 a currentItems. Imprime mensajes si las condiciones no se cumplen
void Pepinillo::tomarItem(Item* item){
    if (currentItems < 10){
        int pesoTotal = 0;
        for (int j = 0; j < currentItems; j++){
            pesoTotal += inventario[j] -> getPeso();
        }
        if(capacidadCarga >= pesoTotal + item -> getPeso()){
            inventario[currentItems] = item;
            currentItems ++;
            cout << "El item " << item -> getNombre() << " ha sido agregado a tu pepinvetario." << endl;
        }
        else {
            cout << "El item es muy pesado" << endl;
            cout << "Capacidad de carga: " << capacidadCarga << " Peso actual:" << pesoTotal << " Peso del item: " << item -> getPeso() << endl;
            cout << "Intenta tirar items de tu inventario o INTENTA HACER MÁS EJERCICIO PARA LEVANTAR MÁS, PEPINILLO FLÁCIDO!" << endl;
        }
    }
    else{
        cout << "Tu inventario esta lleno. Intenta tirar items de tu inventario." << endl;
    }
}

//Recorre todos los apuntadores, a partir de la posicion del item que se quiere dejar, hacia atras. item(i+1) = item(i). Resta 1 a currentItems y agrega el item a la habitación actual
void Pepinillo::dejarItem(Item* item){
    int posicion = posicionItem(item -> getNombre());
    for (int j = posicion; j < currentItems - 1; j++){
        inventario[j] = inventario[j + 1];
    }
    currentItems--;
    getHabActual() -> agregarItem(item);
}

//Regresa true si el string(nombre del item) esta en el inventario
bool Pepinillo::buscaItem(string item){
    for (int i = 0; i < currentItems; i++){
        if (item == inventario[i] -> getNombre()){
            return true;
        }
    }
    return false;
}

//Regresa la posición del string(nombre del item) en el inventario
int Pepinillo::posicionItem(string item){
    int posicion;
    for (int i = 0; i < currentItems; i++){
        if (item == inventario[i] -> getNombre()){
            posicion = i;;
        }
    }
    return posicion; 
}

Item* Pepinillo::getInventario(int posicion){
    return inventario[posicion]; 
}

//Regresa true si la habitación en la dirección que recibe no es un nullptr y el enemigo de la habitación ya fue derrotado
bool Pepinillo::caminar(string direccion){
    Habitacion* nextRoom = getHabActual() -> getSalida(direccion);
    if (nextRoom != nullptr && getHabActual() -> enemigoDerrotado()){
        setHabActual(nextRoom);
        return true;
    }
    else{
        setHabActual(habActual);
        return false;
    }
}

//Recibe un string(nombre del item) y guarda la posición en la que esta. Si el item es de tipo ItemCuración - con downcasting - se obtiene la recuperación del item y se actualiza la health del jugador. Se imprime cuando aumento la salud. Se deja el item en la habitación
bool Pepinillo::curar(string potion){
    int posicion = posicionItem(potion);
    Item* potionItem = inventario[posicion];
    if (ItemCuracion* c = dynamic_cast <ItemCuracion*> (potionItem)){
        actualizaHealth(c -> getRecuperacion());
        dejarItem(c);
        cout << "Salud: +" << c -> getRecuperacion() << endl;
        return true;
    }
    else{
        //cout << "No tienes items de curación en tu inventario" << endl;
        return false;
    }
}

//Polimorfismo. Sobreecribir método atacar. Agrega insultar y gritar
void Pepinillo::atacar(Character* enemigo_){
    gritar();
    insultar();
    Character::atacar(enemigo_);
}

//Revisa si el jugador tiene la "bocina" en el inventario y este en los ductos. Si se cumplen las condiciones vence automaticamente al enemigo de los ductos
void Pepinillo::estornudar(){
    bool gotBocina = buscaItem("bocina");
    if (gotBocina){
        if ("Ductos" == getHabActual() -> getNombre()){
            getHabActual() -> getEnemigo() -> setDerrotado(true);
            cout << "ACHUUUUUUUUUU!!!!" << endl; 
            cout << "La reina rata se murió del miedo de que tengas covid" << endl;  
        }
        else{
            cout << "No puedes estornudar aqui. Hay covid, se responsable" << endl;
        }
    }
    else{
        cout << "No puedes estornudar, eres un pepinillo. Busca la bocina" << endl;
    }
}

//Sobrecarga de operadores para imprimir el inventario y salud del jugador
ostream& operator<< (ostream& salida, Pepinillo& pepinillo_){
    salida << "____________________\n\n";
    salida << "Salud: " << pepinillo_.getHealth() << "\n";
    salida << "<- Pepinventario ->\n";
    for (int i = 0; i < pepinillo_.getCurrentSize(); i++){
        salida << i + 1 << ". " << pepinillo_.getInventario(i) -> getNombre() << "\n";
    }
    return salida;
}

#endif