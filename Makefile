main: main.c
	gcc main.c ADT/inisialisasi.c ADT/pengguna.c ADT/wordmachine.c ADT/charmachine.c ADT/profil.c ADT/pcolor.c -o main

clean:
	rm main