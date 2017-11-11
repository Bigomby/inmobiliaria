#include "../data/data.hpp"

#include <vector>

namespace Menu {

using namespace std;

/**
 * Muestra el menú principal del programa.
 *
 * @return Devuelve la opción elegida en el menú
 */
int displayMenu();

/**
 * Muestra un menú para introducir un nuevo propietario.
 *
 * @return Devuelve la ID del propietario creado
 */
int registerOwner(vector<Data::Owner> &owners);

/**
 * Muestra un menú para introducir un nuevo inmueble.
 *
 * @param properties Vector de inmuebles
 * @param owners     Vector de propietarios
 */
void registerProperty(vector<Data::Property> &properties,
                      vector<Data::Owner> &owners);

/**
 * Pide al usuario que introduzca un nombre de fichero para importar.
 *
* @return Devuelve el nombre del fichero para importar
 */
string importFile();

/**
 * Muestra por pantalla un reporte con todos los inmuebles
 */
void displayReport(vector<Data::Property> &properties,
                   vector<Data::Owner> &owners);
}
