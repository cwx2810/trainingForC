#include <stdio.h>
#include <stdlib.h>
#include "../../01intro/Status.h"
#include "../01SequenceString/SequenceString.c"

int Index_KMP(SString S, SString T, int pos, int next[]);

void get_next(SString T, int next[]);

void get_nextval(SString T, int nextval[]);
