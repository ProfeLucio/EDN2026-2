## Sistema de Control de Carga de Contenedores

Una empresa de logística portuaria necesita gestionar el peso de los contenedores que se cargarán en un buque antes de su salida. Debido a las normativas de tránsito marítimo y terrestre, cada contenedor tiene un límite estricto de Carga Útil (Payload) y Masa Bruta Máxima (Max Gross Weight).

Objetivo:
Implementar un programa en C que utilice una lista enlazada simple para gestionar los contenedores que esperan en el patio de carga.
Requerimientos del programa:
1. Definición de Estructuras:
Crea una estructura llamada Contenedor que contenga los siguientes campos:
	• Tara (peso en kg del contenedor vacío).
	• Carga Útil o Neta (peso en kg de la mercancía dentro del contenedor).
	• Un puntero al siguiente nodo de la lista.
2. Funciones obligatorias a implementar:
	• insertar_contenedor(): Añade un nuevo contenedor al final de la lista de espera. El programa debe calcular y guardar automáticamente la Masa Bruta Máxima (Tara + Carga Útil).
	• mostrar_manifiesto(): Recorre la lista enlazada e imprime en pantalla el desglose de todos los contenedores registrados (Tara, Carga Útil y Masa Bruta).
	• verificar_alertas_peso(): Recorre la lista y muestra una advertencia si algún contenedor supera un límite de Masa Bruta Máxima de 32,500 kg (límite estándar internacional).
