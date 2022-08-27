#ifndef ItemArmadura_h
#define ItemArmadura_h

#include "Item.h"

class ItemArmadura: public Item{
    private:
        int proteccion; //Atributo especifico de ItemArmadura
    public:
        ItemArmadura();
        ItemArmadura(string, string,  int, string, int); 
        int getProteccion() const ; 
        void setProteccion(int);
        void mostrar(); //Polimorfismo. Método sobreescrito. Al método mostrar se le agrega el nuevo atributo protección
};

ItemArmadura::ItemArmadura(){
    proteccion = 0; 
}

ItemArmadura::ItemArmadura(string descripcion_, string nombre_, int peso_, string tipo_, int proteccion_): Item(descripcion_, nombre_, peso_, tipo_) {
    proteccion = proteccion_; 
}

int ItemArmadura::getProteccion() const {
    return proteccion; 
}

void ItemArmadura::setProteccion(int proteccion_){
    proteccion = proteccion_; 
    
}

//Al método mostrar se le agrega el nuevo atributo
void ItemArmadura::mostrar(){
    Item::mostrar(); 
    cout << "Protección: +" << proteccion << endl;
    cout << "_______________" << endl << endl; 
}

#endif 