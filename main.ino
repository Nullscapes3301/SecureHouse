#define potmetro A0
#define boton 13
#include <string.h>

int status = 0;        // Revisar significado de status en /Documentation/status.md
int tung1 = 0;         // Estado anterior del potmetro
int tung2 = 0;         // Estado anterior del boton
int sahur[3];          // Entrada que esta escribiendo el usuario
int sahur2 = 0;         // Longitud de sahur
int PIN[3] = {100, 200, 300};
int debug = 1;

void setup() {
    pinMode(12, OUTPUT);
    digitalWrite(12, HIGH);
    pinMode(potmetro, INPUT);

    pinMode(boton, INPUT);
    Serial.begin(9600);
}

void loop() {
    if (status == 0) {

        if ( scanf("pot")  != tung1 ) {
            status = 1;
        }

        if ( scanf("bot") != tung2 ) {
            status = 1;
        }
    
    }


    if (status == 1) {

        printf(
            char(scanf("pot"))
        );

        if ( scanf("bot") == 1 ) {
            printf(sahur);
            printf(scanf("pot"));
            append(&sahur, scanf("pot"));
            if (len(sahur) == 3) {
                status = 2;
            }
        }

    }

    if (status == 2) {

        if (sahur == PIN) {
            printf("Acceso concedido, presione el boton para cambiar PIN");
            status = 3;
        } else {
            printf("Acceso denegado.");
            status = 0;
        }

        sahur[3] = {};
        sahur2 = 0;
    }

    if (status == 3 ) {

        if ( scanf("pot")  != tung1 ) {
            status = 1;
        }

        if ( scanf("bot") != tung2 ) {
            status = 4;
        }
    }

    if (status == 4) {

        if ( scanf("bot") == 1 ) {
            append(&sahur, scanf("pot"));
            if (len(sahur) == 3) {
                PIN[3] = sahur;
                sahur[3] = {};
                sahur2 = 0;
            }
        }
    }

    tung1 = scanf("pot");
    tung2 = scanf("bot");
}

/*
Modulo de entrada/salida con el usuario
*/
void printf(char text[]) {
    Serial.println(text);
}

float scanf(char mode) {
    if (strcmp(mode, "pot") == 0) {
        return map(analogRead(potmetro), 0, 1023, 0, 255);
    } else {
        return digitalRead(boton);
    }
}

/*
Otras funciones
*/

int validarPIN(int pin[3], int other[3]) {
    return (pin==other);
}

int len(int array[]) {
    int longitud = sizeof(array) / sizeof(array[0]);
    return longitud;
}

void append(int array[], int elemento) {
    if (sahur2 < 3) {
        array[sahur2++] = elemento;
    }
}

void debugc(char comment[]) {
    if (debug) {
        printf(comment);
    }
}
