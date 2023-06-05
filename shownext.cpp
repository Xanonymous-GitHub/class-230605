#include "NextDate.h"

int main(int argc, char **argv) {
    Date *a = NewDateInstance(2001, 3, 4);
    Date *b = NextDate(a);
    ShowDate(b);
}
