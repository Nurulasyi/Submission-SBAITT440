import threading

class FibThread(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)

    def run(self):
        print("Fibonacci Series:")
        x, y = 0, 1
        while x <= 10000:
            print(a)
            x, y = y, x + y

class SqThread(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)

    def run(self):
        print("\nThe Square Numbers:")
        for num in range(1, 10001):
            print(num ** 2)

class CbThread(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)

    def run(self):
        print("\The Cube Numbers:")
        for num in range(1, 10001):
            print(num ** 3)


fibthread = FibThread()
sqthread = SqThread()
cbthread = CbThread()

fibthread.start()
fibthread.join()

sqthread.start()
sqthread.join()

cbthread.start()
cbthread.join()

