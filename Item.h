#ifndef Item_h_
#define Item_h_

class Item{
    private:
        string descripcion,
               nombre,
               tipo;//"Armadura", "Curación" o "Ataque"
        int peso;
    public:
        Item();
        Item(string, string, int, string);
        string getNombre() const;
        string getDescripcion()const ;
        int getPeso() const ;
        string getTipo() const;
        virtual void mostrar()=0;//quite =0;  //Polimorfismo. Imprime el nombre, descripción, peso y tipo del item
};

Item::Item(){
    descripcion = "";
    nombre = "";
    tipo = "";
    peso = 0;
}

Item::Item(string descripcion_, string nombre_, int peso_, string tipo_){
    descripcion = descripcion_;
    nombre = nombre_;
    tipo = tipo_;
    peso = peso_;
}

string Item::getNombre()const {
    return nombre;
}

string Item::getDescripcion() const {
    return descripcion;
}

int Item::getPeso()const {
    return peso;
}

string Item::getTipo() const {
    return tipo;
}

//Imprime el nombre, descripción, peso y tipo del item
void Item::mostrar(){
    cout << "_______________" << endl << endl;
    cout << "Nombre: " << nombre << endl;
    cout << descripcion << endl;
    cout << "Peso: " << peso << endl;
    cout << "Tipo: " << tipo << endl;
}

#endif