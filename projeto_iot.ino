#include <WiFi.h>
#include <PubSubClient.h>

const char* mqtt_server = "broker.hivemq.com";

WiFiClient WOKWI_Client; 
PubSubClient client(WOKWI_Client);

int valorLDR = 0;
int limite = 0;
int valorLED = 0;

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");

    if (client.connect("WOKWI_Client")) {
      Serial.println("connected");      
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
  client.subscribe("limite");
}

void callback(char* topic, byte* payload, unsigned int length) {
  String mensagem;

  for (int i = 0; i < length; i++) {
    mensagem += (char)payload[i];
  }

  Serial.print("Mensagem recebida: ");
  Serial.println(mensagem);
  limite = mensagem.toInt();
  Serial.print("Novo limite: ");
  Serial.println(limite);
}

void setup() {
  Serial.begin(9600);
  pinMode(34, INPUT);
  pinMode(2, OUTPUT);
  limite = 2000;
  //wifi setup
  Serial.print("Connecting to WiFi");
  WiFi.begin("Wokwi-GUEST", "", 6);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  Serial.println(" Connected!");
}

void loop()
{
  reconnect();
  client.loop();
  valorLDR = analogRead(34);
  if (valorLDR > limite) {
    digitalWrite(2, HIGH);
    valorLED = 1;
  } else {
    digitalWrite(2, LOW);
    valorLED = 0;
   }
  client.publish("LED", String(valorLED).c_str());
  client.publish("LDR", String(valorLDR).c_str());
  Serial.println(valorLDR);
  delay(1000);
}