#ifndef _DATA_H_
#define _DATA_H_

namespace react_cpp {

template <typename T>
class data<T> {
public:
  explicit data(T val) { _val = val; }
  virtual ~data() {}

  T value() { return _val; }

  data& operator = (const T& operand) {
    _var = operand;
    return *this;
  }

  data& operator = (const data<T, F>& operand) {
    _var = operand._var;
    return *this;
  }

private:
  T _val;
};

};

#endif
