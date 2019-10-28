#include <gtkmm.h>
#include <gtkmm/application.h>
#include <iostream>
#include <string>
using namespace std;
using namespace Gtk;
using namespace Glib;
int main(int argc, char *argv[])
{
  auto app =
    Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");

  Gtk::Window window;
  window.set_default_size(900, 900);
  window.set_position(WIN_POS_CENTER);
  window.set_title("BlackJack Player");
  return app->run(window);
}
