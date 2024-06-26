#include <Stepper.h>
#define STEPS 2038
Stepper stepper(STEPS, 10, 11, 12, 13);
#include <stDHT.h>
DHT sens(DHT11);
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Keypad.h>  // подключаем библиотеку KeypadLiquidCrystal_I2C lcd(0x27, 16, 2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4;  // 4 строки
const byte COLS = 4;  // 4 столбца

// определим символы для кнопок
char hexaKeys[ROWS][COLS] = {
  { '0', '1', '2', '3' },
  { '4', '5', '6', '7' },
  { '8', '9', 'A', 'B' },
  { 'C', 'D', 'E', 'F' }
};
int r = 0;
byte rowPins[ROWS] = { 6, 7, 8, 9 };  // цифровые выводы строк
byte colPins[COLS] = { 5, 4, 3, 2 };  // цифровые выводы столбцов
// используем класс библиотеки
Keypad kpd(makeKeymap(hexaKeys), colPins, rowPins, COLS, ROWS);
byte customChar[] = {
  B00000,
  B00000,
  B11011,
  B10101,
  B10001,
  B10001,
  B01010,
  B00100
};
void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(10, INPUT);
  digitalWrite(10, HIGH);
  lcd.createChar(0, customChar);
}

void loop() {
  int t = sens.readTemperature(10);
  int h = sens.readHumidity(10);
  char key = kpd.getKey();
  if (key) {
    switch (key) {
      case '0':
        lcd.setCursor(0, 0);
        lcd.print("Hi Artem");
        delay(1000);
        lcd.clear();
        lcd.print("Welcome to your");
        lcd.setCursor(0, 1);
        lcd.print("progect!");
        delay(1000);
        lcd.clear();
        break;
      case '1':
        lcd.setCursor(0, 0);
        lcd.print("progect data");
        delay(1000);
        lcd.clear();
        lcd.print("21.04.2024");
        delay(1000);
        lcd.clear();
        break;
      case '2':
        lcd.setCursor(0, 0);
        lcd.print("Этот");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("проект");
        delay(1000);
        lcd.clear();
        lcd.print("");
        delay(1000);
        lcd.clear();
        lcd.print("как мин к");
        delay(1000);
        lcd.clear();
        lcd.print("можно");
        delay(1000);
        lcd.clear();
        lcd.print("тестировать");
        delay(1000);
        lcd.clear();
        lcd.print("программы");
        delay(1000);
        lcd.clear();
        break;
      case '3':
        lcd.setCursor(0, 0);
        lcd.print("Hum: ");
        lcd.print(h);
        lcd.print("%");
        lcd.setCursor(0, 1);
        lcd.print("Temp: ");
        lcd.print(t);
        lcd.print(" C ");
        delay(1500);
        lcd.clear();
        break;
      case '4':
        lcd.setCursor(0, 0);
        lcd.print(char(0));
        lcd.setCursor(1, 0);
        lcd.print(char(0));
        lcd.setCursor(2, 0);
        lcd.print(char(0));
        lcd.setCursor(3, 0);
        lcd.print(char(0));
        lcd.setCursor(4, 0);
        lcd.print(char(0));
        lcd.setCursor(5, 0);
        lcd.print(char(0));
        lcd.setCursor(6, 0);
        lcd.print(char(0));
        lcd.setCursor(7, 0);
        lcd.print(char(0));
        lcd.setCursor(8, 0);
        lcd.print(char(0));
        lcd.setCursor(9, 0);
        lcd.print(char(0));
        lcd.setCursor(10, 0);
        lcd.print(char(0));
        lcd.setCursor(11, 0);
        lcd.print(char(0));
        lcd.setCursor(12, 0);
        lcd.print(char(0));
        lcd.setCursor(13, 0);
        lcd.print(char(0));
        lcd.setCursor(14, 0);
        lcd.print(char(0));
        lcd.setCursor(15, 0);
        lcd.print(char(0));
        lcd.setCursor(16, 0);
        lcd.print(char(0));
        lcd.setCursor(0, 15);
        lcd.print("You are cool!");
        delay(1500);
        lcd.clear();
    }
  }
}