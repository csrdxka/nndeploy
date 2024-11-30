#include <pybind11/pybind11.h>

#include "nndeploy/framework.h"
#include "nndeploy_api_registry.h"
namespace py = pybind11;

namespace nndeploy {

PYBIND11_MODULE(_nndeploy_internal, m) {
  m.def("nndeployFrameworkInit", nndeployFrameworkInit);
  m.def("nndeployFrameworkDeinit", nndeployFrameworkDeinit);

  // 导入各个命名空间下的Python子module
  nndeploy::NndeployModuleRegistry().ImportAll(m);
}
}  // namespace nndeploy