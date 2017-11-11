#include "../data/data.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

/**
 * En este namespace agrupamos las funciones relacionadas con la lectura del
 * fichero que contiene los datos.
 */
namespace Database {

using namespace std;
using namespace Data;

/**
 * Parsea un fichero CSV que se recibe como argumento con el contenido de los
 * propietarios.
 *
 * @param file  Fichero CSV con los datos a parsear.
 * @return      Vector de propietarios.
 */
vector<Owner> load(const string filename);

/**
 * Almacena los vectores de propietarios en un fichero CSV.
 *
 * @param file   Archivo donde almacenar los propietarios
 * @param owners Vector con los propietarios
 */
void save(const string filename, const vector<Owner> owners);
}
