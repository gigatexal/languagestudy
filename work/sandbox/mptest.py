import multiprocessing as mp
import os
import sys

def get_contents(file):
   with open(file) as f:
      return f.read()


def main():
   
