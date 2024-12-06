#include <WiFi.h>
#include <WebServer.h>

// Wi-Fi credentials
const char* ssid = "iQOO Neo6";
const char* password = "mukunda11";

// Define LED pin
#define LED_BUILTIN 2

// Create a web server instance
WebServer server(80);

void handleLedOn() {
  digitalWrite(LED_BUILTIN, HIGH); // Turn LED ON
  server.send(200, "text/plain", "LED is ON");
}

void handleLedOff() {
  digitalWrite(LED_BUILTIN, LOW); // Turn LED OFF
  server.send(200, "text/plain", "LED is OFF");
}

void setup() {
  // Initialize LED pin
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // Start Serial Monitor
  Serial.begin(115200);
  delay(100);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Print IP Address
  Serial.println("\nConnected to WiFi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Set up web server routes
  server.on("/on", handleLedOn);
  server.on("/off", handleLedOff);

  // Start the server
  server.begin();
  Serial.println("Web server started!");
}

void loop() {
  // Handle client requests
  server.handleClient();
}
