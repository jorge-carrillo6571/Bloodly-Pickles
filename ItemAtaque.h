#ifndef ItemAtaque_h
#define ItemAtaque_h

#include "Item.h"

class ItemAtaque: public Item{
    private:
        int danio;  //Atributo especifico de ItemAtaque
    public:
        ItemAtaque();
        ItemAtaque(string, string,  int, string, int); 
        int getDanio() const ; 
        void mostrar(); //Polimorfismo. Método sobreescrito. Al método mostrar se le agrega el nuevo atributo danio(daño)
};

ItemAtaque::ItemAtaque(){
    danio = 0; 
}

ItemAtaque::ItemAtaque(string descripcion_, string nombre_, int peso_, string tipo_, int danio_): Item(descripcion_, nombre_, peso_, tipo_){
    danio = danio_; 
}

int ItemAtaque::getDanio() const {
    return danio; 
}

//Al método mostrar se le agrega el nuevo atributo danio(daño)
void ItemAtaque::mostrar(){
    Item::mostrar(); 
    cout << "Daño: " << danio << endl;
    cout << "_______________" << endl << endl;
}

#endif 