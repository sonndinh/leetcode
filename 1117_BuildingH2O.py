import threading
        

# Got TLE.
class H2O1:
    def __init__(self):
        self.hydroSem = threading.Semaphore(2)
        self.oxySem = threading.Semaphore(1)
        self.barrier = threading.Barrier(3)


    def hydrogen(self, releaseHydrogen: 'Callable[[], None]') -> None:
        self.hydroSem.acquire()
        self.barrier.wait()
        # releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen()
        self.hydroSem.release()
        

    def oxygen(self, releaseOxygen: 'Callable[[], None]') -> None:
        self.oxySem.acquire()
        self.barrier.wait()
        # releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen()
        self.oxySem.release()
