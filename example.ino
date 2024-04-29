#include <MT8816_ESP.h>

MT8816 MT8816(22, 25, 13, 14, 26, 27, 18, 21, 19, 23); //reset, strobe, data, ay0, ay1, ay2, ax0, ax1, ax2, ax3 pins respectively.

int x_el[4] = {2, 3, 4, 5}, y_el[2] = {2, 3};
Array x_arr(x_el, sizeof(x_el)/sizeof(x_el[0])), y_arr(y_el, sizeof(y_el)/sizeof(y_el[0]));

void setup() {
  MT8816.begin();
  Serial.begin(115200);
}

void loop() {

  Serial.println("2,2 e 3, 2 are connected!! (reset em 10s)");
  MT8816.setConnection(2, 2);
  MT8816.setConnection(3, 2);
  delay(10000);
  
  Serial.println("RESET...");
  MT8816.reset();
  delay(5000);
  
  Serial.println("BROADCAST x(2, 3, 4 e 5) y(2 e 3)!! (reset em 20s)");
  MT8816.broadcast(x_arr, y_arr);
  delay(20000);
}
