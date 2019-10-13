// Copyright © Matt Jones and Contributors. Licensed under the MIT Licence (MIT). See LICENCE.md in the repository root for more information.

#ifndef NOVELRT_LAZY_H
#define NOVELRT_LAZY_H
#include <functional>
#include <memory>

namespace NovelRT {
template<typename T>
class Lazy {
public:
  Lazy(std::function<T()> delegate);
  Lazy(T eagerStartValue, std::function<T()> delegate);
  T& getActual();
  void reset();
  bool isCreated() const;
private:
  std::function<T()> _delegate;
  std::unique_ptr<T> _actual = nullptr;
};

template<typename T>
Lazy<T>::Lazy(std::function<T()> delegate) : _delegate(delegate) {}

template <typename T>
Lazy<T>::Lazy(T eagerStartValue, std::function<T()> delegate) : _delegate(delegate), _actual(std::make_unique<T>(eagerStartValue)) {}

template <typename T>
T& Lazy<T>::getActual() {
  if(!isCreated()) _actual = std::make_unique<T>(_delegate());

  return *_actual;
}

template <typename T>
void Lazy<T>::reset() {
  _actual.reset();
}
template<typename T>
bool Lazy<T>::isCreated() const {
  return _actual != nullptr;
}

}

#endif //NOVELRT_LAZY_H
