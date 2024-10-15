#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

struct Curso {
    string nombre;
    string seccion;
    string codigoCurso;
};

struct Estudiante {
    string nombres;
    string apellidos;
    string departamento;
    string municipio;
    string carrera;
    string fechaNacimiento;
    int edad;
    int aniosEnUniversidad;
    int semestre;
    int codigoEstudiante;
    vector<Curso> cursos;
};

int calcularEdad(int diaNacimiento, int mesNacimiento, int anioNacimiento) {
    time_t t = time(0);
    tm* now = localtime(&t);
    int anioActual = now->tm_year + 1900;
    int mesActual = now->tm_mon + 1; 
    int diaActual = now->tm_mday;

    int edad = anioActual - anioNacimiento;
    if (mesActual < mesNacimiento || (mesActual == mesNacimiento && diaActual < diaNacimiento)) {
        edad--;
    }
    return edad;
}

int generarCodigoEstudiante() {
    return rand() % 9000 + 1000;
}

string generarCodigoCurso() {
    string codigo;
    const char caracteres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < 6; ++i) {
        codigo += caracteres[rand() % (sizeof(caracteres) - 1)];
    }
    return codigo;
}

int stringToInt(const string& str) {
    int num;
    stringstream ss(str);
    ss >> num;
    return num;
}

bool validarFecha(const string& fecha) {
    if (fecha.length() != 10 || fecha[2] != '/' || fecha[5] != '/') {
        return false;
    }
    for (size_t i = 0; i < fecha.length(); ++i) {
        if ((i != 2 && i != 5) && !isdigit(fecha[i])) {
            return false;
        }
    }
    int dia = stringToInt(fecha.substr(0, 2));
    int mes = stringToInt(fecha.substr(3, 2));
    return (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12);
}

