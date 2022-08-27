#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <stdlib.h>

using namespace std;

#include "Pepinillo.h"
#include "ItemArmadura.h"
#include "Game.h"

//Leer descripcion de habitaciones, items y enemigos
vector<string> leerArchivo(){
    //Declaro y abro archivo
    ifstream archivo;
    archivo.open("descripcion.txt");
    vector<string> descripciones; // Vector para guardar descripciones
    if (archivo.is_open()){
        string linea;
        while(getline(archivo,linea)){ //Leo la línea
            descripciones.push_back(linea);
        }
        archivo.close(); //Cerrar archivo
    }
    else{
        //Si no pudo abrir el archivo cierro el flujo hacia el archivo
        cout << "Error de lectura de archivo" << endl;
    }
    return descripciones;
}

void imprimeBienvenida(){
    // Get schwifty
    //delayPuntos(0.5);
    cout << endl << "Oh, yeah!";
    //delayPuntos(0.1);
    cout << endl << "You gotta get schwifty ";
    //delayPuntos(0.1);
    cout << endl << "You gotta get schwifty in here ";
    //delayPuntos(0.1);
    cout << endl << "It's time to get schwifty " << endl;
    //delayPuntos(0.1);
    cout << endl << "Oh, yeah! ";
    //delay(0.1);
    cout << endl << "SHIT ON THE FLOOR!" << endl << endl << endl;
    
    //Pepinillo en la barra Escena 1
    cout << "La musica te despierta. Estas acostado en ...¿una barra de cocina?" << endl;
    cout << "OH NOOOOO! Sos un pepinisho" << endl;
    cout << "Necesitas ayuda. Ves un telefono en el otro lado de la barra." << endl;
    cout << "Escribe la palabra 'ir' para acercarte al telefono." << endl << ">>>> ";
    string input;
    //Se le pide el input, si no lo escribe bien vuelve a pedirlo
    do{
        try{
            cin >> input;
            if (input != "ir"){
                cout << "Ecribe 'ir', exactamente como se ve. " << endl <<  ">>>> ";
            }
        }
        catch (const char* msg){
            cerr << msg << endl;
        }
    }
    while(input != "ir");
    
    cout << "Nunca has sido un pepinillo (DUH!). Tu primer intento moviendote (girando) no sale muy bien, giras al lado contrario y tiras una manzana. \nMientras te preparas para girar de nuevo hacia el telefono escuchas unos sonidos de la sala\nTIKKK!\nTIKKK!\nTIKKK!\nTIKKK!" << endl;
    cout << "Te pones nervioso y entras en panico, porque sabes quien se aproxima.\nZABUUU!\nUn perro gigante - al menos para un pepinillo - fuerte,  de esos perros que intimidan hasta a las personas. Muy hambrienta, comida favorita pepinillos asustados." << endl;
    cout << "Giras lo más rápido que puedes hacia el telefono, pero los nervios te hicieron sudar jugo de pepinillo y resbalaste al bote de basura." << endl << endl;

    //Pepinillo camión de basura Escena 2
    cout << "Te despiertas en un lugar apestoso. No sabes cuanto tiempo ha pasado.\nTe sientes extrañamente fuerte, los jugos de basura te han fortalecido (EEWWW)" << endl;
    cout << "Encuentras unos palillos y te los encajas para poder moverte. Te das cuenta que estas en un camión de basura.\nEscribe la palabra 'explorar' para investigar tu alrededor." << endl << ">>>> ";
    string input2;
    //Se le pide el input, si no lo escribe bien vuelve a pedirlo
    do{
        try{
            cin >> input2;
            if (input2 != "explorar"){
                cout << "Ecribe 'explorar', exactamente como se ve. " << endl << ">>>> ";
            }
        }
        catch (const char* msg){
            cerr << msg << endl;
        }

    }
    while(input2 != "explorar");

    cout << "Al explorar encuentras una caja de cerial con una mapa donde esta una farmacia que tiene la vacuna Anti-Pepinillo para curar tu pepinismo\nTe asomas para ver si estas cerca pero de repente escuchas un ruido e investigas." << endl;
    cout << "OUH SHiT! El ruido era una rata gigante. ¿Que haces correr o pelear?" << endl << ">>>> ";
    string input3;
    bool acabado = false;
    //Se le pide el input, si no lo escribe bien vuelve a pedirlo
    do{
        try{
            cin >> input3;
            if (input3 != "correr" && input3 != "pelear"){
                cout << "Ecribe 'correr' o 'pelear', exactamente como se ve. " << endl << ">>>> ";
                acabado = true;
            }
            else{
                acabado = false;
            } 
        }
        catch (const char* msg){
            cerr << msg << endl;         
        }
    }
    while(acabado);
    
    if (input3 == "correr"){
        cout << "NOOOOOOOO!" << endl << "Un pepinillo que se respeta nunca huye del peligro" << endl << "PELEA!" << endl;
    }

    cout << "Peleaste con la rata gigante. Lamentablemente perdiste un brazito de palillo y saltas del camión para evitar la muerte" << endl;
    cout << "Al parecer los dioses de los pepinillos te favorecen y estas frente al centro comercial en el cual esta la farmacia con la vacuna." << endl << endl << endl << endl;

    //Titulo del juego
    cout << "Bievenido a ";
    //delayPuntos(0.5);
    cout << endl << endl;
    cout << "d8888b. db       .d88b.   .d88b.  d8888b. db    db\n88  `8D 88      .8P  Y8. .8P  Y8. 88  `8D `8b  d8'\n88oooY' 88      88    88 88    88 88   88  `8bd8'\n88~~~b. 88      88    88 88    88 88   88    88\n88   8D 88booo. `8b  d8' `8b  d8' 88  .8D    88\nY8888P' Y88888P  `Y88P'   `Y88P'  Y8888D'    YP\n\nd8888b. d888888b  .o88b. db   dD db      d88888b .d8888.\n88  `8D   `88'   d8P  Y8 88 ,8P' 88      88'     88'  YP\n88oodD'    88    8P      88,8P   88      88ooooo `8bo.\n88~~       88    8b      88`8b   88      88~~     `Y8b.\n88        .88.   Y8b  d8 88 `88. 88booo. 88.     db   8D\n88      Y888888P  `Y88P' YP   YD Y88888P Y88888P `8888Y'";
    cout << endl << endl;
}

