#pragma once

#include <string>
#include <vector>

class Screen {
  friend class Window_mgr;

  // friend void Window_mgr::clear(Screen&);
public:
  using pos = std::string::size_type;

public:
  Screen() = default;
  Screen(pos ht, pos wd, char c)
      : height(ht), width(wd), contents(ht * wd, c) {}

public:
  char get() const { return contents[cursor]; }

  inline char get(pos ht, pos wd) const;

  Screen &move(pos r, pos c);

  void some_member() const;

  Screen &set(char);

  Screen &set(pos, pos, char);

  Screen &display(std::ostream &os) {
    do_display(os);
    return *this;
  }
  Screen const &display(std::ostream &os) const {
    do_display(os);
    return *this;
  }


private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;

  mutable size_t access_ctz = 0;

  void do_display(std::ostream &os) const { os << contents; }
};

class Window_mgr {
public:
  using ScreenIndex = std::vector<Screen>::size_type;

  void clear(ScreenIndex i);

  ScreenIndex addScreen(Screen const &);

private:
  std::vector<Screen> screens{Screen(20, 84, ' ')};
};

void Window_mgr::clear(ScreenIndex i) {
  Screen &s = screens[i];
  s.contents = std::string(s.height * s.width, ' ');
}

void Screen::some_member() const { ++access_ctz; }

char Screen::get(pos ht, pos wd) const { return contents[ht * width + wd]; }

inline Screen &Screen::move(pos r, pos c) {
  pos row = r * width;
  cursor = row + c;
  return *this;
}

inline Screen &Screen::set(char c) {
  contents[cursor] = c;
  return *this;
}

inline Screen &Screen::set(pos r, pos col, char c) {
  pos row = r * width;
  cursor = row + col;
  contents[cursor] = c;
  return *this;
}

Window_mgr::ScreenIndex Window_mgr::addScreen(Screen const&s)
{
    screens.push_back(s);
    return screens.size() - 1;
}