#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <locale.h>//Para usar lenguaje español y tildes
#include <cmath> // Para poder sacar el promedio final

using namespace std;

struct Notas {
    int nota1;
    int nota2;
    int zonaTotal;
    int examenFinal;
    int notaFinal;
    string estado; // Estructura para guardar notas en el resgistro de notas y poder hacerlas ver en los reportres academicos
};

struct Curso {
    string nombre;
    string seccion;
    string codigoCurso;
    Notas notas;
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

    cout << "Ingrese los Nombres: ";
    getline(cin, nuevoEstudiante.nombres);
    cout << "--------------------------------------------------------------------\n";

    cout << "Ingrese los Apellidos: ";
    getline(cin, nuevoEstudiante.apellidos);
    cout << "--------------------------------------------------------------------\n";

    cout << "Ingrese el Departamento: ";
    getline(cin, nuevoEstudiante.departamento);
    cout << "--------------------------------------------------------------------\n";

    cout << "Ingrese el Municipio: ";
    getline(cin, nuevoEstudiante.municipio);
    cout << "--------------------------------------------------------------------\n";

    int opcionCarrera;
    while (true) {
        cout << "Seleccione la carrera:\n";
        cout << "1. Ingeniería en Sistemas\n";
        cout << "2. Administración\n";
        cout << "3. Derecho\n";
        cout << "4. Medicina\n";
        cout << "5. Psicología\n";
        cout << "6. Arquitectura\n";
        cout << "Opción: ";
        cin >> opcionCarrera;
        cin.ignore();
        cout << "---------------------------------------------------------\n";

        if (opcionCarrera >= 1 && opcionCarrera <= 6) {
            switch (opcionCarrera) {
                case 1:
                    nuevoEstudiante.carrera = "Ingeniería en Sistemas";
                    break;
                case 2:
                    nuevoEstudiante.carrera = "Administracioó";
                    break;
                case 3:
                    nuevoEstudiante.carrera = "Derecho";
                    break;
                case 4:
                	nuevoEstudiante.carrera = "Medicina";
                    break;
                case 5: 
                nuevoEstudiante.carrera = "Psicología";
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

    cout << "Ingrese los años que lleva en la universidad: ";
    cin >> nuevoEstudiante.aniosEnUniversidad;
    cout << "--------------------------------------------------------------------\n";
    cin.clear();
    cin.ignore();

    cout << "Ingrese el número de semestres que lleva en la universidad: ";
    cin >> nuevoEstudiante.semestre;
    cout << "--------------------------------------------------------------------\n";
    cin.clear();
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
    cin.clear();
    cin.ignore();

    if (continuar == 's' || continuar == 'S') {
        registrarEstudiante(estudiantes);
    }
}
//------------------------------------------------------------------------------------------------------------------
void asignarCursos(vector<Estudiante>& estudiantes) {
    int codigo;
    while (true) {
        cout << "Ingrese el código del estudiante: ";
        cin >> codigo;
        cin.clear();
        cin.ignore();
        
        cout << "--------------------------------------------------------------------\n";

        for (size_t i = 0; i < estudiantes.size(); ++i) {
            if (estudiantes[i].codigoEstudiante == codigo) {
                cout << "Cursos disponibles para " << estudiantes[i].carrera << ":\n";
                vector<string> cursos;
                cout << "--------------------------------------------------------------------\n";

                if (estudiantes[i].carrera == "Ingeniería en Sistemas") {
                    cursos.push_back("Algoritmos");
                    cursos.push_back("Matemática");
                    cursos.push_back("Física");
                    cursos.push_back("Cálculo");
                    cursos.push_back("Álgebra");
                    cursos.push_back("Estadística");
                } else if (estudiantes[i].carrera == "Administración") {
                    cursos.push_back("Fundamentos de administración");
                    cursos.push_back("Comportamiento Organizacional");
                    cursos.push_back("Marketing estratégico");
                    cursos.push_back("Finanzas corporativas");
                    cursos.push_back("Recursos humanos");
                    cursos.push_back("Emprendimiento");
                } else if (estudiantes[i].carrera == "Derecho") {
                    cursos.push_back("Introducción al diseño");
                    cursos.push_back("Derecho constitucional");
                    cursos.push_back("Derecho civil");
                    cursos.push_back("Derecho penal");
                    cursos.push_back("Derecho administrativo");
                    cursos.push_back("Derecho Internacional");
                } else if (estudiantes[i].carrera == "Medicina") {
                    cursos.push_back("Anatomia humana");
                    cursos.push_back("Fisiología");
                    cursos.push_back("Bioquímica");
                    cursos.push_back("Patología");
                    cursos.push_back("Farmacología");
                    cursos.push_back("Medicina preventiva");
                } else if (estudiantes[i].carrera == "Psicología") {
                    cursos.push_back("Psicología general");
                    cursos.push_back("Psicología del desarrollo");
                    cursos.push_back("Psicología social");
                    cursos.push_back("Psicología clinica");
                    cursos.push_back("Psicología educativa");
                    cursos.push_back("Metodología de la investigación");
                } else if (estudiantes[i].carrera == "Arquitectura") {
                    cursos.push_back("Historia de la arquitectura");
                    cursos.push_back("Diseño arquitectonico");
                    cursos.push_back("Estructuras");
                    cursos.push_back("Urbanismo");
                    cursos.push_back("Instalaciones en edificios");
                    cursos.push_back("Representación gráfica");
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
                cin.clear();
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
//-------------------------------------------------------------------------------------------------------
void controlDeNotas(vector<Estudiante>& estudiantes) {
    int codigo;
    while (true) {
        cout << "Ingrese el código del estudiante: ";
        cin >> codigo;
        cin.clear();
        cin.ignore();
        cout << "--------------------------------------------------------------------\n";

        for (size_t i = 0; i < estudiantes.size(); ++i) {
            if (estudiantes[i].codigoEstudiante == codigo) {
                cout << "Cursos disponibles para " << estudiantes[i].carrera << ":\n";
                vector<string> cursos;
                cout << "--------------------------------------------------------------------\n";

                if (estudiantes[i].carrera == "Ingeniería en Sistemas") {
                    cursos.push_back("Algoritmos");
                    cursos.push_back("Matemática");
                    cursos.push_back("Física");
                    cursos.push_back("Cálculo");
                    cursos.push_back("Álgebra");
                    cursos.push_back("Estadística");
                } else if (estudiantes[i].carrera == "Administración") {
                    cursos.push_back("Fundamentos de administración");
                    cursos.push_back("Comportamiento Organizacional");
                    cursos.push_back("Marketing estrategico");
                    cursos.push_back("Finanzas corporativas");
                    cursos.push_back("Recursos humanos");
                    cursos.push_back("Emprendimiento");
                } else if (estudiantes[i].carrera == "Derecho") {
                    cursos.push_back("Introducción al diseño");
                    cursos.push_back("Derecho constitucional");
                    cursos.push_back("Derecho civil");
                    cursos.push_back("Derecho penal");
                    cursos.push_back("Derecho administrativo");
                    cursos.push_back("Derecho Internacional");
                } else if (estudiantes[i].carrera == "Medicina") {
                	cursos.push_back("Anatomia humana");
                    cursos.push_back("Fisiología");
                    cursos.push_back("Bioquímica");
                    cursos.push_back("Patología");
                    cursos.push_back("Farmacología");
                    cursos.push_back("Medicina preventiva");
                } else if (estudiantes[i].carrera == "Psicología") {
                	cursos.push_back("Psicología general");
                    cursos.push_back("Psicología del desarrollo");
                    cursos.push_back("Psicología social");
                    cursos.push_back("Psicología clinica");
                    cursos.push_back("Psicología educativa");
                    cursos.push_back("Metodología de la investigación");
                } else if (estudiantes[i].carrera == "Arquitectura") {
                	cursos.push_back("Historia de la arquitectura");
                    cursos.push_back("Diseño arquitectonico");
                    cursos.push_back("Estructuras");
                    cursos.push_back("Urbanismo");
                    cursos.push_back("Instalaciones en edificios");
                    cursos.push_back("Representación gráfica");
                }

                
                vector<string> nombresCursos;
                vector<int> notasFinales;
                vector<string> estados;

                for (size_t j = 0; j < estudiantes[i].cursos.size(); ++j) {
                    cout << "Curso: " << estudiantes[i].cursos[j].nombre << endl;
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
                    string estado = (notaFinal >= 60) ? "Aprobado" : "Reprobado";
					
					estudiantes[i].cursos[j].notas.nota1 = nota1;
                    estudiantes[i].cursos[j].notas.nota2 = nota2;
                    estudiantes[i].cursos[j].notas.zonaTotal = zonaTotal;
                    estudiantes[i].cursos[j].notas.examenFinal = examenFinal;
                    estudiantes[i].cursos[j].notas.notaFinal = nota1 + nota2 + zonaTotal + examenFinal;
                    estudiantes[i].cursos[j].notas.estado = (estudiantes[i].cursos[j].notas.notaFinal >= 60) ? "Aprobado" : "Reprobado";
                    //Toda esta seccion sue añadida para guardar las notas en memoria y poder ser llamadas en otras funciones, en este caso los reportes academicos
                    
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
                cin.clear();
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
//------------------------------------------------------------------------------------
void reporteDatosGenerales(const vector<Estudiante>& estudiantes) {
    cout << "==================== Reporte de Datos Generales ====================\n";
    for (const auto& estudiante : estudiantes) {
        cout << "Código: " << estudiante.codigoEstudiante << "\n";
        cout << "Nombres: " << estudiante.nombres << "\n";
        cout << "Apellidos: " << estudiante.apellidos << "\n";
        cout << "Carrera: " << estudiante.carrera << "\n";
        cout << "Fecha de Nacimiento: " << estudiante.fechaNacimiento << endl;
        cout << "Edad: " << estudiante.edad << "\n";
        cout << "Departamento: " << estudiante.departamento << endl;
        cout << "Municipio: " << estudiante.municipio << endl;
        cout << "Años en la Universidad: " << estudiante.aniosEnUniversidad << "\n";
        cout << "Semestre: " << estudiante.semestre << "\n";
        cout << "--------------------------------------------------------------------\n";
    }
    
    return;
}

void reporteAsignacionCursos(const vector<Estudiante>& estudiantes) {
    cout << "==================== Reporte de Asignación de Cursos ====================\n";
    for (const auto& estudiante : estudiantes) {
        cout << "Código del Estudiante: " << estudiante.codigoEstudiante << "\n";
        cout << "Nombres: " << estudiante.nombres << " " << estudiante.apellidos << "\n";
        cout << "Cursos asignados:\n";
        for (const auto& curso : estudiante.cursos) {
            cout << "  - " << curso.nombre << " (Sección: " << curso.seccion << ", Código: " << curso.codigoCurso << ")\n";
        }
        cout << "--------------------------------------------------------------------\n";
    }
}

void reporteNotas(const vector<Estudiante>& estudiantes) {
    int zonaTotal, examenFinal;
    cout << "==================== Reporte de Notas ====================\n";
    for (const auto& estudiante : estudiantes) {
        cout << "Código del Estudiante: " << estudiante.codigoEstudiante << "\n";
        cout << "Nombres: " << estudiante.nombres << " " << estudiante.apellidos << "\n";
        cout << "Notas de Cursos:\n";
        for (const auto& curso : estudiante.cursos) {
            cout << "  - " << curso.nombre << "\n";
            cout << "    Parcial 1: " << curso.notas.nota1 << ", Parcial 2: " << curso.notas.nota2 << "\n";
            cout << "    Zona: " << curso.notas.zonaTotal << ", Examen Final: " << curso.notas.examenFinal << "\n";
            cout << "    Nota Final: " << curso.notas.notaFinal << " (" << curso.notas.estado << ")\n";
        }
        cout << "--------------------------------------------------------------------\n";
    }
}

void reporteRendimientoAcademico(const vector<Estudiante>& estudiantes) {
    cout << "==================== Reporte de Rendimiento Académico ====================\n";
    for (const auto& estudiante : estudiantes) {
        int sumaNotas = 0, aprobados = 0, reprobados = 0;
        for (const auto& curso : estudiante.cursos) {
            sumaNotas += curso.notas.notaFinal;
            if (curso.notas.estado == "Aprobado") {
                aprobados++;
            } else {
                reprobados++;
            }
        }
        float promedio = estudiante.cursos.empty() ? 0 : static_cast<float>(sumaNotas) / estudiante.cursos.size();
        promedio = round(promedio * 100) / 100;
        
        cout << "Código del Estudiante: " << estudiante.codigoEstudiante << "\n";
        cout << "Nombres: " << estudiante.nombres << " " << estudiante.apellidos << "\n";
        cout << "Promedio General: "  << promedio << "\n";
        cout << "Materias Aprobadas: " << aprobados << ", Materias Reprobadas: " << reprobados << "\n";
        cout << "--------------------------------------------------------------------\n";
    }
}

void menuReportes(const vector<Estudiante>& estudiantes) {
	
    	int opcionReporte;
        
    	cout << "Seleccione el tipo de reporte:\n";
    	cout << "1. Datos Generales\n";
    	cout << "2. Asignación de Cursos\n";
    	cout << "3. Notas\n";
    	cout << "4. Rendimiento Académico\n";
     	cout << "5. Regresar al Menú Principal\n";
    	cout << "Opción: ";
    	cin >> opcionReporte;
    	cin.clear();
    	cin.ignore();
    	cout << "--------------------------------------------------------------------\n";

    	switch (opcionReporte) {
        case 1:
            reporteDatosGenerales(estudiantes);
            break;
        case 2:
            reporteAsignacionCursos(estudiantes);
            break;
        case 3:
            reporteNotas(estudiantes);
            break;
        case 4:
            reporteRendimientoAcademico(estudiantes);
            break;
        case 5:
        	return;
        default:
            cout << "Opción no válida. Intente de nuevo.\n";
	    }	
}
//------------------------------------------------------------------------------------
int main() {
	setlocale (LC_CTYPE, "Spanish");
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
        cout << "4. Reportes Académicos\n"; 
        cout << "5. Salir\n";
        cout << "=================================================================\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();
        cin.clear();//para evitar bucles por datos mal ingresados, lo corrobore al ver el video que Brayan envio
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
            	 menuReportes(estudiantes);
                break;
            case 5:
                cout << "Saliendo del programa...\n";
                return 0;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    }
    return 0;
}