void imprimeDespedida(){
    //Imprime titulo del juego
    cout << endl << endl << "Gracias por jugar" << endl << endl << endl;
    cout << "d8888b. db       .d88b.   .d88b.  d8888b. db    db" << endl;
    //delay(0.5);
    cout << "88  `8D 88      .8P  Y8. .8P  Y8. 88  `8D `8b  d8'" << endl;
    //delay(0.5);
    cout << "88oooY' 88      88    88 88    88 88   88  `8bd8'" << endl;
    //delay(0.5);
    cout << "88oooY' 88      88    88 88    88 88   88  `8bd8'" << endl;
    //delay(0.5);
    cout << "88~~~b. 88      88    88 88    88 88   88    88" << endl;
    //delay(0.5);
    cout << "88   8D 88booo. `8b  d8' `8b  d8' 88  .8D    88" << endl;
    //delay(0.5);
    cout << "Y8888P' Y88888P  `Y88P'   `Y88P'  Y8888D'    YP" << endl << endl;
    //delay(0.5);
    cout << "d8888b. d888888b  .o88b. db   dD db      d88888b .d8888." << endl;
    //delay(0.5);
    cout << "88  `8D   `88'   d8P  Y8 88 ,8P' 88      88'     88'  YP" << endl;
    //delay(0.5);
    cout << "88oodD'    88    8P      88,8P   88      88ooooo `8bo." << endl;
    //delay(0.5);
    cout << "88~~       88    8b      88`8b   88      88~~     `Y8b." << endl;
    //delay(0.5);
    cout << "88        .88.   Y8b  d8 88 `88. 88booo. 88.     db   8D" << endl;
    //delay(0.5);
    cout << "88      Y888888P  `Y88P' YP   YD Y88888P Y88888P `8888Y'" << endl << endl;

    //delay(1);

    //Imprime nombres de los creadores, sus servilletas
    cout << endl << endl << "Creado por ";
    //delayPuntos(0.5);
    cout << "JORGE CARRILLO Y FERNANDO CAMACHO" << endl << endl;
}

//Métodos para realizar acciones

