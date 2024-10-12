#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
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

    // Generar los reportes
    reporteDatosGenerales(estudiantes);
    reporteAsignacionCursos(asignaciones);
    reporteNotas(asignaciones);
    reporteRendimientoAcademico(asignaciones);

    return 0;
}
