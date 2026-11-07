# Práctica: Ticket de compra

> Llena cada sección en la fase que se indica. Las instrucciones completas están en `PRACTICA.md`.
> Si una pregunta no aplica (por ejemplo, no hiciste el Experimento C o no tuviste dudas), escribe `No aplica`. Si te sobran filas en una tabla, bórralas.

## 1. Descripción del problema (Fase 1)
<!-- Explica con tus palabras qué hace tu programa y para qué serviría en la vida real. Máximo 4 líneas. -->

El programa sirve para realizar un ticket de compra. Permite ingresar los datos de una compra, calcular el IVA y aplicar un descuento para obtener el total a pagar. Al final muestra el ticket con la información de la compra.

## 2. Entradas y salidas (Fase 1)
<!-- Define cada entrada y cada salida, con su tipo de dato y la función de utilerias.h con la que la vas a leer. -->

**Entradas:**

| Entrada | Tipo de dato | Función de `utilerias.h` |
|---|---|---|
| nombre | string | leerTexto() |
| precio | double | leerDouble() |
| porcentaje | double | leerDouble() |
| descuento | double | leerDouble() |

**Salida** (¿qué datos muestra el ticket?):
El ticket muestra el nombre del cliente, el precio de la compra, el IVA, el descuento aplicado y el total a pagar.

**¿El IVA se calcula sobre el subtotal o sobre lo que queda después del descuento? ¿Por qué?**
El IVA se calcula sobre el subtotal antes del descuento, porque el descuento se aplica después de calcular el IVA.

## 3. Restricciones e invariante (Fases 1 y 2)

**Restricciones** (¿qué debe cumplirse?):

| Dato | ¿Qué valores son válidos? | ¿Por qué? |
|---|---|---|
| Nombre del producto | Texto no vacio | Para identificar el producto |
| Precio | Mayor que 0 | Un precio no puede ser negativo ni cero |
| Cantidad | Entero mayor que 0 | Debe existir al menos una unidad |
| Descuento (%) | Entre 0 y 100 | Un porcentaje de descuento debe estar dentro de ese rango |

**¿Qué hace mi programa si el usuario escribe un dato fuera de rango?**
El programa vuelve a pedir el dato hasta que el usuario escriba un valor valido. 

**¿Puede el total salir negativo? ¿Por qué?**
No, porque el descuento no puede ser mayor al 100% y el IVA se suma al total.

**Invariante 1** (después del ciclo que valida el precio, ¿qué es siempre cierto sobre `precio`?):
precio siempre es mayor que 0.

**Invariante 2** (¿qué relación se cumple siempre entre el subtotal, el descuento, el IVA y el total?):
total = subtotal - descuento + IVA.

## 4. Casos resueltos a mano (Fase 1)

| Caso | Nombre | Precio | Cantidad | Descuento (%) | Subtotal | Descuento ($) | IVA | Total |
|---|---|---|---|---|---|---|---|---|
| 1 (sin descuento) | cuaderno | $100 | 2 | 0% | $100 x 2= $200 | $0 | $200 x 16%=$32 | $200 - 0 + $32 = $232 |
| 2 (con descuento) | Mochila | $500 | 1 | 10% | $500 x 1 = $500 | $500 x 10% = $50 | $500 x 16% = $80 | $500 - $50 + $80= $530 |
| 3 (precio con centavos) | Audifonos | $249.50 | 2 | 15$ | $249.50 x 2 = $499.00 | $499.00 x 15% = $74.85 | $499 x 16% = $79.84 | $499 - $74.85 + 79.84 = $503.99 |

## 5. Tipo de dato abstracto (Fase 1)

| TDA | Datos (¿qué tiene?) | Operaciones (¿qué se puede hacer con él?) |
|---|---|---|
| Producto | nombre (texto), precio, cantidad, descuento | calcular su subtotal |
| Ticket | nombre, precio, cantidad, descuento, IVA, total | calcular el total y mostrar el ticket |

**Jerarquías:** una tienda vende productos por pieza (un cuaderno) y productos por peso (un kilo de tortillas). ¿Los dos son productos? ¿Qué datos tienen en común y cuál cambia?
Sí, los dos son productos. Ambos tienen nombre, precio y cantidad, pero cambia la forma de calcular el precio: uno se vende por pieza y el otro por peso.

## 6. Análisis descendente (Fase 2)
<!-- Completa el árbol. Marca con (ya existe) las partes que ya resuelve una función de utilerias.h o de ticket.h. -->

