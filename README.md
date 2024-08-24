# _Proyecto Shell simplificado_
Este proyecto implementa una versión simplificada de un intérprete de comandos C. El programa le permite ejecutar comandos, administrar variables de entorno y manejar errores básicos. Está diseñado para proporcionar una comprensión fundamental de cómo funciona un shell en un sistema operativo

## _Descripción_
El programa simula el comportamiento básico de un shell, permitiendo al usuario ingresar comandos y ver los resultados. El shell se ejecuta en un bucle infinito, leyendo la entrada del usuario y ejecutando comandos. Además, el programa brinda la capacidad de mostrar variables de entorno y manejar errores de manera personalizada

## 🛠️ _Características_

- **Ejecución de comandos**: Ejecuta comandos del sistema ingresados ​​en la línea de comando.
- **Mostrar variables de entorno**: Con el `ambiente` comando, el programa imprime las variables de entorno actuales.
- **Manejo de errores personalizados**: Muestra mensajes de error detallados en caso de fallas en la ejecución de comandos.
- **Búsqueda ejecutable**: Busca el comando ejecutable en los directorios def
- inidos en la variable PATH del sistema.

## _Comandos disponibles_

- **`es`**: Enumera los archivos y directorios en el directorio actual.

    ```intento
    $ es
    ```

- **`persona con discapacidad`**: Muestra el directorio de trabajo actual.

    ```intento
    $ persona con discapacidad
    ```

- **`ambiente`**: Muestra las variables de entorno actuales..

    ```intento
    $ ambiente
    ```

- **`salida`**: Sale del caparazón.

    ```intento
    $ salida
    ```
## ❌ _Mensajes de error de ejemplo_

- **Comando no encontrado**:

    ```intento
    $ comando_inexistente
    comando_inexistente: 1: comando_inexistente: No existe tal archivo o directorio
    ```

    ## 📊 _diagramas de flujo_
  
  ### 🧩 `Diagrama de flujo principal`
 ![imagen](https://github.com/user-attachments/assets/4c01c501-fec2-4168-b845-4a10a5116340)

### 🔍 `ruta_varita` Diagrama de flujo
![imagen](https://github.com/user-attachments/assets/499187ae-a990-406c-ac7d-00dab612ea5d)

### ✂️ `conjunto de hechizos ` Diagrama de flujo
![contar](https://github.com/user-attachments/assets/4f3a0c88-ec61-4a99-8892-e19e92efa57e)
![dibujo de hechizos](https://github.com/user-attachments/assets/738ee4f6-3890-4d0f-94b2-bc3d58a7ae10)

### ⚡ `poder_fwe` Diagrama de flujo
![imagen](https://github.com/user-attachments/assets/bb55fda4-e184-403b-8456-175b3bce1989)

### `principal`

El punto de entrada del programa. Maneja la entrada del usuario y ejecuta comandos. Imprime un mensaje (`$ `) si se ejecuta en una terminal interactiva.

```
int principal(__atributo__((no utilizado))int ac,
         __atributo__((no utilizado))char **av,
        carácter **entorno)
```
__perror_
Imprime un mensaje de error personalizado que incluye el nombre del comando, el número del comando y el mensaje de error específico..
```
char *_perror(char *s, int recuento, char *in);
```
_matriz_libre_
Libera una matriz de cadenas asignadas dinámicamente.
```
void free_array(char **matriz);
```
_imprimir_arr_
Imprime cada elemento de una matriz de cadenas..
```
char **print_arr(char **arr);
```
_ruta_varita_
Busca un archivo ejecutable en los directorios definidos en la variable de entorno PATH.
```
char *wand_path(const char *entrada);
```
conjunto de hechizos
Divide una cadena en una serie de palabras usando delimitadores predefinidos.
```
char **spellarray(char *entrada);
```
_poder_fwe_
Ejecuta un comando en un proceso hijo. Utiliza execve para ejecutar el comando y fork para crear un nuevo proceso..
```
int power_fwe(char *phatname, char *argv[], char *envp[]);
```
