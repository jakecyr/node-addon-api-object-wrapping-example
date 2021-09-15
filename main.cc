#include "main.h"

Napi::Value Coordinate::GetX(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  return Napi::Number::New(env, this->x);
}

Napi::Value Coordinate::GetY(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  return Napi::Number::New(env, this->y);
}

Napi::Value Coordinate::Dot(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  Coordinate *p2 = Napi::ObjectWrap<Coordinate>::Unwrap(info[0].As<Napi::Object>());

  return Napi::Number::New(env, this->x * p2->x + this->y * p2->y);
}

void Coordinate::ThrowImmutableError(const Napi::CallbackInfo &info, const Napi::Value &value)
{
  Napi::Env env = info.Env();
  throw Napi::TypeError::New(env, "Coordinate is immutable");
}

Coordinate::Coordinate(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Coordinate>(info)
{
  this->x = info[0].As<Napi::Number>();
  this->y = info[1].As<Napi::Number>();
}

Napi::Object Coordinate::Init(Napi::Env env, Napi::Object exports)
{
  Napi::Function coordinateFunction =
      DefineClass(env,
                  "Coordinate",
                  {
                      InstanceMethod("dot", &Coordinate::Dot),
                      InstanceAccessor("x", &Coordinate::GetX, &Coordinate::ThrowImmutableError),
                      InstanceAccessor("y", &Coordinate::GetY, &Coordinate::ThrowImmutableError),
                  });

  exports.Set("Coordinate", coordinateFunction);

  return exports;
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  Coordinate::Init(env, exports);
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
