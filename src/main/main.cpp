#include "appshell/appshell.h"
#include "appshell/appshellmodule.h"

#include "greet/greetmodule.h"
#include "uicomponents/uicomponentsmodule.h"

int main(int argc, char *argv[])
{
    gt::appshell::AppShell app;

    app.addModule(new gt::appshell::AppShellModule());
    app.addModule(new gt::greet::GreetModule());
    app.addModule(new gt::uicomponents::UiComponentsModule());

    int code = app.run(argc, argv);
    return code;
}
