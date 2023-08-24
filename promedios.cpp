/**
Desarrolle un programa que permita cargar los datos de N alumnos de un curso, incluyendo de cada uno:
- Nombre y apellido
- Legajo
- Nota primer parcial
- Nota segundo parcial
- Domicilio (Calle, altura y código postal)

Y que, una vez finalizada la carga, permita mostrar por pantalla los datos de aquellos alumnos en condición de Promoción
(Se considera que un alumno está en condición de Promoción cuando sus notas en ambos parciales son 8 o más)
*/
/**
Mejora de AlumnosDelCurso, usando miembros con valores por default para ahorrar la función de inicialización

--CONSIGNA--
Extender el programa actual para que no se trate de cargar todos los Alumnos y luego se muestren algunos al final,
sino que tenga un menú con las siguientes opciones:
    * Cargar un Alumno (si es que hay lugar -- porque hay una posición con un Alumno vacío)
    * Mostrar los Alumnos cargados (no vacíos!)
    * Mostrar los Alumnos en condición de Promoción
    * Buscar un Alumno por legajo y mostrar sus datos
    * Buscar un Alumno por legajo y vaciarlo (poner su legajo en 0!)
*/

#include<iostream>


using namespace std;


struct Address{
    char nameAdress[40];
    int number;
};

struct Student{
    char fullName[40];
    int file;
    int firstPartial;
    int secondPartial;
    Address address;
};
void addStudent(Student students[], int cont) {
    int exit = 1;
    cout << endl;
    cout << "-------- Carga de Alumnos ----------" << endl;

    for (int i = 0; i < cont; i++) {
        if (students[i].file == 0 && exit == 1) {
            cout << "*** Ingresando alumno Nro *** " << i + 1 << endl;
            cout << endl;
            cin.ignore();
            cout << "Full Name: " << endl;
            cin.getline(students[i].fullName, 40);
            cout << "File Number: " << endl;
            cin >> students[i].file;
            cout << "First Partial: " << endl;
            cin >> students[i].firstPartial;
            cout << "Second Partial: " << endl;
            cin >> students[i].secondPartial;
            cin.ignore();
            cout << "Street Name: " << endl;
            cin.getline(students[i].address.nameAdress, 40);
            cout << "House Number: " << endl;
            cin >> students[i].address.number;
            cout << endl;
            cout << "Presione 'Enter' para continuar o '0' para salir." << endl;
            cin >> exit;
        }
    }
}

void printStudent(Student students[], int N) {
    cout << endl;
    cout << "-------- Alumnos cargados ----------" << endl;
    cout << endl;

    int estudiantesCargados = 0;

    for (int i = 0; i < N; i++) {
        if (students[i].file != 0) {
            cout << endl;
            cout << "***  Alumno N " << i + 1 << endl;
            cout << "Full Name: " << students[i].fullName << endl;
            cout << "File Number: " << students[i].file << endl;
            cout << "First Partial: " << students[i].firstPartial << endl;
            cout << "Second Partial: " << students[i].secondPartial << endl;
            cout << "Street Name: " << students[i].address.nameAdress << endl;
            cout << "Street Number: " << students[i].address.number << endl;
            estudiantesCargados++;
        }
    }

    cout << endl;
    cout << N - estudiantesCargados << " Disponibles para cargar." << endl;
}

void printStudentPromotion(Student students[], int N){
        cout <<endl;
        cout << "-------- Alumnos Promocionados ----------" << endl;

    for(int i = 0; i <= N-1; i ++){
        if(students[i].firstPartial >= 8 && students[i].secondPartial >= 8){
        cout <<endl;
        cout << "***  Alumno N "<< i << endl;
        cout << "Full Name: " << students[i].fullName << endl;
        cout << "File Number: " << students[i].file << endl;
        cout << "Firts Prtial: " << students[i].firstPartial << endl;
        cout << "Second Partial: " << students[i].secondPartial << endl;
        cout << "Street Name: " << students[i].address.nameAdress << endl;
        cout << "Street Number: " << students[i].address.number << endl;
        }
    }
}

void addStudentverify(Student students[],int N){
    int cont = 0;

        for(int i = 0; i <= N-1; i++){

            if(students[i].file == 0){
            cont = cont + 1;
            }

        }
        if(cont > 0) {

                addStudent(students, cont);

            }else {
        cout << "**** No hay espacio disponible para nuevos estudiantes. ***" << endl;
        cout << endl;
    }

}
void startStudents(Student students[], int N){
    for(int i = 0 ; i <= N-1; i++){
        students[i].file = 0;
    };
}
void menu(Student students[], int &option,int N){
    cout << endl;
    cout << "1- Cargar un Alumno (si es que hay lugar -- porque hay una posición con un Alumno vacío)" << endl;
    cout << "2- Mostrar los Alumnos cargados (no vacíos!)" << endl;
    cout << "3- Mostrar los Alumnos en condición de Promoción" << endl;
    cout << "4- Buscar un Alumno por legajo y mostrar sus datos" << endl;
    cout << "5- Buscar un Alumno por legajo y vaciarlo (poner su legajo en 0!)" << endl;
    cout << "0- Salir" << endl;
    cin >> option;
    cout << endl;
    cout << endl;

    switch(option){
    case 1: addStudentverify(students, N);
    break;
    case 2: printStudent(students, N);
    break;
    case 3: printStudentPromotion(students, N);


    }

}
int main()
{
    int N = 2, salir = 0, option = 0;
    Student students[N];

    startStudents(students, N);
    do{
    menu(students, option, N);
    }
    while(option != 0);
    return 0;
}