```
Generar ticket de compra
├── 1. Mostrar bienvenida
├── 2. Pedir los datos
│     ├── 2.1 Pedir el nombre del producto
│     ├── 2.2 Pedir el precio (y validar que sea mayor que 0)
│     ├── 2.3 Pedir la cantidad (y validar que sea mayor que 0)
│     └── 2.4 Pedir el descuento (y validar que este entre 0 y 100)
├── 3. Calcular los importes
│     ├── 3.1 Calcular el subtotal
│     ├── 3.2 calcular el descuento
│     ├── 3.3 calcular el IVA
│     └── 3.4 calcular el total
└── 4. Imprimir el ticket
```

**Análisis ascendente: ¿qué partes del árbol ya estaban resueltas por una función que existe? ¿Cuáles?**
Pedir los datos e imprimir el ticket ya estaban contemplados en funciones existentes de utilerias.h y ticket.h.

**¿Alguna parte del árbol hacía más de una cosa? ¿Cómo la dividiste?**
Sí, la parte de calcular los importes hacía varias operaciones. La dividí en calcular subtotal, descuento, IVA y total.

## 7. Módulos y receta (Fase 2)

| Módulo | ¿Qué recibe? | ¿Qué devuelve? | ¿Función o procedimiento? |
|---|---|---|---|
| `calcularSubtotal` | precio, cantidad | el subtotal | Función |
| `calcularDescuento` | subtotal, porcentaje | el monto del descuento | Función |
| `calcularIVA` | subtotal | el monto del IVA | Funcion |
| `imprimirTicket` | nombre, precio, cantidad, descuento, IVA, total | muestra el ticket | Procedimiento |

<!-- Tu receta va en el archivo RECETA.md. Aquí solo responde las preguntas. -->

**¿Probé mi receta a mano con mis 3 casos?** Sí 
**¿Tuve que corregirla? ¿Qué cambié?** No. La receta funciono correctamente con los tres casos. 

## 8. Cómo compilar y ejecutar (Fase 3)

Compilar (desde la carpeta del proyecto):

```bash
g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o ticket
```

Ejecutar en macOS:

```bash
./ticket
```

Ejecutar en Windows:

```bash
.\ticket.exe
```

**¿En qué sistema operativo trabajé?** _____

## 9. Ejemplo de ejecución (Fase 3)
<!-- Pega aquí lo que muestra tu programa en pantalla con el caso 2 de la tabla de pruebas (Cuaderno, 50, 2, 10). -->

```
_____
```

## 10. De la receta al código (Fase 3)
<!-- Para cada paso de TU receta, escribe el módulo o la instrucción de C++ que lo implementa. Agrega las filas que necesites. -->

