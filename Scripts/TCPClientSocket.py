import socket
import sys
import argparse

HOST = "10.3.5.12"  # The server's hostname or IP address
PORT = 5050  # The port used by the server

def recieveProcess(process):

    process = process.encode('utf-8')
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        s.sendall(process)
        data = s.recv(1024)

parser = argparse.ArgumentParser(description="TCP Socket Server/Client for PCO Camera")
parser.add_argument('--process', type=str,default = None ,help="Start, Stop, Restart, default is None")
#########################################################
args = parser.parse_args()
pMode = args.process

if __name__ == "__main__":
    
    if pMode.lower() == 'start':
        recieveProcess('Start')
    elif pMode.lower() == 'stop':
        recieveProcess('Stop')
    elif pMode.lower() == 'restart':
        recieveProcess('Restart')
    else:
        sys.exit()
