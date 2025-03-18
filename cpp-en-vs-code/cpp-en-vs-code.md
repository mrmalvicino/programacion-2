# C++ en VS Code

1. Descargar el compilador [Mingw-w64 GCC](https://github.com/skeeto/w64devkit/releases).

2. Agregarlo a las variables de entorno de Windows.

3. Instalar la extensión [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) en Visual Studio Code.

4. Crear un archivo llamado `tasks.json` en el Workspace de VS Code, a partir de la siguiente plantilla:

    ```json
    {
        "version": "2.0.0",
        "tasks": [
            {
                "label": "C/C++: g++.exe",
                "detail": "Compile on Windows",
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

5. Compilar seleccionando `Run Task...` y luego `Compile on Windows` en el menú `Terminal`.

6. Inicializar una terminal en el proyecto para ejecutar el programa, seleccionando la opción `New Terminal` del menú `Terminal` y usando el comando:

    ```bash
    .\bin\main.exe
    ```