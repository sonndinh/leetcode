import threading
from collections import deque

class H2O:
    def __init__(self):
        self.hydro_queue, self.oxy_queue = deque(), deque()
        self.lock = threading.Lock()

    def hydrogen(self, releaseHydrogen: 'Callable[[], None]') -> None:
        self.hydro_queue.append(releaseHydrogen)
        self._release()

    def oxygen(self, releaseOxygen: 'Callable[[], None]') -> None:
        self.oxy_queue.append(releaseOxygen)
        self._release()
        
    def _release(self) -> None:
        self.lock.acquire()
        if len(self.hydro_queue) > 1 and len(self.oxy_queue) > 0:
            self.hydro_queue.popleft()()
            self.hydro_queue.popleft()()
            self.oxy_queue.popleft()()
        self.lock.release()


class H2O2:
    def __init__(self):
        self.cv = threading.Condition()
        self.hydro_count = 0 # Count number of hydrogen molecule released.


    def hydrogen(self, releaseHydrogen: 'Callable[[], None]') -> None:
        with self.cv:
            while self.hydro_count == 2:
                self.cv.wait()
            # releaseHydrogen() outputs "H". Do not change or remove this line.
            releaseHydrogen()
            self.hydro_count += 1
            self.cv.notify()
        

    def oxygen(self, releaseOxygen: 'Callable[[], None]') -> None:
        with self.cv:
            while self.hydro_count < 2:
                self.cv.wait()
            # releaseOxygen() outputs "O". Do not change or remove this line.
            releaseOxygen()
            self.hydro_count = 0
            self.cv.notify()


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