//Ayuda
void ayuda(){
    string palabras[9] = {"ayuda", "tomar", "dejar", "ir", "inventario", "usar", "atacar", "estornudar", "maldecir"};
    cout << "_____________________________________" << endl << endl;
    cout << "<- Acciones que se pueden realizar ->" << endl << endl;
    for (int i = 0; i < 9; i++){
        cout << i + 1 << ". " << palabras[i] << endl;
    }
    cout << "_____________________________________" << endl << endl;
}

//Tomar
void tomar(Pepinillo* pepinillo_, string itemTomado){
    Habitacion* habActual = pepinillo_ -> getHabActual();
    int num = habActual -> buscaItem(itemTomado); //veo si está en el cuarto (posicion dentro del vector)
    if (num != -1){
        Item* itemATomar = habActual -> getItem(num);
        if (ItemArmadura* c = dynamic_cast <ItemArmadura*> (itemATomar)){// Revisa si es de tipo armadura para aumentaar la salud en 20 puntos 
            pepinillo_ -> tomarItem(c);
            habActual -> eliminarItem(num);
            pepinillo_ -> actualizaHealth(c -> getProteccion());
            cout << "Salud: +" << c -> getProteccion() << endl;
            itemATomar -> mostrar();
        }
        else{
            pepinillo_ -> tomarItem(itemATomar);// Se agrega el item deseado al inventario 
            habActual -> eliminarItem(num);
            itemATomar -> mostrar();
        }
    }
    else{// Si el item no se encuentra en la habitación, se despliega la descripción de la habitación 
        cout << "Ese objeto no se encuentra en esta habitacion..." << endl;
        habActual -> descripcionHab();
    }
}

//Dejar
void dejar(Pepinillo* pepinillo_, string itemDejado){
    Habitacion* habActual = pepinillo_ -> getHabActual();
    if (pepinillo_ -> buscaItem(itemDejado)){
        int posicionItem = pepinillo_ -> posicionItem(itemDejado);
        Item* itemADejar = pepinillo_ -> getInventario(posicionItem);
        pepinillo_ -> dejarItem(itemADejar);
        itemADejar -> mostrar();
        cout << "Ups. Se te cayo el item " << itemDejado << endl;
    }
    else{
        cout << "No tienes ese item en el pepinventario. Revisa tu pepinventario o escribe bien." << endl;
    }
}

//Ir 
void ir(Pepinillo* pepinillo_, string direccion_){
    Enemigo* enemigo = pepinillo_ -> getHabActual() -> getEnemigo();
    if (pepinillo_ -> caminar(direccion_)){
        Habitacion* habActual = pepinillo_ -> getHabActual();
        cout << "Te has movido hacia el " << direccion_ << endl;
        habActual -> descripcionHab(); 
    }
    else{
        cout << "No hay salida en esa dirección o no has derrotado al enemigo." << endl; // En el caso de que no sea posible ir a esa direccion (hay una pared), se debe introducir otra dirección
        cout << enemigo -> getNombre() << endl << enemigo -> getDescripcion() << endl;
    }
}

//Inventario 
void inventario(Pepinillo* pepinillo_){
    cout << *pepinillo_;
}

//Usar
void usar(Pepinillo* pepinillo_, string itemUsado){
    int posicionItem = pepinillo_ -> posicionItem(itemUsado);
    Item* itemAUsar = pepinillo_ -> getInventario(posicionItem);
    if (pepinillo_ -> buscaItem(itemUsado) && pepinillo_ -> curar(itemUsado)){//Se revisa si es de tipo curacion para curar la salud
        cout << "Haz consumido " << itemUsado << "." << endl;
    }
    else if (ItemArmadura* armadura = dynamic_cast <ItemArmadura*> (itemAUsar)){ // Se revisa si es de tipo armadura, en ese caso se le informa que ya la trae puesta 
        cout << "Los pepinillos son fuertes, no nesecitas armadura :)" << endl << "Susurrado:" << endl << "No te creas ya traes puesta tu armadura. Los pepinillo son debiles :(" << endl;
    }
    else if (ItemAtaque* ataque = dynamic_cast <ItemAtaque*> (itemAUsar)){//Se revisa si es de tipo ataque ya que se necesita otro comando para usar un item tipo ataque 
        cout << "Para usar tu arma tienes que utilizar el comando ataque. A menos que quieras rasurarte con ella." << endl;
    }
    else{
        cout << "No tienes ese item en el pepinventario. Revisa tu pepinventario o escribe bien." << endl;
    }
}

