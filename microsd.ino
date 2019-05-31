//menambahkan libraries SPI.h dan SD.h
#include <SD.h>
#include <SPI.h>

Sd2Card card;
SdVolume volume;
SdFile root;

const int chipSelect = 4;

void setup()
{
//set up untuk komunikasi serial melalui serial monitor
Serial.begin(9600);

Serial.print("\nInitializing SD card...");
pinMode(SS, OUTPUT);

//untuk memastikan sd card terbaca
while (!card.init(SPI_HALF_SPEED, chipSelect)) {
Serial.println("inisialisasi gagal. Hal untuk memeriksa:");
Serial.println("* Apakah kartu sudah dimasukkan?");
Serial.println("* Apakah pengkabelan sudah benar?");
Serial.println("* Anda mengubah pin chipselect yang menyesuaikan dengan module?");
}

// Mencetak jenis kartu
Serial.print("\nTipe Kartu ");
switch(card.type()) {
case SD_CARD_TYPE_SD1:
Serial.println("SD1");
break;
case SD_CARD_TYPE_SD2:
Serial.println("SD2");
break;
case SD_CARD_TYPE_SDHC:
Serial.println("SDHC");
break;
default:
Serial.println("tidak diketahui"); }

if (!volume.init(card)) {
Serial.println("tidak bisa menemukan FAT16 / partisi FAT32. \ Pastikan telah diformat kartu");
return;
}

// Mencetak jenis dan ukuran volume FAT-jenis pertama
uint32_t volumesize;
Serial.print("\nVolume type is FAT");
Serial.println(volume.fatType(), DEC);
Serial.println();

volumesize = volume.blocksPerCluster();
volumesize *= volume.clusterCount();
volumesize *= 512;
Serial.print("Volume size (bytes): ");
Serial.println(volumesize);
Serial.print("Volume size (Kbytes): ");
volumesize /= 1024;
Serial.println(volumesize);
Serial.print("Volume size (Mbytes): ");
volumesize /= 1024;
Serial.println(volumesize);

Serial.println("\nFile yang ditemukan pada kartu (nama, tanggal dan ukuran dalam bytes): ");
root.openRoot(volume);

root.ls(LS_R | LS_DATE | LS_SIZE);
}

void loop(void) {
}

