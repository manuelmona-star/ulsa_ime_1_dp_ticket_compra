#pragma once

#include <iostream>
#include <string>
#include <iomanip>

// Calcula el subtotal
// Recibe: precio y cantidad
// Devuelve: precio por cantidad
inline double calcularSubtotal(double precio, int cantidad) {
    return precio * cantidad;
}

// Calcula el descuento
// Recibe: subtotal y porcentaje de descuento
// Devuelve: monto del descuento
inline double calcularDescuento(double subtotal, double porcentaje) {
    return subtotal * porcentaje / 100.0;
}

// Calcula el IVA
// Recibe: subtotal después del descuento
// Devuelve: monto del IVA
inline double calcularIVA(double subtotalConDescuento) {
    const double IVA = 0.16;
    return subtotalConDescuento * IVA;
}

// Imprime el ticket
inline void imprimirTicket(
    const std::string& nombre,
    double precio,
    int cantidad,
    double subtotal,
    double descuento,
    double porcentajeDescuento,
    double iva,
    double total
) {
    std::cout << "\n====================================\n";
    std::cout << "          TICKET DE COMPRA\n";
    std::cout << "====================================\n";

    std::cout << "Cliente:   " << nombre << "\n";
    std::cout << "Precio:    $" << std::fixed << std::setprecision(2) << precio << "\n";
    std::cout << "Cantidad:  " << cantidad << "\n";
    std::cout << "Subtotal:  $" << subtotal << "\n";
    std::cout << "Descuento (" << std::fixed << std::setprecision(0) << porcentajeDescuento << "%): $" 
              << std::fixed << std::setprecision(2) << descuento << "\n";
    std::cout << "IVA:       $" << iva << "\n";
    std::cout << "TOTAL:     $" << total << "\n";

    std::cout << "====================================\n";
}