# WinPoints
Es un juego con una serie de preguntas que van aumentando de dificultad a medida que el jugador va acumulando puntos.

# Instalación
Se necesita descargar el instalador MinGW para obtener la utilidad G++, permitir compilar el programa en C++ y generar el archivo ejecutable.
Para su descarga:
-Dirigirse https://sourceforge.net/projects/mingw/files/ Pulsando sobre el vínculo "Download mingw-get-setup.exe". Recordar la ruta de instalación.
- Al finalizar la descarga, se busca y ejecuta el instalador y se pulsa Continue.
-Cuando haya terminado la instalación, clic en Continue y aparecerán los componentes a instalar
-Clic derecho al paquete mingw32-gcc-g++ y mingw32-base, seleccionamos la opción Mark for Installation
-Ve al menú Installation -> Apply Changes y luego clic en el botón Apply para empezar la instalación. Cuando finalice, clic en el botón Close
-Por defecto MinGW se instala en la carpeta C:\MinGW. Para poder ejecutar el compilador G++ desde cualquier otra carpeta se necesita añadir la ruta de la carpeta C:\MinGW\bin\ a la variable de entorno PATH. Se abre el Panel de control de Windows y se pulsa sobre Sistema
-Click en Configuración avanzada del sistema -> variables de entorno
-Se selecciona Path en la parte Variables del sistema y se presiona el botón Editar -> Luego al botón Nuevo
-Se escribe la ruta C:\MinGW\bin. Se pulsa el botón Aceptar
-Para saber si todo está correcto se ejecuta el Símbolo del Sistema y una vez abierto se escribe g++ --version. Debería desplegar la versión de g++.

# Ejecución
Se descarga el repositorio y se ejecuta el Símbolo del Sitema buscando el directorio de la ruta del archivo donde se encuentra el repositorio, una vez encontrado, se escribe g++ WinPoints.cpp Question.cpp.
Dentro de la carpeta se habrá creado un archivo ejecutable para hacer uso del juego. Sin embargo dentro de este repositorio pongo a disposición el archivo ejecutable previamente creado por mi con los pasos anteriores para poder descargarlo y usarlo.

Se abre el archivo ejecutable y se inicia el juego, una vez finalizado el juego se habrá creado un archivo llamado History.txt donde se guardarán los datos de los jugadores como histórico del juego.
