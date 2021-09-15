#include <napi.h>

class Coordinate : public Napi::ObjectWrap<Coordinate>
{
private:
  double x;
  double y;

public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  Coordinate(const Napi::CallbackInfo &info);

  void ThrowImmutableError(const Napi::CallbackInfo &info, const Napi::Value &value);

  Napi::Value GetX(const Napi::CallbackInfo &info);
  Napi::Value GetY(const Napi::CallbackInfo &info);
  Napi::Value Dot(const Napi::CallbackInfo &info);
};
