bin/punteros : src/punteros.cpp
	c++ src/punteros.cpp -o bin/punteros -I include

ejecutar: bin/punteros
	./bin/punteros

assets/kristally.mp3 : assets/kristally.wav
	ffmpeg -i assets/kristally.wav -codec:a libmp3lame -qscale:a 2 assets/kristally.mp3