#ifndef Character_h_
#define Character_h_

#include "Item.h"

class Character{
    private: 
        string nombre;
        int health;
    public:
        Character();
        Character(string, int);
        string getNombre();
        int getHealth();
        void setHealth(int);
        void actualizaHealth(int); //Le suma el valor que recibe al valor actual de health
        virtual void gritar() = 0; //Polimorfismo. Imprime un grito
        virtual void atacar(Character*) = 0; //Polimorfismo. Calcula un número random entre 0 a 2. Si sale dos el ataque falla. Imprime si el ataque falló o acertó
};

Character::Character(){
    nombre = "";
    health = 0;
}

Character::Character(string nombre_, int health_){
    nombre = nombre_;
    health = health_;
}

string Character::getNombre(){
    return nombre;
}

int Character::getHealth(){
    return health;
}

void Character::setHealth(int health_){
    health = health_;
}

//Le suma el valor que recibe al valor actual de health
void Character::actualizaHealth(int health_){
    health += health_;
}

//Polimorfismo. Imprime un grito
void Character::gritar(){
    cout << "AAAAAHHHHHHHH!!!!" << endl;
}

//Polimorfismo. Calcula un número random entre 0 a 2. Si sale dos el ataque falla. Imprime si el ataque falló o acertó
void Character::atacar(Character* atacado){
    srand((unsigned) time(0));
    int randomNumber = rand()%2;
    if (randomNumber == 2){
        cout << atacado -> getNombre() << " esquivo el ataque." << endl; 
    }
    else{
        atacado -> actualizaHealth(-20);
        cout << "El ataque acerto. GOLPE CRITICO!! -60 de HP" << endl;
    }
}

#endif