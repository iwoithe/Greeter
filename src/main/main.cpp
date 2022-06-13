#include "appshell/appshell.h"
#include "appshell/appshellmodule.h"

int main(int argc, char *argv[])
{
    gt::appshell::AppShell app;

    app.addModule(new gt::appshell::AppShellModule());

    int code = app.run(argc, argv);
    return code;
}
