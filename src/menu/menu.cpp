#include "../data/data.hpp"
#include "menu.hpp"

#include <fstream>
#include <iostream>
#include <vector>

namespace Menu {

using namespace std;

int displayMenu() {
  int option = 0;

  cout << "Selecciona una opción: " << endl;
  cout << "-----------------------" << endl;
  cout << "\t 1. Registrar propietario" << endl;
  cout << "\t 2. Registrar inmueble" << endl;
  cout << "\t 3. Generar reporte de inmuebles" << endl;
  cout << "\t 4. Importar propietarios" << endl;
  cout << "\t 5. Guardar datos" << endl;
  cout << "\t 6. Salir" << endl;

  std::cin >> option;
  return option;
}

int registerOwner(vector<Data::Owner> &owners) {
  Data::Owner owner;

  cout << "Registrar propietario: " << endl;
  cout << "-----------------------" << endl;

  cout << "ID: ";
  std::cin >> owner.id;

  // Se comprueba que el ID no exista previamente
  for (const auto &stored_owner : owners) {
    if (stored_owner.id == owner.id) {
      cout << "Ya existe un propietario con el ID indicado" << endl;
      return -1;
    }
  }

  cout << "Nombre: ";
  std::cin >> owner.name;
  cout << "Teléfono: ";
  std::cin >> owner.phone;
  cout << "Email: ";
  std::cin >> owner.email;
  cout << "Dirección: ";
  std::cin >> owner.address;

  // Se añade el propietario creado al vector de propietarios
  owners.push_back(owner);

  return owner.id;
}

void registerProperty(vector<Data::Property> &properties,
                      vector<Data::Owner> &owners) {
  Data::Property property;
  int type;
  int kind;
  int owner_id;
  bool found = false;

  cout << "Registrar inmueble: " << endl;
  cout << "--------------------" << endl;

  cout << "ID de propietario: ";
  cin >> owner_id;

  // Se busca si existe el propietario
  for (const auto &owner : owners) {
    if (owner.id == owner_id) {
      cout << "-> Registrando inmueble para: " << owner.name << endl;
      found = true;
      break;
    }
  }

  if (found) {
    // Si existe se asocia el inmueble al propietario
    property.owner_id = owner_id;
  } else {
    // Si no existe se pide crearlo
    const int id = registerOwner(owners);
    if (id < 0) {
      return;
    }

    property.owner_id = id;
  }

  cout << "Código [1: Casa | 2: Apartamento | 3: Oficina]: ";
  std::cin >> type;
  switch (type) {
  case 1:
    property.type = Data::PropertyType::House;
    break;

  case 2:
    property.type = Data::PropertyType::Apartment;
    break;

  case 3:
    property.type = Data::PropertyType::Office;
    break;

  default:
    cout << "Código inválido" << endl;
    return;
  }

  if (property.type != Data::PropertyType::Office) {
    cout << "Número de habitaciones: ";
    std::cin >> property.rooms;
  } else {
    cout << "Número de divisiones: ";
    std::cin >> property.divisions;
  }

  cout << "Número de baños: ";
  std::cin >> property.bathrooms;

  cout << "Dirección: ";
  std::cin >> property.address;

  cout << "Barrio: ";
  std::cin >> property.neighborhood;

  cout << "Tipo de negocio [1: Arriendo | 2: Venta]: ";
  std::cin >> kind;
  switch (kind) {
  case 1:
    property.kind = Data::PropertyKind::Rent;
    break;

  case 2:
    property.kind = Data::PropertyKind::Sell;
    break;

  default:
    cout << "Código inválido" << endl;
    return;
  }

  cout << "Valor del inmueble: ";
  std::cin >> property.value;

  properties.push_back(property);
}

string importFile() {
  string filename;

  cout << "Introduce el nombre del fichero a importar: ";
  std::cin >> filename;

  return filename;
}

void displayReport(vector<Data::Property> &properties,
                   vector<Data::Owner> &owners) {
  string property_type;

  for (const auto &property : properties) {
    cout << "Inmueble: " << endl;
    cout << "----------" << endl;

    cout << "ID del propietario: " << property.owner_id << endl;

    switch (property.type) {
    case Data::PropertyType::House:
      property_type = "Casa";
      break;

    case Data::PropertyType::Apartment:
      property_type = "Apartamento";
      break;

    case Data::PropertyType::Office:
      property_type = "Oficina";
      break;
    }
    cout << "Tipo de inmueble: " << property_type << endl;

    if (property.type == Data::PropertyType::Office) {
      cout << "Número de divisiones: " << property.divisions << endl;
    } else {
      cout << "Número de habitaciones: " << property.rooms << endl;
    }

    cout << "Número de baños: " << property.bathrooms << endl;
    cout << "Dirección: " << property.address << endl;
    cout << "Barrio: " << property.neighborhood << endl;
    cout << "Tipo de negocio: "
         << (property.kind == Data::PropertyKind::Rent ? "Arriendo" : "Venta")
         << endl;
    cout << "Valor del inmueble: " << property.value << endl;
    cout << endl;
  }
}
}
