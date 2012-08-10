#include <stdio.h>
#include <stdlib.h>
 
typedef void effector(int);
typedef struct transition transition;
struct transition {
  int state;
  effector *effect;
};
 
typedef enum sigil sigil;
enum sigil { Letter, Slash, Star, EndOfFile };
 
sigil sigilify(int c) {
  switch (c) {
    case '/':  return Slash;
    case '*':  return Star;
    case EOF:  return EndOfFile;
    default:   return Letter;
  }
}
 
void emit    (int c) { putchar(c); }
void slash   (int c) { putchar('/'); putchar(c); }
void nothing (int c) { }
void halt    (int c) { exit(EXIT_SUCCESS); }
 
#define T(state, sigil) (((state) << 2) | sigil)
 
int main() {
  transition state = { 0, emit };
  transition table[] = {
    [T(0, Slash)]={ 1, nothing }, [T(0, Letter)]={ 0, emit },    [T(0, Star)]={ 0, emit },    [T(0, EndOfFile)]={ 0, halt },
    [T(1, Slash)]={ 0, slash },   [T(1, Letter)]={ 0, slash },   [T(1, Star)]={ 2, nothing }, [T(1, EndOfFile)]={ 0, halt },
    [T(2, Slash)]={ 2, nothing }, [T(2, Letter)]={ 2, nothing},  [T(2, Star)]={ 3, nothing }, [T(2, EndOfFile)]={ 0, halt },
    [T(3, Slash)]={ 0, nothing }, [T(3, Letter)]={ 2, nothing }, [T(3, Star)]={ 2, nothing }, [T(3, EndOfFile)]={ 0, halt },
  };
 
  for (;;) {
    int c = getchar();
    (state = table[T(state.state, sigilify(c))]).effect(c);
  }
}

