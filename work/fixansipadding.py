"""Usage: fixansipadding [-h | --help] (INPUT ...)

Options:
-h --help                Show this
-v --version             Show version
INPUT                    FILES to edit or DIRECTORIES to search recursively for files to edit

"""
from docopt import docopt
import os
import multiprocessing as mp

def _abspath(file):
    return os.path.abspath(file)

def _splitext(file):
    return os.path.splitext(file)

def _isfile(file):
    return os.path.isfile(file)

def _join(dir,file):
    return os.path.join(dir, file)

def _get_files_by_path(paths, extension='.sch'): # currently supports only one extension, must be .txt for example
        yield from (_abspath(_join(dir, file))
                    for path in paths
                    for dir, subdir, files in os.walk(path)
                    for file in files
                    if _splitext(file)[1] == extension
                   )#kinda looks like SQL

def _get_files(files,extension='.sch'):
    yield from (file for file in files if _isfile(file) and _splitext(file)[1] == extension)

def _combine_iters(*args): # more or less like itertools.chain or zip
    for elem in args:
           yield from elem

def replace_in_files(file):
    with open(file, 'r', encoding='utf-16-le') as f:
        contents = f.read()
        before_hash = hash(contents)
        contents = contents.replace('SET ANSI_PADDING OFF', 'SET ANSI_PADDING ON')
        after_hash = hash(contents)
        if before_hash == after_hash:
            return False
        else:
            with open(file, 'w', encoding='utf-16-le') as f:
                f.write(contents)
            return True


def run(multithreaded=False, files=None, apply_func=None):
    processed = None
    num_cpus = 1
    if multithreaded is True:
        num_cpus = mp.cpu_count()
    if num_cpus and files and apply_func:
        process_pool = mp.Pool(num_cpus)
        processed = process_pool.map(apply_func, files)
    if processed:
        return processed
    else:
        return None


if __name__ == '__main__':
    if sys.platform.startswith('win'):
       mp.freeze_support()
    
    args = docopt(__doc__, version='fixansipadding v 1.0')
    user_inputs = args['INPUT']

    validated_files = _get_files(user_inputs)
    validated_paths = _get_files_by_path(user_inputs)
    files = _combine_iters(validated_files, validated_paths)

    print(str(sum(run(multithreaded=True,files=files,apply_func=replace_in_files))) + " file(s) fixed.")











