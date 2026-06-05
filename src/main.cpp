#include <ftxui/component/app.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/linear_gradient.hpp>
#include <ftxui/screen/screen.hpp>

using namespace ftxui;

using entries = std::vector<std::string>;

int main() {
  using namespace ftxui;

  entries tab_values = {
      "Entry 1",
      "Entry 2",
      "Entry 3",
  };

  int tab_selected = 0;
  auto tab_toggle = Toggle(&tab_values, &tab_selected);

  std::vector<entries> tabs = {{
                                   "Forest",
                                   "Water",
                                   "I don't know",
                               },
                               {
                                   "Hello",
                                   "Hi",
                                   "Hay",
                               },
                               {
                                   "Table",
                                   "Nothing",
                                   "Is",
                                   "Empty",
                               }};
  int tabs_selected[3] = {0, 0, 0};

  std::string content_1;
  auto textarea =
      Input(&content_1) | bgcolor(LinearGradient{0, Color::Red, Color::Blue});
  int size = 50;

  auto tab_container = Container::Tab(
      {
          Radiobox(&tabs[0], &tabs_selected[0]),
          Radiobox(&tabs[1], &tabs_selected[1]),
          Radiobox(&tabs[2], &tabs_selected[2]),
      },
      &tab_selected);

  auto container = Container::Stacked({tab_toggle, tab_container, textarea});

  auto renderer = Renderer(container, [&] {
    return vbox({
               tab_toggle->Render(),
               separator(),
               tab_container->Render(),
               separator(),
               textarea->Render(),
           }) |
           border;
  });

  auto screen = App::TerminalOutput().Fullscreen();
  screen.Loop(renderer);

  return 0;
}
