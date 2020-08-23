// Copyright © Matt Jones and Contributors. Licensed under the MIT Licence (MIT). See LICENCE.md in the repository root for more information.

#include "NovelRT.h"
#include "NovelRT.Interop/Maths/NovelRTGeoMatrix4x4F.h"
#include <cmath>

#ifdef __cplusplus
using namespace NovelRT;
extern "C" {
#endif

  NovelRTBool NovelRT_GeoMatrix4x4F_isNaN(NovelRTGeoMatrix4x4F matrix) {
    if(NovelRT_GeoVector4F_isNaN(matrix.x) || NovelRT_GeoVector4F_isNaN(matrix.y) || NovelRT_GeoVector4F_isNaN(matrix.z) || NovelRT_GeoVector4F_isNaN(matrix.w)) {
      return NOVELRT_TRUE;
    }

    return NOVELRT_FALSE;
  }

  NovelRTGeoMatrix4x4F NovelRT_GeoMatrix4x4F_getDefaultIdentity() {
    auto identity = Maths::GeoMatrix4x4<float>::getDefaultIdentity();
    return reinterpret_cast<NovelRTGeoMatrix4x4F&>(identity);
  }

  NovelRTBool NovelRT_GeoMatrix4x4F_equal(NovelRTGeoMatrix4x4F lhs, NovelRTGeoMatrix4x4F rhs) {
    if(reinterpret_cast<const Maths::GeoMatrix4x4<float>&>(lhs) == reinterpret_cast<const Maths::GeoMatrix4x4<float>&>(rhs)) {
      return NOVELRT_TRUE;
    }

    return NOVELRT_FALSE;
  }

  NovelRTBool NovelRT_GeoMatrix4x4F_notEqual(NovelRTGeoMatrix4x4F lhs, NovelRTGeoMatrix4x4F rhs) {
    if(reinterpret_cast<const Maths::GeoMatrix4x4<float>&>(lhs) != reinterpret_cast<const Maths::GeoMatrix4x4<float>&>(rhs)) {
      return NOVELRT_TRUE;
    }

    return NOVELRT_FALSE;
  }

  NovelRTResult NovelRT_GeoMatrix4x4F_addMatrix(NovelRTGeoMatrix4x4F lhs, NovelRTGeoMatrix4x4F rhs, NovelRTGeoMatrix4x4F* result, const char** errorMessage) {
    if(result == nullptr) {
      if(errorMessage != nullptr) {
        *errorMessage = NovelRT_getErrMsgIsNullptr();
      }

      return NOVELRT_FAILURE;
    }

    if(NovelRT_GeoMatrix4x4F_isNaN(lhs) || NovelRT_GeoMatrix4x4F_isNaN(rhs)) {
      if(errorMessage != nullptr) {
        *errorMessage = NovelRT_getErrMsgIsNaN();
      }

      return NOVELRT_FAILURE;
    }
    
    const Maths::GeoMatrix4x4<float>& cFirst = reinterpret_cast<const Maths::GeoMatrix4x4<float>&>(lhs);
    const Maths::GeoMatrix4x4<float>& cOther = reinterpret_cast<const Maths::GeoMatrix4x4<float>&>(rhs);
    Maths::GeoMatrix4x4<float> resultToReturn = cFirst + cOther;
    *result = reinterpret_cast<NovelRTGeoMatrix4x4F&>(resultToReturn);

    return NOVELRT_SUCCESS;
  }

  NovelRTResult NovelRT_GeoMatrix4x4F_subtractMatrix(NovelRTGeoMatrix4x4F lhs, NovelRTGeoMatrix4x4F rhs, NovelRTGeoMatrix4x4F* result, const char** errorMessage) {
    if(result == nullptr) {
      if(errorMessage != nullptr) {
        *errorMessage = NovelRT_getErrMsgIsNullptr();
      }

      return NOVELRT_FAILURE;
    }

    if(NovelRT_GeoMatrix4x4F_isNaN(lhs) || NovelRT_GeoMatrix4x4F_isNaN(rhs)) {
      if(errorMessage != nullptr) {
        *errorMessage = NovelRT_getErrMsgIsNaN();
      }

      return NOVELRT_FAILURE;
    }
    
    const Maths::GeoMatrix4x4<float>& cFirst = reinterpret_cast<const Maths::GeoMatrix4x4<float>&>(lhs);
    const Maths::GeoMatrix4x4<float>& cOther = reinterpret_cast<const Maths::GeoMatrix4x4<float>&>(rhs);
    Maths::GeoMatrix4x4<float> resultToReturn = cFirst - cOther;
    *result = reinterpret_cast<NovelRTGeoMatrix4x4F&>(resultToReturn);

    return NOVELRT_SUCCESS;
  }

  NovelRTResult NovelRT_GeoMatrix4x4F_multiplyMatrix(NovelRTGeoMatrix4x4F lhs, NovelRTGeoMatrix4x4F rhs, NovelRTGeoMatrix4x4F* result, const char** errorMessage) {
    if(result == nullptr) {
      if(errorMessage != nullptr) {
        *errorMessage = NovelRT_getErrMsgIsNullptr();
      }

      return NOVELRT_FAILURE;
    }

    if(NovelRT_GeoMatrix4x4F_isNaN(lhs) || NovelRT_GeoMatrix4x4F_isNaN(rhs)) {
      if(errorMessage != nullptr) {
        *errorMessage = NovelRT_getErrMsgIsNaN();
      }

      return NOVELRT_FAILURE;
    }
    
    const Maths::GeoMatrix4x4<float>& cFirst = reinterpret_cast<const Maths::GeoMatrix4x4<float>&>(lhs);
    const Maths::GeoMatrix4x4<float>& cOther = reinterpret_cast<const Maths::GeoMatrix4x4<float>&>(rhs);
    Maths::GeoMatrix4x4<float> resultToReturn = cFirst * cOther;
    *result = reinterpret_cast<NovelRTGeoMatrix4x4F&>(resultToReturn);

    return NOVELRT_SUCCESS;
  }

  NovelRTResult NovelRT_GeoMatrix4x4F_addAssignMatrix(NovelRTGeoMatrix4x4F* lhs, NovelRTGeoMatrix4x4F rhs, const char** errorMessage) {
    if(lhs == nullptr) {
      if(errorMessage != nullptr) {
        *errorMessage = NovelRT_getErrMsgIsNullptr();
      }

      return NOVELRT_FAILURE;
    }

    if(NovelRT_GeoMatrix4x4F_isNaN(*lhs) || NovelRT_GeoMatrix4x4F_isNaN(rhs)) {
      if(errorMessage != nullptr) {
        *errorMessage = NovelRT_getErrMsgIsNaN();
      }

      return NOVELRT_FAILURE;
    }
    
    Maths::GeoMatrix4x4<float>& cFirst = reinterpret_cast<Maths::GeoMatrix4x4<float>&>(*lhs);
    const Maths::GeoMatrix4x4<float>& cOther = reinterpret_cast<const Maths::GeoMatrix4x4<float>&>(rhs);
    cFirst += cOther;

    return NOVELRT_SUCCESS;
  }

  NovelRTResult NovelRT_GeoMatrix4x4F_subtractAssignMatrix(NovelRTGeoMatrix4x4F* lhs, NovelRTGeoMatrix4x4F rhs, const char** errorMessage) {
    if(lhs == nullptr) {
      if(errorMessage != nullptr) {
        *errorMessage = NovelRT_getErrMsgIsNullptr();
      }

      return NOVELRT_FAILURE;
    }

    if(NovelRT_GeoMatrix4x4F_isNaN(*lhs) || NovelRT_GeoMatrix4x4F_isNaN(rhs)) {
      if(errorMessage != nullptr) {
        *errorMessage = NovelRT_getErrMsgIsNaN();
      }

      return NOVELRT_FAILURE;
    }
    
    Maths::GeoMatrix4x4<float>& cFirst = reinterpret_cast<Maths::GeoMatrix4x4<float>&>(*lhs);
    const Maths::GeoMatrix4x4<float>& cOther = reinterpret_cast<const Maths::GeoMatrix4x4<float>&>(rhs);
    cFirst -= cOther;

    return NOVELRT_SUCCESS;
  }

  NovelRTResult NovelRT_GeoMatrix4x4F_multiplyAssignMatrix(NovelRTGeoMatrix4x4F* lhs, NovelRTGeoMatrix4x4F rhs, const char** errorMessage) {
    if(lhs == nullptr) {
      if(errorMessage != nullptr) {
        *errorMessage = NovelRT_getErrMsgIsNullptr();
      }

      return NOVELRT_FAILURE;
    }

    if(NovelRT_GeoMatrix4x4F_isNaN(*lhs) || NovelRT_GeoMatrix4x4F_isNaN(rhs)) {
      if(errorMessage != nullptr) {
        *errorMessage = NovelRT_getErrMsgIsNaN();
      }

      return NOVELRT_FAILURE;
    }
    
    Maths::GeoMatrix4x4<float>& cFirst = reinterpret_cast<Maths::GeoMatrix4x4<float>&>(*lhs);
    const Maths::GeoMatrix4x4<float>& cOther = reinterpret_cast<const Maths::GeoMatrix4x4<float>&>(rhs);
    cFirst *= cOther;

    return NOVELRT_SUCCESS;
  }

  NovelRTResult NovelRT_GeoMatrix4x4F_addFloat(NovelRTGeoMatrix4x4F lhs, float rhs, NovelRTGeoMatrix4x4F* result, const char** errorMessage) {
    if(result == nullptr) {
      if(errorMessage != nullptr) {
        *errorMessage = NovelRT_getErrMsgIsNullptr();
      }

      return NOVELRT_FAILURE;
    }

    if(NovelRT_GeoMatrix4x4F_isNaN(lhs) || std::isnan(rhs)) {
      if(errorMessage != nullptr) {
        *errorMessage = NovelRT_getErrMsgIsNaN();
      }

      return NOVELRT_FAILURE;
    }
    
    Maths::GeoMatrix4x4<float>& cFirst = reinterpret_cast<Maths::GeoMatrix4x4<float>&>(lhs);
    Maths::GeoMatrix4x4<float> resultToReturn = cFirst + rhs;
    *result = reinterpret_cast<NovelRTGeoMatrix4x4F&>(resultToReturn);

    return NOVELRT_SUCCESS;
  }

  NovelRTResult NovelRT_GeoMatrix4x4F_subtractFloat(NovelRTGeoMatrix4x4F lhs, float rhs, NovelRTGeoMatrix4x4F* result, const char** errorMessage) {
    if(result == nullptr) {
      if(errorMessage != nullptr) {
        *errorMessage = NovelRT_getErrMsgIsNullptr();
      }

      return NOVELRT_FAILURE;
    }

    if(NovelRT_GeoMatrix4x4F_isNaN(lhs) || std::isnan(rhs)) {
      if(errorMessage != nullptr) {
        *errorMessage = NovelRT_getErrMsgIsNaN();
      }

      return NOVELRT_FAILURE;
    }
    
    Maths::GeoMatrix4x4<float>& cFirst = reinterpret_cast<Maths::GeoMatrix4x4<float>&>(lhs);
    Maths::GeoMatrix4x4<float> resultToReturn = cFirst - rhs;
    *result = reinterpret_cast<NovelRTGeoMatrix4x4F&>(resultToReturn);

    return NOVELRT_SUCCESS;
  }

  NovelRTResult NovelRT_GeoMatrix4x4F_multiplyFloat(NovelRTGeoMatrix4x4F lhs, float rhs, NovelRTGeoMatrix4x4F* result, const char** errorMessage) {
    if(result == nullptr) {
      if(errorMessage != nullptr) {
        *errorMessage = NovelRT_getErrMsgIsNullptr();
      }

      return NOVELRT_FAILURE;
    }

    if(NovelRT_GeoMatrix4x4F_isNaN(lhs) || std::isnan(rhs)) {
      if(errorMessage != nullptr) {
        *errorMessage = NovelRT_getErrMsgIsNaN();
      }

      return NOVELRT_FAILURE;
    }
    
    Maths::GeoMatrix4x4<float>& cFirst = reinterpret_cast<Maths::GeoMatrix4x4<float>&>(lhs);
    Maths::GeoMatrix4x4<float> resultToReturn = cFirst - rhs;
    *result = reinterpret_cast<NovelRTGeoMatrix4x4F&>(resultToReturn);

    return NOVELRT_SUCCESS;
  }

  NovelRTResult NovelRT_GeoMatrix4x4F_addAssignFloat(NovelRTGeoMatrix4x4F* lhs, float rhs, const char** errorMessage) {
    if(lhs == nullptr) {
      if(errorMessage != nullptr) {
        *errorMessage = NovelRT_getErrMsgIsNullptr();
      }

      return NOVELRT_FAILURE;
    }

    if(NovelRT_GeoMatrix4x4F_isNaN(*lhs) || std::isnan(rhs)) {
      if(errorMessage != nullptr) {
        *errorMessage = NovelRT_getErrMsgIsNaN();
      }

      return NOVELRT_FAILURE;
    }
    
    Maths::GeoMatrix4x4<float>& cFirst = reinterpret_cast<Maths::GeoMatrix4x4<float>&>(*lhs);
    cFirst += rhs;

    return NOVELRT_SUCCESS;
  }

  NovelRTResult NovelRT_GeoMatrix4x4F_subtractAssignFloat(NovelRTGeoMatrix4x4F* lhs, float rhs, const char** errorMessage) {
    if(lhs == nullptr) {
      if(errorMessage != nullptr) {
        *errorMessage = NovelRT_getErrMsgIsNullptr();
      }

      return NOVELRT_FAILURE;
    }

    if(NovelRT_GeoMatrix4x4F_isNaN(*lhs) || std::isnan(rhs)) {
      if(errorMessage != nullptr) {
        *errorMessage = NovelRT_getErrMsgIsNaN();
      }

      return NOVELRT_FAILURE;
    }
    
    Maths::GeoMatrix4x4<float>& cFirst = reinterpret_cast<Maths::GeoMatrix4x4<float>&>(*lhs);
    cFirst -= rhs;

    return NOVELRT_SUCCESS;
  }

  NovelRTResult NovelRT_GeoMatrix4x4F_multiplyAssignFloat(NovelRTGeoMatrix4x4F* lhs, float rhs, const char** errorMessage) {
    if(lhs == nullptr) {
      if(errorMessage != nullptr) {
        *errorMessage = NovelRT_getErrMsgIsNullptr();
      }

      return NOVELRT_FAILURE;
    }

    if(NovelRT_GeoMatrix4x4F_isNaN(*lhs) || std::isnan(rhs)) {
      if(errorMessage != nullptr) {
        *errorMessage = NovelRT_getErrMsgIsNaN();
      }

      return NOVELRT_FAILURE;
    }
    
    Maths::GeoMatrix4x4<float>& cFirst = reinterpret_cast<Maths::GeoMatrix4x4<float>&>(*lhs);
    cFirst *= rhs;

    return NOVELRT_SUCCESS;
  }

#ifdef __cplusplus
}
#endif
