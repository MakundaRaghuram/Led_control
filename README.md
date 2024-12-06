
Step-by-Step Overview:
ESP32 Setup:

Microcontroller: The ESP32 is programmed to host a web server, which listens for HTTP requests to control an LED connected to one of its pins.
Web Server Code: The ESP32 code includes routes for handling requests like /on and /off to turn the LED on and off. It also hosts a simple HTML interface for manual control (optional).
Wi-Fi Connection: The ESP32 is connected to a Wi-Fi network to enable communication with the computer running the hand gesture detection script. The ESP32's IP address is printed to the serial monitor upon successful connection.
Computer Setup (Python Script):

Computer Vision Library: The Python script uses OpenCV for video capture and image processing. Optionally, other libraries like MediaPipe can be integrated for more advanced hand tracking.
Hand Gesture Detection: The script processes frames from the webcam, detects hand gestures, and sends HTTP requests to the ESP32 if a specific gesture is recognized.
HTTP Requests: The Python script uses the requests library to send GET requests to the ESP32 to turn the LED on or off based on detected gestures.
Communication Between Components:

Detecting Hand Gestures: The Python script captures video frames and converts them to grayscale or processes them using a specific algorithm (e.g., contour detection or a pre-trained model) to recognize hand gestures.
Decision Logic: The Python code includes logic to determine if a gesture is detected (e.g., detecting the presence of a hand or a specific gesture like a "thumbs up" or "fist").
Sending HTTP Commands: When a gesture is detected (e.g., one hand or no hand visible), the Python script sends an HTTP request to the ESP32, which triggers the handleLedOn or handleLedOff function to turn the LED on or off.
LED Control on ESP32:

Server Handling: The ESP32's web server receives the HTTP GET request and calls the corresponding function (handleLedOn or handleLedOff).
LED Pin Control: The ESP32 sets the state of its built-in LED pin (LED_BUILTIN) based on the received command. When the /on command is received, the LED turns on; when /off is received, the LED turns off.
Feedback: The ESP32 sends a response back to the Python script or the client (browser) to confirm the action, such as "LED is ON" or "LED is OFF."