//Atacar
void atacar(Pepinillo* pepinillo_, string itemDeAtaque){
    Enemigo* enemigo_ = pepinillo_ -> getHabActual() -> getEnemigo();
    if(pepinillo_ -> buscaItem(itemDeAtaque)){
        cout << "_________________________" << endl<<endl;
        cout << "Musica epica empieza a sonar" << endl;
        cout << "FIGHT!!" << endl << endl;
        pepinillo_ -> atacar(enemigo_);
        cout << endl << endl << "Ataque " << enemigo_ -> getNombre() << endl << endl; 
        enemigo_ -> atacar(pepinillo_);
        cout << endl << endl << enemigo_ -> getNombre() << ": Plañiras por este día!!!!!" << endl; 
        cout << endl << pepinillo_ -> getNombre() << ": " << "Feliz Navidad, inmundo Animal y Feliz Año Nuevo." << endl;
        cout << "FIGHT OVER" << endl;
        cout << "_________________________" << endl;
        enemigo_ -> setDerrotado(true);
    }
    else{
        cout << "No tienes un arma ¿Con qué piensas atacar, con tus dientes?" << endl; 
    }
}

//Maldecir
void maldecir(Pepinillo* pepinillo_){
    pepinillo_ -> gritar();
    pepinillo_ -> insultar();
}

//Estornudar
void estornudar(Pepinillo* pepinillo_){
    pepinillo_ -> estornudar(); 
}

//Método para realizar una acción dependiendo al input del jugador
//Desicion
void desicion(Pepinillo* pepinillo_, string input){
    if(input == "ayuda"){
        ayuda();
    }
    else if(input == "tomar"){
        cout << "¿Que item quieres tomar?" << endl << ">>>> ";
        string itemTomar;
        cin >> itemTomar;
        tomar(pepinillo_, itemTomar);
    }
    else if(input == "dejar"){
        cout << "¿Que item quieres dejar?" << endl << ">>>> ";
        string itemDejar;
        cin >> itemDejar;
        dejar(pepinillo_, itemDejar);
    }
    else if(input == "ir"){
        cout << "¿A dónde quieres ir?" << endl << ">>>> ";
        string direccion;
        cin >> direccion;
        ir(pepinillo_, direccion);
    }
    else if(input == "inventario"){
        inventario(pepinillo_);
    }
    else if(input == "usar"){
        cout << "¿Que quieres usar?" << endl << ">>>> ";
        string itemUsar;
        cin >> itemUsar;
        usar(pepinillo_, itemUsar);
    }
    else if(input == "atacar"){
        cout << "¿Con que quieres atacar?" << endl << ">>>> ";
        string itemAtacar;
        cin >> itemAtacar;
        atacar(pepinillo_, itemAtacar);

    }
    else if(input == "estornudar"){
        estornudar(pepinillo_);
    }
    else if(input == "maldecir"){
        maldecir(pepinillo_);
    }
    else{
        cout << "No reconozo esa palabra." << endl;
    }
}

