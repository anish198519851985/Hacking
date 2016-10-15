import os, sys, getopt
import multiprocessing as mp
import re
import itertools

def get_files(path, pattern):
  for (dirpath, dirnames, filenames) in os.walk(path):
    for filename in filenames:
      if filename.endswith(pattern):
        yield os.path.join(dirpath, filename)

def worker_search_fn(arg):
  fname, regex = arg
  with open(fname, 'rt') as f:
    match = regex.search(f.read())
    if match:
      print(fname + " " +":"+ match.group())
      return

def main(argv):
  path, f_pattern, s_pattern = '', '', ''
  try:
     opts, args = getopt.getopt(argv,"hi:p:f:s:S:",["ifile=","file_pattern=","string_pattern=","string_flags="])
  except getopt.GetoptError:
     print 'test.py -i <path> -p <pattern> -f <file_name1, file_name2 ...> -S <python flags>'
     print 'example usage python a.py -i . -s \'.*_i2c_register.*\' -f .c,.h,.cpp -S "S"'
     sys.exit(2)
  for opt, arg in opts:
     if opt == '-h':
        print 'test.py -i <path> -p <pattern>, -f <file_name1, file_name2 ...>'
        sys.exit()
     elif opt in ("-i", "--ifile"):
        path = arg
     elif opt in ("-f", "--file_pattern"):
        f_pattern = arg.split(",")
     elif opt in ("-s", "--string_pattern"):
        s_pattern = arg
     elif opt in ("-S", "--string_flags"):
        s_pattern_flags = arg

  regex = re.compile(s_pattern, getattr(re, s_pattern_flags))
  files = get_files(path, tuple(f_pattern))
  mp.Pool().map(worker_search_fn, itertools.izip(files, itertools.repeat(regex)))

if __name__ == "__main__":
  main(sys.argv[1:])
