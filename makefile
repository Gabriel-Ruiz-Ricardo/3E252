bin/punteros : src/punteros.cpp
	c++ src/punteros.cpp -o bin/punteros -I include

ejecutar: bin/punteros
	./bin/punteros

assets/kristally.mp3 : assets/kristally.wav
	ffmpeg -i assets/kristally.wav -codec:a libmp3lame -qscale:a 2 assets/kristally.mp3

bin/ejemplo : src/ejemplo.cpp
	c++ src/ejemplo.cpp -o bin/ejemplo -Iinclude -l ftxui-screen
#Enlazando libreria compilada

ejemplo : bin/ejemplo
	./bin/ejemplo

