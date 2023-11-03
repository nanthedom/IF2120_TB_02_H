#include "../pengguna/pengguna.h"
#include "balasan.h"
#include <stdio.h>
#include <stdlib.h>

extern int currentIdReply;
extern Pengguna *currentUser;

void CreateBalasan(Balasan *reply)
{
    id(reply) = currentIdReply;
    text(reply) = currentWord;
    author(reply) = Nama(*currentUser);
    DATETIME dt;
    BacaDATETIME(&dt);
    datetime(reply) = dt;
}