| Paso de la receta | Módulo o instrucción de C++ que lo implementa |
|---|---|
| 1. Mensaje de bienvenida | `cout` |
| 2. Pedir los datos | `leerTexto()` y `leerDouble()` |
| 3. Calcular el subtotal | `calcularSubtotal()` |
| 4. Calcular el descuento | `calcularDescuento()` |
| 5. Calcular el IVA y el total | `calcularIVA()` e ìmprimirTicket()` |

**¿Hubo algún paso de mi receta que me costó traducir a C++? ¿Cuál y por qué?**
Sí, calcular el IVA y el total, porque tuve que convertir las operaciones de la receta a instrucciones y usar las variables correspondientes.

**Formato del ticket: ¿qué ancho usé en `std::setw` y por qué? ¿Qué pasa si uso un número menor que el largo de la etiqueta más larga?**
Usé un ancho de 20 en std::setw para que los datos quedaran alineados. Si uso un número menor que el largo de la etiqueta más larga, el texto no tendrá suficiente espacio y puede quedar desalineado.

**¿Convertí el ancho de las líneas del ticket (36) en una constante? ¿Cómo la llamé? Si no, ¿por qué?**
No, todavia no lo converti en una constante.

## 11. Experimentos y depuración (Fase 3)

**Experimento A: depuración de `calcularDescuento`**

| Paso de depuración | Lo que hice o encontré |
|---|---|
| 1. Reproduce: ¿con qué datos falló? | Probé con un descuento de 10% y un subtotal de $500. |
| 2. Aísla: ¿qué valor intermedio estaba mal? (salidas `[DEBUG]`) | El valor del descuento no coincidía con el resultado esperado. |
| 3. Explica: ¿cuál era la causa? | La operación del porcentaje no estaba calculándose correctamente. |
| 4. Corrige: ¿qué cambiaste? | Corregí la fórmula para calcular el descuento como subtotal * porcentaje / 100. |
| 5. Limpia: ¿comentaste tus salidas `[DEBUG]`? | Sí, eliminé las salidas de depuración. |

**La prueba con 0 % pasó aunque la función tenía un error. ¿Qué me enseña eso sobre elegir mis casos de prueba?**
Que no basta con probar un solo caso. Es necesario utilizar diferentes valores, incluyendo casos normales, límites y casos que puedan revelar errores.


**Experimento B: al cambiar el IVA a 8 %, ¿cuántas líneas tuve que cambiar? ¿Qué mejoraría?**
Tuve que cambiar la línea donde se calcula el IVA. Mejoraría el programa usando una constante para que el porcentaje del IVA se pueda cambiar en un solo lugar.

**¿Mi ticket seguía diciendo `IVA (16%)`? ¿Qué hice al respecto?**
Sí. Cambié el texto del ticket para que mostrara el porcentaje de IVA correspondiente.


**Experimento C (opcional): al cambiar el parámetro dentro de `calcularIVA`, ¿cambió la variable de `main()`? ¿Por qué?**
_____

## 12. La constante "Le atendio" (Fase 3)

**¿Dónde definí la constante con mi nombre?** (marca una)
- [x] Constante local dentro de `imprimirTicket`
- [ ] Constante a nivel de la librería, en `ticket.h`
- [ ] Función que siempre devuelve la misma cadena

**¿Por qué elegí esa opción?**
Porque el nombre de quien atiende solamente se utiliza al imprimir el ticket. Al ser una constante local, queda definida cerca del lugar donde se necesita y no afecta otras partes del programa.

**¿Qué otras partes del programa podrían necesitar el nombre de quien atiende? (un mensaje de bienvenida, un ticket de devolución...)**
Podría utilizarse en un mensaje de bienvenida, en un ticket de devolución o en alguna otra parte donde se necesite mostrar quién atendió.

**Si mañana atiende otra persona, ¿en cuántos lugares tengo que cambiar el nombre?**
En un solo lugar, porque el nombre está definido como una constante y se utiliza desde imprimirTicket.

**Si el nombre se leyera del teclado o de un archivo, ¿cuánto código tendría que cambiar con mi opción?**
Tendría que cambiar la constante por una variable que reciba el nombre desde el teclado o desde el archivo. También habría que modificar la función si fuera necesario pasarle ese nombre como parámetro.

## 13. Tabla de pruebas (Fase 4)
<!-- Los datos de entrada de cada caso están en PRACTICA.md, Fase 4. -->

| # | Caso | Esperado (subtotal / descuento / IVA / total) | Obtenido | ¿Pasó? |
|---|---|---|---|---|
| 1 | Sin descuento | 100.00 / 0.00 / 16.00 / 116.00 | _____ | _____ |
| 2 | Con descuento | 100.00 / 10.00 / 14.40 / 104.40 | _____ | _____ |
| 3 | Descuento de 15 % | 600.00 / 90.00 / 81.60 / 591.60 | _____ | _____ |
| 4 | Precio con centavos | 19.99 / 0.00 / 3.20 / 23.19 | _____ | _____ |
| 5 | Descuento total | 90.00 / 90.00 / 0.00 / 0.00 | _____ | _____ |
| 6 | Precio inválido | vuelve a pedir el precio dos veces; 40.00 / 0.00 / 6.40 / 46.40 | _____ | _____ |
| 7 | Cantidad inválida | vuelve a pedir la cantidad dos veces; 20.00 / 0.00 / 3.20 / 23.20 | _____ | _____ |
| 8 | Descuento inválido | vuelve a pedir el descuento dos veces; 100.00 / 20.00 / 12.80 / 92.80 | _____ | _____ |
| 9 | Texto en el precio | vuelve a pedir el precio una vez; 100.00 / 0.00 / 16.00 / 116.00 | _____ | _____ |
| 10 | Nombre con espacios | muestra el nombre completo; 25.50 / 0.00 / 4.08 / 29.58 | _____ | _____ |
| 11 | Nombre vacío | vuelve a pedir el nombre una vez; 12.00 / 0.00 / 1.92 / 13.92 | _____ | _____ |
| 12 | Caso propio 1: _____ | _____ | _____ | _____ |
| 13 | Caso propio 2: _____ | _____ | _____ | _____ |

**En el caso 4 el IVA real es 3.1984. ¿Por qué mi ticket muestra 3.20?**
_____

**En el caso 10, ¿el ticket siguió alineado? Si no, ¿qué corregí?**
_____

## 14. Generalización (Fase 4)

**¿Qué cálculo hacen `calcularDescuento` y `calcularIVA`? ¿Qué cambia entre una y otra?**
calcularDescuento calcula una cantidad de descuento aplicando un porcentaje sobre el subtotal. calcularIVA calcula el IVA aplicando el porcentaje de IVA sobre el subtotal. Las dos realizan un cálculo porcentual, pero utilizan porcentajes diferentes y representan conceptos distintos.

**Receta de `calcularPorcentaje`** (también va en `RECETA.md`):

```text
MÓDULO calcularPorcentaje(cantidad, porcentaje)
    CALCULAR resultado = cantidad * porcentaje / 100
    DEVOLVER resultado
