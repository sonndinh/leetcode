import threading

class ZeroEvenOdd:
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
        
