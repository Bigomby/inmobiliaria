#include <string>

#ifndef DATA_H
#define DATA_H

/**
 * En este namespace guardamos los tipos de datos.
 */
namespace Data {

using namespace std;

/**
 * Propietario
 */
struct Owner {
  int id;         // Identificación
  string phone;   // Teléfono
  string name;    // Nombre
  string email;   // Correo
  string address; // Dirección
};

/**
 * Indica el tipo de inmueble
 */
enum PropertyType { House, Apartment, Office };

/**
 * Indica el tipo de negocio
 */
enum PropertyKind { Rent, Sell };

/**
 * Inmueble
 */
struct Property {
  int owner_id;
  PropertyType type;   // Código del inmueble
  int rooms;           // Número de habitaciones
  int divisions;       // Número de divisiones
  int bathrooms;       // Número de baños
  string address;      // Dirección
  string neighborhood; // Barrio
  PropertyKind kind;   // Tipo de negocio
  int value;           // Valor del inmueble
};
}

#endif // DATA_H
