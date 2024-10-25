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

int main() {
    setlocale(LC_CTYPE, "Spanish");
    vector<Estudiante> estudiantes = cargarDatosDesdeArchivo();
    int opcionReporte;

    while (true) {
        cout << "-----------------------------------------------------------------\n";
        cout << "                         --- UMG ---\n";
        cout << "-----------------------------------------------------------------\n";
        cout << "Seleccione el tipo de reporte:\n";
        cout << "1. Datos Generales\n";
        cout << "2. Asignación de Cursos\n";
        cout << "3. Notas\n";
        cout << "4. Rendimiento Académico\n";
        cout << "5. Regresar al Menú Principal\n";
        cout << "Opción: ";
        cin >> opcionReporte;
        cin.ignore();
        cin.clear();
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
                cout << "Saliendo del programa...\n";
                return 0;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    }

    return 0;
}
//Mario David Tereta Sapalun 0905-15-14297 (Control de Notas, Proyecto Final Individual)
