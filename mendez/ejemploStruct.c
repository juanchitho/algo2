
struct alumno{
  int edad;
  char *nombre;
  float promedio;
};

int main(){
  struct alumno agustin;
  agustin.edad = 21;
  agustin.promedio = 8.60;
  agustin.nombre = "Agustin";

  struct alumno *un_alumno = &agustin;
  un_alumno->edad=20;
  (*un_alumno).edad = 20;
  un_alumno[0].edad = 20;
  return 0;
}
