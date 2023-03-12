import socket
from time import sleep
from datetime import datetime
# import win32comext.shell.shell as shell
import os
# import time
# import random
# from pathlib import Path
# from SMWinservice import SMWinservice

HOST = "10.3.5.12"  # Standard loopback interface address (localhost)
PORT = 5050  # Port to listen on (non-privileged ports are > 1023)

def executeProcess(execute):
    
    try:
        if execute == "start":
            os.system("cmd /c start start_ioc.bat")
        elif execute == "stop":
            os.system("taskkill /im ioc.exe /F")
        elif execute == "restart":
            # shell.ShellExecuteEx(lpVerb='runas', lpFile='cmd.exe', lpParameters='/c '+'net stop nxservice')
            os.system("taskkill /im ioc.exe /F")
            sleep(5)
            os.system("cmd /c start start_ioc.bat")
            # shell.ShellExecuteEx(lpVerb='runas', lpFile='cmd.exe', lpParameters='/c '+'net start nxservice')
        else:
            pass
            #commands = 'net ' + execute + ' nxservice'
            #shell.ShellExecuteEx(lpVerb='runas', lpFile='cmd.exe', lpParameters='/c '+commands)
    except:
        pass
    finally:
        pass

while 1:
            try:
                with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
                    s.bind((HOST, PORT))
                    s.listen()
                    conn, addr = s.accept()
                    with conn:
                        print(f"Connected by {addr}")

                        while True:
                            data = conn.recv(1024)
                            conn.sendall(data)
                            if not data:
                                break
                            if data.decode('utf-8').lower() == "start":
                                print('Started ', datetime.now().strftime("%d-%b-%Y, %H:%M:%S"))
                                executeProcess(data.decode('utf-8').lower())
                            elif data.decode('utf-8').lower() == "stop":
                                print('Stopped ', datetime.now().strftime("%d-%b-%Y, %H:%M:%S"))
                                executeProcess(data.decode('utf-8').lower())
                            elif data.decode('utf-8').lower() == "restart":
                                executeProcess(data.decode('utf-8').lower())
                                print('Restarted ', datetime.now().strftime("%d-%b-%Y, %H:%M:%S"))
                            else:
                                pass
                        sleep(0.05)
            except:
                sleep(0.05)
            finally:
                sleep(0.05)

# class PythonCornerExample(SMWinservice):
#     _svc_name_ = "TCPServerSocket"
#     _svc_display_name_ = "TCP Server Socket"
#     _svc_description_ = "Service for PCO IOC"

#     def start(self):
#         self.isrunning = True

#     def stop(self):
#         self.isrunning = False

#     def main(self):
#         HOST = "127.0.0.1"  # Standard loopback interface address (localhost)
#         PORT = 1234  # Port to listen on (non-privileged ports are > 1023)
        

# if __name__ == '__main__':
#     PythonCornerExample.parse_command_line()
