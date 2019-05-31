#include <SPI.h>
#include <SD.h>

File myFile;

void setup() {
 Serial.begin(9600);   // baud komunikasi serial

  Serial.println("Open file on MicroSD card...");

  if (!SD.begin(4)) {
    Serial.println("Failed read open Microsd card!");
    return;
  }
  Serial.println("Success read open Microsd card!");

  myFile = SD.open("coba.txt", FILE_WRITE); //menulis File coba.txt

  // jika file sudah berhasil dibuka maka tulis data dimulai
  if (myFile) {
    Serial.println("mencoba nulis data di file coba.txt");
    myFile.println("success write data");
    // tutup file
    myFile.close();
    Serial.println("done!");
  } else {
    // jika gagal print error
    Serial.println("failed open coba.txt");
  }
}

void loop() {
}

