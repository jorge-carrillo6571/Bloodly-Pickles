#ifndef Enemigo_h_
#define Enemigo_h_

#include "Character.h"

// Se crea la clase Enemigo que hereda de Character
class Enemigo: public Character{
    private:
        string descripcion; 
        int danio; 
        bool derrotado;
    public:
        Enemigo();
        Enemigo(string, int, string, int, bool);
        string getDescripcion(); 
        int getDanio(); 
        bool getDerrotado();
        void setDerrotado(bool);
        void gritar(); 
        void atacar(Character*);
};

Enemigo::Enemigo(){
    descripcion = "";
    danio = 0;  
    derrotado = false;
}

Enemigo::Enemigo(string nombre_, int health_, string descripcion_, int danio_, bool derrotado_): Character(nombre_, health_){
    descripcion = descripcion_; 
    danio = danio_; 
    derrotado = false;
}

string Enemigo::getDescripcion(){
    return descripcion; 
}

int Enemigo::getDanio(){
    return danio; 
}

bool Enemigo::getDerrotado(){
    return derrotado;
}

void Enemigo::setDerrotado(bool derrotado_){
    derrotado = derrotado_;
}

void Enemigo::gritar(){
    Character::gritar(); // Se usa el método virtual que despliega un cout gritando 
    cout << "Maldito PEPINILLO!!!" << endl; 
}

void Enemigo::atacar(Character* pepinillo){
    gritar();
    Character::atacar(pepinillo);//Llama  a la función de atacar la cual mediant números aleatorios decide si el jugador recibe daño
}

#endif