void registrarEstudiante(vector<Estudiante>& estudiantes) {
    Estudiante nuevoEstudiante;

    cout << "Ingrese los nombres: ";
    getline(cin, nuevoEstudiante.nombres);
    cout << "--------------------------------------------------------------------\n";

    cout << "Ingrese los apellidos: ";
    getline(cin, nuevoEstudiante.apellidos);
    cout << "--------------------------------------------------------------------\n";

    cout << "Ingrese el departamento: ";
    getline(cin, nuevoEstudiante.departamento);
    cout << "--------------------------------------------------------------------\n";

    cout << "Ingrese el municipio: ";
    getline(cin, nuevoEstudiante.municipio);
    cout << "--------------------------------------------------------------------\n";

    int opcionCarrera;
    while (true) {
        cout << "Seleccione la carrera:\n";
        cout << "1. Ingenieria en Sistemas\n";
        cout << "2. Administracion\n";
        cout << "3. Derecho\n";
        cout << "4. Medicina\n";
        cout << "5. Psicologia\n";
        cout << "6. Arquitectura\n";
        cout << "Opcion: ";
        cin >> opcionCarrera;
        cin.ignore();
        cout << "---------------------------------------------------------\n";

        if (opcionCarrera >= 1 && opcionCarrera <= 6) {
            switch (opcionCarrera) {
                case 1:
                    nuevoEstudiante.carrera = "Ingeniería en Sistemas";
                    break;
                case 2:
                    nuevoEstudiante.carrera = "Administracion";
                    break;
                case 3:
                    nuevoEstudiante.carrera = "Derecho";
                    break;
                case 4:
                	nuevoEstudiante.carrera = "Medicina";
                    break;
                case 5: 
                nuevoEstudiante.carrera = "Psicologia";
                    break;
                case 6:
                	nuevoEstudiante.carrera = "Arquitectura";
                    break;
            }
            break;
        } else {
            cout << "Valor inválido, vuelva a intentarlo.\n";
        }
    }

    while (true) {
        cout << "Ingrese la fecha de nacimiento (DD/MM/AAAA): ";
        getline(cin, nuevoEstudiante.fechaNacimiento);
        cout << "---------------------------------------------------------\n";

        if (validarFecha(nuevoEstudiante.fechaNacimiento)) {
            int diaNacimiento = stringToInt(nuevoEstudiante.fechaNacimiento.substr(0, 2));
            int mesNacimiento = stringToInt(nuevoEstudiante.fechaNacimiento.substr(3, 2));
            int anioNacimiento = stringToInt(nuevoEstudiante.fechaNacimiento.substr(6, 4));
            nuevoEstudiante.edad = calcularEdad(diaNacimiento, mesNacimiento, anioNacimiento);
            break;
        } else {
            cout << "Valor inválido, vuelva a intentarlo.\n";
        }
    }

    cout << "Ingrese los anios que lleva en la universidad: ";
    cin >> nuevoEstudiante.aniosEnUniversidad;
    cout << "--------------------------------------------------------------------\n";
    cin.ignore();

    cout << "Ingrese el número de semestres que lleva en la universidad: ";
    cin >> nuevoEstudiante.semestre;
    cout << "--------------------------------------------------------------------\n";
    cin.ignore();

    nuevoEstudiante.codigoEstudiante = generarCodigoEstudiante();
    estudiantes.push_back(nuevoEstudiante);

    cout << "Estudiante registrado con éxito!\n";
    cout << " \n";
    cout << "====================================================================\n";
    cout << "Datos del estudiante registrado:\n";
    cout << "--------------------------------------------------------------------\n";
    cout << "Código: " << nuevoEstudiante.codigoEstudiante << endl;
    cout << " \n";
    cout << "Nombres: " << nuevoEstudiante.nombres << endl;
    cout << " \n";
    cout << "Apellidos: " << nuevoEstudiante.apellidos << endl;
    cout << " \n";
    cout << "Departamento: " << nuevoEstudiante.departamento << endl;
    cout << " \n";
    cout << "Municipio: " << nuevoEstudiante.municipio << endl;
    cout << " \n";
    cout << "Carrera: " << nuevoEstudiante.carrera << endl;
    cout << " \n";
    cout << "Fecha de Nacimiento: " << nuevoEstudiante.fechaNacimiento << endl;
    cout << " \n";
    cout << "Edad: " << nuevoEstudiante.edad << endl;
    cout << " \n";
    cout << "Años en la Universidad: " << nuevoEstudiante.aniosEnUniversidad << endl;
    cout << " \n";
    cout << "Semestre: " << nuevoEstudiante.semestre << endl;
    cout << "--------------------------------------------------------------------\n";

   
    char continuar;
    cout << "¿Quieres registrar otro estudiante? (s/n): ";
    cin >> continuar;
    cin.ignore();

    if (continuar == 's' || continuar == 'S') {
        registrarEstudiante(estudiantes);
    }
}

