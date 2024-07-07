#include <WebServer.h>

WebServer server(80);

void handle_root() {
  server.send(200, "text/plain", "Hello from Pool Controller!");
}

void handle_status() {
  String msg = "Relay ";
  msg += get_current_relay();
  msg += " is currently active";
  server.send(200, "text/html", msg);
}

void handle_not_found() {
  String msg = "File Not Found\n\n";
  msg += "URI: ";
  msg += server.uri();
  msg += "\nMethod: ";
  msg += (server.method() == HTTP_GET) ? "GET" : "POST";
  msg += "\nArguments: ";
  msg += server.args();
  msg += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    msg += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", msg);
}

void setup_server() {
  server.on("/", handle_root);
  server.on("/status", handle_status);

  server.onNotFound(handle_not_found);

  server.begin();
}

void poll_server() {
  server.handleClient();
}
