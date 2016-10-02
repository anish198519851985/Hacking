import os, sys, getopt
import re
import glob

def get_files(path, pattern):
  for (dirpath, dirnames, filenames) in os.walk(path):
    for filename in filenames:
      if filename.endswith(pattern):
        yield os.path.join(dirpath, filename)	

def parse_files(file, pattern):
  line_no = 0
  regex = re.compile(pattern)
  with open(file, 'r') as outfile:
    for line in outfile:
      line_no += 1
      match = regex.search(line)
      if match:
        print(file + " " + str(line_no) + ":"+ match.group())
  		
def main(argv):
  path, f_pattern, s_pattern = '', '', ''
  try:
     opts, args = getopt.getopt(argv,"hi:p:f:s:",["ifile=","file_pattern=","string_pattern="])
  except getopt.GetoptError:
     print 'test.py -i <path> -p <pattern> -f <file_name1, file_name2 ...>'
     print 'example usage python a.py -i . -s \'.*_i2c_register.*\' -f .c,.h,.cpp'
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

  files = get_files(path, tuple(f_pattern))
  for file in files:
    parse_files(file, s_pattern)
	
if __name__ == "__main__":
  main(sys.argv[1:])
