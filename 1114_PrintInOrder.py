import threading


# Use Condition objects
class Foo:
    def __init__(self):
        self.cond_var = threading.Condition()
        self.finished_first = False
        self.finished_second = False
    
    def first(self, printFirst: 'Callable[[], None]') -> None:
        # printFirst() outputs "first". Do not change or remove this line.
        with cond_var:
            printFirst()
            self.finished_first = True
            self.cond_var.notify_all()

    def second(self, printSecond: 'Callable[[], None]') -> None:
        # printSecond() outputs "second". Do not change or remove this line.
        with cond_var:
            while not self.finished_first:
                cond_var.wait()
            printSecond()
            self.finished_second = True
            self.cond_var.notify_all()

    def third(self, printThird: 'Callable[[], None]') -> None:
        # printThird() outputs "third". Do not change or remove this line.
        with cond_var:
            while not self.finished_second:
                cond_var.wait()
            printThird()


# Use Barrier objects.
class Foo:
    def __init__(self):
        self.barriers = [threading.Barrier(2), threading.Barrier(2)]

    def first(self, printFirst: 'Callable[[], None]') -> None:
        # printFirst() outputs "first". Do not change or remove this line.
        printFirst()
        self.barriers[0].wait()

    def second(self, printSecond: 'Callable[[], None]') -> None:
        # printSecond() outputs "second". Do not change or remove this line.
        self.barriers[0].wait()
        printSecond()
        self.barriers[1].wait()

    def third(self, printThird: 'Callable[[], None]') -> None:
        # printThird() outputs "third". Do not change or remove this line.
        self.barriers[1].wait()
        printThird()

# Use Event objects.
class Foo2:
    def __init__(self):
        self.events = [threading.Event(), threading.Event()]

    def first(self, printFirst: 'Callable[[], None]') -> None:
        # printFirst() outputs "first". Do not change or remove this line.
        printFirst()
        self.events[0].set()

    def second(self, printSecond: 'Callable[[], None]') -> None:
        # printSecond() outputs "second". Do not change or remove this line.
        self.events[0].wait()
        printSecond()
        self.events[1].set()

    def third(self, printThird: 'Callable[[], None]') -> None:
        # printThird() outputs "third". Do not change or remove this line.
        self.events[1].wait()
        printThird()

# Use Lock objects.
class Foo1:
    def __init__(self):
        self.locks = [threading.Lock(), threading.Lock()]
        # The main thread holds both locks.
        self.locks[0].acquire()
        self.locks[1].acquire()

    def first(self, printFirst: 'Callable[[], None]') -> None:
        # printFirst() outputs "first". Do not change or remove this line.
        printFirst()
        self.locks[0].release()


    def second(self, printSecond: 'Callable[[], None]') -> None:
        # printSecond() outputs "second". Do not change or remove this line.
        with self.locks[0]:
            printSecond()
            self.locks[1].release()

    def third(self, printThird: 'Callable[[], None]') -> None:
        # printThird() outputs "third". Do not change or remove this line.
        with self.locks[1]:
            printThird()
