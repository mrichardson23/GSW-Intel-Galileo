import SocketServer
import SimpleHTTPServer

PORT=80
class MyTCPServer(SocketServer.TCPServer):
	allow_reuse_address = True
class myHandler(SimpleHTTPServer.SimpleHTTPRequestHandler):
	def do_GET(self):
		self.send_response(200)
		self.send_header("Content-type", "text/html")
		self.end_headers()
		self.wfile.write("<html><body>")
		self.wfile.write("<h1>The button is")
		with open("/sys/class/gpio/gpio32/value", "r") as gpio:
			state = gpio.read(1)
			if state == "0":
				self.wfile.write(" not")
			self.wfile.write(" pressed!</h1>")
			self.wfile.write("</body></html>")
httpd = MyTCPServer(("", PORT), myHandler)
print "Serving from port", PORT
httpd.serve_forever()