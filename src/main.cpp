#include "database/database.hpp"
#include "menu/menu.hpp"

using namespace std;

// Nombre por defecto del fichero a cargar al inicio
const string filename = "propietarios.csv";

int main() {
  int option = 0;

  // Se leen los propietarios del fichero al iniciar el programa
  vector<Data::Owner> owners = Database::load(filename);

  // Se crea un vector vacío de inmuebles
  vector<Data::Property> properties;

  while (option != 6) {
    // Se muestra el menú principal
    option = Menu::displayMenu();

    switch (option) {
    case 1: // Registrar nuevo propietario
      Menu::registerOwner(owners);
      break;

    case 2: // Registrar nuevo inmueble
      Menu::registerProperty(properties, owners);
      break;

    case 3: // Generar reporte
      Menu::displayReport(properties, owners);
      break;

    case 4: { // Importar propietarios
      // Se pide el nombre del ficher a importar
      const string import_file = Menu::importFile();

      // Se crea un vector con el contenido del fichero a importar
      const vector<Data::Owner> imported_owners = Database::load(import_file);

      // Se recorre el vector con el contenido a importar y se añade al
      // vector de propietarios
      for (const auto &import_owner : imported_owners) {
        bool found = false;

        // Se comprueba si la ID ya existe
        for (const auto &owner : owners) {
          if (import_owner.id == owner.id) {
            found = true;
            break;
          }
        }

        // Los propietarios cuyas IDs ya existan no se importan
        if (!found) {
          owners.push_back(import_owner);
        }
      }

      break;
    }

    case 5: // Exportar los propietarios en un fichero
      Database::save(filename, owners);
      break;

    case 6: // Salir
      cout << "Saliendo..." << endl;
      break;

    default:
      cout << "Opción inválida" << endl;
      return 1;
    }
  }
}
