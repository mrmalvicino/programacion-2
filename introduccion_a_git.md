# Introducción a Git

- [Introducción a Git](#introducción-a-git)
  - [Conceptos básicos](#conceptos-básicos)
    - [¿Qué es Git y por qué usarlo?](#qué-es-git-y-por-qué-usarlo)
    - [¿Cuál es la diferencia entre Git y GitHub?](#cuál-es-la-diferencia-entre-git-y-github)
    - [Contribuir a un proyecto](#contribuir-a-un-proyecto)
    - [Otras características de GitHub](#otras-características-de-github)
  - [Glosario de comandos](#glosario-de-comandos)
  - [Instalación y configuración](#instalación-y-configuración)
  - [Crear un repositorio vacío](#crear-un-repositorio-vacío)
  - [Clonar un repositorio remoto](#clonar-un-repositorio-remoto)
  - [Sincronizar cambios por terminal](#sincronizar-cambios-por-terminal)

## Conceptos básicos

### ¿Qué es Git y por qué usarlo?

&nbsp;
Git es un sistema de **control de versiones** que permite llevar un registro de los cambios en el código fuente de un proyecto.

- Permite **colaborar** con otros desarrolladores sin sobrescribir cambios.

- Facilita **recuperar versiones** anteriores del código.

- Permite la **distribución de tareas** entre los desarrolladores.

### ¿Cuál es la diferencia entre Git y GitHub?

&nbsp;
El espacio donde se almacenan los archivos del proyecto junto con su historial de cambios se llama **repositorio**. Podríamos tener un repositorio **local** en una única computadora o en una red sin conexión a internet, y aún así usar Git para que uno o más desarrolladores gestionen las versiones de un programa.

&nbsp;
Github es una plataforma que permite alojar repositorios **remotos** en sus servidores, los cuales eventualmente pueden estar vinculados a repositorios locales.

### Contribuir a un proyecto

&nbsp;
Varios desarrolladores pueden tener **clones** locales de un mismo repositorio remoto para **realizar cambios** en un entorno controlado. De esta forma, si es necesario, es posible **revertir** cambios sin afectar los demás clones, o bien **incorporarlos** al repositorio remoto. Así, otros desarrolladores pueden **obtener** los cambios publicados en el repositorio remoto sin que se vean afectados los cambios sobre los que trabajaban en sus respectivos repositorios locales.

&nbsp;
Hay dos formas de realizar cambios en un repositorio de GitHub. Por un lado, el creador de un proyecto puede nombrar **colaboradores** o **contribuidores** para que estos puedan realizar cambios como si el respositorio fuese propio. Y por otro lado, cualquier persona puede descargar un clon de cualquier repositorio, realizar cambios, y **solicitar** al creador que los incorpore.

### Otras características de GitHub

&nbsp;
GitHub también ofrece herramientas para gestionar las **tareas** de los distintos desarrolladores, reportar **errores**, proponer y **revisar** aportes de terceros, **automatizar** pruebas e implementaciones y **documentar** los proyectos. Además, proporciona **alojamiento** gratuito para sitios web estáticos y funciona como **red social**, ya que cada cuenta puede tener seguidores y hay un feed donde es posible visualizar las interacciones.

## Glosario de comandos

&nbsp;
Existen comandos para realizar las acciones que se mencionaron anteriormente. Los siguientes son los más importantes:

| Comando | Explicación |
|-|-|
| `init` | Inicializa el versionado de un repositorio. |
| `clone` | Crea una copia local de un repositorio remoto. |
| `add` | Agrega los cambios hechos al próximo commit. |
| `commit` | Guarda un registro del estado actual del proyecto. |
| `pull` | Obtiene los commits del repositorio remoto, incorporándolos localmente. |
| `push` | Publica en el repositorio remoto los commits incorporados localmente. |
| `status` | Consulta el estado de cambios de los archivos del repositorio. |
| `log` | Consulta la lista de commits del repositorio. |

## Instalación y configuración

&nbsp;
Por única vez, es necesario instalar y configurar Git vinculando una cuenta de Github localmente.

1. Descargar e instalar [Git](https://git-scm.com/).

2. Crear una cuenta en [GitHub](https://github.com/).

3. Iniciar sesión en GitHub y en configuraciones dirigirse a la sección [Developer Settings](https://github.com/settings/tokens) para generar un Token clásico con todos los permisos tildados.

    > [!WARNING]
    &nbsp;Una vez creado, el token no se puede volver a consultar, por lo que es necesario guardarlo para futura referencia.

4. Crear una carpeta llamada `repos` que va a ser utilizada para almacenar clones locales de repositorios.

5. Inicializar una terminal en la carpeta `repos`. Para esto, hacer click derecho con la carpeta abierta y seleccionar `Abrir en Terminal` o abrir una terminal y navegar con el comando `cd` hasta la ruta donde esté ubicada la carpeta.

6. Configurar el nombre de usuario, mail y Token:
    ```
    git config --global user.name TU_NOMBRE_DE_USUARIO
    git config --global user.email TU_DIRECCION_DE@MAIL.COM
    git config --global user.password TU_TOKEN
    ```

    > [!NOTE]
    &nbsp;
    Con el comando `git config -l` es posible verificar la lista de configuraciones.

## Crear un repositorio vacío

1. Iniciar sesión en GitHub y crear un repositorio remoto vacío que tenga el `NOMBRE_DEL_PROYECTO`.

2. Dentro de la carpeta `repos` hecha durante la [instalación y configuración](#instalación-y-configuración), crear una carpeta con el mismo `NOMBRE_DEL_PROYECTO` que el repositorio remoto.

3. Abrir una terminal en la carpeta del proyecto e inicializar el versionado:
    ```
    git init
    ```

4. Luego de agregar los archivos iniciales del proyecto, hacer un primer commit:
    ```
    git add .
    git commit -m "Primer commit"
    ```

5. Finalmente, vincular el repositorio local con el remoto y publicar los cambios reemplazando `TU_NOMBRE_DE_USUARIO` y el `NOMBRE_DEL_PROYECTO`:
    ```
    git remote add origin www.github.com/TU_NOMBRE_DE_USUARIO/NOMBRE_DEL_PROYECTO.git
    git branch -M main
    git push -u origin main
    ```

6. Si llega a haber un error, usar los comandos `git remote -v` y `git remote remove origin` para ver y quitar la URL configurada respectivamente. Luego, intentar nuevamente con:
    ```
    git remote set-url origin https://github.com/TU_NOMBRE_DE_USUARIO/NOMBRE_DEL_PROYECTO.git
    git branch -M main
    git push -u origin main
    ```

## Clonar un repositorio remoto

1. Abrir una terminal en la carpeta `repos` hecha durante la [instalación y configuración](#instalación-y-configuración). Para esto, hacer click derecho con la carpeta abierta y seleccionar `Abrir en Terminal` o abrir una terminal y navegar con el comando `cd` hasta la ruta donde esté ubicada la carpeta.

2. Crear una copia local de un repositorio remoto, reemplazando el `NOMBRE_DE_USUARIO` y `NOMBRE_DEL_PROYECTO`:
    ```
    git clone www.github.com/NOMBRE_DE_USUARIO/NOMBRE_DEL_PROYECTO.git
    ```

    > [!NOTE]
    &nbsp;
    Con el comando `git log --oneline` es posible consultar un resumen de todos los commits hechos.

## Sincronizar cambios por terminal

1. Abrir una terminal en la carpeta `NOMBRE_DEL_PROYECTO`.

2. Obtener posibles cambios que pueda tener el repositorio remoto:
    ```
    git pull
    ```

3. (Opcional) Consultar los cambios realizados en el repositorio local del proyecto:
    ```
    git status
    ```

4. Agregar los archivos que están preparados para ser comiteados.
   - Para agregar un solo archivo que tenga cambios:
        ```
        git add NOMBRE_DEL_ARCHIVO
        ```

   - Para agregar todos los archivos que tengan cambios:
        ```
        git add .
        ```

5. Para guardar una nueva versión del repositorio, hacer un commit especificando los cambios incorporados:
    ```
    git commit -m "Detallar acá los cambios incorporados"
    ```

6. Publicar los commits hechos en la rama `main` del repositorio remoto alojado en GitHub:
    ```
    git push
    ```