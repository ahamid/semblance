#include "parser.h"
// for NULL
#include <stdlib.h>

int main(int argc, const char * const * const args) {
  return parse(args[1], NULL);
}
