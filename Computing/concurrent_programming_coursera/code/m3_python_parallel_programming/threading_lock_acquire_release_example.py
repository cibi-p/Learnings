# Based on RealPython Threading Example page at https://realpython.com/intro-to-python-threading/ and
#   Python.org _thread library documentation at
#   https://docs.python.org/3/library/_thread.html?highlight=_thread#module-_thread
import logging
import sys
import time

import pydash as _
from threading import Lock, active_count, Thread

from core import Core, critical_section_acquire_release


class ThreadingLockAcquireReleaseExample:

    def __init__(self):
        self.num_threads = 1
        self.lock = Lock()
        self.args_conf_list = [['-n', 'num_threads', 1, 'number of concurrent threads to execute']]
        self.core = Core(self.args_conf_list)

        log_format = "%(asctime)s: %(message)s"
        logging.basicConfig(format=log_format, level=logging.INFO, datefmt="%H:%M:%S")

    def parse_args(self, argv):
        namespace = self.core.parse_args(argv)
        if namespace:
            self.num_threads = int(_.get(namespace, 'num_threads', 1))

    def run(self):
        threads = list()

        # Need an initial count of threads running in process for future calculation
        initial_num_threads = active_count()
        for index in range(self.num_threads):
            logging.info("ThreadingLockAcquireReleaseExample run    : create and start thread %d.", index)
            thread = Thread(group=None, target=critical_section_acquire_release, args=(index, self.lock))
            threads.append(thread)
            thread.start()

        while active_count() > initial_num_threads:
            logging.info("Waiting for no active threads. Number of active threads: %d", active_count() -
                         initial_num_threads)
            time.sleep(1)

        logging.info("There are no longer any active threads and the program will exit.")


if __name__ == "__main__":
    threadingLockAcquireReleaseExample = ThreadingLockAcquireReleaseExample()
    threadingLockAcquireReleaseExample.parse_args(sys.argv[1:])
    threadingLockAcquireReleaseExample.run()