void asignarCursos(vector<Estudiante>& estudiantes) {
    int codigo;
    while (true) {
        cout << "Ingrese el código del estudiante: ";
        cin >> codigo;
        cin.ignore();
        cout << "--------------------------------------------------------------------\n";

        for (size_t i = 0; i < estudiantes.size(); ++i) {
            if (estudiantes[i].codigoEstudiante == codigo) {
                cout << "Cursos disponibles para " << estudiantes[i].carrera << ":\n";
                vector<string> cursos;
                cout << "--------------------------------------------------------------------\n";

                if (estudiantes[i].carrera == "Ingeniería en Sistemas") {
                    cursos.push_back("Algoritmos");
                    cursos.push_back("Matematica");
                    cursos.push_back("Fisica");
                    cursos.push_back("Calculo");
                    cursos.push_back("Algebra");
                    cursos.push_back("Estadistica");
                } else if (estudiantes[i].carrera == "Administracion") {
                    cursos.push_back("Fundamentos de administracion");
                    cursos.push_back("Comportamiento Organizacional");
                    cursos.push_back("Marketing estrategico");
                    cursos.push_back("Finanzas corporativas");
                    cursos.push_back("Recursos humanos");
                    cursos.push_back("Emprendimiento");
                } else if (estudiantes[i].carrera == "Derecho") {
                    cursos.push_back("Introduccion al diseño");
                    cursos.push_back("Derecho constitucional");
                    cursos.push_back("Derecho civil");
                    cursos.push_back("Derecho penal");
                    cursos.push_back("Derecho administrativo");
                    cursos.push_back("Derecho Internacional");
                } else if (estudiantes[i].carrera == "Medicina") {
                    cursos.push_back("Anatomia humana");
                    cursos.push_back("Fisiologia");
                    cursos.push_back("Bioquimica");
                    cursos.push_back("Pantologia");
                    cursos.push_back("Farmacologia");
                    cursos.push_back("Medicina preventiva");
                } else if (estudiantes[i].carrera == "Psicologia") {
                    cursos.push_back("Psicologia general");
                    cursos.push_back("Psicologia del desarrollo");
                    cursos.push_back("Psicologia social");
                    cursos.push_back("Psicologia clinica");
                    cursos.push_back("Psicologia educativa");
                    cursos.push_back("Metodologia de la investigacion");
                } else if (estudiantes[i].carrera == "Arquitectura") {
                    cursos.push_back("Historia de la arquitectura");
                    cursos.push_back("Diseño arquitectonico");
                    cursos.push_back("Estructuras");
                    cursos.push_back("Urbanismo");
                    cursos.push_back("Instalaciones en edificios");
                    cursos.push_back("Representacion grafica");
                }

               
                for (size_t j = 0; j < cursos.size(); ++j) {
                    Curso nuevoCurso;
                    nuevoCurso.nombre = cursos[j];

                    cout << "Asignar sección para el curso " << nuevoCurso.nombre << " (Sección A, B, C, D): ";
                    getline(cin, nuevoCurso.seccion);
                    cout << "--------------------------------------------------------------------\n";

                    while (nuevoCurso.seccion != "A" && nuevoCurso.seccion != "B" && nuevoCurso.seccion != "C" && nuevoCurso.seccion != "D") {
                        cout << "Sección inválida, por favor ingrese A, B, C o D: ";
                        getline(cin, nuevoCurso.seccion);
                    }

                    nuevoCurso.codigoCurso = generarCodigoCurso();
                    estudiantes[i].cursos.push_back(nuevoCurso);
                }

                cout << "Cursos asignados:\n";
                cout << "====================================================================\n";
                for (size_t j = 0; j < estudiantes[i].cursos.size(); ++j) {
                    cout << estudiantes[i].cursos[j].nombre << ":\n";
                    cout << "  Código del curso: " << estudiantes[i].cursos[j].codigoCurso << endl;
                    cout << "  Sección: " << estudiantes[i].cursos[j].seccion << endl;
                    cout << "--------------------------------------------------------------------\n";
                }

               
                char continuar;
                cout << "¿Quieres asignar más cursos? (s/n): ";
                cin >> continuar;
                cin.ignore();

                if (continuar == 's' || continuar == 'S') {
                    asignarCursos(estudiantes); 
                }

                return;
            }
        }
        cout << "No se encontró un estudiante con el código: " << codigo << endl;
    }
}

