#server.py
#python2.7
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = socket.gethostname()
print '\nHost name is %s' % host

s.bind(('192.168.1.100', 8000))
#or we can use the default addr, which is the local addr
#	s.bind(('', 8000)) 

while True:
	data, addr = s.recvfrom(1024)
	if not data:
		print 'Received nothing! Client is offline!'
		break
	print 'Message:\t', data, '\tfrom\t', addr
s.close()
