import threading

class FooBar:
    def __init__(self, n):
        self.n = n
        self.cond_var = threading.Condition()
        self.foo_turn = True


    def foo(self, printFoo: 'Callable[[], None]') -> None:
        for i in range(self.n):
            with self.cond_var:
                while not self.foo_turn:
                    self.cond_var.wait()
                # printFoo() outputs "foo". Do not change or remove this line.
                printFoo()
                self.foo_turn = False
                self.cond_var.notify()


    def bar(self, printBar: 'Callable[[], None]') -> None:
        for i in range(self.n):
            with self.cond_var:
                while self.foo_turn:
                    self.cond_var.wait()
                # printBar() outputs "bar". Do not change or remove this line.
                printBar()
                self.foo_turn = True
                self.cond_var.notify()
