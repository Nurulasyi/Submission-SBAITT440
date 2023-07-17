import socket

def number():
    while True:
        try:
            num = int(input("Please enter a number: "))
            return num
        except ValueError:
            print("Wrong Action! Please enter an integer.")

def client():
    clientsock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    num = number()
    clientsock.sendto(str(num).encode(), ('localhost', 8888))

    response, servraddr = clientsock.recvfrom(1024)
    print("Server:", response.decode())

    clientsock.close()

client()

