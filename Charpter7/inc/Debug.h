#pragma once

class Debug {
public:
  constexpr Debug(bool b = true) : hardWare(b), io(b), other(b) {}
  constexpr Debug(bool h, bool i, bool o) : hardWare(h), io(i), other(o) {}

  constexpr bool any() const { return hardWare || io || other; }

  void set_io(bool b) { io = b; }
  void set_hadrWare(bool b) { hardWare = b; }
  void set_Other(bool b) { other = b; }

private:
  bool hardWare;
  bool io;
  bool other;
};