FIN MÓDULO
```

**¿Cómo quedaron el descuento y el IVA después del cambio?**
El descuento y el IVA se pueden calcular utilizando la misma solución general de porcentaje, cambiando únicamente la cantidad y el porcentaje que se utilizan.

**¿Volví a correr toda la tabla de pruebas después del cambio? ¿Todo siguió pasando?**
Pendiente. Se comprobará después de implementar calcularPorcentaje y ejecutar nuevamente la tabla completa de pruebas.

**¿Agregué `calcularPorcentaje` a mi tabla de módulos (sección 7)?** Sí 

**¿En qué otro programa podría reutilizar `calcularPorcentaje`?**
Pendiente. Se comprobará después de implementar calcularPorcentaje y ejecutar nuevamente la tabla completa de pruebas.

## 15. Revisión de calidad (Fase 4)

| Principio | Pregunta | ¿Lo cumple? | Evidencia |
|---|---|---|---|
| Correcto | ¿Pasa todas las pruebas de la tabla? | _____ | _____ |
| Robusto | ¿Resiste datos inválidos sin fallar ni terminar? | _____ | _____ |
| Legible | ¿Otra persona entiende tu código sin que se lo expliques? | _____ | _____ |
| Modular | ¿Cada función hace una sola cosa? | _____ | _____ |
| Sin números mágicos | ¿Los valores fijos tienen nombre? | _____ | _____ |
| Fácil de mantener | Si cambia el IVA o quien atiende, ¿cuántas líneas cambias? | _____ | _____ |
| Reutilizable | ¿Alguna de tus funciones serviría en otro programa? | _____ | _____ |

## 16. Reto obligatorio (Fase 4)

**¿Qué reto elegí?** (número y nombre; el 4 no cuenta como obligatorio) _____

**¿Por qué lo elegí?**
_____

**¿Cómo lo resolví? ¿Qué módulos agregué o cambié?**
_____

**¿Hice algún otro reto opcional? ¿Cuál?**
_____

## 17. Bitácora de mejoras (Fase 4)

| # | ¿Qué falló o qué quise mejorar? | ¿Qué cambié? | ¿Funcionó? |
|---|---|---|---|
| 1 | _____ | _____ | _____ |
| 2 | _____ | _____ | _____ |

## 18. Dudas para el profesor (Fase 3)

| Duda | Lo que ya intenté |
|---|---|
| _____ | _____ |

## 19. Reflexión final

**¿Qué aprendí con esta práctica?**
_____

**Ahora que terminé, ¿qué cambiaría de mi proceso?**
_____

**¿Qué fue lo más difícil y cómo lo resolví?**
_____

**¿Qué pregunta me quedó sin responder?**
_____

**Comparado con las prácticas anteriores, donde todo estaba en `main()`, ¿dividir el programa en módulos me facilitó o me complicó el trabajo? ¿Por qué?**
_____

**¿Cómo encontré el error de `calcularDescuento`? ¿Lo habría encontrado si solo hubiera probado sin descuento?**
_____

## 20. Commits (Fase 5)

**¿Cuántos commits hice durante la práctica?** _____

**Si hice menos de 3, ¿por qué?**
_____

## 21. Lista de verificación antes de entregar (Fase 5)

- [ ] Llené las secciones 1 a 20 (no quedan `_____`; escribí `No aplica` donde corresponde)
- [ ] Completé el árbol de análisis descendente y la tabla de módulos
- [ ] Escribí en `RECETA.md` la receta de `main` y la de cada módulo, antes de programar
- [ ] Cada bloque de `main.cpp` tiene su comentario `// Paso N`, de acuerdo con mi receta
- [ ] Corregí el error de `calcularDescuento` y documenté cómo lo encontré
- [ ] Hice los Experimentos A y B y dejé el código correcto al terminar
- [ ] Mi ticket se ve alineado y termina con la línea "Le atendio:", leída de una constante
- [ ] Justifiqué dónde definí la constante con mi nombre
- [ ] Escribí `calcularPorcentaje` y volví a correr todas las pruebas
- [ ] Hice al menos uno de los retos y lo documenté
- [ ] No queda ninguna salida `[DEBUG]` activa
- [ ] Mi programa compila sin advertencias
- [ ] Probé todos los casos de la tabla
- [ ] Revisé los principios de calidad de mi programa
- [ ] No modifiqué `utilerias.h`
- [ ] Tengo al menos 3 commits con mensajes claros (o justifiqué por qué no)
- [ ] Hice `git push` y verifiqué mi fork en GitHub
- [ ] Mi fork se llama `ulsa_ime_1_dp_ticket_compra`, mis módulos están en `include/ticket.h` y mi programa principal en `src/main.cpp`
- [ ] Entregué el enlace de mi fork en Classroom
