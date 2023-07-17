import socket

def prime(n):
    if n <= 1:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def server():
    servrsock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    servrsock.bind(('localhost', 8888))
    print("Server is running...")

    while True:
        data, clientaddr = servrsock.recvfrom(1024)
        num = int(data.decode())

        result = prime(num)
        response = "This is prime number" if result else "Thos is not prime number"
        servrsock.sendto(response.encode(), clientaddr)

server()