int main(){
    // CREACIÓN DE OBJETOS

    //Creación de jugador
    Pepinillo* pepinillo;
    //Creación de enemigos
    Enemigo *enemigoPetCo, *enemigoDuctos;
    //Creación de habitaciones
    Habitacion *room1, *bestBuy, *petCo, *ductos, *cuartoConserje, *farmacia;
    //Creación de items
    Item *piernas, *brazos, *corcholata, *bocina, *espada, *jugoPepinillo, *sobreKetchup, *pipi, *cura, *collar, *barilla;

    //INICIALIZACIÓN DE LAS PARTES DEL JUEGO (JUGADOR, ENEMIGOS, HABITACIONES, ITEMS)

    //Lee y guarda las descripciones de items, habitaciones y enemigos
    vector<string> descripciones = leerArchivo();
    //Incializar jugador
    pepinillo = new Pepinillo("Pickle Rick", 40, nullptr, 40);
    //Incializar enemigos
    enemigoPetCo = new Enemigo("Señor Hamster Rogelio", 40, descripciones[0], 10, false);
    enemigoDuctos = new Enemigo("Reina Rata", 60, descripciones[1], 15, false);
    //Incializar habitaciones 
    room1 = new Habitacion("Centro comercial", "Estas fuera de las tiendas, con BestBuy al norte", nullptr);
    bestBuy = new Habitacion("BestBuy", descripciones[2], nullptr);
    petCo = new Habitacion("PetCo", descripciones[3], enemigoPetCo);
    cuartoConserje = new Habitacion("Cuarto Conserje", descripciones[4], nullptr);
    ductos = new Habitacion("Ductos", descripciones[5], enemigoDuctos);
    farmacia = new Habitacion("Farmacia", descripciones[6], nullptr);
    //Incializar items
    piernas = new ItemArmadura(descripciones[7],"piernas", 10, "armadura", 20);
    brazos = new ItemArmadura(descripciones[8], "brazos", 5, "armadura", 20);
    corcholata = new ItemArmadura(descripciones[9], "corcholata", 2, "armadura", 15);
    bocina = new ItemAtaque(descripciones[10], "bocina", 5, "ataque", 100);
    espada = new ItemAtaque(descripciones[11], "excalibur", 4, "ataque", 20);
    jugoPepinillo = new ItemCuracion(descripciones[12], "jugo", 2, "curación", 15);
    sobreKetchup = new ItemCuracion(descripciones[13], "ketchup", 2, "curación", 10);
    pipi = new ItemCuracion(descripciones[14], "pipi", 1, "curación", 5);
    cura = new ItemCuracion(descripciones[15], "cura", 1, "curación", 100);
    collar = new ItemAtaque(descripciones[16], "collar", 3, "ataque", 25); 
    barilla = new ItemAtaque(descripciones[17], "barilla", 5, "ataque", 20); 
    //Colocar al jugador
    pepinillo -> setHabActual(room1);
    //Agregar items a las habitaciones
        //BestBuy
    bestBuy -> agregarItem(piernas);
    bestBuy -> agregarItem(brazos);
    bestBuy -> agregarItem(jugoPepinillo);
    bestBuy -> agregarItem(espada);
    bestBuy -> agregarItem(corcholata);
        //PetCo
    petCo -> agregarItem(pipi);
    petCo -> agregarItem(collar); 
        //Cuarto Conserje
    cuartoConserje -> agregarItem(sobreKetchup);
    cuartoConserje -> agregarItem(bocina);
        //Ductos
    ductos -> agregarItem(barilla); 
        //Farmacia
    farmacia -> agregarItem(cura);
        
    //Set salidas
    room1 -> setSalida(bestBuy, nullptr, nullptr, nullptr);
    bestBuy -> setSalida(cuartoConserje, room1, nullptr, petCo);
    cuartoConserje -> setSalida(ductos, bestBuy, nullptr, nullptr);
    ductos -> setSalida(farmacia, cuartoConserje, nullptr, nullptr);
    petCo -> setSalida(farmacia, nullptr, bestBuy, nullptr);


    //INICIO DE JUEGO 

    //Impresión de la bienvenida
    imprimeBienvenida();

    cout << "Escribe todo en minusculas. No nos gusta trabajar con mayusculas." << endl;
    cout << "Para saber que acciones puedes realizar escribe la palabra: 'ayuda'." << endl << ">>>> ";
    string input1;
    do{
        cin >> input1;
        if (input1 != "ayuda"){
            cout << "Ecribe 'ayuda', exactamente como se ve. Todavia no sabes que otra cosa hacer." << endl <<  ">>>> ";
        }
    }
    while(input1 != "ayuda");
    
    //Impresión de las acciones que puede realizar el jugador
    ayuda();

    bool tengoCura = pepinillo -> buscaItem("cura");

    while(pepinillo -> getHabActual() != farmacia && !tengoCura){
        string input2;
        Habitacion* habitacionActual = pepinillo -> getHabActual();
        do{
            cout << endl << "¿Que quieres hacer?" << endl << ">>>> ";
            cin >> input2;
            desicion(pepinillo, input2);
        }
        while(pepinillo -> getHabActual() == habitacionActual);
    }
    
    //Game over. Impresión de la despedida
    imprimeDespedida();

    return 0;
}