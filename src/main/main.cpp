#include "appshell/appshell.h"
#include "appshell/appshellmodule.h"

#include "greet/greetmodule.h"

int main(int argc, char *argv[])
{
    gt::appshell::AppShell app;

    app.addModule(new gt::appshell::AppShellModule());
    app.addModule(new gt::greet::GreetModule());

    int code = app.run(argc, argv);
    return code;
}
