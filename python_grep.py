import os, sys, getopt
import re

def get_files(path, pattern):
  for (dirpath, dirnames, filenames) in os.walk(path):
    for filename in filenames:
      if filename.endswith(pattern):
        yield os.path.join(dirpath, filename)

def parse_files(file, pattern, s_pattern_flags):
  regex = re.compile(pattern, s_pattern_flags)
  with open(file, 'r') as outfile:
      match = regex.search(outfile.read())
      if match:
        print(file + " " +":"+ match.group())

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

  files = get_files(path, tuple(f_pattern))
  for file in files:
    parse_files(file, s_pattern, getattr(re, s_pattern_flags))

if __name__ == "__main__":
  main(sys.argv[1:])
