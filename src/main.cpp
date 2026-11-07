// Práctica: Ticket de compra
// main() solo coordina: pide los datos, llama a los módulos y muestra el ticket.

#include <iostream>
#include <string>

#include "utilerias.h"
#include "ticket.h"

int main() {

    // Variables
    std::string nombre;
    double precio = 0.0;
    int cantidad = 0;
    double porcentajeDescuento = 0.0;

    double subtotal = 0.0;
    double descuento = 0.0;
    double iva = 0.0;
    double total = 0.0;

    // Paso 1: mensaje de bienvenida
    std::cout << "====================================\n";
    std::cout << "       TICKET DE COMPRA\n";
    std::cout << "====================================\n";

    // Paso 2: pedir y validar los datos

    nombre = leerCadena("Ingrese el nombre del producto: ");

    do {
        precio = leerDecimal("Ingrese el precio: ");

        if (precio <= 0) {
            std::cout << "El precio debe ser mayor que 0.\n";
        }
    } while (precio <= 0);

    do {
        cantidad = leerEntero("Ingrese la cantidad: ");

        if (cantidad <= 0) {
            std::cout << "La cantidad debe ser mayor que 0.\n";
        }
    } while (cantidad <= 0);

    do {
        porcentajeDescuento =
            leerDecimal("Ingrese el descuento (0 a 100): ");

        if (porcentajeDescuento < 0 ||
            porcentajeDescuento > 100) {
            std::cout << "El descuento debe estar entre 0 y 100.\n";
        }
    } while (porcentajeDescuento < 0 ||
             porcentajeDescuento > 100);

    // Paso 3: calcular los importes llamando a los módulos de ticket.h

    subtotal = calcularSubtotal(precio, cantidad);

    descuento =
        calcularDescuento(subtotal, porcentajeDescuento);

    double subtotalConDescuento = subtotal - descuento;

    iva = calcularIVA(subtotalConDescuento);

    total = subtotalConDescuento + iva;

    // Paso 4: imprimir el ticket

    imprimirTicket(
        nombre,
        precio,
        cantidad,
        subtotal,
        descuento,
        porcentajeDescuento,
        iva,
        total
    );

    return 0;
}