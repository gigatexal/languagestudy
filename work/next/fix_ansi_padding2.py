import os
import multiprocessing as mp
import sys

def get_files(path, extension='.sch'):#currently supports only one extension, must be .txt for example
    for dir,subdir,files in os.walk(path):
        for file in files:
            curr_file = os.path.join(dir,file)
            full_path = os.path.abspath(curr_file)
            ext = os.path.splitext(full_path)[1]

            if ext == extension:
                yield full_path


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
    print(run(multithreaded=True, files=get_files('c:\\test\\unc\\'), apply_func=replace_in_files))












