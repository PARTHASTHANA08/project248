//  using DHT11 with ESP32
//  measuring humidity and temperature
//  getting all SI units for temperature and humidity

//  including DHT library to use the sensor
#include<DHT.h>

//  declaring sensor pin
byte sensor_pin = 4;

//  macro for type of sensor used
#define sensor_type DHT11

//  making object using constructor
DHT dht_sensor(sensor_pin , sensor_type);

const byte r_pin = 18;  //  GPIO 25,26,27
const byte g_pin = 19;
const byte b_pin = 21;

//  channel
const byte r_channel = 0;
const byte g_channel = 1;
const byte b_channel = 2;

//  frequency and resolution
const int frequency = 5000;
const int resolution = 8;

void setup(){

  //  serial communication
  Serial.begin(115200);
  

  //  initialize the DHT sensor
  
  

  //  setup function
  ledcSetup(r_channel , frequency , resolution);
  ledcSetup(g_channel , frequency , resolution);
  ledcSetup(b_channel , frequency , resolution);

  //  attaching channel with pin
  ledcAttachPin(r_pin , r_channel);
  ledcAttachPin(g_pin , g_channel);
  ledcAttachPin(b_pin , b_channel);
  
}

void loop(){

  //  calculating temperature in celcius
  float temp_c = dht_sensor.readTemperature();  //  DHT works in 0 to 50 deg celcius
  Serial.print("Temperature in Celcius : ");
  Serial.println(temp_c);
  //  calculate temperature in fahrenheit
  float temp_f = (temp_c *9/5) + 32 ;
  Serial.print("Temperature in Fahrenheit : ");
  Serial.println(temp_f);
  //  calculate temperature in kelevin
  float temp_k = temp_c + 273.15 ;
  Serial.print("Temperature in Kelvin : ");
  Serial.println(temp_k);

  //  calculate relative humidity
  float humid = dht_sensor.readHumidity();
  Serial.print("Humdity : ");
  Serial.println(humid);
  //  calculating dew point
  float dp = temp_c -((100-humid)/5);
  Serial.print("Dew Point : ");
  Serial.println(dp);


  //  check if temp_c and other variables are not numbers, then return



  //  print all the values

  

  //  wait for 2 seconds
  delay(2000);  //  sensor is slow, wait for 2 sec, before taking new readings
  
}
