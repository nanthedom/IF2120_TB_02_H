main: main.c
	gcc main.c ADT/inisialisasi/inisialisasi.c ADT/pengguna/pengguna.c ADT/wordmachine/wordmachine.c ADT/charmachine/charmachine.c ADT/profil/profil.c ADT/pcolor/pcolor.c ADT/kicau/kicau.c ADT/time/time.c ADT/datetime/datetime.c ADT/draf/draf.c -o main

clean:
	rm main