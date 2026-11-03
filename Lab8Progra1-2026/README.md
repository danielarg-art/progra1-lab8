# Lab8 Pizza Builder - Proyecto Grupal

## Descripción General.
Este es un Lab8 grupal de programación para construir una aplicación Pizza Builder. 

## Estructura del Equipo
**Tamaño del grupo:** 3 miembros

Cada miembro del equipo es responsable de implementar un tipo de ingrediente:
- **Miembro 1:** Ingredientes de queso (cheese)
- **Miembro 2:** Ingredientes de carnes (meat)
- **Miembro 3:** Ingredientes de hierbas (herb)

*Nota: El ingrediente tomates ya está implementado como referencia*

## Crear un repositorio nuevo (Solo un miembro del equipo lo creará, y agregar a los demás como colaboradores)
## Estrategia de ramas (branches)
Cada miembro del equipo debe crear y trabajar en su propio feature branch 

```
feature/cheese
feature/meats
feature/herbs
```

## Al finalizar su parte del Lab8, sus cambios deberán subirse utilizando commit y push a su propia rama.
## Luego crear un Pull Request que deberá ser revisado por los demás miembros y aceptado.
## (Ojo, un Pull Request fusionado a la rama principal, que no tengan almenos la revision de otro miembro del equipo, serán penalizados con 5 puntos menos para la persona que fusionó esos cambios)
## El proceso correcto es, por ejemplo.
## Si Juan hace los cambios para incluir el Queso como ingrediente al sistema, Juan hace primero una rama llamada "feature/cheese", implenta su parde de los cambio, 
## hace Commit y Push a su rama, se dirige a Github, en el repositorio, crea un nuevo Pull Request desde su rama "feature/cheese" in "main" o "master", la rama principal.
## Alguien del equipo, revisa y acepta los cambios de Juan, pero es Juan mismo el que deberá dar Merge a esos cambios. Juan es responsable de dar click en Merge por que 
## el está comprometiendose que hizo esos cambios de forma correcta, y alguien más le puso le dio visto bueno.
## La gestión de equipo con Git será valorado por un total de:
## --- 40 Puntos

### Responsabilidades Individuales

#### 1. Implementación de Clase Repository --- 30 Puntos 
Cada miembro debe crear su clase repository específica para su ingrediente usando `TomatoesRepository` como referencia:

- `CheeseRepository` (para ingredientes de queso)
- `MeatsRepository` (para ingredientes de carne)
- `HerbsRepository` (para ingredientes de hierbas)

**Métodos Requeridos:**
- Constructor que carga datos del archivo `.txt` correspondiente
- `GetAvailableQuantity(const std::string& ingredientType)` - Retorna la cantidad disponible
- `UpdateQuantity(const std::string& ingredientType, int newQuantity)` - Actualiza la cantidad

#### 2. Archivos de Datos
Trabajar con su archivo de ingredientes correspondiente:
- `cheese.txt` (para el miembro de queso)
- `meats.txt` (para el miembro de carnes)
- `herbs.txt` (para el miembro de hierbas)

#### 3. Integración con PizzaBuilder --- 30 Puntos 
Modificar la clase `PizzaBuilder` para incluir su ingrediente:

- Agregar su repository como variable miembro
- Agregar su método de selección de ingrediente (ej., `SelectCheese()`, `SelectMeats()`, `SelectHerbs()`)
- Actualizar el método `BuildPizza()` para llamar su método de selección
- Agregar su lista de ingredientes disponibles como variable miembro

### Estructura del Proyecto
```
├── main.cpp                 (NO MODIFICAR)
├── PizzaBuilder.h/.cpp     (Modificar para agregar sus ingredientes)
├── DataLoader.h/.cpp       (Solo referencia)
├── IngredientSelector.h/.cpp  (NO MODIFICAR)
├── TomatoesRepository.h/.cpp (Implementación de referencia)
├── [Su]Repository.h/.cpp (Su implementación)
├── tomatoes.txt           (Datos de referencia)
├── cheese.txt             (Datos de queso)
├── meats.txt              (Datos de carnes)
├── herbs.txt              (Datos de hierbas)
└── README.md              (Este archivo)
```

## Resultado Esperado

### Características Finales del Pizza Builder:
1. **Selección Completa de Ingredientes:** Los 4 tipos de ingredientes (tomatoes, cheese, meats, herbs) disponibles
2. **Gestión de Cantidades:** Los ingredientes se reducen en cantidad cuando son seleccionados
3. **Interfaz de Usuario:** Proceso de selección limpio para cada tipo de ingrediente
4. **Seguimiento de Inventario:** Muestra en tiempo real las cantidades disponibles (Revisar como imprime en el ejemplo del Tomate)

### Flujo de Experiencia del Usuario:
1. El usuario ejecuta la aplicación
2. Se muestra la selección para cada tipo de ingrediente
3. El usuario selecciona ingredientes deseados basado en cantidades disponibles
4. La pizza final muestra todos los ingredientes seleccionados
5. El inventario se actualiza automáticamente

## Requisitos Técnicos

### Implementación del Patrón Repository:
- Cada repository sigue el mismo patrón de interfaz
- Carga de datos a través de la utilidad `DataLoader`
- Manejo de excepciones para ingredientes inválidos
- Gestión y persistencia de cantidades

### Uso de Templates:
- El template `IngredientSelector<T>` no debe modificarse, está hecho con un template, y funciona con todos los tipos de clase repository.
- Esta lógica permite reutilizar una misma clase para diferentes tipos de repositorio.
- No es necesario modificarla, pero si deben entender como se usa,
- Revisenlo en el método SelectTomatoes, lo requeriran para crear: SelectCheese , SelectHerb , SelectMeat

### Puntos de Integración:
- Agregar el include de su repository en `PizzaBuilder.h`
- Al Agregar nuevos archivos, como cuando se agregan los repositorios, esto actualizará los archivos del proyecto 
- (`.vcxproj` y `.vcxproj.filters`) 


## Restricciones
- **NO modificar `main.cpp`**
- Mantener el flujo actual de interfaz de usuario
- Usar el sistema de template `IngredientSelector` existente. 
- (No modificar la clase `IngredientSelector`, pero si utilizarla en lo solicitado)
- Seguir el patrón Repository establecido por `TomatoesRepository`

## Criterios de Evaluación
1. **Funcionalidad:** ¿Su selección de ingredientes funciona correctamente?
2. **Integración:** ¿Se integra perfectamente con el código existente?
3. **Calidad de Código:** Sigue convenciones para escritura de código.
4. **Colaboración en Equipo:** Uso apropiado de feature branches y control de versiones

## Cómo Empezar
1. Clonar el repositorio
2. Crear su feature branch: `git checkout -b feature/[su-ingrediente]`
3. Examinar `TomatoesRepository.h/.cpp` como referencia de implementación
4. Implementar su clase repository e integrar con `PizzaBuilder`
5. Probar su implementación exhaustivamente
6. Hacer commit y push de su feature branch para su integración mediante el Pull Request a Main.

## Criterios de Éxito
✅ Los 4 ingredientes (tomatoes, cheese, meats, herbs) son seleccionables
✅ El seguimiento de cantidades funciona correctamente para todos los ingredientes
✅ El usuario puede construir una pizza completa con múltiples tipos de ingredientes
✅ Sin errores de compilación
✅ La aplicación ejecuta sin fallos al descargarse del repositorio y builder.
✅ Código limpio y mantenible siguiendo patrones especificados en el proyecto.