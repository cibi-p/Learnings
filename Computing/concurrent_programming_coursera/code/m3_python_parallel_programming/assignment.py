#!/usr/bin/env python3
"""
Assignment: Thread-based Ticketing System

Objective:
-----------
Simulate a ticketing system using Python threads.

Each thread represents a participant with a unique ticket number.
Threads must wait for their turn — i.e., they can only proceed when
the current ticket number being "served" matches their ticket number.

Instructions:
-------------
1. Implement proper thread synchronization using Locks and shared variables.
2. Ensure that ticket numbers start at 0 and are served sequentially.
3. Each thread prints two messages to a file named `output-<part_id>.txt`:
    a) "Thread retrieved ticket number: X started"
    b) "Thread with ticket number: X completed"
4. Threads must wait for their turn based on a shared variable.
5. The number of threads is specified via command-line arguments (-n).
"""

import logging
import random
import sys
import time
from threading import Thread, Lock

from core import Core  # Provided support class


# -------------------------------------------------------------------
# THREAD FUNCTION
# -------------------------------------------------------------------
def execute_ticketing_system_participation(ticket_number, part_id, shared_variable):
    """
    Each thread runs this function.

    TODO:
    -----
    1. Print the "retrieved ticket number" message (already provided below).
    2. Wait until the shared variable allows this thread's ticket number to proceed.
    3. Simulate work (e.g., time.sleep()).
    4. Print the "completed" message (already provided below).
    5. Update the shared variable to allow the next ticket to run.

    Args:
        ticket_number (int): Unique ticket number for this thread.
        part_id (str): Used for the output filename.
        shared_variable (dict): Contains shared state (e.g., current_ticket, lock).
    """

    output_file_name = f"output-{part_id}.txt"

    # Required start message – DO NOT MODIFY
    print(f"Thread retrieved ticket number: {ticket_number} started", file=open(output_file_name, "a"))

    # TODO: Add logic to wait for your ticket number
    # Example: while shared_variable['current_ticket'] != ticket_number: wait
    while shared_variable['current_ticket'] != ticket_number:
        continue

    # Simulate work (optional)
    time.sleep(random.uniform(0.1, 1.0))
    # Required completion message – DO NOT MODIFY
    print(f"Thread with ticket number: {ticket_number} completed", file=open(output_file_name, "a"))

    # TODO: Update shared variable (increment current_ticket) once done
    shared_variable['current_ticket'] += 1
    return 0


# -------------------------------------------------------------------
# MAIN ASSIGNMENT CLASS
# -------------------------------------------------------------------
class Assignment(Core):
    """
    Controls execution of the assignment.
    Handles argument parsing, thread creation, and coordination.
    """

    USERNAME = "cibi"      # TODO: Replace with your actual username
    active_threads = []

    def __init__(self, args):
        # Argument configuration
        self.num_threads = 1
        self.args_conf_list = [
            ['-n', 'num_threads', 1, 'number of concurrent threads to execute'],
            ['-u', 'user', None, 'the user submitting the assignment (must match .user file)'],
            ['-p', 'part_id', 'test', 'assignment part identifier (default: test)']
        ]

        # Initialize Core base class and parse args
        super().__init__(self.args_conf_list)
        super().parse_args(args=args)

        # Logging setup
        logging.basicConfig(format="%(asctime)s: %(message)s",
                            level=logging.INFO,
                            datefmt="%H:%M:%S")

    def run(self):
        """
        TODO:
        -----
        1. Create a shared variable (e.g., dict with 'current_ticket' and 'lock').
        2. Create threads for the number of participants (-n argument).
        3. Start all threads, each running execute_ticketing_system_participation().
        4. Wait for all threads to complete (join).
        5. Ensure the grader print statements are output in correct order.

        Note:
        -----
        - Do not remove or modify output file logic.
        - Ticket numbers must start at 0 and proceed sequentially.
        """
        output_file_name = f"output-{self.part_id}.txt"
        open(output_file_name, 'w').close()  # Clear output file

        if self.test_username_equality(self.USERNAME):
            # TODO: Initialize shared variable (e.g., {'current_ticket': 0, 'lock': Lock()})

            # TODO: Create threads, assign ticket numbers starting from 0, and start them

            # TODO: Wait for all threads to finish
            shared_variable = {
                'current_ticket': 0,
                'lock': Lock()
            }
            self.lock = Lock()
            threads = list()
            for ticket_number in range(self.num_threads):
                thread = Thread(group=None, target=execute_ticketing_system_participation, args=(ticket_number, self.part_id, shared_variable))
                threads.append(thread)
                thread.start()


            # Optionally manage tickets centrally
            self.manage_ticketing_system()

            logging.info("Assignment completed all running threads.")
            return 0
        else:
            logging.error("Error: Username mismatch. Check .user file.")
            return 1

    def manage_ticketing_system(self):
        """
        TODO:
        -----
        Optional:
        - Implement central ticket management here if desired.
        - Ensure shared variable increments are synchronized.
        - Make sure no two threads are served simultaneously.

        Notes:
        -----
        - Can remain a placeholder if all logic is handled in the threads themselves.
        """
        return 0


# -------------------------------------------------------------------
# PROGRAM ENTRY POINT
# -------------------------------------------------------------------
if __name__ == "__main__":
    assignment = Assignment(args=sys.argv[1:])
    exit_code = assignment.run()
    sys.exit(exit_code)

