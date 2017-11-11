#include "database.hpp"

#include <fstream>

namespace Database {

vector<Owner> load(const string filename) {
  vector<Owner> owners;
  ifstream file;

  // Se abre el fichero
  file.open(filename);
  if (file.fail()) {
    cout << "Error opening file" << endl;
    return vector<Owner>();
  }

  while (!file.eof()) {
    Owner owner;
    string id;

    // Obtiene la ID del propietario y la convierte a entero
    getline(file, id, ',');
    owner.id = atoi(id.c_str());
    if (id.size() < 1) {
      break;
    }

    // Obtiene nombre del propietario
    getline(file, owner.name, ',');
    if (owner.name.size() < 1) {
      break;
    }

    // Obtiene el teléfono del propietario
    getline(file, owner.phone, ',');
    if (owner.phone.size() < 1) {
      break;
    }

    // Obtiene el email del propietario
    getline(file, owner.email, ',');
    if (owner.email.size() < 1) {
      break;
    }

    // Obtiene la dirección del propietario
    getline(file, owner.address);
    if (owner.address.size() < 1) {
      break;
    }

    // Almacena el propietario en el vector
    owners.push_back(owner);
  }

  // Se cierra el fichero
  file.close();

  return owners;
}

void save(const string filename, const vector<Owner> owners) {
  ofstream file;

  // Se abre el fichero
  file.open(filename);
  if (file.fail()) {
    cout << "Error opening file" << endl;
    return;
  }

  // Se recorre el vector de propietarios
  for (auto const &owner : owners) {
    file << owner.id << "," << owner.name << "," << owner.phone << ","
         << owner.email << "," << owner.address;

    // Si NO es el último elemento del vector se introduce nueva linea
    if (&owner != &owners.back()) {
      file << endl;
    }
  }

  // Se cierra el fichero
  file.close();
}
}
