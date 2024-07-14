#include <WebServer.h>

WebServer server(80);

void handle_root() {
  server.send(200, "text/html", "Hello from Pool Controller!<br><br><a href=\"relays/0/on\">Turn relay 0 on</a><br><a href=\"relays/0/off\">Turn relay 0 off </a>");
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

void handle_relay0_on() {
  set_relay(0, true);
  String msg = "Relay 0 has been set on";
  server.send(200, "text/html", msg);
}

void handle_relay0_off() {
  set_relay(0, false);
  String msg = "Relay has been set off";
  server.send(200, "text/html", msg);
}

void setup_server() {
  server.on("/", handle_root);
  server.on("/status", handle_status);
  server.on("/relays/0/on", handle_relay0_on);
  server.on("/relays/0/off", handle_relay0_off);

  server.onNotFound(handle_not_found);

  server.begin();
}

void poll_server() {
  server.handleClient();
}