void controlDeNotas(vector<Estudiante>& estudiantes) {
    int codigo;
    while (true) {
        cout << "Ingrese el código del estudiante: ";
        cin >> codigo;
        cin.ignore();
        cout << "--------------------------------------------------------------------\n";

        for (size_t i = 0; i < estudiantes.size(); ++i) {
            if (estudiantes[i].codigoEstudiante == codigo) {
                cout << "Cursos disponibles para " << estudiantes[i].carrera << ":\n";
                vector<string> cursos;
                cout << "--------------------------------------------------------------------\n";

                if (estudiantes[i].carrera == "Ingeniería en Sistemas") {
                    cursos.push_back("Algoritmos");
                    cursos.push_back("Matematica");
                    cursos.push_back("Fisica");
                    cursos.push_back("Calculo");
                    cursos.push_back("Algebra");
                    cursos.push_back("Estadistica");
                } else if (estudiantes[i].carrera == "Administracion") {
                    cursos.push_back("Fundamentos de administracion");
                    cursos.push_back("Comportamiento Organizacional");
                    cursos.push_back("Marketing estrategico");
                    cursos.push_back("Finanzas corporativas");
                    cursos.push_back("Recursos humanos");
                    cursos.push_back("Emprendimiento");
                } else if (estudiantes[i].carrera == "Derecho") {
                    cursos.push_back("Introduccion al diseño");
                    cursos.push_back("Derecho constitucional");
                    cursos.push_back("Derecho civil");
                    cursos.push_back("Derecho penal");
                    cursos.push_back("Derecho administrativo");
                    cursos.push_back("Derecho Internacional");
                } else if (estudiantes[i].carrera == "Medicina") {
                	cursos.push_back("Anatomia humana");
                    cursos.push_back("Fisiologia");
                    cursos.push_back("Bioquimica");
                    cursos.push_back("Pantologia");
                    cursos.push_back("Farmacologia");
                    cursos.push_back("Medicina preventiva");
                } else if (estudiantes[i].carrera == "Psicologia") {
                	cursos.push_back("Psicologia general");
                    cursos.push_back("Psicologia del desarrollo");
                    cursos.push_back("Psicologia social");
                    cursos.push_back("Psicologia clinica");
                    cursos.push_back("Psicologia educativa");
                    cursos.push_back("Metodologia de la investigacion");
                } else if (estudiantes[i].carrera == "Arquitectura") {
                	cursos.push_back("Historia de la arquitectura");
                    cursos.push_back("Diseño arquitectonico");
                    cursos.push_back("Estructuras");
                    cursos.push_back("Urbanismo");
                    cursos.push_back("Instalaciones en edificios");
                    cursos.push_back("Representacion grafica");
                }

                
                vector<string> nombresCursos;
                vector<int> notasFinales;
                vector<string> estados;

                for (size_t j = 0; j < cursos.size(); ++j) {
                    cout << "Curso: " << cursos[j] << endl;
                    cout << " \n";

                    int nota1, nota2, zonaTotal, examenFinal;

                    do {
                        cout << "Ingrese la nota del primer parcial (0-15): ";
                        cin >> nota1;
                    } while (nota1 < 0 || nota1 > 15);

                    do {
                        cout << "Ingrese la nota del segundo parcial (0-15): ";
                        cin >> nota2;
                    } while (nota2 < 0 || nota2 > 15);

                    do {
                        cout << "Ingrese la zona total (0-35): ";
                        cin >> zonaTotal;
                    } while (zonaTotal < 0 || zonaTotal > 35);

                    do {
                        cout << "Ingrese la nota del examen final (0-35): ";
                        cin >> examenFinal;
                    } while (examenFinal < 0 || examenFinal > 35);
                    cout << "--------------------------------------------------------------------\n";

                    int notaFinal = nota1 + nota2 + zonaTotal + examenFinal;
                    string estado = (notaFinal >= 60) ? "Aprobado" : "Desaprobado";

                    
                    nombresCursos.push_back(cursos[j]);
                    notasFinales.push_back(notaFinal);
                    estados.push_back(estado);
                }

                cout << "\n --- Resultados finales ---:\n";
                cout << "====================================================================\n";
                for (size_t j = 0; j < nombresCursos.size(); ++j) {
                    cout << "Curso: " << nombresCursos[j] << "\n";
                    cout << "\n";
                    cout << "Nota final: " << notasFinales[j] << "\n";
                    cout << "Estado: " << estados[j] << "\n";
                    cout << "--------------------------------------------------------------------\n";
                }

                
                char continuar;
                cout << "¿Quieres registrar más notas? (s/n): ";
                cin >> continuar;
                cin.ignore();

                if (continuar == 's' || continuar == 'S') {
                    controlDeNotas(estudiantes); 
                }

                return;
            }
        }
        cout << "No se encontró un estudiante con el código: " << codigo << endl;
    }
}

int main() {
    srand(time(0)); 
    vector<Estudiante> estudiantes;
    int opcion;

    while (true) {
        cout << "-----------------------------------------------------------------\n";
        cout << "                         --- UMG ---\n";
        cout << "-----------------------------------------------------------------\n";
        cout << "1. Registro de estudiantes\n";
        cout << "2. Asignar cursos\n";
        cout << "3. Control de notas\n";
        cout << "4. Salir\n";
        cout << "=================================================================\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();
        cout << "--------------------------------------------------------------------\n";

        switch (opcion) {
            case 1:
                registrarEstudiante(estudiantes);
                break;
            case 2:
                asignarCursos(estudiantes);
                break;
            case 3:
                controlDeNotas(estudiantes);
                break;
            case 4:
                cout << "Saliendo del programa...\n";
                return 0;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    }

    return 0;
}
