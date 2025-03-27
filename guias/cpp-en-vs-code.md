# C++ en VS Code

## Compilador

&nbsp;
Cuando programás en C++, escribís código en un archivo de texto con extensión `.cpp`. Sin embargo, la computadora no entiende directamente ese código, y necesita traducirlo. El compilador toma el código fuente codificado en C++ y lo convierte en un archivo ejecutable, que en Windows tiene extensión `.exe`.

>[!IMPORTANT]
&nbsp;
A diferencia de MacOs y Linux, Windows no tiene un compilador de C++ instalado de manera predeterminada.

### Instalación de w64devkit

>[!IMPORTANT]
&nbsp;
A diferencia de CodeBlocks y otros IDEs, Visual Studio Code es un editor de código por lo que que no cuenta con un compilador de C++.

&nbsp;
Si no tenés instalado ningún compilador de C++, podés descargar [w64devkit](https://github.com/skeeto/w64devkit) que incluye el compilador `gcc/g++`.

1. Dirigite a los [Releases](https://github.com/skeeto/w64devkit/releases) del repositorio y descargá el instalador `.exe` acorde a la arquitectura que tenga tu sistema operativo.

2. Descomprimilo y copiá la ruta de la carpeta bin que contiene el paquete, donde se encuentran todos los compiladores que provee. Si hiciste la instalación en el disco rígido, la ruta debería ser:

    ```
    C:\w64devkit\bin
    ```

### Variables de entorno

&nbsp;
Las variables de entorno son valores almacenados en el sistema operativo para poder ser usados por programas. El `Path` es una variable de entorno que almacena las rutas donde el sistema busca archivos ejecutables.

&nbsp;
Para que VS Code pueda usar el compilador `gcc/g++` que incluye [w64devkit](https://github.com/skeeto/w64devkit), es necesario agregarlo al `Path`. Pero podés agregar cualquier compilador que tengas instalado.

1. En inicio, buscar `env`:

    ![Imgur](./../images/environment-variables-1.png)

2. Abrir las variables de entorno:

    ![Imgur](./../images/environment-variables-2.png)

3. Editar el `Path`:

    ![Imgur](./../images/environment-variables-3.png)

4. Agregar una nueva ruta y pegar la ruta del compilador:

    ![Imgur](./../images/environment-variables-4.png)

## Visual Studio Code

1. Descargar e instalar [Visual Studio Code](https://code.visualstudio.com).

2. Instalar la extensión [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) en Visual Studio Code.

3. Crear un archivo llamado `tasks.json` en una carpeta llamada `.vscode` dentro del Workspace, a partir de la siguientes plantillas.

   - Para compilar en Windows:
       ```json
       {
           "version": "2.0.0",
           "tasks": [
               {
                   "label": "C/C++: g++.exe",
                   "detail": "Compile (Windows) | main.cpp",
                   "type": "shell",
                   "command": "g++.exe",
                   "args": [
                       "-fdiagnostics-color=always",
                       "-std=c++17",
                       "-Wall",
                       "-Wextra",
                       "-pedantic",
                       "${fileDirname}\\main.cpp",
                       "-o",
                       "${fileDirname}\\bin\\${fileBasenameNoExtension}.exe"
                   ],
                   "options": {
                       "cwd": "${fileDirname}"
                   },
                   "problemMatcher": [
                       "$gcc"
                   ],
                   "group": {
                       "kind": "build"
                   }
               }
           ]
       }
       ```

   - Para compilar en MacOs:
       ```json
       {
           "version": "2.0.0",
           "tasks": [
               {
                   "label": "C/C++: clang++",
                   "detail": "Compile (MacOs) | main.cpp",
                   "type": "shell",
                   "command": "clang++",
                   "args": [
                       "-stdlib=libc++",
                       "-std=c++14",
                       "-std=c++17",
                       "-Wall",
                       "-Wextra",
                       "-pedantic",
                       "-pedantic-errors",
                       "-g",
                       "${fileDirname}/main.cpp",
                       "-o",
                       "${fileDirname}/bin/${fileBasenameNoExtension}"
                   ],
                   "problemMatcher": [
                       "$gcc"
                   ],
                   "group": {
                       "kind": "build",
                       "isDefault": true
                   }
               }
           ]
       }
       ```

4. (Opcional) Si obtenés un error en la línea `#include <iostream>`, simplemente creá dentro de la carpeta `.vscode` un archivo que se llame `c_cpp_properties.json` y tenga el siguiente código, reiniciando VS Code luego.

    ```json
    {
        "configurations": [
            {
                "name": "C++ for Linux",
                "includePath": [
                    "${workspaceFolder}/**"
                ],
                "defines": [],
                "compilerPath": "/usr/bin/gcc",
                "cStandard": "c17",
                "cppStandard": "c++98",
                "intelliSenseMode": "linux-gcc-x64"
            },
            {
                "name": "C++ for Mac",
                "defines": [],
                "includePath": [
                    "${workspaceFolder}/**"
                ],
                "macFrameworkPath": [
                    "/System/Library/Frameworks",
                    "/Library/Frameworks"
                ],
                "compilerPath": "/usr/bin/clang",
                "cStandard": "c11",
                "cppStandard": "gnu++14",
                "intelliSenseMode": "macos-gcc-arm64"
            },
            {
                "name": "C++ for Windows",
                "includePath": [
                    "${workspaceFolder}/**"
                ],
                "defines": [],
                "compilerPath": "C:\\w64devkit\\bin\\g++.exe",
                "cStandard": "c17",
                "cppStandard": "c++17",
                "intelliSenseMode": "clang-x64",
                "browse": {
                    "path": [
                        "${workspaceFolder}"
                    ]
                }
            }
        ],
        "version": 4
    }
    ```

>[!NOTE]
&nbsp;
Si bien en un proyecto real sería una mala práctica, no agregué la carpeta [.vscode](./../.vscode) a `.gitignore` para que la misma se incluya en el repositorio y puedas ver un ejemplo de cómo quedan los archivos `tasks.json` y `c_cpp_properties.json` con las configuraciones para varios sistemas operativos.

## Compilar y ejecutar

1. Verificar que exista una carpeta llamada `bin` en el mismo directorio que se encuentre el archivo `main.cpp` y si no existe crearla.

2. Abrir en VS Code el archivo `main.cpp` y dirigirse al menú `Terminal`, seleccionar `Run Task...` y luego elegir la task llamada `Compile (Windows) | main.cpp` si estás en Windows o `Compile (MacOs) | main.cpp` si estás en MacOs.

3. Dirigirse al menú `Terminal`, y seleccionar la opción `New Terminal` para inicializar una terminal bash en el proyecto que se encuentre el archivo `main.cpp` que se quiere compilar.

4. Ejecutar el programa, usando los siguientes comandos.

   - En Windows:
       ```bash
       .\bin\main.exe
       ```

   - En MacOs:
       ```bash
       ./bin/main
       ```