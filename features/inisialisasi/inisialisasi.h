#include "../../ADT/boolean/boolean.h"
#include "../../ADT/wordmachine/wordmachine.h"
#include "../pengguna/pengguna.h"

extern boolean isLogin;
extern boolean isClosed;

void init();
void prosesCmd(Word cmd);
void parseMultiCmd(Word w, Word *cmd, Word* param0, Word* param1);

