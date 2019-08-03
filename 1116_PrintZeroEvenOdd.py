import threading

# Use locks.
class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        # Locks for zero, even, and odd functions.
        self.locks = [threading.Lock(), threading.Lock(), threading.Lock()]
        self.locks[1].acquire()
        self.locks[2].acquire()
        self.count = 1
        
	# printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range (self.n):
            self.locks[0].acquire()
            printNumber(0)
            if self.count % 2 == 0:
                self.locks[1].release()
            else:
                self.locks[2].release()

        
    def even(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(1, self.n+1):
            if i % 2 == 1:
                continue
            self.locks[1].acquire()
            printNumber(self.count)
            self.count += 1
            self.locks[0].release()
        
    def odd(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(1, self.n+1):
            if i % 2 == 0:
                continue
            self.locks[2].acquire()
            printNumber(self.count)
            self.count += 1
            self.locks[0].release()

class ZeroEvenOdd1:
    def __init__(self, n):
        self.n = n
        self.cond_var = threading.Condition()
        self.count = 1
        
        
	# printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(self.n):
            with self.cond_var:
                while self.count % 2 == 0:
                    self.cond_var.wait()
                printNumber(0)
                self.count += 1
                self.cond_var.notify_all()
        
        
    def even(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(1, self.n+1):
            # Ignore odd numbers.
            if i % 2 != 0:
                continue
            with self.cond_var:
                while self.count % 2 != 0 or (self.count/2) % 2 != 0:
                    self.cond_var.wait()
                printNumber(i)
                self.count += 1
                self.cond_var.notify_all()
        
        
    def odd(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(1, self.n+1):
            # Ignore even numbers.
            if i % 2 == 0:
                continue
            with self.cond_var:
                while self.count % 2 != 0 or (self.count/2) % 2 == 0:
                    self.cond_var.wait()
                printNumber(i)
                self.count += 1
                self.cond_var.notify_all()
        
