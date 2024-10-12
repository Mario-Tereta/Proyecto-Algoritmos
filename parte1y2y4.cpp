#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum Carrera { INGENIERIA = 1, ADMINISTRACION, DERECHO, MEDICINA, PSICOLOGIA, ARQUITECTURA, CRIMINOLOGIA };

string obtenerNombreCarrera(Carrera carrera) {
    switch (carrera) {
        case INGENIERIA: return "Ingenieria";
        case ADMINISTRACION: return "Administracion";
        case DERECHO: return "Derecho";
        case MEDICINA: return "Medicina";
        case PSICOLOGIA: return "Psicologia";
        case ARQUITECTURA: return "Arquitectura";
        case CRIMINOLOGIA: return "Criminologia";
        default: return "Carrera desconocida";
    }
}

struct Estudiante {
    int carnet;
    string nombres;
    string apellidos;
    int edad;
    string fechaNacimiento;
    string telefono;
    string correoElectronico;
    string direccion;
    string fechaInicioUniversidad;
    Carrera carrera;
};

struct Curso {
    std::string codigoCurso;
    std::string nombreCurso;
    int creditos;
};

struct Asignacion {
    Curso curso;
    std::string codigoEstudiante;
    int semestre;
};

string leerCadena(const string& mensaje) {
    string entrada;
    cout << mensaje;
    getline(cin, entrada);
    return entrada;
}

int leerEntero(const string& mensaje) {
    int valor;
    cout << mensaje;
    cin >> valor;
    cin.ignore();  
    return valor;
}

void registrarEstudiante(vector<Estudiante> &estudiantes) {
    Estudiante est;
    est.carnet = estudiantes.size() + 1;

    est.nombres = leerCadena("Ingrese Nombres: ");
    est.apellidos = leerCadena("Ingrese Apellidos: ");
    est.edad = leerEntero("Ingrese Edad: ");
    est.fechaNacimiento = leerCadena("Ingrese Fecha de Nacimiento (DD/MM/AAAA): ");
    est.telefono = leerCadena("Ingrese Numero de Telefono: ");
    est.correoElectronico = leerCadena("Ingrese Correo Electronico: ");
    est.direccion = leerCadena("Ingrese Direccion: ");
    est.fechaInicioUniversidad = leerCadena("Ingrese Fecha de Inicio de la Universidad (DD/MM/AAAA): ");

    cout << "Seleccione carrera: \n";
    cout << "1: Ingenieria\n";
    cout << "2: Administracion\n";
    cout << "3: Derecho\n";
    cout << "4: Medicina\n";
    cout << "5: Psicologia\n";
    cout << "6: Arquitectura\n";
    cout << "7: Criminologia\n";
    int opcionCarrera = leerEntero("");

    if (opcionCarrera >= 1 && opcionCarrera <= 7) {
        est.carrera = static_cast<Carrera>(opcionCarrera);
    } else {
        cout << "Opcion no valida. Se asignara carrera desconocida.\n";
        est.carrera = INGENIERIA;
    }

    estudiantes.push_back(est);

    cout << "Estudiante registrado con exito en la carrera: " << obtenerNombreCarrera(est.carrera) << "\n";
}

void reporteDatosGenerales(const vector<Estudiante>& estudiantes) {
    cout << "\n--- Reporte de Datos Generales de los Estudiantes ---\n";
    for (const auto& est : estudiantes) {
        cout << "Carnet: " << est.carnet << "\n";
        cout << "Nombres: " << est.nombres << "\n";
        cout << "Apellidos: " << est.apellidos << "\n";
        cout << "Edad: " << est.edad << "\n";
        cout << "Carrera: " << obtenerNombreCarrera(est.carrera) << "\n";
        cout << "Correo: " << est.correoElectronico << "\n\n";
    }
}

void reporteAsignacionCursos(const vector<Asignacion>& asignaciones) {
    cout << "\n--- Reporte de Asignación de Cursos ---\n";
    for (const auto& asig : asignaciones) {
        cout << "Codigo Estudiante: " << asig.codigoEstudiante << "\n";
        cout << "Curso: " << asig.curso.nombreCurso << "\n";
        cout << "Creditos: " << asig.curso.creditos << "\n";
        cout << "Semestre: " << asig.semestre << "\n\n";
    }
}

void reporteNotas(const vector<Asignacion>& asignaciones) {
    cout << "\n--- Reporte de Notas ---\n";
    for (const auto& asig : asignaciones) {
        cout << "Codigo Estudiante: " << asig.codigoEstudiante << "\n";
        cout << "Curso: " << asig.curso.nombreCurso << "\n";
        cout << "Nota parcial: " << rand() % 50 + 51 << "\n"; // Generar nota aleatoria entre 51 y 100
        cout << "Nota final: " << rand() % 50 + 51 << "\n\n"; // Generar nota aleatoria entre 51 y 100
    }
}

void reporteRendimientoAcademico(const vector<Asignacion>& asignaciones) {
    cout << "\n--- Reporte de Rendimiento Académico ---\n";
    for (const auto& asig : asignaciones) {
        int notaFinal = rand() % 50 + 51; // Nota aleatoria entre 51 y 100
        cout << "Codigo Estudiante: " << asig.codigoEstudiante << "\n";
        cout << "Curso: " << asig.curso.nombreCurso << "\n";
        cout << "Nota Final: " << notaFinal << "\n";
        cout << (notaFinal >= 60 ? "Estado: Aprobado\n\n" : "Estado: Reprobado\n\n");
    }
}

int main() {
    vector<Estudiante> estudiantes;
    vector<Asignacion> asignaciones;

    // Registrar un estudiante de prueba
    registrarEstudiante(estudiantes);

    // Registrar asignaciones de prueba
    std::vector<Curso> cursos = {
        {"10001", "Algoritmos", 3}, {"10002", "Matemática", 4}, {"10003", "Física", 4}
    };

    Asignacion asig = {cursos[0], "1", 1};
    asignaciones.push_back(asig);

    // Generar los reportes
    reporteDatosGenerales(estudiantes);
    reporteAsignacionCursos(asignaciones);
    reporteNotas(asignaciones);
    reporteRendimientoAcademico(asignaciones);

    return 0;
}

