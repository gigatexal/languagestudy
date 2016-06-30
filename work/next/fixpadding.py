"""
Usage: FixPadding [-h | --help] [-q | --quiet] [-v | --verbose] [--extension FILEXTS] (INPUT ...)

Options:
-h --help                Show this
-q --quiet               Show no output, will always show number of files modified
-v --verbose             Print out filenames that were modified
--extension FILEXTS      Extensions to return, omitting means all valid files will be processed
INPUT                    FILES to edit or DIRECTORIES to search recursively for files to edit

"""
import os
import itertools
from docopt import docopt

def files_by_dir(dirs):
   for dir in dirs:
      for _dir,subdir,files in os.walk(dir):
         for file in files:
            curr_file_path = os.path.join(_dir,file)
            yield os.path.abspath(curr_file_path)   


def files_from_input(files):
   for item in user_input:
      if os.path.isfile(item):
         yield os.path.abspath(item)


def combine_iterators(*args):
   yield from itertools.chain(args)
  
def has_extension(**kwargs):


if __name__ == '__main__':
   args = docopt(__doc__)
   quiet      = args['--quiet']
   verbose    = args['--verbose']
   exts       = args['--extension']
   user_input = args['INPUT']
   print(args)
  
   dirs           = files_by_dir(user_input)
   files_from_cli = files_from_input(user_input)
   
  

   files = ( file for file in itertools.chain(dirs,files_from_cli) 
   





