#ifndef ItemCuracion_h
#define ItemCuracion_h

#include "Item.h"

class ItemCuracion: public Item{
    private:
        int recuperacion; //Atributo especifico de ItemCuración
    public:
        ItemCuracion();
        ItemCuracion(string, string, int, string, int); 
        int getRecuperacion() const ; 
        void mostrar(); //Polimorfismo. Método sobreescrito. Al método mostrar se le agrega el nuevo atributo recuperación
};

ItemCuracion::ItemCuracion(){
    recuperacion = 0; 
}

ItemCuracion::ItemCuracion(string descripcion_, string nombre_, int peso_, string tipo_,  int recuperacion_): Item( descripcion_, nombre_, peso_, tipo_){
    recuperacion = recuperacion_; 
}

int ItemCuracion::getRecuperacion()const {
    return recuperacion; 
}

//Al método mostrar se le agrega el nuevo atributo recuperación
void ItemCuracion::mostrar(){
    Item::mostrar(); 
    cout << "Recuperación: +" << recuperacion << endl; 
    cout << "_______________" << endl << endl;
}

#endif 