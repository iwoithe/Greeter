#include "appshell/appshell.h"

int main(int argc, char *argv[])
{
    gt::appshell::AppShell app;
    int code = app.run(argc, argv);
    return code;
}
