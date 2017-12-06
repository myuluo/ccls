#include "entry_points.h"
#include "message_handler.h"

#include <loguru.hpp>

struct CqueryExitWhenIdleHandler : MessageHandler {
  IpcId GetId() const override { return IpcId::CqueryExitWhenIdle; }
  void Run(std::unique_ptr<BaseIpcMessage> request) override {
    *exit_when_idle = true;
    WorkThread::request_exit_on_idle = true;
  }
};
REGISTER_MESSAGE_HANDLER(CqueryExitWhenIdleHandler);