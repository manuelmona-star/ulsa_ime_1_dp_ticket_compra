# Receta: Ticket de compra

<!-- Escribe aquí tus recetas en pseudocódigo, ANTES de programar.
     Primero la receta del programa principal (main) y después una receta corta para cada módulo que vas a escribir tú.
     El primer paso de main es solo un ejemplo del formato; el resto es tuyo.
     Si las corriges después de probarlas a mano, deja aquí la versión final. -->

## Receta del programa principal (`main`)

<!-- Debe leerse casi igual que tu árbol de análisis descendente (sección 6 del README). -->

```text
1. MOSTRAR "Bienvenido a mi programa"
2. MOSTRAR "Ingrese el nombre del cliente"
3. LEER nombre
4. MOSTRAR "Ingrese el precio del producto"
5. LEER precio
6. CALCULAR IVA del producto
7. CALCULAR descuento del producto
8. CALCULAR porcentaje del descuento
9. CALCULAR total a pagar
10. MOSTRAR el ticket de compra
11. MOSTRAR "Le atendió: " y el nombre del cliente
```

## Recetas de los módulos

<!-- Para cada módulo: qué recibe, qué hace y qué devuelve. -->

### `calcularIVA`

```text
MODULO calcularIVA(subtotalConDescuento)
CALCULAR IVA = subtotalConDescuento * 0.16
DEVOLVER IVA

FIN MODULO
```

### `imprimirTicket`

```text
MODULO imprimirTicket(nombre, precio, IVA, descuento, total)
MOSTRAR "Ticket de compra"
    MOSTRAR nombre
    MOSTRAR precio
    MOSTRAR IVA
    MOSTRAR descuento
    MOSTRAR total

FIN MODULO
```

### `calcularPorcentaje` (Fase 4)

```text
MODULO calcularPorcentaje(cantidad, porcentaje)

CALCULAR resultado = cantidad * porcentaje / 100
DEVOLVER resultado

FIN MODULO
```

### Otros módulos que agregues (por ejemplo, para tu reto)

```text
 MÓDULO calcularDescuento(precio, porcentaje)

    CALCULAR descuento = precio * porcentaje / 100
    DEVOLVER descuento

FIN MÓDULO
```
